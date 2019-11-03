#pragma once
#include "GameObject.h"

class SpawnProjectTile
{
private:
	static SpawnProjectTile* _instance;
public:
	static SpawnProjectTile* GetInstance();
};