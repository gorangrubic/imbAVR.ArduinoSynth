/*
  ==============================================================================

    imbGeneralTools.cpp
    Created: 22 Oct 2019 6:28:28pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "imbGeneralTools.h"
/* Adaptation of Stackoverflow answer: https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c */
std::string imbGeneralTools::GetRandomString(int numberOfChars)
{

		static auto& chrs = "0123456789"
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		thread_local static std::mt19937 rg{ std::random_device{}() };
		thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

		std::string s;

		s.reserve(numberOfChars);

		while (numberOfChars--)
			s += chrs[pick(rg)];

		return s;

}

  Colour imbGeneralTools::ColorFromHex(String color_hex)
  {
	  
	  if (color_hex.startsWith("#")) color_hex = color_hex.substring(1);


	  if (color_hex.length() == 6) {
		  unsigned int r, g, b;
		  sscanf(color_hex.getCharPointer(), "%02x%02x%02x", &r, &g, &b);

		  return Colour(r, g, b);
	  }
	  else if (color_hex.length() == 8) {

		  unsigned int a, r, g, b;
		  sscanf(color_hex.getCharPointer(), "%02%02x%02x%02x", &a, &r, &g, &b);

		  return Colour(juce::uint8(r), juce::uint8(g), juce::uint8(b), juce::uint8(a));
		
	  }
	  return Colour();
  }

  Colour imbGeneralTools::ColorFromHex(std::string hexCode)
  {
	  return ColorFromHex(juce::String(hexCode));
  }

  std::string imbGeneralTools::GetParentPath(std::string path, int steps, bool emptyOnRoot)
  {
	  String output = "";
	  steps = std::abs(steps);

	  int pathNodeCount = imbGeneralTools::Count(path);

	  return GetPathVersion(path, pathNodeCount - steps, false);
  }

  std::string imbGeneralTools::GetPathVersion(std::string path, int steps, bool emptyOnRoot)
  {
	  String output = "";

	  String input = path;

	  if (steps == 0) return path;
	  if (path.empty()) return path;

	  bool doInverse = (steps < 0);

	  for (size_t i = 0; i < std::abs(steps); i++)
	  {
		  String trimmed;
		  String rest;

		  int dotPos = -1;
		  if (doInverse) {
			  dotPos = input.lastIndexOf(".");
		  }
		  else {
			  dotPos = input.indexOf(".");
		  }

		  if (dotPos == -1) {
			  if (emptyOnRoot) return "";
		  }
		  else {
			  if (output.isEmpty()) {
				  return input.toStdString();
			  }
			  else {
				  return output.toStdString();
			  }
		  }

		  if (doInverse) {
			  trimmed = input.substring(dotPos);
			  rest = input.substring(0, dotPos);
			  output = imbGeneralTools::Append(trimmed.toStdString(), output.toStdString());
		  }
		  else {
			  trimmed = input.substring(0, dotPos); 
			  rest = input.substring(dotPos);
			  output = imbGeneralTools::Append(output.toStdString(), trimmed.toStdString());
		  }

		  input = rest;
		 
	  }
  }

  /// <summary>
  /// Joins [left] and [right] string, ensuring that exactly one [separator] is between them in the result.
  /// </summary>
  /// <param name="left">The left.</param>
  /// <param name="right">The right.</param>
  /// <param name="separator">The separator.</param>
  /// <returns></returns>
  std::string imbGeneralTools::Append(std::string left, std::string right, std::string separator)
  {
	  String _l = left;
	  String _r = right;

	  if (_l.endsWith(separator)) {
		  _l = _l.substring(0, _l.length() - separator.length());
	  }

	  if (_r.startsWith(separator)) {
		  _r = _r.substring(separator.length());
	  }


	  if (_r.isEmpty()) {
		  return _l.toStdString();
	  }

	  if (_l.isEmpty()) {
		  return _r.toStdString();
	  }

	  return _l.toStdString() + separator + _r.toStdString();
  }

  int imbGeneralTools::Count(std::string input, std::string needle)
  {
	  int output = 0;
	  String _i = input;
	  int dotPos = -1;

	  dotPos = _i.indexOf(0, needle);

	  while (dotPos != -1) {
		  output++;
		  dotPos = _i.indexOf(dotPos+1, needle);
		  
	  }

	  return 0;
  }
