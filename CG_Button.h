#pragma once

#include "LibCommonGraphIncludes.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class CG_Button : public Button, public CG_ResolutionAdapter
{
public:
	static CG_Button* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static CG_Button* createWithRelativePos(std::string fileName, float posX, float posY);

	bool initWithAbsolutePos(std::string filename, int posX, int posY);
	bool initWithRelativePos(std::string filename, float posX, float posY);

	virtual void onPressStateChangedToNormal();
	virtual void onPressStateChangedToPressed();

	void setButtonImage(std::string filename);

	//void setTitleFontSize(int FontSize);
	
};
