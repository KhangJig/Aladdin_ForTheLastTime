#pragma once
#include "GameObject.h"
#include "Debug.h"

class BrickInObject : public GameObject
{
	static vector<Animation *> animations;

	int x, y;

	int CellID;

	int id;

public:
	BrickInObject(int x, int y, int CellID, int id);

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetX() { return this->x; }

	int GetY() { return this->y; }

	int GetID() { return this->id; }

	int GetCellID() { return this->CellID; }

	vector<Animation *> GetAnimation() { return this->animations; }

	static void LoadResources(RECT* listSprite, Sprite * items);

	void Update(DWORD dt);

	void Render();

	~BrickInObject();
};