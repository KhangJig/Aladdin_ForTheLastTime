#include "Guard1State.h"
#include <math.h>

Guard1State * Guard1State::__instance = NULL;

Guard1State *Guard1State::GetInstance(Guard1 *guard1)
{
	if (__instance == NULL)
		__instance = new Guard1State(guard1);
	return __instance;
}

Guard1State::Guard1State(Guard1 *guard1)
{
	this->guard1 = guard1;
	this->stateGuard1 = GUARD1_IDLE;
	this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
}

StateGuard1 Guard1State::GetState()
{
	return this->stateGuard1;
}

void Guard1State::SetState(StateGuard1 state)
{
	this->stateGuard1 = state;
}

void Guard1State::stateIdle() 
{
	anim = guard1->GetAnimationsList()[GUARD1_IDLE];
	this->guard1->SetSpeedX(0);
	this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	this->guard1->SetAttacking(false);

	if (abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()) <= 50)
	{
		if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) >= 50
			&& abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) <= 200)
		{
			anim->Reset();
			this->SetState(GUARD1_WALK);
			return;
		}
		if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) <= 50 )
		{
			if (Aladdin::GetInstance()->GetAladdinHP() > 0)
			{
				Sound::GetInstance()->PlaySound(this->guard1->GetSoundGuardHit());
				anim->Reset();
				this->SetState(GUARD1_HIT);
			}
			return;
		}
	}
}

void Guard1State::stateHurting()
{
	anim = guard1->GetAnimationsList()[GUARD1_HURT];
	this->guard1->SetSpeedX(0);
	this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(GUARD1_IDLE);
		return;
	}
}

void Guard1State::stateWalking()
{
	this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = guard1->GetAnimationsList()[GUARD1_WALK];

	if (Aladdin::GetInstance()->GetPositionX() < this->guard1->GetPositionX())
	{
		this->guard1->SetSpeedX(-GUARD1_WALK_SPEED);
	}
	else
	{
		this->guard1->SetSpeedX(GUARD1_WALK_SPEED);
	}

	if (abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()) > 50 
		|| abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) > 200)
	{
		anim->Reset();
		this->SetState(GUARD1_IDLE);
		return;
	}

	if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) < 50 )
	{
		if (Aladdin::GetInstance()->GetAladdinHP() > 0)
		{
			Sound::GetInstance()->PlaySound(this->guard1->GetSoundGuardHit());
			anim->Reset();
			this->SetState(GUARD1_HIT);
		}
		return;
	}
}

void Guard1State::stateHit()
{
	this->guard1->SetSpeedX(0);
	this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = guard1->GetAnimationsList()[GUARD1_HIT];

	if (abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()) > 50 
		|| abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) > 200)
	{
		anim->Reset();
		this->SetState(GUARD1_IDLE);
		return;
	}
	if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) >= 50 
		&& abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) <= 200)
	{
		anim->Reset();
		this->SetState(GUARD1_WALK);
		return;
	}

	if (anim->IsDone())
	{
		this->guard1->SetAttacking(true);
		anim->Reset();
		this->SetState(GUARD1_IDLE);
		return;
	}
}

void Guard1State::stateDead() 
{
	this->guard1->SetSpeedX(0); 
	this->guard1->SetAttacking(false);
	this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = guard1->GetAnimationsList()[GUARD1_DEAD];

	if (this->guard1->GetEnemiesDeadEffect()->GetHidden())
	{
		this->guard1->SetDie(true);
		Grid::GetInstance()->SetisLifeListObject(this->guard1->GetID(), false);
		return;
	}
}

void Guard1State::Colision()
{

}

void Guard1State::Update(DWORD dt)
{

	switch (stateGuard1)
	{

	case GUARD1_IDLE:
		this->stateIdle();
		break;

	case GUARD1_HURT:
		this->stateHurting();
		break;

	case GUARD1_WALK:
		this->stateWalking();
		break;

	case GUARD1_HIT:
		this->stateHit();
		break;

	case GUARD1_DEAD:
		this->stateDead();
		break;

	default:
		break;
	}


	this->timeCount += dt;
}

void Guard1State::Render()
{
	SpriteData spriteData;
	if (this->guard1 != NULL)
	{
		spriteData.width = GUARD1_SPRITE_WIDTH;
		spriteData.height = GUARD1_SPRITE_HEIGHT;
		spriteData.x = guard1->GetPositionX();
		spriteData.y = guard1->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = guard1->IsLeft();
		spriteData.isFlipped = guard1->IsFlipped();
	}

	anim->Render(spriteData);
}

Guard1State::~Guard1State()
{
	delete anim;
}