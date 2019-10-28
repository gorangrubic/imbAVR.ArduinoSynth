#pragma once


#include "../JuceLibraryCode/JuceHeader.h"
//#include "ParameterController.h"
//#include "../Source/Model/SynthDeviceModel.h"
#include "../Model/SynthDeviceModel.h"
#include "../Source/Application/Components/IOManager.h"

#include "../Source/Application/imbSynthStateData.h"





class imbSynthAudioProcessor 
		: public AudioProcessor, 
			public AudioProcessorListener,
				public Timer,
	private MidiKeyboardStateListener,
	private MidiInputCallback,
	private AsyncUpdater
{

public:

	/*
	static BusesProperties getBusesProperties()
	{
		return BusesProperties().withInput("Input", AudioChannelSet::stereo(), true)
			.withOutput("Output", AudioChannelSet::stereo(), true);
	}*/
	
	UndoManager undoManager;

	imbSynthStateData synthState;
	SynthDeviceModel * model;

	IOManager ioManager;


	juce::AudioProcessorValueTreeState parameters;

	void timerCallback() override;
	
	void DeployModel();

	/* Called when everything is ready for normal use*/
	void Start();
	bool IsStarted = false;

	void timerCallback() override
	{
		updateDeviceList(true);
		updateDeviceList(false);
	}

	//void handleNoteOn(MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
	//{
	//	MidiMessage m(MidiMessage::noteOn(midiChannel, midiNoteNumber, velocity));
	//	m.setTimeStamp(Time::getMillisecondCounterHiRes() * 0.001);
	//	sendToOutputs(m);
	//}

	//void handleNoteOff(MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
	//{
	//	MidiMessage m(MidiMessage::noteOff(midiChannel, midiNoteNumber, velocity));
	//	m.setTimeStamp(Time::getMillisecondCounterHiRes() * 0.001);
	//	sendToOutputs(m);
	//}

	//void handleIncomingMidiMessage(MidiInput* /*source*/, const MidiMessage& message) override
	//{
	//	// This is called on the MIDI thread
	//	const ScopedLock sl(midiMonitorLock);
	//	incomingMessages.add(message);
	//	triggerAsyncUpdate();
	//}

	//void handleAsyncUpdate() override
	//{
	//	// This is called on the message loop
	//	Array<MidiMessage> messages;

	//	{
	//		const ScopedLock sl(midiMonitorLock);
	//		messages.swapWith(incomingMessages);
	//	}

	//	String messageText;

	//	for (auto& m : messages)
	//		messageText << m.getDescription() << "\n";

	//	midiMonitor.insertTextAtCaret(messageText);
	//}

	//void sendToOutputs(const MidiMessage& msg)
	//{
	//	for (auto midiOutput : midiOutputs)
	//		if (midiOutput->outDevice.get() != nullptr)
	//			midiOutput->outDevice->sendMessageNow(msg);
	//}

	////==============================================================================
	//bool hasDeviceListChanged(const Array<MidiDeviceInfo>& availableDevices, bool isInputDevice)
	//{
	//	ReferenceCountedArray<MidiDeviceListEntry>& midiDevices = isInputDevice ? midiInputs
	//		: midiOutputs;

	//	if (availableDevices.size() != midiDevices.size())
	//		return true;

	//	for (auto i = 0; i < availableDevices.size(); ++i)
	//		if (availableDevices[i] != midiDevices[i]->deviceInfo)
	//			return true;

	//	return false;
	//}

	//ReferenceCountedObjectPtr<MidiDeviceListEntry> findDevice(MidiDeviceInfo device, bool isInputDevice) const
	//{
	//	const ReferenceCountedArray<MidiDeviceListEntry>& midiDevices = isInputDevice ? midiInputs
	//		: midiOutputs;

	//	for (auto& d : midiDevices)
	//		if (d->deviceInfo == device)
	//			return d;

	//	return nullptr;
	//}

	//void closeUnpluggedDevices(const Array<MidiDeviceInfo>& currentlyPluggedInDevices, bool isInputDevice)
	//{
	//	ReferenceCountedArray<MidiDeviceListEntry>& midiDevices = isInputDevice ? midiInputs
	//		: midiOutputs;

	//	for (auto i = midiDevices.size(); --i >= 0;)
	//	{
	//		auto& d = *midiDevices[i];

	//		if (!currentlyPluggedInDevices.contains(d.deviceInfo))
	//		{
	//			if (isInputDevice ? d.inDevice.get() != nullptr
	//				: d.outDevice.get() != nullptr)
	//				closeDevice(isInputDevice, i);

	//			midiDevices.remove(i);
	//		}
	//	}
	//}

	//void updateDeviceList(bool isInputDeviceList)
	//{
	//	auto availableDevices = isInputDeviceList ? MidiInput::getAvailableDevices()
	//		: MidiOutput::getAvailableDevices();

	//	if (hasDeviceListChanged(availableDevices, isInputDeviceList))
	//	{

	//		ReferenceCountedArray<MidiDeviceListEntry>& midiDevices
	//			= isInputDeviceList ? midiInputs : midiOutputs;

	//		closeUnpluggedDevices(availableDevices, isInputDeviceList);

	//		ReferenceCountedArray<MidiDeviceListEntry> newDeviceList;

	//		// add all currently plugged-in devices to the device list
	//		for (auto& newDevice : availableDevices)
	//		{
	//			MidiDeviceListEntry::Ptr entry = findDevice(newDevice, isInputDeviceList);

	//			if (entry == nullptr)
	//				entry = new MidiDeviceListEntry(newDevice);

	//			newDeviceList.add(entry);
	//		}

	//		// actually update the device list
	//		midiDevices = newDeviceList;

	//		// update the selection status of the combo-box
	//		if (auto* midiSelector = isInputDeviceList ? midiInputSelector.get() : midiOutputSelector.get())
	//			midiSelector->syncSelectedItemsWithDeviceList(midiDevices);
	//	}
	//}


	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioBuffer<float>&, MidiBuffer&) override;

	//==============================================================================
	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	
//	AudioProcessorValueTreeState::ParameterLayout CreateParameterLayout();

	void audioProcessorParameterChanged(AudioProcessor* processor,
		int parameterIndex,
		float newValue);

	void audioProcessorParameterChangeGestureEnd(AudioProcessor* processor,
		int parameterIndex);

	void audioProcessorChanged(AudioProcessor* processor);

	imbSynthAudioProcessor(SynthDeviceModel *_model) :
		AudioProcessor(BusesProperties()),
		model{ _model },
		undoManager(),
		//rootIdentifier(_model),
		parameters(*this, &this->undoManager),
		synthState(model, &parameters)
		//parameters(*this, &this->undoManager, name, CreateParameterLayout())
	{
		//DeployModel();

	
	};
	
	~imbSynthAudioProcessor();
};
