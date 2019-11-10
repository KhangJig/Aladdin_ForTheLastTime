﻿#pragma once
#include "Constants.h"
#include "Debug.h"
#include "State.h"
#include "Aladdin.h"

enum StateAladdin
{
	STATE_STAND,
	STATE_HEAD_UP,
	STATE_RUN,
	STATE_STAND_JUMP,
	STATE_FALL,
	STATE_TOUCH_GROUND,
	STATE_SIT,
	STATE_STAND_HIT,
	STATE_STAND_THROW,
	STATE_SIT_HIT,
	STATE_SIT_THROW,
	STATE_RUN_JUMP,
};

class AladdinState : public State
{
protected:
	static AladdinState * __instance;
	StateAladdin stateAladdin;
	Aladdin *aladdin;
	Animation * anim;
	RECT* listSprite;
	float startJumpY;

public:
	float timeCount;
	AladdinState(Aladdin *aladdin);
	~AladdinState();

	static AladdinState * GetInstance(Aladdin *aladdin);

	StateAladdin GetState();

	void SetState(StateAladdin State);

	void stateStanding();
	void stateHeadUp();
	void stateWalking();
	void stateJumping();
	void stateFalling();
	void stateTouchGround();
	void stateSitting();
	void stateStandHit();
	void stateStandThrow();
	void stateSitHit();
	void stateSitThrow();




	void KeyHandle();
	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;
};
