#pragma once
#include "GameObject.h"
#include "Debug.h"

class Score : public GameObject
{
	static vector<Animation *> animations;

	static Score *__instance;

	int x, y;

	int num;

	Score();

public:
	static Score *GetInstance();

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetNum() { return this->num; }

	void SetNum(int num) { this->num = num; }

	static void LoadResources();

	void Update(DWORD dt);

	void Render();

	~Score();
};