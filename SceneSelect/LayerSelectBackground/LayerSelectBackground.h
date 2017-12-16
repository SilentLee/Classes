#pragma once
#pragma once
#include "LayerEx.h"

class LayerSelectBackground : public LayerEx
{
public:
	static LayerSelectBackground* create();
	bool init();
};