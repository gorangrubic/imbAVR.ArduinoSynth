/*
  ==============================================================================

    imbTimeScheduler.h
    Created: 26 Oct 2019 5:56:41am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbValueSetFile.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"
#include "../Source/Utility/imbTimeWatch.h"
#include "../Source/Application/Components/SynthApplicationTask.h"

class imbTimeScheduler {


public:

	void Reset();

	imbTimeWatch IOUpdateCycle = imbTimeWatch(50);
	imbTimeWatch CCMessagesCycle = imbTimeWatch(10);

	imbTimeWatch FullSyncPlayTimeout = imbTimeWatch(1000);
	imbTimeWatch DeviceConnectRetry = imbTimeWatch(5000);
	imbTimeWatch UIRefreshRate = imbTimeWatch(250);
	imbTimeWatch ConfirmationTimeout = imbTimeWatch(10);


	imbTimeWatch NotPlayingTimeout = imbTimeWatch(500);


	SynthApplicationTask::task Cycle();

	imbTimeScheduler();
};

void imbTimeScheduler::Reset()
{
}

SynthApplicationTask::task imbTimeScheduler::Cycle()
{
	SynthApplicationTask::task output = SynthApplicationTask::_task::nothingToDo;

	if (this->CCMessagesCycle.Check()) output |= SynthApplicationTask::_task::executeCCLive;
	if (this->UIUpdateCycle.Check()) output |= SynthApplicationTask::_task::UIUpdate;

	return output;
}

imbTimeScheduler::imbTimeScheduler()
{
	Reset();
}
