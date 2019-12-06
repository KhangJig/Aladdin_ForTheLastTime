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

	Guard1::LoadResources();
}

void Grid::InitializeMapGrid(TileMap *tileMap)
{
	mapSize = 8;

	listCell = new GridData[mapSize*mapSize];
	Tile* tempTile;

	for (int y = 0; y < mapSize; y++)
	{
		//DebugOut(L"Y - %d\n", y);
		for (int x = 0; x < mapSize; x++)
		{
			//DebugOut(L"X - %d\n", x);
			for (int yy = 0; yy < GRID_SIZE_BY_TILE; yy++)
			{
				//DebugOut(L"yy - %d\n", yy);
				for (int xx = 0; xx < GRID_SIZE_BY_TILE; xx++)
				{
					tempTile = tileMap->currentMap->GetTile(xx + x * GRID_SIZE_BY_TILE, yy + y * GRID_SIZE_BY_TILE);
					listCell[x + y * mapSize].tiles.push_back(tempTile);
				}
			}
		}
	}

	// get possion object map
	for (int i = 0; i < tileMap->GetListTileObj().size(); i++)
	{
		this->tileObjectMap22.push_back(tileMap->GetListTileObj()[i]);
	}

	// get possion object & enemies
	for (int i = 0; i < tileMap->GetEnemiesAndObjecs().size(); i++)
	{
		this->enemiesnObjects.push_back(tileMap->GetEnemiesAndObjecs()[i]);
		this->SpawnObject(tileMap->GetEnemiesAndObjecs()[i]);
	}
}

void Grid::GetCameraPosOnGrid(int &l, int &r, int &t, int &b) {
	RECT rect = viewport->GetRect();

	l = (int)(rect.left / GRID_SIZE);
	t = (int)(rect.top % GRID_SIZE > 300 ? rect.top / GRID_SIZE + 1 : rect.top / GRID_SIZE);
	r = (int)(rect.right / GRID_SIZE );
	b = (int)(rect.bottom / GRID_SIZE);

	//if (r == 5 && t == 2)
	//	r = 4;
	if (t == 3)
		t -= 1;

	/*DebugOut(L"l r t b  %d %d %d %d\n", l, r, t, b);*/
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
	
	for (int i = 0; i < this->tileObjectMap22.size(); i++)
	{
		if (Viewport::GetInstance()->IsObjectInCamera2(&this->tileObjectMap22.at(i)))
		{
			nearbyTiles.push_back(&this->tileObjectMap22.at(i));
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
			Guard1* object = new Guard1(enemies.x, enemies.y);
			OnUpdateObject temp;
			temp.object = object;

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
			listCell[x + y * mapSize].Render();
			//(listCell + x + y * mapSize)->Render();
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
