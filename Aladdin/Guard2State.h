#pragma once
#include "Constants.h"
#include "Debug.h"
#include "State.h"
#include "Guard2.h"

class Guard2;
enum StateGuard2
{
	GUARD2_IDLE,
	GUARD2_HURT,
	GUARD2_WALK,
	GUARD2_HIT,
	GUARD2_DEAD
};

class Guard2State : public State
{
protected:
	static Guard2State * __instance;
	StateGuard2 stateGuard2;
	Guard2 *guard2;
	Animation * anim;
public:
	float timeCount;

	Guard2State(Guard2 *guard2);
	~Guard2State();

	static Guard2State * GetInstance(Guard2 *guard2);

	StateGuard2 GetState();
	void SetState(StateGuard2 State);

	void stateIdle();
	void stateHurting();
	void stateWalking();
	void stateHit();
	void stateDead();

	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;
};
