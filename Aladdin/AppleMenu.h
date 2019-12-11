#pragma once
#include "GameObject.h"
#include "Debug.h"

class AppleMenu : public GameObject
{
	static vector<Animation *> animations;

	static AppleMenu *__instance;

	int x, y;

	int num;

	AppleMenu();

public:
	static AppleMenu *GetInstance();

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetNum() { return this->num; }

	void SetNum(int num) { this->num = num; }

	static void LoadResources();

	void Update(DWORD dt);

	void Render();

	~AppleMenu();
};