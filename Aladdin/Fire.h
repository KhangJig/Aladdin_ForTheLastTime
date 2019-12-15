#pragma once
#include "GameObject.h"
#include "Debug.h"

class Fire : public GameObject
{
	static vector<Animation *> animations;

	int Radius;

	bool Direction;

public:
	Fire(float x, float y, bool direction);

	int GetRadius() { return this->Radius; }

	bool GetDirection() { return this->Direction; }

	void SetRadius(int num) { this->Radius = num; }

	void SetDirection(bool dir) { this->Direction = dir; }

	static void LoadResources(RECT* listSprite, Sprite * items);

	void Update(DWORD dt);

	void Render();

	~Fire();
};