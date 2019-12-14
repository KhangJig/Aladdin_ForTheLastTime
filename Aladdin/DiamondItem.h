#pragma once
#include "GameObject.h"
#include "Debug.h"

class DiamondItem : public GameObject
{
	static vector<Animation *> animations;

	int x, y;

	int CellID;

	int id;

public:
	DiamondItem(int x, int y, int CellID, int id);

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetID() { return this->id; }

	int GetCellID() { return this->CellID; }

	static void LoadResources(RECT* listSprite, Sprite * items);

	void Update(DWORD dt);

	void Render();

	~DiamondItem();
};