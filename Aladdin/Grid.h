#pragma once
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include "GameObject.h"
#include "SpawnProjectTile.h"
#include "Constants.h" 
#include "Aladdin.h"

#include "Guard1.h"
#include "Jafar.h"

#include "AppleItem.h"
#include "DiamondItem.h"
#include "GenieFaceItem.h"

#include "ThornObject.h"
#include "BallObject.h"
#include "BrickInObject.h"
#include "BrickOutObject.h"

#include "AppleEffect.h"
#include "EnemiesDeadEffect.h"
#include "ItemEffect.h"


using namespace std;

#define GRID_SIZE_BY_TILE (int)(GRID_SIZE / TILE_SIZE)

struct OnUpdateObject
{
	GameObject* object;
	ObjectnEnemies ene;
	bool isGenerated = false;
	bool isLife = true;
	float delaySpawn = 10000;
	float timeCount = 0001;
};

struct GridData
{
	vector<Tile*> tiles;
	int x;
	int y;

	vector<OnUpdateObject> listObject;

	void Render()
	{
		for (int y = 0; y < GRID_SIZE_BY_TILE; y++)
			for (int x = 0; x < GRID_SIZE_BY_TILE; x++)
			{
				TileMap::GetInstance()->Render(tiles.at(x + y * GRID_SIZE_BY_TILE));
			}
	}
};

struct GridCell
{
	vector<TileObjectMap> abc;
	vector<ObjectnEnemies> xyz;
};

class Grid
{
private:
	static Grid* _instance;

	int mapSize;

	Viewport* viewport;

	Aladdin* aladdin;
	
	vector <OnUpdateObject> listObject;

	void UpdateCurrentTiles();

	float timeCount;

public:
	static Grid* GetInstance();

	Grid();

	void InitializeMapGrid(TileMap *tileMap);

	void GetCameraPosOnGrid(int &l, int &r, int &t, int &b);

	vector<Tile*> currentTile;

	vector<Tile *> GetCurTiles() { return this->currentTile; }

	GridData* listCell;

	vector<TileObjectMap> tileObjectMap22;

	vector<TileObjectMap *> GetNearbyObjectTiles();

	vector<TileObjectMap *> GetNearbyObjectTilesThorn();

	vector<TileObjectMap *> GetNearbyObjectTilesForEnemies(int CellID);

	vector<ObjectnEnemies> enemiesnObjects;

	vector<GridCell> gridCell;

	GridData* GetCell(int x, int y)
	{
		return (listCell + x + y * mapSize);
	}

	set<int> listCellNow;

	void SpawnObject(ObjectnEnemies enemies);

	bool CheckObjectInsideCamera(GameObject* object);

	bool CheckObjectInsideCamera2(int x, int y);

	bool OnCell(int id);

	vector <OnUpdateObject> GetListUpdateObject() { return listObject; }

	void SetisLifeListObject(int pos, bool life) { this->listObject.at(pos).isLife = life; }

	void Update(DWORD dt);

	void Render();

	void DisableAllObject()
	{
		for (int i = 0; i < listObject.size(); i++)
		{
			listObject.at(i).isGenerated = true;
		}
	}
};