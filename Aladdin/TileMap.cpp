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

			//switch (mapId)
			//{
			//case MAP_1_ID:
			//{
			//	if (find(_BrickStage_1.begin(), _BrickStage_1.end(), (map.tiles + x + y * size)->tileId) != _BrickStage_1.end())
			//	{
			//		(map.tiles + x + y * size)->type = ObjectType::BRICK;
			//	}
			//}
			//break;
			//}

			(map.tiles + x + y * size)->x = x;
			(map.tiles + x + y * size)->y = y;
		}

	//for (int y = map.size - 1; y > map.height - 1; y--)
	//	for (int x = 0; x < map.size; x++)
	//	{
	//		(map.tiles + x + y * size)->tileId = -1;
	//		(map.tiles + x + y * size)->x = x;
	//		(map.tiles + x + y * size)->y = y;
	//	}

	tilesData.close();

	D3DXIMAGE_INFO info;

	D3DXGetImageInfoFromFile(tileSetLocation, &info);

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

			DebugOut(L"[INFO] i -j  %d - %d\n", i, j);

			Sprite *tempTile = new Sprite(tileSetLocation, rect, TILES_TRANSCOLOR);
			map.TilesSetSprite.push_back(tempTile);
			if (map.TilesSetSprite.size() == map.height*size) break;
		}
	}
	mapList.push_back(map);

}

void TileMap::LoadSpawnData(LPCWSTR filePath, int mapId)
{
	ifstream tilesData;
	tilesData.open(filePath);

	string data;

	tilesData >> data;

	for (int y = mapList[mapId].height - 1; y >= 0; y--)
		for (int x = 0; x < mapList[mapId].size; x++)
		{
			tilesData >> data;
			(mapList[mapId].tiles + x + y * mapList[mapId].size)->SpawnObjectID = stoi(data);
		}

	tilesData.close();
}

void TileMap::AddTileObjectMap(TileObjectMap tiles) 
{
	this->listTileObjectMap.push_back(tiles);
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
		switch (mapId)
		{
		case MAP_1_ID:
		{
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
				tilesObj.type = ObjectType::THORN;
			}
		}
		break;

		default:
			break;
		}

		tilesData >> data;
		tilesObj.x = stoi(data);

		tilesData >> data;
		tilesObj.y = stoi(data);

		tilesData >> data;
		tilesObj.width = stoi(data);

		tilesData >> data;
		tilesObj.height = stoi(data);

		this->AddTileObjectMap(tilesObj);
	}

	tilesData.close();
}

void TileMap::AddEnemiesAndObjects(ObjectnEnemies enemies)
{
	this->listEnemiesObjects.push_back(enemies);
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

		switch (mapId)
		{
		case MAP_1_ID:
		{
			if (stoi(data) == 1)
			{
				enemies.SpawnObjectID = ObjectAndEnemies::GUARD1;
			}
		}
		break;

		default:
			break;
		}

		tilesData >> data;
		enemies.x = stoi(data);

		tilesData >> data;
		enemies.y = stoi(data);

		this->AddEnemiesAndObjects(enemies);
	}

	tilesData.close();
}

void TileMap::SetCurrentMap(int mapID)
{
	currentMap = &mapList[mapID];

}

void TileMap::soundLock(bool lock)
{

}

//void TileMap::Render(int x, int y)
//{
//	if (currentMap->GetTile(x, y)->tileId == -1)
//		return;
//
//	SpriteData spriteData;
//	spriteData.width = TILE_SIZE;
//	spriteData.height = TILE_SIZE;
//	spriteData.x = x * TILE_SIZE;
//	spriteData.y = y * TILE_SIZE;
//	spriteData.isLeft = true;
//
//	currentMap->GetSpriteByID(currentMap->GetTile(x, y)->tileId)->SetData(spriteData);
//
//	Graphics::GetInstance()->Draw(currentMap->GetSpriteByID(currentMap->GetTile(x, y)->tileId));
//}

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


