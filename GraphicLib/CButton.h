#pragma once

#include "..\Classes\GraphicLib\GraphicLibIncludes.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class CButton : public Button, public ResolutionAdapter
{
public:
	static CButton* createButtonWithAbsolutePos(std::string fileName, int posX, int posY);
	static CButton* createButtonWithRelativePos(std::string fileName, float posX, float posY);

	bool initWithAbsolutePos(std::string filename, int posX, int posY);
	bool initWithRelativePos(std::string filename, float posX, float posY);

	virtual void onPressStateChangedToNormal();
	virtual void onPressStateChangedToPressed();

	void setButtonImage(std::string filename);

	//void setTitleFontSize(int FontSize);
	
};
