#include "DiagnosticDeviceViewSet.h"



DiagnosticDeviceViewSet::DiagnosticDeviceViewSet()
{
}
void DiagnosticDeviceViewSet::Deploy(GuiScreen * Screen)
{
	screenView.Deploy(Screen);
	SetFirstCall(true);
}
//void DiagnosticDeviceViewSet::Deploy(DiagnosticData Data, TransferLink  deviceLink_SynthControlToSignal, TransferLink  deviceLink_SynthControlToDiagnostic,
//	SignalControlManagerClass  SignalControlManager, MonitorMessage  msg, GuiScreen * Screen)
//{
//	
//	//view0_r1 = RowTemplates::RowWithTwoByteFields("SYBF", deviceLink_SynthControlToSignal.bufferIndex, "SDBF", deviceLink_SynthControlToDiagnostic.bufferIndex);
//
//	//view1_r1 = RowTemplates::RowWithTwoByteFields("ATT", msg.State.CCValues[CC_AmpAttack], "DEC", msg.State.CCValues[CC_AmpDecayTime]);
//	//view1_r2 = RowTemplates::RowWithTwoByteFields("REL", msg.State.CCValues[CC_AmpRelease], "SUS", msg.State.CCValues[CC_AmpSustainLevel]);
//
//	//view6_r1 = RowTemplates::RowTextWithPrefix("1", Data.LogMessages[0]);
//	//view6_r2 = RowTemplates::RowTextWithPrefix("2", Data.LogMessages[1]);
//	//view6_r3 = RowTemplates::RowTextWithPrefix("3", Data.LogMessages[2]);
//	//view6_r4 = RowTemplates::RowTextWithPrefix("4", Data.LogMessages[3]);
//	//view6_r5 = RowTemplates::RowTextWithPrefix("5", Data.LogMessages[4]);
//
//	//
//	////Views[0].AddRow(&view0_r0, Screen);
//	//Views[0].AddRow(&view0_r1, Screen);
//
//
//	//Views[1].AddRow(&view1_r0, Screen);
//	//Views[1].AddRow(&view1_r1, Screen);
//	//Views[1].AddRow(&view1_r2, Screen);
//
//	//Views[2].AddRow(&view2_r0, Screen);
//
//	//Views[3].AddRow(&view3_r0, Screen);
//
//	//Views[4].AddRow(&view4_r0, Screen);
//
//
//	//Views[5].AddRow(&view5_r0, Screen);
//
//	//Views[6].AddRow(&view6_r0, Screen);
//	//Views[6].AddRow(&view6_r1, Screen);
//	//Views[6].AddRow(&view6_r2, Screen);
//	//Views[6].AddRow(&view6_r3, Screen);
//	//Views[6].AddRow(&view6_r4, Screen);
//	//Views[6].AddRow(&view6_r5, Screen);
//
//	//Views[7].AddRow(&view7_r0, Screen);
//
//}


void DiagnosticDeviceViewSet::RenderClassHeader(TransferLink * link, String title, GuiScreen * Screen, ACEMegaHostTFTClass * Display) {
	screenView.AddHeader(title, Screen, Display, state, B00100011, 1);
	screenView.AddHalfWidthLabelAndByteValue("cID", link->activeHeader.class_id, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000001, 1);
	screenView.AddHalfWidthLabelAndByteValue("Size", link->activeHeader.size, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000000, 1, true);
	screenView.AddLabelAndByteValue("Prot", link->activeHeader.protocol, FieldValueRenderMode::graphic_bitBoxArray, Screen, Display, state, B00100010, 1);
	screenView.AddHalfWidthLabelAndByteValue("CtrB", link->NumberOfControlBytes, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000001, 1);
	screenView.AddHalfWidthLabelAndByteValue("AllB", link->activeHeader.size + link->NumberOfControlBytes, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000000, 1, true);
}

void DiagnosticDeviceViewSet::RenderScreen(GuiScreen * Screen, ACEMegaHostTFTClass * Display)
{
	screenView.Deploy(Screen);

	screenView.Reset();

	if ((state & B00000001) == B00000001) Display->fillScreen(Screen->BackColor);

	
	switch (currentView) {


	case 0:
		screenView.AddHeader("Overview", Screen, Display, state, B00100011, 1);

		screenView.AddHalfWidthLabelAndByteValue("Sy2S", deviceLink_SynthControlToSignal->bufferIndex, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000001, 1);
		screenView.AddHalfWidthLabelAndByteValue("Sy2D", deviceLink_SynthControlToDiagnostic->bufferIndex, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000000, 1, true);

		screenView.AddLabelAndByteValue("ID", deviceRegistration->deviceType, FieldValueRenderMode::graphic_bitBoxArray, Screen, Display, state, B00000010, 1);
		screenView.AddLabelAndByteValue("Reg", deviceRegistration->devices, FieldValueRenderMode::graphic_bitBoxArray, Screen, Display, state, B00000010, 1);
		
		screenView.AddHeader("Signal Generator", Screen, Display, state, B00100000, 1);
		screenView.AddLabelAndByteValue("DevID", devicePort_SignalGen->Signature.deviceType, FieldValueRenderMode::graphic_bitBoxArray, Screen, Display, state, B00100010, 1);
		screenView.AddHalfWidthLabelAndUIntValue("Rate", devicePort_SignalGen->baudrate, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000001, 1,false);
		screenView.AddHalfWidthLabelAndUIntValue("Max", devicePort_SignalGen->Signature.maxBaudrate, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000000, 1, true);

		screenView.AddHeader("Synth to SiGen", Screen, Display, state, B00100000, 1);
		screenView.AddLabelAndByteValue("DevID", devicePort_SynthControlToSignal->Signature.deviceType, FieldValueRenderMode::graphic_bitBoxArray, Screen, Display, state, B00100010, 1);
		screenView.AddHalfWidthLabelAndUIntValue("Rate", devicePort_SynthControlToSignal->baudrate, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000001, 1, false);
		screenView.AddHalfWidthLabelAndUIntValue("Max", devicePort_SynthControlToSignal->Signature.maxBaudrate, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000000, 1, true);

		screenView.AddHeader("Synth to DiagDevice", Screen, Display, state, B00100000, 1);
		screenView.AddLabelAndByteValue("DevID", devicePort_SynthControlToDiagnostic->Signature.deviceType, FieldValueRenderMode::graphic_bitBoxArray, Screen, Display, state, B00100010, 1);
		screenView.AddHalfWidthLabelAndUIntValue("Rate", devicePort_SynthControlToDiagnostic->baudrate, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000001, 1, false);
		screenView.AddHalfWidthLabelAndUIntValue("Max", devicePort_SynthControlToDiagnostic->Signature.maxBaudrate, FieldValueRenderMode::numeric_value, Screen, Display, state, B00000000, 1, true);

		/*screenView.AddHeader("GUI Demo", Screen, Display, state, B00100001, 1);
		screenView.AddLabelAndByteValue("Bits8", B01010011, FieldValueRenderMode::graphic_bitBoxArray, Screen, Display, state, B00100010, 1);
		screenView.AddLabelAndByteValue("Bits4L", B01010011, FieldValueRenderMode::graphic_bitBoxArrayLow4, Screen, Display, state, B00100010, 1);
		screenView.AddLabelAndByteValue("Bits4H", B01010011, FieldValueRenderMode::graphic_bitBoxArrayHigh4, Screen, Display, state, B00100010, 1);
		screenView.AddHalfWidthLabelAndByteValue("V1", 127, FieldValueRenderMode::numeric_value, Screen, Display, state, B00100001, 1);
		screenView.AddHalfWidthLabelAndByteValue("V2", 250, FieldValueRenderMode::numeric_value, Screen, Display, state, B00100000, 1, true);
		screenView.AddLabelAndByteValue("V1", 127, FieldValueRenderMode::graphic_horizontal_bar, Screen, Display, state, B00100010, 1);
		screenView.AddLabelAndByteValue("V2", 250, FieldValueRenderMode::graphic_horizontal_bar, Screen, Display, state, B00100010, 1);
*/
		break;

	case 1:
		//screenView.AddHeader("Synth to SiGen", Screen, Display, state, B00100001, 1);
		RenderClassHeader(deviceLink_SynthControlToSignal, "SC2Signal", Screen, Display);
		RenderClassHeader(deviceLink_SynthControlToDiagnostic, "SC2Diagnostic", Screen, Display);
		
		break;

	case 2:
		screenView.AddHeader("Synth state B", Screen, Display, state, B00100001, 1);
		break;

	case 3:
		screenView.AddHeader("Signal state", Screen, Display, state, B00100001, 1);
		break;

	case 4:
		screenView.AddHeader("MIDI messages", Screen, Display, state, B00100001, 1);
		break;

	case 5:
		screenView.AddHeader("Log messages", Screen, Display, state, B00100001, 1);
		break;
	case 6:
		screenView.AddHeader("Signal instructions", Screen, Display, state, B00100001, 1);
		break;
	case 7:
		screenView.AddHeader("Other", Screen, Display, state, B00100001, 1);
		break;
	}

	SetFirstCall(false);
}


//
//void DiagnosticDeviceViewSet::Deploy(DiagnosticDeviceManager _diagnosticDevice, GuiScreen * Screen)
//{
//	diagnosticDevice = &_diagnosticDevice;
//

//}
//
//template class GuiScreenViewSet<8>;