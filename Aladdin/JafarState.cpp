#include "JafarState.h"
#include <math.h>

JafarState * JafarState::__instance = NULL;

JafarState *JafarState::GetInstance(Jafar *jafar)
{
	if (__instance == NULL)
		__instance = new JafarState(jafar);
	return __instance;
}

JafarState::JafarState(Jafar *jafar)
{
	this->jafar = jafar;
	this->stateJafar = JAFAR_HIT;
	this->jafar->SetSpeedX(0);
	this->jafar->SetSpeedY(0);
}

StateJafar JafarState::GetState()
{
	return this->stateJafar;
}

void JafarState::SetState(StateJafar state)
{
	this->stateJafar = state;
}

void JafarState::stateJafarIdle()
{
	anim = jafar->GetAnimationsList()[JAFAR_IDLE];
}

void JafarState::stateJafarHurt()
{
	anim = jafar->GetAnimationsList()[JAFAR_HURT];
	if (this->anim->IsDone())
	{
		this->SetState(JAFAR_HIT);
		return;
	}
}

void JafarState::stateJafarHit()
{
	anim = jafar->GetAnimationsList()[JAFAR_HIT];
}

void JafarState::stateSnakeIdle()
{

}

void JafarState::stateSnakeHurt()
{

}

void JafarState::stateSnakeHit()
{

}

void JafarState::stateDead() 
{

}

void JafarState::Colision()
{

}

void JafarState::Update(DWORD dt)
{

	switch (stateJafar)
	{

	case JAFAR_IDLE:
		this->stateJafarIdle();
		break;

	case JAFAR_HURT:
		this->stateJafarHurt();
		break;

	case JAFAR_HIT:
		this->stateJafarHit();
		break;

	case SNAKE_IDLE:
		this->stateSnakeIdle();
		break;

	case SNAKE_HURT:
		this->stateSnakeHurt();
		break;

	case SNAKE_HIT:
		this->stateSnakeHit();
		break;

	case JAFAR_DEAD:
		this->stateDead();
		break;

	default:
		break;
	}

	this->timeCount += dt;
}

void JafarState::Render()
{
	SpriteData spriteData;
	if (this->jafar != NULL)
	{
		spriteData.width = JAFAR_SPRITE_WIDTH;
		spriteData.height = JAFAR_SPRITE_HEIGHT;
		spriteData.x = jafar->GetX();
		spriteData.y = jafar->GetY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = jafar->IsLeft();
		spriteData.isFlipped = jafar->IsFlipped();
	}
	anim->Render(spriteData);
}

JafarState::~JafarState()
{
	delete anim;
}