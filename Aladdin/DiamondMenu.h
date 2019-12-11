#pragma once
#include "GameObject.h"
#include "Debug.h"

class DiamondMenu : public GameObject
{
	static vector<Animation *> animations;

	static DiamondMenu *__instance;

	int x, y;

	int num;

	DiamondMenu();

public:
	static DiamondMenu *GetInstance();

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetNum() { return this->num; }

	void SetNum(int num) { this->num = num; }

	static void LoadResources();

	void Update(DWORD dt);

	void Render();

	~DiamondMenu();
};