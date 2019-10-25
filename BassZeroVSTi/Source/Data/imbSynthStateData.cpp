#include "imbSynthStateData.h"




//
//void imbSynthStateData::SaveSettings(bool saveAs)
//{
//
//	auto t = folders->FolderSettings.GetFilepath(configuration);
//
//	
//	fc.reset(new FileChooser("Choose a file to save...",
//		juce::String(t),
//		configuration.filenameExtension, false));
//
//	fc->launchAsync(FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles,
//		[&,this](const FileChooser& chooser)
//	{
//		auto result = chooser.getURLResult();
//		auto name = result.isEmpty() ? String()
//			: (result.isLocalFile() ? result.getLocalFile().getFullPathName()
//				: result.toString(true));
//
//		
//
//		AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon,
//			"File Chooser...",
//			"You picked: " + name);
//	});
//
//	//auto result = fc->showDialog(FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles, );
//	//synthState->configuration.SaveFile();
//
//}

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
		//w.addButton("Both", 3);
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
	if (mapRole == ccTranslationMapRole::unknown) return;

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
	if (mapRole == ccTranslationMapRole::unknown) return;

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
	//folders = std::shared_ptr<SynthApplicationFolderCollection>(_folders);

	//ioPorts.deploy();
	//configuration.ioSettings.Deploy(ioPorts);

	configuration.LoadFile(environment->folders.FolderSettings.GetFilepath(configuration), true);


	model->CollectAllParameters(Parameters);

	for each (auto var in Parameters)
	{
		if (var->typeMIDIMessage == imbControlParameterMessageType::ccMIDI) {
			InputToHardwareMap->SetDefault(var->ccID);
			HardwareToOutputMap->SetDefault(var->ccID);
		}
		
		ParametersByIDPath.Add(var->parameterIDPath, var.get());

	}
	
	//controlDisplayModel.reset(new ControlStateDisplayModel(InputToHardwareMap, HardwareToOutputMap, environment.get()));

	for each (auto var in Parameters)
	{
		var->onGUIFocus = [&, this](std::string idPath) {

			SetParameterInFocus(idPath);
		};

	}
	
}

void imbSynthStateData::SetParameterInFocus(std::string parameterIDPath)
{

	bool newInFocus = false;
	if (inFocusParameterID != parameterIDPath) {
		newInFocus = true;
	}

	inFocusParameterID == parameterIDPath;

	if (ParametersByIDPath.Contains(parameterIDPath)) {
		auto parameter = ParametersByIDPath.GetPointer(parameterIDPath);
		controlDisplayModel->SetParameter(parameter);

	}
	else {
		
	}
	

	
}

imbSynthStateData::~imbSynthStateData()
{
}
