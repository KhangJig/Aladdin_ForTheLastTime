#pragma once
#include "GameObject.h"
#include "Debug.h"

class Apple : public GameObject
{
	vector<Animation *> animations;
	static Apple * __instance;

	int state;

	bool isStartThrow = true;

	bool isReturn = true;

	bool isAladdinLeft;

	float maxDistance;

	float distance;
public:
	Apple();

	bool isFlying = false;

	bool IsFlying() { return this->isFlying; }

	void SetIsFlying(bool isFlying) { this->isFlying = isFlying; }

	static Apple * GetInstance();

	void LoadResources();

	void AppleFlying();

	void Update(DWORD dt);

	void Render();

	float ParabolCurrentX(float posX, float posY, float currentX);

	float GetDistance() { return this->distance; }

	~Apple();
};

