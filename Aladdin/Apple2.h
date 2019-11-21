#pragma once
#include "GameObject.h"
#include "Debug.h"

class Apple2 : public GameObject
{
	vector<Animation *> animations;
	static Apple2 * __instance;

	int state;

	bool isStartThrow = true;

	bool isReturn = true;

	bool isAladdinLeft;

	float maxDistance;

	float distance;
public:
	Apple2();

	bool isFlying = false;

	bool IsFlying() { return this->isFlying; }
	void SetIsFlying(bool isFlying) { this->isFlying = isFlying; }

	static Apple2 * GetInstance();

	void LoadResources();

	void AppleFlying();

	void Reset();

	void Update(DWORD dt);

	void Render();

	float GetDistance() { return this->distance; }

	~Apple2();
};

