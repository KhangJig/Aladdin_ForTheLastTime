#pragma once
#include "GameObject.h"
#include "Debug.h"

class LifeMenu : public GameObject
{
	static vector<Animation *> animations;

	static LifeMenu *__instance;

	int x, y;

	int num;

	LifeMenu();

public:
	static LifeMenu *GetInstance();

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetNum() { return this->num; }

	void SetNum(int num) { this->num = num; }

	static void LoadResources();

	void Update(DWORD dt);

	void Render();

	~LifeMenu();
};