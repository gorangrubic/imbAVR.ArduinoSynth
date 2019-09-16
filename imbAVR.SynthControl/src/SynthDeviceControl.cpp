#include "SynthDeviceControl.h"



SynthDeviceControl::SynthDeviceControl()
{
}


SynthDeviceControl::~SynthDeviceControl()
{
}

//
//
//// --
//
//void handleNoteOn(byte inChannel, byte inNumber, byte inVelocity)
//{
//	Serial.print("NoteOn  ");
//	Serial.print(inNumber);
//	Serial.print("\tvelocity: ");
//	Serial.println(inVelocity);
//}
//void handleNoteOff(byte inChannel, byte inNumber, byte inVelocity)
//{
//	Serial.print("NoteOff ");
//	Serial.print(inNumber);
//	Serial.print("\tvelocity: ");
//	Serial.println(inVelocity);
//}
//
//void setup() {
//	Serial.begin(115200);
//	while (!Serial);
//	MIDI.begin();
//	MIDI.setHandleNoteOn(handleNoteOn);
//	MIDI.setHandleNoteOff(handleNoteOff);
//	Serial.println("Arduino ready.");
//}
//
//void loop() {
//	MIDI.read();
//}


void SynthDeviceControl::setup() {

	pinMode(7, OUTPUT);
	digitalWrite(7, HIGH);
	
	SPI.begin();

	SPI.setClockDivider(SPI_CLOCK_DIV128);

	//pinMode(SOUND_OUT, OUTPUT);
	mainControl.time_factor = ENGINE_TIMEFACTOR;

	mainControl.setup();
	
	SignalGeneratorLink.setup(7, B00000111, 10);

	Engine_Chrono.start();

#ifdef DEBUG_NOTE_PLAY

	DebugNote_Chrono.start();

#endif // DEBUG_NOTE_PLAY

#ifdef READ_MIDI_SERIAL

//	PortMidi.begin(READ_MIDI_SERIAL_BAUDRATE);

#endif // READ_MIDI_SERIAL
	

	vol_cluster.init(PIN_VOLCLUSTER_CLOCK, PIN_VOLCLUSTER_VOL1, PIN_VOLCLUSTER_VOL2, PIN_VOLCLUSTER_VOL3);

#ifdef USE_DIGPOTCLUSTER

	dp_cluster.init(PIN_DPCLUSTER_LATCH, PIN_DPCLUSTER_CLOCK, PIN_DPCLUSTER_DATA);

#endif // USE_DIGPOTCLUSTER


#ifdef SYNTHDIAG_DEVICE_ON

	//PortTwo.begin(SYNTHDIAG_DEVICE_BAUDRATE);
#endif // SERIAL_ON


}


String SynthDeviceControl::DescribeMidi(midiEventPacket_t rx) {

	String output = "Header: ";

	output += rx.header;
	output += " b1: ";
	output += rx.byte1;
	output += " b2: ";
	output += rx.byte2;
	output += " b3: ";
	output += rx.byte3;

	
	return output;
}


// the loop function runs over and over again until power down or reset
void SynthDeviceControl::loop(midiEventPacket_t rx) {






#ifdef DEBUG_NOTE_PLAY

	

			if (DebugNote_Chrono.hasPassed(DEBUG_NOTE_CYCLE_DURATION,false)) {
				tone(SOUND_OUT, 220, DEBUG_NOTE_DURATION);
				DebugNote_Chrono.restart();
				mainControl.noteOn(1, DEBUG_NOTE_PITCH, 100);
			}

			if (DebugNote_Chrono.elapsed() > DEBUG_NOTE_DURATION) {
				mainControl.noteOff(1, DEBUG_NOTE_PITCH, 100);
			}
			//else {
			//	if (!mainControl.tone_on) {

			//		mainControl.noteOn(1, DEBUG_NOTE_PITCH, 100);
			//		tone(SOUND_OUT, 1660, 50);
			//		//rx.header = 0x9;
			//		//rx.byte1 = 1 & 0xF;
			//		//rx.byte2 = DEBUG_NOTE_PITCH;
			//		//rx.byte3 = 100;
			//	}
			//}


#endif // DEBUG_NOTE_PLAY

#ifdef READ_MIDI_SERIAL
		
			if (MidiRead_Chrono.hasPassed(100)) {
				//if (Serial.available()) {


				//	byte b = Serial.read();

				//	rx.header = b & 0b11110000;

				//	rx.byte1 = b;

				//	rx.byte2 = Serial.read();
				//	rx.byte3 = Serial.read();

				//	//
				//}
				//else {
				//	rx.header = 0;

				//	//tone(SOUND_OUT, 880, 50);
				//}
				MidiRead_Chrono.restart();
			}
		
#endif




		switch (rx.header) {
			case 0:
				break; //No pending events
			case 0x9:
				mainControl.noteOn(rx.byte1 & 0xF, rx.byte2, rx.byte3);
				break;

			case 0x8:
				mainControl.noteOff(rx.byte1 & 0xF, rx.byte2, rx.byte3);
				break;

			case 0xB:

				mainControl.controlChange(rx.byte1 & 0xF, rx.byte2, rx.byte3);
				break;
			case  0xF:

				mainControl.systemMessage(rx.byte1 & 0xF, rx.byte2, rx.byte3);
				break;
		}




	unsigned int cT = mainControl.DoTick();



#ifdef USE_DIGPOTCLUSTER

	dp_cluster.Write(
		mainControl.State.CSValues.Data[CS_WAVEFORMA_MOD],
		mainControl.State.CSValues.Data[CS_FLT_CutOff],
		mainControl.State.CSValues.Data[CS_WAVEFORMB_MOD],
		mainControl.State.CSValues.Data[CS_FLT_Resonance],
		127,
		127,
		127,	
		mainControl.State.CSValues.Data[CS_WAVEFORMAB_MIX]
	);

	//dp_cluster.Write(
	//	mainControl.State.out_waveform_a_shaper,
	//	mainControl.State.out_flt_value,
	//	mainControl.State.out_waveform_b_flt,
	//	mainControl.State.out_flt_gain,
	//	127,
	//	mainControl.State.out_mainComponent_gain,
	//	mainControl.State.out_waveform_mix,
	//	mainControl.State.out_distortion_mix
	//);

#endif // USE_DIGPOTCLUSTER


	vol_cluster.setVolume(
		mainControl.State.CSValues.Data[CS_PERKA_L_AMP],
		mainControl.State.CSValues.Data[CS_PERKA_R_AMP],
		
		mainControl.State.CSValues.Data[CS_PERKB_L_AMP],
		mainControl.State.CSValues.Data[CS_PERKB_R_AMP],
				
		mainControl.State.CSValues.Data[CS_MASTER_L_AMP],
		mainControl.State.CSValues.Data[CS_MASTER_R_AMP]
	);



	// ----------- sending all scheduled instructions to signal generator

	for (byte i = 0; i < mainControl.linkBuffer.bufferIndex; i++)
	{

//	while (mainControl.linkBuffer.GetIndex() > 0) {

#ifdef SYNTHDIAG_DEVICE_ON


		byte index = i;
		SignalMacroInstruction instruction = mainControl.linkBuffer.Data[i];

#ifdef SMI_UNPACKED_FORM

		byte b2 = instruction.b2;
		byte b3 = instruction.b3;
		byte b4 = instruction.b4;

		byte s_id = instruction.sid;
		byte cc_id = instruction.cid;
		//Serial.println("smi->" + String(s_id) + ":" + String(cc_id) + "|" + String(b2) + ":" + String(b3) + ":" + String(b4)  + "[" + String(index) + "]");
		Serial.print("smi-->");
		Serial.print(s_id);
		
		Serial.println(":" + String(cc_id) + "|" + String(b2) + ":" + String(b3) + ":" + String(b4) + "[" + String(index) + "]");
#else
		byte b1 = instruction.data >> 24;
		byte b2 = instruction.data >> 16;
		byte b3 = instruction.data >> 8;
		byte b4 = instruction.data;

		byte s_id = (b1 & B11110000) >> 4;
		byte cc_id = b1 & B00001111;
		Serial.println("smi->" + String(s_id) + ":" + String(cc_id) + "|" + String(b2) + ":" + String(b3) + ":" + String(b4) + "[" + String(index) + "]");
#endif
		//byte b1 = (smi.data >> 24)&B11111111;  //smi.data&B11111111;

		//byte s_id = b1 >> 4;
		//byte cc_id = b1 & B00001111;

		//byte b2 = (smi.data >> 16)&B11111111;
		//byte b3 = (smi.data >> 8)&B11111111;
		//byte b4 = smi.data&B11111111;

		
		SignalGeneratorLink.Send(instruction);
		
#else
		SignalGeneratorLink.Send(mainControl.linkBuffer.GetLast());
#endif

		


	}

	mainControl.linkBuffer.ClearAll();



//	if (Engine_Chrono.hasPassed(Engine_Tick)) {
//
//#ifdef SYNTHDIAG_DEVICE_ON
//
//
//		for (size_t i = 0; i < MonitorMessageHeaderSize; i++)
//		{
//			PortTwo.write(MonitorMessageStartChar);
//		}
//
//		MonitorMessage msg;
//
//		msg.State = mainControl.State; // .CCValues = mainControl.CCValues;
//		msg.cT = cT;
//		msg.SerialWrite(Data);
//
//		for (size_t i = 0; i < MonitorMessageSize_Bytes; i++)
//		{
//			PortTwo.write(Data[i]);
//		}
//
//#endif // SERIAL_ON
//
//		Engine_Chrono.restart();
//
//	}

}
