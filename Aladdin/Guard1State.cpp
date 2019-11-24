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
	if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) <= 140 && abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()) == 80)
	{
		anim->Reset();
		this->SetState(GUARD1_WALK);
		return;
	}
	else
	{
		this->guard1->SetSpeedX(0);
		this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		anim = guard1->GetAnimationsList()[GUARD1_IDLE];
		return;
	}
}

void Guard1State::stateHurting()
{
	this->guard1->SetSpeedX(GUARD1_WALK_SPEED);
	this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = guard1->GetAnimationsList()[GUARD1_HURT];
	return;
}

void Guard1State::stateWalking()
{
	if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) <= 30 && abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()) == 80)
	{
		anim->Reset();
		this->SetState(GUARD1_HIT);
		return;
	}
	else
	{
		if (Aladdin::GetInstance()->GetPositionX() <= this->guard1->GetPositionX())
		{
			this->guard1->SetSpeedX(GUARD1_WALK_SPEED);

		}
		else
		{
			this->guard1->SetSpeedX(-GUARD1_WALK_SPEED);
		}

		this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		anim = guard1->GetAnimationsList()[GUARD1_WALK];
		return;
	}
}

void Guard1State::stateHit()
{
	if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) > 30 && abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()) == 80)
	{
		anim->Reset();
		this->SetState(GUARD1_WALK);
		return;
	}
	else
	{
		this->guard1->SetSpeedX(0);
		this->guard1->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		anim = guard1->GetAnimationsList()[GUARD1_HIT];
		return;
	}
}

void Guard1State::Colision()
{

}

void Guard1State::Update(DWORD dt)
{
	//DebugOut(L"Guard %d - %d \n", (int)this->guard1->GetPositionX(), (int)this->guard1->GetPositionY());
	//DebugOut(L"Aladdin %d - %d \n", (int)Aladdin::GetInstance()->GetPositionX(), (int)Aladdin::GetInstance()->GetPositionY());

	DebugOut(L" asdasda - %d    \n", (int)abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()));

	DebugOut(L" nbnmmbm - %d    \n", (int)abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()));
	
	if (abs(Aladdin::GetInstance()->GetPositionY() - this->guard1->GetPositionY()) <= 40)
	{
		DebugOut(L" asdsdadsda- \n");
		if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) <= 140 && abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) >= 30)
		{
			DebugOut(L" GUARD1_WALK \n");
			this->SetState(GUARD1_WALK);
		}
		else if (abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) <= 30 && abs(Aladdin::GetInstance()->GetPositionX() - this->guard1->GetPositionX()) >= 30)
		{
			DebugOut(L" GUARD1_HURT \n");
			this->SetState(GUARD1_HURT);
		}
	}

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
		spriteData.isFlipped = !guard1->IsFlipped();
	}

	anim->Render(spriteData);
}

Guard1State::~Guard1State()
{
	delete anim;
}