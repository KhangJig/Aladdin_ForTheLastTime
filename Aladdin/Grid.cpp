#include "Grid.h"

Grid* Grid::_instance;

Grid* Grid::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Grid();
	}
	return _instance;
}

Grid::Grid()
{
	aladdin = Aladdin::GetInstance();
	viewport = Viewport::GetInstance();
}

void Grid::InitializeMapGrid(TileMap *tileMap)
{
	/*NOTES*/
	mapSize = tileMap->currentMap->size/3;

	listCell = new GridData[mapSize*mapSize];

	for (int y = 0; y < mapSize; y++)
		for (int x = 0; x < mapSize; x++)
			for (int yy = 0; yy < GRID_SIZE_BY_TILE; yy++)
				for (int xx = 0; xx < GRID_SIZE_BY_TILE; xx++)
				{
					Tile* tempTile = tileMap->currentMap->GetTile(xx + x * GRID_SIZE_BY_TILE, yy + y * GRID_SIZE_BY_TILE);
					(listCell + x + y * mapSize)->tiles.push_back(tempTile);
					if (tempTile->SpawnObjectID != 0)
						(listCell + x + y * mapSize)->hasSpawnTiles.push_back(tempTile);
				}
}

void Grid::GetCameraPosOnGrid(int &l, int &r, int &t, int &b) {
	RECT rect = viewport->GetRect();

	l = (int)(rect.left / GRID_SIZE);
	t = (int)(rect.top % GRID_SIZE == 0 ? rect.top / GRID_SIZE - 1 : rect.top / GRID_SIZE);
	//t = (int)(rect.top / GRID_SIZE);
	r = (int)(rect.right / GRID_SIZE);
	b = (int)(rect.bottom / GRID_SIZE);
	if (r >= mapSize)
		r = mapSize - 1;
	if (t >= mapSize)
		t = mapSize - 1;
}

void Grid::UpdateCurrentTiles()
{
	currentTile.clear();
	RECT rect = aladdin->GetRect();
	int left = (int)(rect.left / GRID_SIZE);
	int right = (int)(rect.right / GRID_SIZE);
	int top = (int)(rect.top % GRID_SIZE == 0 ? rect.top / GRID_SIZE - 1 : rect.top / GRID_SIZE);
	//int top = (int)(rect.top / GRID_SIZE);
	int bottom = (int)(rect.bottom / GRID_SIZE);

	for (int x = left; x <= right; x++)
	{
		for (int y = bottom; y <= top; y++)
		{
			currentTile.insert(currentTile.end(), GetCell(x, y)->tiles.begin(), GetCell(x, y)->tiles.end());
		}
	}
}

vector<Tile *> Grid::GetNearbyTiles(int l, int r, int t, int b)
{
	vector<Tile*> nearbyTiles;
	int left = (int)(l / GRID_SIZE);
	int right = (int)(r / GRID_SIZE);
	int top = (int)(t % GRID_SIZE == 0 ? t / GRID_SIZE - 1 : t / GRID_SIZE);
	int bottom = (int)(b / GRID_SIZE);

	for (int x = left; x <= right; x++)
	{
		for (int y = bottom; y <= top; y++)
		{
			nearbyTiles.insert(nearbyTiles.end(), GetCell(x, y)->tiles.begin(), GetCell(x, y)->tiles.end());
		}
	}

	return nearbyTiles;
}

vector<Tile *> Grid::GetNearbyTiles(RECT rect)
{
	vector<Tile*> nearbyTiles;
	int left = (int)(rect.left / GRID_SIZE);
	int right = (int)(rect.right / GRID_SIZE);
	int top = (int)(rect.top % GRID_SIZE == 0 ? rect.top / GRID_SIZE - 1 : rect.top / GRID_SIZE);
	int bottom = (int)(rect.bottom / GRID_SIZE);

	if (bottom < 0)
		bottom = 0;
	if (left < 0)
		left = 0;

	for (int x = left; x <= right; x++)
	{
		for (int y = bottom; y <= top; y++)
		{
			nearbyTiles.insert(nearbyTiles.end(), GetCell(x, y)->tiles.begin(), GetCell(x, y)->tiles.end());
		}
	}

	return nearbyTiles;
}

void Grid::SpawnObject(int ObjectID, Tile* tile)
{

	switch (ObjectID)
	{
	case 1:
	{

	}
	break;
	}
}

bool Grid::CheckObjectInsideCamera(GameObject* object)
{
	if (timeCount < 2000)
		return true;

	int test = 1;

	RECT rect = viewport->GetRect();
	if (object->GetPositionX() < rect.left - 64 * test || object->GetPositionX() > rect.right + 64 * test ||
		object->GetPositionY() < rect.bottom - 64 * test || object->GetPositionY() > rect.top + 64 * test)
		return false;
	return true;
}

void Grid::Update(DWORD dt)
{
	timeCount += dt;
	aladdin->Update(dt);
	aladdin->UpdateCollision(dt);

	for (int i = 0; i < listObject.size(); i++)
	{
		if (listObject.at(i).disable)
			continue;

		listObject.at(i).object->Update(dt);

		if (!CheckObjectInsideCamera(listObject.at(i).object))
		{
			listObject.at(i).disable = true;
		}
	}
}

void Grid::Render()
{
	int lCell, rCell, tCell, bCell;
	this->GetCameraPosOnGrid(lCell, rCell, tCell, bCell);

	for (int y = bCell; y <= tCell; y++)
	{
		for (int x = lCell; x <= rCell; x++)
		{
			(listCell + x + y * mapSize)->Render();

			if ((listCell + x + y * mapSize)->hasSpawnTiles.size() > 0)
			{
				for (int i = 0; i < (listCell + x + y * mapSize)->hasSpawnTiles.size(); i++)
				{
					if (!(listCell + x + y * mapSize)->hasSpawnTiles.at(i)->bCanSpawn)
						continue;

					SpawnObject((listCell + x + y * mapSize)->hasSpawnTiles.at(i)->SpawnObjectID,
						(listCell + x + y * mapSize)->hasSpawnTiles.at(i));
					(listCell + x + y * mapSize)->hasSpawnTiles.at(i)->bCanSpawn = false;
				}
			}
		}
	}

	for (int i = 0; i < listObject.size(); i++)
	{
		if (listObject.at(i).disable)
			continue;
		listObject.at(i).object->Render();
	}
	aladdin->Render();
}
