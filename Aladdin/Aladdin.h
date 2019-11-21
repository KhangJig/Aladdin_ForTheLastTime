#pragma once
#include "GameObject.h"
#include "AladdinState.h"
#include "Constants.h"
#include "Game.h"
#include "State.h"
#include "Apple.h"

class Aladdin : public GameObject
{
	Aladdin();

	static Aladdin *__instance;
	State *state, *stateApple;

	Apple *apple;

	bool isGrounded = false;
	static vector<Animation *> animations;
	DWORD lastFrameTime;

	bool bImortal;
	float timeCount;
	bool trueImortal;
	bool isApple;

public:
	void LoadResources();

	static Aladdin *GetInstance();

	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetIsGrounded(bool isGrounded) { this->isGrounded = isGrounded; }
	bool GetIsGrounded() { return isGrounded; }

	void SetIsApple(bool isApple) { this->isApple = isApple; }
	bool GetisApple() { return isApple; }

	void SetColliderDemension(float width, float height)
	{
		this->collider.width = width;
		this->collider.height = height;
	}

	void Reset();

	vector<Animation *> GetAnimationsList() { return animations; }

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;
};