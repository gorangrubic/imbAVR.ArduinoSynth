/*
  ==============================================================================

    matrixModel.h
    Created: 28 Oct 2019 5:37:37am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
#include "../Source/Data/Structures/imbDictionary.h"
#include "../Source/Data/Structures/imbValueSetFile.h"

class matrixModelEntryCollection {

public:
	SharedPointerVector<matrixModelEntryBase> items;

	matrixModelEntryCollection() {

	}
};

class matrixModelEntryBase :Rectangle<int> {

	static matrixModelEntryBase * Merge(matrixModelEntryBase a, matrixModelEntryBase b) {

	}
};

template<typename T, int D>
class matrixModelEntry:matrixModelEntryBase {

public:

	T dimensions[D];

	int state = 0;

	//Rectangle<int> dimensions = Rectangle<int>();
	matrixModelEntry() {

	}

};



class matrixProjectedSpace:Rectangle<int> {

public:

	struct projectionAxialZone:Rectangle<double> {

		float factor;
		bool isHorizontal;
		int index;

	};

	std::vector<projectionAxialZone> horizontalZones;
	std::vector<projectionAxialZone> verticalZones;

	Point<int> GetCellCoordinatesAt(double _x, double _y) {

	}

	void setProjection(std::vector<projectionAxialZone> &_borders, std::vector<float>&_pattern, int division, bool isHorizontal) {
		
		_borders.clear();

		double cellSize = getWidth() / division;

		int pi = 0;
		double c = 0;
		for (auto i = 0; i < division; i++)
		{
			if (pi >= _pattern.size()) {
				pi = 0;
			}
			pi++;


			projectionAxialZone zone;

			zone.index = i;

			if (isHorizontal) {
				zone.setTop(0);
				zone.setLeft(c);
				zone.setHeight(getHeight());
			}
			else {
				zone.setTop(c);
				zone.setLeft(0);
				zone.setWidth(getWidth());
			}

			c += cellSize * _pattern[i];

			if (isHorizontal) {
				zone.setRight(c);
			}
			else {
				zone.setHeight(c);
			}

			_borders.push_back(zone);

		}

	}

	void setProjection(Rectangle<int> division, matrixGridDistortionPattern distortion) {
		setProjection(horizontalZones, distortion.horizontal, division.getWidth(), true);
		setProjection(verticalZones, distortion.vertical, division.getHeight(), false);
	};

	matrixProjectedSpace(int _width, int _height) {
		setWidth(_width);
		setHeight(_height);
	}

	matrixProjectedSpace() {

	}
};

class matrixModelRules {

public:

	int maxEntryPerColumn = 1;
	int maxEntryPerRow = -1;

	bool autoMergeHorizontally = true;
	bool autoMergeVertically = false;

	bool allowMergeHorizontally = true;
	bool allowMergeVertically = false;

	matrixModelRules();
};

class matrixGridDistortionPattern {
public:
	std::vector<float> horizontal;
	std::vector<float> vertical;

	void Set(bool isHorizontal, float d1 = 1.0, float d2 = 1.0, float d3 = 1.0, float d4 = 1.0, float d5 = 0.0) {

		std::vector<float> target = vertical;
		if (isHorizontal) {
			target = vertical;
		}

		target.clear();
		if (d1 != 0.0) target.push_back(d1);
		if (d2 != 0.0) target.push_back(d2);
		if (d3 != 0.0) target.push_back(d3);
		if (d4 != 0.0) target.push_back(d4);
		if (d5 != 0.0) target.push_back(d5);
	}

	matrixGridDistortionPattern() {
		Set(true);
		Set(false);
	}
	
};

template<int W,int H, typename T>
class matrixModel {

public:

	matrixProjectedSpace space;

	matrixModelRules rules;

	matrixGridDistortionPattern distortion;

	matrixModelEntryCollection entries;

	Rectangle<int> dimensions = Rectangle<int>(0, 0, W, H);



	matrixModel() {

	}
		 
};