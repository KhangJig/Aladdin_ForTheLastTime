#pragma once
#include "GameObject.h"
#include "Debug.h"

enum HPState
{
	LV_ZERO,
	LV_ONE,
	LV_TWO,
	LV_THREE,
	LV_FOUR,
	LV_FIVE,
	LV_SIX,
	LV_SEVEN,
	LV_EIGHT,
	LV_NINE,
	LV_TEN
};

class HP : public GameObject
{
	static vector<Animation *> animations;

	static HP *__instance;

	int x, y;

	HPState State;

	HP();

public:
	static HP *GetInstance();

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	HPState GetState() { return this->State; }

	void SetState(HPState state) { this->State = state; }

	static void LoadResources();

	void Update(DWORD dt);

	void Render();

	~HP();
};