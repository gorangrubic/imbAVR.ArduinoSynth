/*
  ==============================================================================

    imbSynthLibraryContributor.h
    Created: 27 Oct 2019 4:06:58am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Application/GeneralDefinitions.h"

class imbSynthLibraryContributor :public imbValueSetFile
{
public:

	dataStringProperty ID = dataStringProperty("ID", "", "ID", "Unique contributor reference code");
	dataStringProperty FullName = dataStringProperty("FullName", "", "Full name", "First and last name");
	dataStringProperty Projects = dataStringProperty("Project","", "Project(s) or artist pseudonim");
	dataStringProperty Company = dataStringProperty("Company", "", "Company or label");
	dataStringProperty Web = dataStringProperty("Web", "", "Web", "Web page");
	dataStringProperty Note = dataStringProperty("Note", "");


	std::string GetAuthorDescription() {

		std::string output = "";

		output = imbGeneralTools::Append(output, Projects.Get(), "\n ");
		output = imbGeneralTools::Append(output, Company.Get(), "\n ");
		output = imbGeneralTools::Append(output, Web.Get(), "\n ");

		return output;
	}

	imbSynthLibraryContributor(std::string _name)
		: imbValueSetFile("contributor", _name, FILEEXTENSION_CONTRIBUTOR, "Author", "") { // dataObject(_name, _label, _description, _unit, _helpUrl) {
		elementClassRole = "imbSynthLibraryContributor";

		Add(&ID,true);
		Add(&FullName, true);
		Add(&Projects, true);
		Add(&Company, true);
		Add(&Web, true);
		Add(&Note, true);

	}
	~imbSynthLibraryContributor();

private:

};



imbSynthLibraryContributor::~imbSynthLibraryContributor()
{
}