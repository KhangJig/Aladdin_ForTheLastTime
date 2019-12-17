#pragma once
#include "GameObject.h"
#include "Debug.h"

class Sense : public GameObject
{
	static vector<Animation *> animations;

	static Sense *__instance;

	int x, y;

	Sense();

public:
	static Sense *GetInstance();

	vector <Sprite*> tiles;

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	static void LoadResources();

	void Update(DWORD dt);

	void Render();

	~Sense();
};