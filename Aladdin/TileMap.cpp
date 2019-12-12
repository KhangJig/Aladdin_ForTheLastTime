#include "TileMap.h"

TileMap* TileMap::_instance = nullptr;

TileMap * TileMap::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new TileMap();

		_instance->LoadTilesData(TILES_MATRIX_STAGE_1, TILES_SET_MATRIX_STAGE_1, MAP_1_ID);
		_instance->LoadObjectMap(POSSISION_MAPOBJECT_1, MAP_1_ID);
		_instance->LoadEnemies(POSSISION_ENEMIES_1, MAP_1_ID);

		_instance->LoadTilesData(TILES_MATRIX_STAGE_2, TILES_SET_MATRIX_STAGE_2, MAP_2_ID);
		_instance->LoadObjectMap(POSSISION_MAPOBJECT_2, MAP_2_ID);
	}
	return _instance;
}

void TileMap::LoadTilesData(LPCWSTR filePath, LPCWSTR tileSetLocation, int mapId)
{
	MapPack map;

	ifstream tilesData;
	tilesData.open(filePath);

	string data;

	tilesData >> data;
	int size = stoi(data);

	map.size = size;

	tilesData >> data;
	map.height = stoi(data);

	map.tiles = new Tile[size*size];

	for (int y = map.height - 1; y >= 0; y--)
		for (int x = 0; x < map.size; x++)
		{
			tilesData >> data;
			(map.tiles + x + y * size)->tileId = stoi(data);

			(map.tiles + x + y * size)->x = x;
			(map.tiles + x + y * size)->y = y;
		}

	tilesData.close();

	D3DXIMAGE_INFO info;

	D3DXGetImageInfoFromFile(tileSetLocation, &info);
	Sprite *tempTile = new Sprite(tileSetLocation, TILES_TRANSCOLOR);

	// add tile (include tileset image) -> maplist
	for (int i = 0; i < info.Height  / TILE_SIZE; i++)
	{
		for (int j = 0; j < info.Width / TILE_SIZE; j++)
		{
			RECT rect;
			rect.left = j * TILE_SIZE;
			rect.right = rect.left + TILE_SIZE;
			rect.top = i * TILE_SIZE;
			rect.bottom = rect.top + TILE_SIZE;

			Sprite *tile = new Sprite(tempTile->GetTexture(), rect, TILES_TRANSCOLOR);
			map.TilesSetSprite.push_back(tile);

			if (map.TilesSetSprite.size() == map.height*size) break;
		}
	}

	mapList.push_back(map);

}

void TileMap::LoadObjectMap(LPCWSTR filePath, int mapId)
{
	ifstream tilesData;
	TileObjectMap tilesObj;
	tilesData.open(filePath);
	string data;

	tilesData >> data;
	int lenght = stoi(data);


	for (int i = 0; i < lenght ; i++)
	{
		tilesData >> data;

		if (stoi(data) == 1)
		{
			tilesObj.type = ObjectType::BRICK;
		}
		if (stoi(data) == 2)
		{
			tilesObj.type = ObjectType::WALL;
		}
		if (stoi(data) == 3)
		{
			tilesObj.type = ObjectType::ROPE;
		}

		tilesData >> data;
		tilesObj.GridCellID = stoi(data);

		tilesData >> data;
		tilesObj.x = stoi(data);

		tilesData >> data;
		tilesObj.y = stoi(data);

		tilesData >> data;
		tilesObj.width = stoi(data);

		tilesData >> data;
		tilesObj.height = stoi(data);

		mapList[mapId].AddTileObjectMap(tilesObj);
	}

	tilesData.close();
}

void TileMap::LoadEnemies(LPCWSTR filePath, int mapId)
{
	ifstream tilesData;
	ObjectnEnemies enemies;
	tilesData.open(filePath);
	string data;

	tilesData >> data;
	int lenght = stoi(data);

	for (int i = 0; i < lenght; i++)
	{
		tilesData >> data;

		switch (stoi(data))
		{
		case 1:
			enemies.SpawnObjectID = ObjectAndEnemies::GUARD1; break;
		case 2:
			enemies.SpawnObjectID = ObjectAndEnemies::GUARD2; break;
		case 3:
			enemies.SpawnObjectID = ObjectAndEnemies::BOMBBER; break;
		case 4:
			enemies.SpawnObjectID = ObjectAndEnemies::BAT; break;
		case 5:
			enemies.SpawnObjectID = ObjectAndEnemies::THORN; break;
		case 6:
			enemies.SpawnObjectID = ObjectAndEnemies::BALL; break;
		case 7:
			enemies.SpawnObjectID = ObjectAndEnemies::WALL_BRICK; break;
		case 8:
			enemies.SpawnObjectID = ObjectAndEnemies::APPLE; break;
		case 9:
			enemies.SpawnObjectID = ObjectAndEnemies::DIAMOND; break;
		case 10:
			enemies.SpawnObjectID = ObjectAndEnemies::BOTTLE; break;
		case 11:
			enemies.SpawnObjectID = ObjectAndEnemies::GENIE_FACE; break;
		case 12:
			enemies.SpawnObjectID = ObjectAndEnemies::SHOP; break;
		}

		tilesData >> data;
		enemies.CellID = stoi(data);

		tilesData >> data;
		enemies.x = stoi(data);

		tilesData >> data;
		enemies.y = stoi(data);

		mapList[mapId].AddEnemiesAndObjects(enemies);
	}

	tilesData.close();
}

void TileMap::SetCurrentMap(int mapID)
{
	currentMap = &mapList[mapID];

}

MapPack TileMap::GetMap()
{
	return *currentMap;

}

void TileMap::soundLock(bool lock)
{

}

void TileMap::Render(Tile* itile)
{
	if (itile->tileId == -1) {
		return;
	}

	SpriteData spriteData;
	spriteData.width = TILE_SIZE;
	spriteData.height = TILE_SIZE;
	spriteData.x = itile->x * TILE_SIZE;
	spriteData.y = itile->y * TILE_SIZE;

	spriteData.isLeft = true;

	Sprite* temp = currentMap->GetSpriteByID(itile->tileId);
	temp->SetData(spriteData);

	Graphics::GetInstance()->Draw(temp);
}


