#pragma once
#include "Constants.h"
#include "Debug.h"
#include "State.h"
#include "Guard1.h"

class Guard1;
enum StateGuard1
{
	GUARD1_IDLE,
	GUARD1_HURT,
	GUARD1_WALK,
	GUARD1_HIT,
	GUARD1_DEAD
};

class Guard1State : public State
{
protected:
	static Guard1State * __instance;
	StateGuard1 stateGuard1;
	Guard1 *guard1;
	Animation * anim;
public:
	float timeCount;

	Guard1State(Guard1 *guard1);
	~Guard1State();

	static Guard1State * GetInstance(Guard1 *guard1);

	StateGuard1 GetState();
	void SetState(StateGuard1 State);

	void stateIdle();
	void stateHurting();
	void stateWalking();
	void stateHit();
	void stateDead();

	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;
};
