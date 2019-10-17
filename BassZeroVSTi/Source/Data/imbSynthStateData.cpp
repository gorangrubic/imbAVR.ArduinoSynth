#include "imbSynthStateData.h"





ccTranslationMap * imbSynthStateData::GetCCMapByRole(ccTranslationMapRole mapRole)
{
	switch (mapRole) {
	case ccTranslationMapRole::input:
		return InputToHardwareMap.get();
		break;
	case ccTranslationMapRole::output:
		return HardwareToOutputMap.get();
		break;
	}
}

ccTranslationMapRole imbSynthStateData::CheckCCMapRole(ccTranslationMapRole mapRole, std::string msg_ins)
{
	if (mapRole == ccTranslationMapRole::unknown) {

		//std::string ins = "to load into.";

		AlertWindow w("CC Map",
			"Select CC Map " + msg_ins,
			AlertWindow::QuestionIcon);

		//w.addTextEditor("text", "enter some text here", "text field:");
		//w.addComboBox("option", { "option 1", "option 2", "option 3", "option 4" }, "some options");
		w.addButton("Both", 3);
		w.addButton("Input", 1);
		w.addButton("Output", 2);
		w.addButton("Cancel", 0, KeyPress(KeyPress::escapeKey, 0, 0));

		auto r = w.runModalLoop();

		mapRole = (ccTranslationMapRole)r;

	}

	return mapRole;
}

void imbSynthStateData::LoadCCMap(std::string filepath, ccTranslationMapRole mapRole)
{
	mapRole = CheckCCMapRole(mapRole, "to load into.");
	ccTranslationMap * cc_map = GetCCMapByRole(mapRole);

	fc.reset(new FileChooser("Choose BassZero CC Map file to load...", File::getCurrentWorkingDirectory(),
		FILEEXTENSION_CCMAP,true));

	fc->launchAsync(FileBrowserComponent::openMode
		| FileBrowserComponent::canSelectFiles,
		[&, this](const FileChooser& chooser)
	{
		String chosen;
		auto results = chooser.getURLResults();

		if (results.isEmpty()) return; 

		auto r = results.getFirst();

		if (r.isLocalFile()) {

			juce::File f = juce::File(r.getLocalFile().getFullPathName());
			if (f.exists()) return;

			imbValueSet valueSet;

			valueSet.FromString(f.loadFileAsString().toStdString());
			
			cc_map->FromPropertySet(valueSet);

			
		}
		else {

		}
	});

}

void imbSynthStateData::SaveCCMap(std::string filepath, ccTranslationMapRole mapRole)
{
	mapRole = CheckCCMapRole(mapRole, "to load into.");
	ccTranslationMap * ccMap = GetCCMapByRole(mapRole);

	fc.reset(new FileChooser("Choose BassZero CC Map file to load...", File::getCurrentWorkingDirectory(),
		FILEEXTENSION_CCMAP, true));

	fc->launchAsync(FileBrowserComponent::openMode
		| FileBrowserComponent::canSelectFiles,
		[&, this](const FileChooser& chooser)
	{
		String chosen;
		auto results = chooser.getURLResults();

		if (results.isEmpty()) return;

		auto r = results.getFirst();

		if (r.isLocalFile()) {

			imbValueSet valueSet = ccMap->ToPropertySet();
			juce::File f = juce::File(r.getLocalFile().getFullPathName());
			if (f.exists()) f.deleteFile();
			f.create();
			f.appendText(valueSet.ToString());
		}
		else {

		}
	});
}

void imbSynthStateData::Initiated()
{
	model->CollectAllParameters(Parameters);

	for each (auto var in Parameters)
	{
		if (var->typeMIDIMessage == imbControlParameterMessageType::ccMIDI) {
			InputToHardwareMap->SetDefault(var->ccID);
			HardwareToOutputMap->SetDefault(var->ccID);
		}

		var->onGUIFocus = [&, this](imbControlParameter * parameter) {
			SetParameterInFocus(parameter);

		};
	}
	
}

void imbSynthStateData::SetParameterInFocus(imbControlParameter * parameter)
{
	bool newInFocus = false;
	if (inFocusParameterID != parameter->parameterIDPath) {
		newInFocus = true;
	}

	inFocusParameterID == parameter->parameterIDPath;

	controlDisplayModel->SetParameter(parameter);
}

imbSynthStateData::~imbSynthStateData()
{
}
