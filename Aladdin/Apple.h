#pragma once
#include "GameObject.h"
#include "Debug.h"
#include "Sound.h"
#include "AppleEffect.h"

class Apple : public GameObject
{
	vector<Animation *> animations;

	static Apple * __instance;

	AppleEffect *appleEffect;

	GSound * appleSplat;

	int state;

	bool isStartThrow = true;

	bool isReturn = true;

	bool isAladdinLeft;

	float maxDistance;

	float distance;

	bool isFlying = false;
public:
	Apple();

	bool GetIsFlying() { return this->isFlying; }

	void SetIsFlying(bool isFlying) { this->isFlying = isFlying; }

	static Apple * GetInstance();

	void LoadResources();

	void AppleFlying();

	void Update(DWORD dt);

	void UpdateCollision(vector<TileObjectMap *> tiles);

	void Render();

	float ParabolCurrentX(float posX, float posY, float currentX);

	float GetDistance() { return this->distance; }

	~Apple();
};

