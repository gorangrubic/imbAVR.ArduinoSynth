/*
  ==============================================================================

    SynthApplicationTask.h
    Created: 26 Oct 2019 6:04:32am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../Source/Utility/SafeEnum.h"

namespace SynthApplicationTask {
	enum _task :int {
		nothingToDo = 1 << 0,
		executeNote = 1 << 1,
		executeCCLive = 1 << 2,
		executeCCSustained = 1 << 3,
		executeOPM = 1 << 4,
		deviceConnect = 1 << 5,
		playbackFinished = 1 << 6,
		playbackStarted = 1 << 7,
		IOUpdate = 1 << 8,
		UIRefreshRate = 1 << 9,

		//none = 0,
		//isElementContainer = 1 << 0, // binary 0001
		//isValueRanged = 1 << 1, // binary 0010
		//isAutomatizable = 1 << 2, // binary 0100
		//isEditableFromGUI = 1 << 3, // binary 1000
		//doReconfigureEditor = 1 << 4,
		//doUseAssignedColor = 1 << 5,
		//doSetValueByContextMenu = 1 << 6,
		//doAllowCopyPaste = 1 << 7,
		//hideGUIEditor = 1 << 8,
		///* Element is  */
		//isDisabled = 1 << 9,
		///* when true, the parameter will be declared in DAW even if isAutomatizable is flase  */
		//doDeclareInValueTree = 1 << 10,
		///// <summary>
		///// minValue is less than zero, maxValue is above zero
		///// </summary>
		//isSignedRange = 1 << 11,
	};

	typedef SafeEnum<enum _task> task;
}
