#pragma once
#include "Constants.h"
#include "Debug.h"
#include "State.h"
#include "Jafar.h"

class Jafar;
enum StateJafar
{
	JAFAR_IDLE,
	JAFAR_HURT,
	JAFAR_HIT,
	SNAKE_IDLE,
	SNAKE_HURT,
	SNAKE_HIT,
	JAFAR_DEAD
};

class JafarState : public State
{
protected:

	static JafarState * __instance;

	StateJafar stateJafar;

	Jafar *jafar;

	Animation * anim;

public:
	float timeCount;

	JafarState(Jafar *jafar);

	static JafarState * GetInstance(Jafar *jafar);

	StateJafar GetState();

	void SetState(StateJafar State);

	void stateJafarIdle();
	void stateJafarHurt();
	void stateJafarHit();
	void stateSnakeIdle();
	void stateSnakeHurt();
	void stateSnakeHit();
	void stateDead();

	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;

	~JafarState();
};
