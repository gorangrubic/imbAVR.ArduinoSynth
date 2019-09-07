// 
// 
// 

#include "DiagnosticDeviceManager.h"

void DiagnosticDeviceManager::SynthToSignalTransfer()
{

	// -------------
	int SynthControlBytes = Serial1.available();

	if (SynthControlBytes > 0) {
		Data.SignalInBufferIndex = SynthControlBytes;
		for (size_t i = 0; i < SynthControlBytes; i++)
		{
			byte b = Serial1.read();
			Data.SignalInBuffer[i] = b;
		}
		LedToggle(LED_SYNTHTOSIGNAL);
	}
	else
	{
		Data.SignalInBufferIndex = 0;
	}


	for (size_t i = 0; i < Data.SignalInBufferIndex; i++)
	{
		Serial2.write(Data.SignalInBuffer[i]);
	}
	// -------------


	// -------------
	int SignalControlBytes = Serial2.available();

	if (SignalControlBytes > 0) {
		Data.SynthInBufferIndex = SignalControlBytes;
		for (size_t i = 0; i < SignalControlBytes; i++)
		{
			byte b = Serial2.read();
			Data.SynthInBuffer[i] = b;
		}
		LedToggle(LED_SIGNALTOSYNTH);
	}
	else
	{
		Data.SynthInBufferIndex = 0;
	}


	for (size_t i = 0; i < Data.SynthInBufferIndex; i++)
	{
		Serial1.write(Data.SynthInBuffer[i]);
	}
	// -----------------------------------------



	if (Data.SynthInBufferIndex > 0) {

		if (link.ByteCodeProtocol) {

			for (size_t i = 0; i < Data.SignalInBufferIndex; i++)
			{
				SignalControlManager.Receive(Data.SignalInBuffer[i]);
			}
		}
		else {

			String input = "";

			for (size_t i = 0; i < Data.SignalInBufferIndex; i++)
			{
				input += Data.SignalInBuffer[i];
			}

			while (input.indexOf("[") > -1) {

				byte lastIndex = link.instructionIndex;

				input = link.readStringChar(input);

				if (lastIndex != link.instructionIndex) {

					SignalControlManager.Perform(link.instruction);

				}
			}

		}
	}
	
}

void DiagnosticDeviceManager::Log(String logLine)
{

	Data.AddLog(logLine);

	if (LogToSerial) {
		Serial.print(Data.LogCount);
		Serial.print(": ");
		Serial.println(logLine);
	}
}

void DiagnosticDeviceManager::setup()
{

	deviceRegistration.bootStart(&devicePort_SignalGen);
	deviceRegistration.bootStart(&devicePort_SynthControlToDiagnostic);
	deviceRegistration.bootStart(&devicePort_SynthControlToSignal);

	

	while (!(deviceRegistration.bootLoop(Serial1) && deviceRegistration.bootLoop(Serial2) && deviceRegistration.bootLoop(PortSynthDebug))) {


	}



	link.mode = 0;

	GUI.TextSize = 2;

	Display.setTextSize(GUI.TextSize);
	Display.begin();
	Display.setRotation(1);
	Display.fillScreen(GLCD_CL_BLACK);
	Display.println("Starting");

	module.setupDisplay(true, 7);
	
	

	ViewSet.ActiveViews = 4;

	ViewSet.Views[0].AddRow(&v1_title);
	ViewSet.Views[0].AddRow(&v1_subtitle);
	ViewSet.Views[0].AddRow(&v1_SCData);

	ViewSet.Views[1].AddRow(&v2_title);
	ViewSet.Views[1].AddRow(&v2_1);
	ViewSet.Views[1].AddRow(&v2_2);


	ViewSet.Views[2].AddRow(&v3_title);

	ViewSet.Views[3].AddRow(&v4_title);

	ViewSet.Views[4].AddRow(&v5_title);

	//GuiScreenView * currentView = &ViewSet.CreateView();
	//currentView->AddRow(RowHeading("Overview"));

	////currentView = &ViewSet.CreateView();
	//ViewSet.Views[1].AddRow(&RowHeading("Synth state 1"));

	////currentView = &ViewSet.CreateView();
	//ViewSet.Views[2].AddRow(&RowHeading("Synth state 2"));

	////currentView = &ViewSet.CreateView();
	//ViewSet.Views[3].AddRow(&RowHeading("Signal-gen state 1"));

	////currentView = &ViewSet.CreateView();
	//ViewSet.Views[4].AddRow(&RowHeading("Signal-gen state 2"));

//	currentView = &ViewSet.CreateView();
//	cViewSet.Views[0].AddRow(RowHeading("Diagnostic"));


	/*
	RowFirst.Deploy(GUI);
	RowSecond.Deploy(GUI);
	RowTopHeading.Deploy(GUI, "Waveform CCs");
	RowAmpCtrlHeading.Deploy(GUI, "AMP ADSR");

	RowAmpCtrlFirst.Deploy(GUI, GLCD_CL_CYAN);
	RowAmpCtrlSecond.Deploy(GUI, GLCD_CL_CYAN);
	RowAmpCtrlThird.Deploy(GUI, GLCD_CL_CYAN);


	RowFltCtrlHeading.Deploy(GUI, "FLT ADSR");

	RowFltCtrlFirst.Deploy(GUI, GLCD_CL_RED);
	RowFltCtrlSecond.Deploy(GUI, GLCD_CL_RED);
	RowFltCtrlThird.Deploy(GUI, GLCD_CL_RED);
	RowFltCtrlFourth.Deploy(GUI);
	*/

	


	Serial2.begin(baudrate_signal_device);
	Serial1.begin(baudrate_signal_device);

	Serial.begin(baudrate_mainserial);
	PortSynthDebug.begin(baudrate_mainserial);

	

	SignalControlManager.AddSignalUnit(2); // S0
	SignalControlManager.AddSignalUnit(3); // S1
	SignalControlManager.AddSignalUnit(4); // S2
	SignalControlManager.AddSignalUnit(5); // S3
	SignalControlManager.AddSignalUnit(6); // S4
	SignalControlManager.AddSignalUnit(7); // S5
}

void DiagnosticDeviceManager::UpdateLedDisplay() {

	LedSet(LED_AUTOCHANGEON, displayModeAutochange);

	module.setLEDs(LedState);

	if (lastDisplayMode != displayMode) {
		String toDisplay = "_____  ";
		toDisplay += displayMode;


		module.setDisplayToString(toDisplay);
		//module->setDisplayDigit(0, displayMode, true);
		//module.setDisplayToDecNumber(diagnosticDevice.displayMode, dots, false);
		//module.setLED(TM1638_COLOR_RED, displayMode);
	}
}

void DiagnosticDeviceManager::LedSet(byte led_id, boolean state) {
	if (state) {
		bitWrite(LedState, led_id, 1);
	}
	else
	{
		bitWrite(LedState, led_id, 0);
	}
}

void DiagnosticDeviceManager::LedToggle(byte led_id) {
	if (bitRead(LedState, led_id) == 0) {
		bitWrite(LedState, led_id, 1);
	}
	else
	{
		bitWrite(LedState, led_id, 0);
	}
}

void DiagnosticDeviceManager::loop()
{

	if (heartbeat_chrono.hasPassed(1000)) {
		LedToggle(7);
		heartbeat_chrono.restart();
	}

	// ----- buttons read
	word buttons = module.getButtons();
	
//	byte mode = 0;

	// button pressed - change mode
	if (buttons != 0) {
		byte mode = buttons >> 1;
		if (mode < 128) {
			module.clearDisplay();
			delay(50);
		}

		switch (mode) {
		case 0:
			displayMode = 0;

			break;
		case 1:
			displayMode = 1;
			break;
		case 2:
			displayMode = 2;
			break;
		case 4:
			displayMode = 3;
			break;
		case 8:
			displayMode = 4;
			break;
		case 16:
			displayMode = 5;
			break;
		case 32:
			displayMode = 6;
			break;
		case 64:
			displayMode = 7;
			break;
		case 128:
			//displayMode = 8;
			break;
		case 256:
			//displayMode = 9;
			break;
		}

	}
	// ---

	if (refresh_display_chrono.hasPassed(250)) {

		
		UpdateLedDisplay();

		ViewSet.UpdateScreen(displayMode, &Display);
		refresh_display_chrono.restart();
	}

	if (auto_change_display_chrono.hasPassed(5000)) {
		displayMode++;
		if (displayMode > ViewSet.ActiveViews) {
			displayMode = 0;
		}

		auto_change_display_chrono.restart();
	}


	
	char command = ' ';
	if (Serial.available()) {

		command = Serial.read();

		switch (command) {
			case '0':
				displayMode = 0;
				break;
			case '1':
				displayMode = 1;
				break;
			case '2':
				displayMode = 2;
				break;
			case '3':
				displayMode = 3;
				break;
			case '4':
				displayMode = 4;
				break;
			case 'C':
				break;
			default:
				break;
		}

		LedToggle(LED_PCTODIAGNOSTIC);
	}

	SynthToSignalTransfer();


	if (auto_change_display_chrono.hasPassed(5000)) {
		displayMode++;
		if (displayMode > ViewSet.ActiveViews) {
			displayMode = 0;
		}

		auto_change_display_chrono.restart();
	}



	while (PortSynthDebug.available()) {

		byte b = PortSynthDebug.read();
		if (mmHeader >= MonitorMessageHeaderSize) {
			if (mmDataIndex >= MonitorMessageSize_Bytes) {
				mmHeader = 0;
				mmDataIndex = 0;
				msg.SerialRead(mmData);
			}
			else {
				mmData[mmDataIndex] = b;
				mmDataIndex++;
			}
		}
		else {
			if (b == MonitorMessageStartChar) {
				mmHeader++;
				mmDataIndex = 0;
			}	
		}
	}


}
