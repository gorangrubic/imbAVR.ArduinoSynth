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

ParameterMap * imbSynthStateData::GetParameterMap(dataObjectPropertyBase * property)
{

	switch (property->parClass) {
	case parameterClass::ccSustained:
	case parameterClass::ccLive:
		return &parameterMapCC;

		break;
	case parameterClass::opm:
		return &parameterMapSysEx;
		break;
	case parameterClass::configuration:
		break;
	case parameterClass::unspecified:
		break;
	}
	return nullptr;
}

ParameterMapEntry * imbSynthStateData::GetParameterMapEntry(dataObjectPropertyBase * property)
{

	ParameterMap * m = GetParameterMap(property);
	return m->getEntryByPathID(property->parameterIDPath);
}



std::vector<ParametarValueMessage> imbSynthStateData::prepareMessages(parameterClass parClass, bool forceAll)
{
	std::vector<ParametarValueMessage> output = std::vector<ParametarValueMessage>();

	std::vector<dataObjectPropertyBase*> allProperties;

	model->GetAllProperties(allProperties, parClass);

	for each (auto var in allProperties)
	{
		if (forceAll) {
			parameterLastValuesSent.Remove(var->parameterIDPath);
		}

		auto s = var->GetStringValue().toStdString();

		if (!parameterLastValuesSent.hasSameValue(var->parameterIDPath, s)) {

			ParameterMap * m = GetParameterMap(var);

			auto v = var->GetCCByteValue();
			auto me = m->getEntryByPathID(var->parameterIDPath);
			auto i = me->id;
			ParametarValueMessage pvm = ParametarValueMessage(i, v, var->parClass);
			output.push_back(pvm);

			parameterLastValuesSent.Set(var->parameterIDPath, s);
		}
	}

	return output;
}

MidiMessage imbSynthStateData::ConvertToMidi(ParametarValueMessage pvm)
{
	return MidiMessage();
}

std::vector<MidiMessage> imbSynthStateData::ConvertToMidi(std::vector<ParametarValueMessage>& pvm)
{
	return std::vector<MidiMessage>();
}

ParametarValueMessage imbSynthStateData::ConvertFromMidi(MidiMessage m)
{
	return ParametarValueMessage();
}

std::vector<ParametarValueMessage> imbSynthStateData::ConvertFromMidi(std::vector<MidiMessage> m)
{
	return std::vector<ParametarValueMessage>();
}

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
	
	configuration.LoadFile(environment->folders.FolderSettings.GetFilepath(configuration), true);

	
	std::vector<dataObjectPropertyBase*> allProperties;

	model->GetAllProperties(allProperties);

	for each (dataObjectPropertyBase * var in allProperties)
	{
		switch (var->parClass) {
		case parameterClass::ccLive:
			parameterMapCC.Add(var);
			break;
		case parameterClass::ccSustained:
			parameterMapCC.Add(var);
			break;
		case parameterClass::opm:
			parameterMapSysEx.Add(var);
			break;
		case parameterClass::configuration:
			break;
		case parameterClass::unspecified:
			break;
		}
	}

	// --- load library

	// --- load last 

}

//void imbSynthStateData::SetParameterInFocus(std::string parameterIDPath)
//{
//
//	bool newInFocus = false;
//	if (inFocusParameterID != parameterIDPath) {
//		newInFocus = true;
//	}
//
//	inFocusParameterID == parameterIDPath;
//
//	if (ParametersByIDPath.Contains(parameterIDPath)) {
//		auto parameter = ParametersByIDPath.GetPointer(parameterIDPath);
//		controlDisplayModel->SetParameter(parameter);
//
//	}
//	else {
//		
//	}
//	
//
//	
//}

imbSynthStateData::~imbSynthStateData()
{
}
