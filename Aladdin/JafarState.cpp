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
	this->stateJafar = JAFAR_IDLE;
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
	if (abs(this->jafar->GetX() - Aladdin::GetInstance()->GetPositionX()) <= JAFAR_RADIUS)
	{
		Fire* fire = new Fire(this->jafar->GetX(), this->jafar->GetY() - JAFAR_SPRITE_HEIGHT, this->jafar->IsLeft());
		this->jafar->AddListFire(fire);

		this->SetState(JAFAR_HIT);
		return;
	}
}

void JafarState::stateJafarHurt()
{
	anim = jafar->GetAnimationsList()[JAFAR_HURT];
	if (this->anim->IsDone())
	{
		anim->Reset();
		this->SetState(JAFAR_IDLE);
		return;
	}
}

void JafarState::stateJafarHit()
{
	anim = jafar->GetAnimationsList()[JAFAR_HIT];
	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(JAFAR_IDLE);
		return;
	}
}

void JafarState::stateSnakeIdle()
{
	anim = jafar->GetAnimationsList()[SNAKE_IDLE];
	if (abs(this->jafar->GetX() - Aladdin::GetInstance()->GetPositionX()) <= JAFAR_RADIUS)
	{
		Fire* fire = new Fire(this->jafar->GetX(), this->jafar->GetY() - JAFAR_SPRITE_HEIGHT, this->jafar->IsLeft());
		this->jafar->AddListFire(fire);

		this->SetState(SNAKE_HIT);
		return;
	}
}

void JafarState::stateSnakeHurt()
{
	anim = jafar->GetAnimationsList()[SNAKE_HURT];
	if (this->anim->IsDone())
	{
		anim->Reset();
		this->SetState(SNAKE_IDLE);
		return;
	}
}

void JafarState::stateSnakeHit()
{
	anim = jafar->GetAnimationsList()[SNAKE_HIT];
	if (this->anim->IsDone())
	{
		anim->Reset();
		this->SetState(SNAKE_IDLE);
		return;
	}
}

void JafarState::stateDead() 
{
	this->anim = jafar->GetAnimationsList()[JAFAR_DEAD];
	if (this->anim->IsDone())
	{
		Grid::GetInstance()->SetisLifeListObject(this->jafar->GetID(), false);
		Aladdin::GetInstance()->SetScoreNumber(Aladdin::GetInstance()->GetScoreNumber() + JAFAR_POINT);
		if (Aladdin::GetInstance()->GetScoreNumber() > ALADDIN_DEFAULT_MAXS_SCORE) 
		{
			Aladdin::GetInstance()->SetScoreNumber(ALADDIN_DEFAULT_MAXS_SCORE);
		}
		return;
	}
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
		spriteData.width = this->jafar->GetSnakePower() ? SNAKE_SPRITE_WIDTH : JAFAR_SPRITE_WIDTH;
		spriteData.height = this->jafar->GetSnakePower() ? SNAKE_SPRITE_HEIGHT : JAFAR_SPRITE_HEIGHT;
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