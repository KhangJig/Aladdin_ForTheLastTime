#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Sprite.h"
#include "Debug.h"
#include "Constants.h"
#include "GameObject.h"
#include "Sound.h"

using namespace std;

#define MAP_1_ID 0
#define MAP_2_ID 1

struct Tile {
	int tileId;
	int x, y;
	int size = TILE_SIZE;
};

struct TileObjectMap {
	ObjectType type;
	int x, y;
	int GridCellID;
	int height, width;
};

struct ObjectnEnemies {
	int x, y;
	int CellID;
	int SpawnObjectID;
	bool bCanSpawn = true;
};

struct MapPack {
	int size;
	int height;
	Tile* tiles;

	vector <Sprite*> TilesSetSprite;

	vector <TileObjectMap> listTileObjectMap;

	vector <ObjectnEnemies> listEnemiesObjects;

	Sprite* GetSpriteByID(int id)
	{
		if (id != -1)
			return TilesSetSprite.at(id);
		return nullptr;
	}

	Tile* GetTile(int x, int y)
	{
		/*return (tiles + x + y * size);*/
		return &tiles[x + y * size];
	}

	void AddTileObjectMap(TileObjectMap tiles)
	{
		this->listTileObjectMap.push_back(tiles);
	}

	void AddEnemiesAndObjects(ObjectnEnemies enemies)
	{
		this->listEnemiesObjects.push_back(enemies);
	}
};

class TileMap
{
private:

	static TileMap* _instance;

	vector <MapPack> mapList;

	void LoadTilesData(LPCWSTR filePath, LPCWSTR tileSetLocation, int mapId);
	void LoadSpawnData(LPCWSTR filePath, int mapId);
	void LoadObjectMap(LPCWSTR filePath, int mapId);
	void LoadEnemies(LPCWSTR filePath, int mapId);

public:
	static TileMap* GetInstance();

	MapPack* currentMap;

	void SetCurrentMap(int mapID);

	void Render(Tile* itile);

	void soundLock(bool lock);
};