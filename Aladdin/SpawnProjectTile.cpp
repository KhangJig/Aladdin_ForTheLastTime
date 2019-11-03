#include "SpawnProjectTile.h"

SpawnProjectTile* SpawnProjectTile::_instance;


SpawnProjectTile* SpawnProjectTile::GetInstance()
{
	if (_instance == nullptr)
		_instance = new SpawnProjectTile();
	return _instance;
}

