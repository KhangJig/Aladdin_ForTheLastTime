#pragma once
#include "Constants.h"
#include "Debug.h"
#include "State.h"
#include "Aladdin.h"

enum StateAladdin
{
	IDLE_STAND,
	STATE_HEAD_UP,
	STATE_RUN,
	STATE_STAND_JUMP,
	STATE_FALL,
	STATE_TOUCH_GROUND,
	STATE_SIT,
	IDLE_SIT,
	STATE_STAND_HIT,
	STATE_STAND_THROW,
	STATE_SIT_THROW,
	STATE_SIT_HIT,
	STATE_RUN_JUMP,
	STATE_FALL_2,
	STATE_JUMP_THROW,
	STATE_JUMP_HIT,
	STATE_DOUBLE_HIT,
	STATE_HURT,
	STATE_RUN_HIT,
	STATE_RUN_THROW,
	IDLE_CLIMB,
	STATE_CLIMB,
	STATE_JUMP_CLIMB,
	STAND_ON_BRICK
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
	void stateSittingIdle();
	void stateStandHit();
	void stateStandThrow();
	void stateSitHit();
	void stateSitThrow();
	void stateRunJump();
	void stateFall2();
	void stateJumpHit();
	void stateJumpThrow();
	void stateDoubleHit();
	void stateHurt();
	void stateRunHit();
	void stateRunThrow();
	void stateClimb();
	void stateClimbing();
	void stateJumpClimb();
	void stateStandOnBrick();



	void KeyHandle();
	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;
};
