// 
// 
// 

#include "DiagnosticData.h"

void DiagnosticData::AddLog(String logMessage)
{

	if (LogIndex >= LOG_SIZE) {
		LogIndex = 0;
	}

	LogMessages[LogIndex] = logMessage;

	LogIndex++;
	LogCount++;
}
