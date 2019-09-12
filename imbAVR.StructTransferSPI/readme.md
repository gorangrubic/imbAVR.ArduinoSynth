# imbAVR.StructTransferSPI

Lightweight library for sending structured data (structs) to another Arduino using SPI protocol. 

*spiSender<TData>* and *spiReceiver<TData, ISize>* are class templates that facilitate transfer, serialization and deserialization of your struct TData. 


	spiSender<customMessage> dataSender = spiSender<customMessage>(pinSS);


## How to use

### Minimum setup on SPI Slave side (Arduino that receives the data):

    
	spiReceiver<customMessage, 5> dataReceiver = spiReceiver<customMessage, 5>();

	void setup() {

		pinMode(MISO, OUTPUT);

		SPCR |= _BV(SPE);

		dataReceiver.setup(B00000011);

		SPI.attachInterrupt();

	}

	ISR(SPI_STC_vect)
	{
		dataReceiver.Receive(SPDR);
	}


	void loop()
	{
		byte result = dataReceiver.loop();

		if ((result & B11110000) == B11110000) {
			for (size_t i = 0; i < dataReceiver.InstanceBufferIndex; i++)
			{
				log(dataReceiver.InstanceBuffer[i]);

			}
			dataReceiver.ClearInstanceBuffer();
		}
		else if (result != B00000000) {
			log(String(result, BIN));
		}
	} 

	
### Minimum setup on SPI Master side (Arduino that sends the data):

    
	spiSender<customMessage> dataSender = spiSender<customMessage>();

	void setup() {

		digitalWrite(pinSS, HIGH);

		SPI.begin();
	
		SPI.setClockDivider(SPI_CLOCK_DIV8);

		dataSender.setup(pinSS, B00000011);

	}

	customMessage msg;

	void loop()
	{

		// here you make changes to the message
		... 

		...

		// and send it
		dataSender.Send(msg);

		delay(500);
	} 


---

Size of buffer memory allocated by spiReceiver is result of: 
  - sizeof(TData)
  and
  - ISize template parameter

where:

  - DataBuffer size is function of: (sizeof(TData) + 2 ) * ISize


Size of allocated buffer is controled ISize (byte) parameter


## Protocol bits

Both spiSender and spiReceived have byte property: [protocol], which has default value: 0b00000000

By default, no mechanisms of data consistency and redundancy are enforced. Also, after each TData instance pulled, DataBuffer is trimmed (panned) left - instead of flushed. When working with small buffer (ISize=2..3), this might lead to buffer cliping, i.e. data corruption. 

Protocol bit 0 [xxxxxxx1]:

  - Enables single *control byte*, computed from all bytes in the struct and appended as sufix, on the end of each transfer. This will allow data consistency check at spiReceiver side, by comparison between received control byte and one computed from received data. By using this option, you can reduce undetected data errors to 0%.

Protocol bit 1 [xxxxxx1x]:

  - *Double send* option will repeat each transfer twice (including the control byte), allowing spiReceiver to use the second transfer in case first found corrupted (by control byte check). This will reduce effective transfer speed by half, as cost of reduced probability of data loss. 

Protocol bit 2 [xxxxx1xx]:

  - Enables DataBuffer flushing, after first TData instace is deserialized (disables DataBuffer panning described above)



blog: http://blog.veles.rs