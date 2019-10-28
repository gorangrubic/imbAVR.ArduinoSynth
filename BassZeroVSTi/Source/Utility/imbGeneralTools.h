/*
  ==============================================================================

    imbGeneralTools.h
    Created: 22 Oct 2019 6:28:28pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <random>
#include <string>

class imbGeneralTools {


	public:

		/* returns random string*/
		static std::string GetRandomString(int numberOfChars);

		/* makes color from Boris >:) */
		static Colour ColorFromHex(String hexCode);


		/* makes color from Boris >:) */
		static Colour ColorFromHex(std::string hexCode);

		
		static std::string GetParentPath(std::string path, int steps = 1, bool emptyOnRoot=true);		

		/// <summary>
		/// Gets the path version: when [steps] > 0, returns first [steps] nodes of path. if [steps] < 0, returns last [steps] nodes of path
		/// </summary>
		/// <param name="path">The path.</param>
		/// <param name="steps">The steps.</param>
		/// <param name="emptyOnRoot">if set to <c>true</c> [empty on root].</param>
		/// <returns></returns>
		static std::string GetPathVersion(std::string path, int steps = 1, bool emptyOnRoot = true);

		static std::string namePartSeparator() { return "_"; };
		static std::string extensionSeparator() { return "."; };
		static std::string dataSeparator() { return "."; };
		static std::string filepathSeparator() { return "/"; };

		static std::string Append(std::string left, std::string right, std::string separator=".");

		static int Count(std::string input, std::string needle = ".");

};