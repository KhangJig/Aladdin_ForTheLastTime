﻿#include "Grid.h"

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

	Guard1::LoadResources();
}

void Grid::InitializeMapGrid(TileMap *tileMap)
{
	mapSize = tileMap->currentMap->size / 3;

	listCell = new GridData[mapSize*mapSize];
	Tile* tempTile;

	for (int y = 0; y < mapSize; y++)
	{
		for (int x = 0; x < mapSize; x++)
		{
			for (int yy = 0; yy < GRID_SIZE_BY_TILE; yy++)
			{
				for (int xx = 0; xx < GRID_SIZE_BY_TILE; xx++)
				{
					tempTile = tileMap->currentMap->GetTile(xx + x * GRID_SIZE_BY_TILE, yy + y * GRID_SIZE_BY_TILE);
					listCell[x + y * mapSize].tiles.push_back(tempTile);
				}
			}
		}
	}

	GridCell gridcell;

	for (int i = 0; i < 18; i++)
	{
		// test grid cell mapobject
		for (int y = 0; y < tileMap->currentMap->listTileObjectMap.size(); y++)
		{
			if (tileMap->currentMap->listTileObjectMap[y].GridCellID == i)
			{
				gridcell.abc.push_back(tileMap->currentMap->listTileObjectMap[y]);
			}
		}

		// test grid cell enemies
		for (int y = 0; y < tileMap->currentMap->listEnemiesObjects.size(); y++)
		{
			if (tileMap->currentMap->listEnemiesObjects[y].CellID == i)
			{
				gridcell.xyz.push_back(tileMap->currentMap->listEnemiesObjects[y]);
				this->SpawnObject(tileMap->currentMap->listEnemiesObjects[y]);
			}
		}
		this->gridCell.push_back(gridcell);
	}
}

void Grid::GetCameraPosOnGrid(int &l, int &r, int &t, int &b) {
	RECT rect = viewport->GetRect();

	l = (int)(rect.left / GRID_SIZE);
	t = (int)(rect.top % GRID_SIZE > 300 ? rect.top / GRID_SIZE + 1 : rect.top / GRID_SIZE);
	r = (int)(rect.right / GRID_SIZE );
	b = (int)(rect.bottom / GRID_SIZE);

	if (t == 3)
		t -= 1;

	//DebugOut(L" l t r b  %d %d %d %d \n", l, t, r, b);
}

void Grid::UpdateCurrentTiles()
{
	currentTile.clear();
	RECT rect = aladdin->GetRect();
	int left = (int)(rect.left / GRID_SIZE);
	int right = (int)(rect.right / GRID_SIZE);
	int top = (int)(rect.top % GRID_SIZE == 0 ? rect.top / GRID_SIZE - 1 : rect.top / GRID_SIZE);
	int bottom = (int)(rect.bottom / GRID_SIZE);

	for (int x = left; x <= right; x++)
	{
		for (int y = bottom; y <= top; y++)
		{
			currentTile.insert(currentTile.end(), GetCell(x, y)->tiles.begin(), GetCell(x, y)->tiles.end());
		}
	}
}

vector<TileObjectMap *> Grid::GetNearbyObjectTiles()
{
	vector<TileObjectMap*> nearbyTiles;
	for (set<int>::iterator it = this->listCellNow.begin(); it != this->listCellNow.end(); ++it)
	{
		for (int y = 0; y < this->gridCell.at(*it).abc.size(); y++)
		{
			if (Viewport::GetInstance()->IsObjectInCamera2(&this->gridCell.at(*it).abc.at(y)))
			{
				nearbyTiles.push_back(&this->gridCell.at(*it).abc.at(y));
			}
		}
	}


	return nearbyTiles;
}

vector<TileObjectMap *> Grid::GetNearbyObjectTilesForEnemies(int CellID)
{
	vector<TileObjectMap*> nearbyTiles;

	for (set<int>::iterator it = this->listCellNow.begin(); it != this->listCellNow.end(); ++it)
	{
		for (int y = 0; y < this->gridCell.at(*it).abc.size(); y++)
		{
			nearbyTiles.push_back(&this->gridCell.at(*it).abc.at(y));
		}
	}


	return nearbyTiles;
}

void Grid::SpawnObject(ObjectnEnemies enemies)
{
	switch (enemies.SpawnObjectID)
	{
	case ObjectAndEnemies::GUARD1:
		{
			OnUpdateObject temp;
			temp.ene = enemies;

			listObject.push_back(temp);
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

bool Grid::CheckObjectInsideCamera2(int x, int y)
{
	if (timeCount < 2000)
		return true;

	int test = 1;

	RECT rect = viewport->GetRect();

	if (x > rect.left - 62 && x < rect.right + 162 &&
		y > rect.bottom - 50 && y < rect.top + 50)
	{
		return true;
	}

	return false;
}

bool Grid::OnCell(int id)
{
	for (set<int>::iterator it = this->listCellNow.begin(); it != this->listCellNow.end(); ++it)
	{
		if (*it == id)
			return true;
	}
	return false;
}

void Grid::Update(DWORD dt)
{

	timeCount += dt;
	aladdin->Update(dt);
	aladdin->UpdateCollision(dt);

	for (int i = 0; i < listObject.size(); i++)
	{
		if (OnCell(listObject.at(i).ene.CellID))
		{
			if (!listObject.at(i).isGenerated)
			{
				if (CheckObjectInsideCamera2(listObject.at(i).ene.x, listObject.at(i).ene.y))
				{
					DebugOut(L"Guard Created!\n");
					if (listObject.at(i).ene.SpawnObjectID == 1)
					{
						listObject.at(i).object = new Guard1(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID);
						listObject.at(i).isGenerated = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < listObject.size(); i++)
	{
		if (listObject.at(i).isGenerated && listObject.at(i).isLife)
		{
			this->listObject.at(i).object->Update(dt);
		}
	}

}

void Grid::Render()
{
	int lCell, rCell, tCell, bCell;
	this->GetCameraPosOnGrid(lCell, rCell, tCell, bCell);

	this->listCellNow.clear();
	this->listCellNow.insert(lCell);
	this->listCellNow.insert(lCell + 6*tCell);
	this->listCellNow.insert(rCell);
	this->listCellNow.insert(rCell + 6*bCell);

	for (int y = bCell; y <= tCell; y++)
	{
		for (int x = lCell; x <= rCell; x++)
		{
			listCell[x + y * mapSize].Render();
		}
	}


	for (int i = 0; i < listObject.size(); i++)
	{
		if (listObject.at(i).isGenerated && listObject.at(i).isLife)
			listObject.at(i).object->Render();
	}

	aladdin->Render();
}