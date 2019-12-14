#pragma once
#include "Constants.h"
#include "Debug.h"
#include "State.h"
#include "Bat.h"

class Bat;
enum StateBat
{
	BAT_IDLE,
	BAT_START_FLY,
	BAT_FLYING,
	BAT_BE_KILL_APPLE,
	BAT_BE_KILL_SWORD
};

class BatState : public State
{
protected:
	static BatState * __instance;
	StateBat stateBat;
	Bat *bat;
	Animation * anim;
public:
	float timeCount;

	BatState(Bat *bat);
	~BatState();

	static BatState * GetInstance(Bat *bat);

	StateBat GetState();
	void SetState(StateBat State);

	void stateIdle();
	void stateStartFly();
	void stateFlying();
	void stateBeKillApple();
	void stateBeKillSword();

	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;
};
