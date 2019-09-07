// 
// 
// 

#include "DeviceRegistration.h"

bool DeviceRegistration::bootStart(DevicePort * port)
{
	if (startTime == 0) startTime = millis();

	
	switch (port->portType)
	{
	case 0:
		port->hardwarePort->begin(9600);
		break;
	default:
		port->softwarePort->begin(9600);
		break;
	}

	port->transferLink.SetHeader(port->transferLink.MakeHeader(TRANSFERCLASSID_DEVICESIGNATURE, sizeof(DeviceSignature), false, 0b11, 0b10, 0b10, true));
	port->transferLink.Send(&port, &port->transferLink.activeHeader);

}

bool DeviceRegistration::bootLoop(DevicePort * port)
{
	

	if (port->Signature.deviceType == DEVICESIGNATURE_UNKNOWN) {

	}


	if (millis() - startTime > REGISTRATION_TIMEOUT) {
		return true;
	}
}
