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

	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Miscellaneous\\Items.txt");
	Sprite * sprites = new Sprite(ITEMS_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_5);

	AppleItem::LoadResources(listSprite, sprites);
	DiamondItem::LoadResources(listSprite, sprites);
	GenieFaceItem::LoadResources(listSprite, sprites);
	ExtraHeartItem::LoadResources(listSprite, sprites);
	BottleItem::LoadResources(listSprite, sprites);

	listSprite = loadTXT.LoadRect((char*)"Resource\\Background\\MapObjects.txt");
	sprites = new Sprite(MAPOBJECTS_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_6);

	ThornObject::LoadResources(listSprite, sprites);
	BallObject::LoadResources(listSprite, sprites);
	BrickInObject::LoadResources(listSprite, sprites);
	BrickOutObject::LoadResources(listSprite, sprites);

	AppleEffect::LoadResources();
	EnemiesDeadEffect::LoadResources();
	ItemEffect::LoadResources();

	Guard1::LoadResources();
	Jafar::LoadResources();
}

void Grid::InitializeMapGrid(TileMap *tileMap)
{
	this->gridCell.clear();
	this->listObject.clear();

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
			if (Viewport::GetInstance()->IsObjectInCamera2(&this->gridCell.at(*it).abc.at(y)) && this->gridCell.at(*it).abc.at(y).type != ObjectType::ROPE)
			{
				nearbyTiles.push_back(&this->gridCell.at(*it).abc.at(y));
			}
		}
	}


	return nearbyTiles;
}

vector<TileObjectMap *> Grid::GetNearbyObjectTilesThorn()
{
	vector<TileObjectMap*> nearbyTiles;
	for (set<int>::iterator it = this->listCellNow.begin(); it != this->listCellNow.end(); ++it)
	{
		for (int y = 0; y < this->gridCell.at(*it).abc.size(); y++)
		{
			if (Viewport::GetInstance()->IsObjectInCamera2(&this->gridCell.at(*it).abc.at(y)) && this->gridCell.at(*it).abc.at(y).type == ObjectType::ROPE)
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
	OnUpdateObject temp;
	temp.ene = enemies;
	listObject.push_back(temp);
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
					switch (listObject.at(i).ene.SpawnObjectID)
					{
					case ObjectAndEnemies::GUARD1:
					{
						DebugOut(L"Guard 1 Created!\n");
						listObject.at(i).object = new Guard1(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::GUARD2:
					{

					}break;
					case ObjectAndEnemies::BOMBBER:
					{

					}break;
					case ObjectAndEnemies::BAT:
					{

					}break;
					case ObjectAndEnemies::THORN:
					{
						listObject.at(i).object = new ThornObject(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::BALL:
					{
						listObject.at(i).object = new BallObject(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::BRICK_IN:
					{
						listObject.at(i).object = new BrickInObject(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::BRICK_OUT:
					{
						listObject.at(i).object = new BrickOutObject(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::APPLE:
					{
						DebugOut(L"Apple-items Created!\n");
						listObject.at(i).object = new AppleItem(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::DIAMOND:
					{
						DebugOut(L"Apple-items Created!\n");
						listObject.at(i).object = new DiamondItem(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::BOTTLE:
					{
						DebugOut(L"Bottle-items Created!\n");
						listObject.at(i).object = new BottleItem(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::GENIE_FACE:
					{
						DebugOut(L"GenieFace-items Created!\n");
						listObject.at(i).object = new GenieFaceItem(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::EXTRA_HEART:
					{
						DebugOut(L"ExtraHeartItem-items Created!\n");
						listObject.at(i).object = new ExtraHeartItem(listObject.at(i).ene.x, listObject.at(i).ene.y, listObject.at(i).ene.CellID, i);
						listObject.at(i).isGenerated = true;
					}break;
					case ObjectAndEnemies::SHOP:
					{

					}break;
					case ObjectAndEnemies::JAFAR:
					{
						DebugOut(L"Jafar Created!\n");
						listObject.at(i).object = new Jafar(listObject.at(i).ene.x, listObject.at(i).ene.y);
						listObject.at(i).isGenerated = true;
					}break;
					default:
						break;
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
		{
			if (listObject.at(i).ene.SpawnObjectID == ObjectAndEnemies::GUARD1 ||
				listObject.at(i).ene.SpawnObjectID == ObjectAndEnemies::GUARD2 ||
				listObject.at(i).ene.SpawnObjectID == ObjectAndEnemies::BOMBBER ||
				listObject.at(i).ene.SpawnObjectID == ObjectAndEnemies::BAT || 
				listObject.at(i).ene.SpawnObjectID == ObjectAndEnemies::JAFAR)
			{
				listObject.at(i).object->Render();
			}
			else
			{
				if (CheckObjectInsideCamera2(listObject.at(i).ene.x, listObject.at(i).ene.y))
				{
					listObject.at(i).object->Render();
				}
			}
		}
	}

	aladdin->Render();
}