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
#define MAP_2_ID 2

struct Tile {
	int tileId;
	int x, y;
	int size = TILE_SIZE; 

	///* Ememies */
	//int SpawnObjectID;  // loai object xuat hien o tile
	//bool bCanSpawn = true;
};

struct TileObjectMap {
	ObjectType type;
	int x, y;
	int height, width;
	Collider *colider;
};

struct ObjectnEnemies {
	int x, y;
	int SpawnObjectID;
	bool bCanSpawn = true;
};

struct MapPack {
	int size;
	int height;
	Tile* tiles;

	vector <Sprite*> TilesSetSprite;

	Sprite* GetSpriteByID(int id)
	{
		if (id != -1)
			return TilesSetSprite.at(id);
		return nullptr;
	}

	Tile* GetTile(int x, int y)
	{
		return (tiles + x + y * size);
	}
};

class TileMap
{
private:

	static TileMap* _instance;

	vector <MapPack> mapList;

	vector <TileObjectMap> listTileObjectMap;

	vector <ObjectnEnemies> listEnemiesObjects;

	void LoadTilesData(LPCWSTR filePath, LPCWSTR tileSetLocation, int mapId);
	void LoadSpawnData(LPCWSTR filePath, int mapId);
	void LoadObjectMap(LPCWSTR filePath, int mapId);
	void LoadEnemies(LPCWSTR filePath, int mapId);

	const vector<int> _BrickStage_1{ 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274 };
	const vector<int> _RopeSwingStage_2{ 60, 61, 73 };

	const vector<int> _WallStage_2{ 32, 33, 44, 45, 65, 66, 67, 95, 96, 98, 99, 100, 101, 102, 103, 109, 112, 113, 114, 115, 116, 117, 133, 137, 172, 173, 215, 218, 222, 223, 224, 225, 226, 248, 249, 250, 261, 262, 263, 264, 265, 276 };

public:
	static TileMap* GetInstance();

	MapPack* currentMap;

	void AddTileObjectMap(TileObjectMap tiles);

	vector <TileObjectMap> GetListTileObj() { return listTileObjectMap; }

	void AddEnemiesAndObjects(ObjectnEnemies enemies);

	vector <ObjectnEnemies> GetEnemiesAndObjecs() { return listEnemiesObjects; }

	void SetCurrentMap(int mapID);

	//void Render(int x, int y);
	void Render(Tile* itile);

	void soundLock(bool lock);
};