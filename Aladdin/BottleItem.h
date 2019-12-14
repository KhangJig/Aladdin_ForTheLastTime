#pragma once
#include "GameObject.h"
#include "Debug.h"

enum BottleState
{
	BottleState1,
	BottleState2,
	BottleState3
};

class BottleItem : public GameObject
{
	static vector<Animation *> animations;

	int x, y;

	int CellID;

	int id;

	BottleState state;

	bool check;

public:
	BottleItem(int x, int y, int CellID, int id);

	void SetPos(int x, int y) { this->x = x; this->y = y;}

	int GetID() { return this->id; }

	int GetCellID() { return this->CellID; }

	bool GetCheck() { return this->check; }

	void SetCheck(bool check) { this->check = check; }

	void SetState(BottleState state) { this->state = state; }

	static void LoadResources(RECT* listSprite, Sprite * items);

	void Update(DWORD dt);

	void Render();

	~BottleItem();
};