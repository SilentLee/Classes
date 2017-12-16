#pragma once
#include "LayerEx.h"

class LayerBattleBackground : public LayerEx
{
public:
	static LayerBattleBackground* create();
	bool init();
};