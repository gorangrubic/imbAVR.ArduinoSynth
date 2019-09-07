// 
// 
// 

#include "DeviceRegistration.h"

bool DeviceRegistration::bootStart(DevicePort * port, TransferLink * transferLink)
{

	transferLink->SetHeader(TransferLink::MakeHeader(TRANSFERCLASSID_DEVICESIGNATURE, sizeof(DeviceSignature)));
	port->begin(9600);

	
	DeviceSignature signatureToSend;
	signatureToSend.deviceType = deviceType;
	signatureToSend.maxBaudrate = port->baudrate;
	
	TRANSFER_SENDDATA(transferLink, port, signatureToSend)

}

bool DeviceRegistration::bootLoop(DevicePort * port, TransferLink * transferLink)
{
	if (port->Signature.deviceType == DEVICESIGNATURE_UNKNOWN) {
		byte result = transferLink->Receive(port);
		if (IS_RECEIVE_RESULTSUCCESS(result)) {

			TRANSFER_LOADDATA(port->Signature, transferLink)

				devices |= port->Signature.deviceType;

			return true;
		}
		else {
			if (millis()  > REGISTRATION_TIMEOUT) {
				return true;
			}
		}
	}
	else {
		return true;
	}
}


void DeviceRegistration::bootComplete(DevicePort * port)
{
	if (port->Signature.deviceType == DEVICESIGNATURE_UNKNOWN) {
		port->baudrate = min(port->Signature.maxBaudrate, port->baudrate);
		port->end();
		port->begin(port->baudrate);
		delay(50);
	}
}


DeviceRegistration::DeviceRegistration(byte _deviceType)
{
	deviceType = deviceType;
}
