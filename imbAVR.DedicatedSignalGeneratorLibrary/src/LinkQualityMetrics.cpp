#include "LinkQualityMetrics.h"
#include "MathTool.h"
//
//
//void LinkQualityMetrics::ControlCall(byte ControlValue)
//{
//}
//
//bool LinkQualityMetrics::Evaluate()
//{
//	return false;
//}

bool LinkQualityMetrics::Count(byte receiveResult)
{
	if (StartTime == 0) StartTime = millis();

	LastCountTime = millis();

	if (receiveResult == B00000000) {
		NothingReceived++;
		return false;
	}


	

	if (MessageCounted >= TestTarget) return false;

	MessageCounted++;

	if (bitRead(receiveResult, 6) == 1) {
		DataBufferClipping++;
	}

	if (bitRead(receiveResult, 7) == 1) {
		SuccessAll++;


		byte successOnNth = receiveResult & B00001111;
		successOnNth = constrain(successOnNth, 0, 8);

		SuccessOn[successOnNth]++;

	}
	else {
		FailAll++;
	}


	ReportIndex++;
	if (ReportIndex > ReportCount) {
		ReportIndex = 0;
		return true;
	}
	return false;

}

void LinkQualityMetrics::ShortReport(HardwareSerial * hSerial)
{

	hSerial->println("Messages: " + String(MessageCounted) + " / " + String(TestTarget));

	hSerial->println("FailAll: " + String(FailAll) + " / " + String(MessageCounted));
	hSerial->println("Success rate: " + String(MathTool::GetRatio(SuccessAll, MessageCounted, 0,0),5) + "[" + String(SuccessAll)+ "/" + String(MessageCounted) + "]");

	for (size_t i = 0; i < 8; i++)
	{
		if (SuccessOn[i] != 0) {
			hSerial->println("Success on [" + String(i) + "]: " + String(MathTool::GetRatio(SuccessOn[i], MessageCounted, 0, 0), 5) + "[" + String(SuccessOn[i]) + "/" + String(MessageCounted) + "]");
		}
	}

//	hSerial->println("Success on 2nd: " + String(MathTool::GetRatio(SuccessOnSecond, MessageCounted, 0, 0), 5) + "[" + String(SuccessOnSecond) + "/" + String(MessageCounted) + "]");
	hSerial->println("Nothing received: " + String(NothingReceived) + " -- DataBuffer Clipping: " + String(DataBufferClipping) );

	hSerial->println("Avg. message period: " + String((LastCountTime - StartTime) / MessageCounted) + " ms");
}

LinkQualityMetrics::LinkQualityMetrics()
{
}


LinkQualityMetrics::~LinkQualityMetrics()
{
}
