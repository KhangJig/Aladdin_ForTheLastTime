#include "Guard2State.h"
#include <math.h>

Guard2State * Guard2State::__instance = NULL;

Guard2State *Guard2State::GetInstance(Guard2 *guard2)
{
	if (__instance == NULL)
		__instance = new Guard2State(guard2);
	return __instance;
}

Guard2State::Guard2State(Guard2 *guard2)
{
	this->guard2 = guard2;
	this->stateGuard2 = GUARD2_IDLE;
	this->guard2->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
}

StateGuard2 Guard2State::GetState()
{
	return this->stateGuard2;
}

void Guard2State::SetState(StateGuard2 state)
{
	this->stateGuard2 = state;
}

void Guard2State::stateIdle() 
{
	anim = guard2->GetAnimationsList()[GUARD2_IDLE];
	this->guard2->SetSpeedX(0);
	this->guard2->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	this->guard2->SetAttacking(false);

	if (abs(Aladdin::GetInstance()->GetPositionY() - this->guard2->GetPositionY()) <= 50)
	{
		if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) >= 50
			&& abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) <= 200)
		{
			anim->Reset();
			this->SetState(GUARD2_WALK);
			return;
		}
		if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) <= 50 )
		{
			if (Aladdin::GetInstance()->GetAladdinHP() > 0)
			{
				Sound::GetInstance()->PlaySound(this->guard2->GetSoundGuardHit());
				anim->Reset();
				this->SetState(GUARD2_HIT);
			}
			return;
		}
	}
}

void Guard2State::stateHurting()
{
	anim = guard2->GetAnimationsList()[GUARD2_HURT];
	this->guard2->SetSpeedX(0);
	this->guard2->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(GUARD2_IDLE);
		return;
	}
}

void Guard2State::stateWalking()
{
	this->guard2->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = guard2->GetAnimationsList()[GUARD2_WALK];

	if (Aladdin::GetInstance()->GetPositionX() < this->guard2->GetPositionX())
	{

		this->guard2->SetSpeedX(-GUARD2_WALK_SPEED);
	}
	else
	{
		this->guard2->SetSpeedX(GUARD2_WALK_SPEED);
	}

	if (abs(Aladdin::GetInstance()->GetPositionY() - this->guard2->GetPositionY()) > 50 
		|| abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) > 200)
	{
		anim->Reset();
		this->SetState(GUARD2_IDLE);
		return;
	}

	if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) < 50 )
	{
		if (Aladdin::GetInstance()->GetAladdinHP() > 0)
		{
			Sound::GetInstance()->PlaySound(this->guard2->GetSoundGuardHit());
			anim->Reset();
			this->SetState(GUARD2_HIT);
		}
		return;
	}
}

void Guard2State::stateHit()
{
	this->guard2->SetSpeedX(0);
	this->guard2->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = guard2->GetAnimationsList()[GUARD2_HIT];

	if (abs(Aladdin::GetInstance()->GetPositionY() - this->guard2->GetPositionY()) > 50 
		|| abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) > 200)
	{
		anim->Reset();
		this->SetState(GUARD2_IDLE);
		return;
	}
	if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) >= 50 
		&& abs(Aladdin::GetInstance()->GetPositionX() - this->guard2->GetPositionX()) <= 200)
	{
		anim->Reset();
		this->SetState(GUARD2_WALK);
		return;
	}

	if (anim->IsDone())
	{
		this->guard2->SetAttacking(true);
		anim->Reset();
		this->SetState(GUARD2_IDLE);
		return;
	}
}

void Guard2State::stateDead() 
{
	this->guard2->SetSpeedX(0); 
	this->guard2->SetAttacking(false);
	this->guard2->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = guard2->GetAnimationsList()[GUARD2_DEAD];

	if (this->guard2->GetEnemiesDeadEffect()->GetHidden())
	{
		this->guard2->SetDie(true);
		Grid::GetInstance()->SetisLifeListObject(this->guard2->GetID(), false);
		return;
	}
}

void Guard2State::Colision()
{

}

void Guard2State::Update(DWORD dt)
{

	switch (stateGuard2)
	{

	case GUARD2_IDLE:
		this->stateIdle();
		break;

	case GUARD2_HURT:
		this->stateHurting();
		break;

	case GUARD2_WALK:
		this->stateWalking();
		break;

	case GUARD2_HIT:
		this->stateHit();
		break;

	case GUARD2_DEAD:
		this->stateDead();
		break;

	default:
		break;
	}


	this->timeCount += dt;
}

void Guard2State::Render()
{
	SpriteData spriteData;
	if (this->guard2 != NULL)
	{
		spriteData.width = GUARD2_SPRITE_WIDTH;
		spriteData.height = GUARD2_SPRITE_HEIGHT;
		spriteData.x = guard2->GetPositionX();
		spriteData.y = guard2->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = guard2->IsLeft();
		spriteData.isFlipped = guard2->IsFlipped();
	}

	anim->Render(spriteData);
}

Guard2State::~Guard2State()
{
	delete anim;
}