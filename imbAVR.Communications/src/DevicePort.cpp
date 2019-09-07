// 
// 
// 

#include "DevicePort.h"

DevicePort::DevicePort(SoftwareSerial * softSerial)
{
	softwarePort = softSerial;
	portType = 1;
}

DevicePort::DevicePort(HardwareSerial * hardSerial)
{
	hardwarePort = hardSerial;
	portType = 0;
}

byte DevicePort::read()
{
	switch (portType)
	{
	case 0:
		return hardwarePort->read();
		break;
	default:
		return softwarePort->read();
		break;
	}
}

void DevicePort::write(byte data)
{
	switch (portType)
	{
	case 0:
		hardwarePort->write(data); 
		break;
	default:
		softwarePort->write(data);
		break;
	}
}

int DevicePort::available()
{
	switch (portType)
	{
	case 0:
		return hardwarePort->available();
		break;
	default:
		return softwarePort->available();
		break;
	}

}

void DevicePort::flush()
{
	switch (portType)
	{
	case 0:
		hardwarePort->flush();
		break;
	default:
		softwarePort->flush();
		break;
	}
}

void DevicePort::begin(unsigned int rate)
{
	switch (portType)
	{
	case 0:
		hardwarePort->begin(rate);
		break;
	default:
		softwarePort->begin(rate);
		break;
	}
}

void DevicePort::end()
{
	switch (portType)
	{
	case 0:
		hardwarePort->end();
		break;
	default:
		softwarePort->end();
		break;
	}
}
