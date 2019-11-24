#pragma once
#include "Debug.h"
#include "GameObject.h"
#include "Constants.h"
#include "Game.h"
#include "SpawnProjectTile.h"
#include "State.h"
#include "Guard1State.h"

class Guard1 : public GameObject
{
	Guard1();

	static Guard1 *__instance;

	State *state;

	static vector<Animation *> animations;

	DWORD lastFrameTime;

public:
	Guard1(float x, float y);
	static void LoadResources();

	bool isOnGround = false;

	float posx, posy;

	static Guard1 *GetInstance();

	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }

	void SetColliderDemension(float width, float height)
	{
		this->collider.width = width;
		this->collider.height = height;
	}

	vector<Animation *> GetAnimationsList() { return animations; }

	void Update(DWORD dt) override;

	void Render() override;

	void OnCollision();
};