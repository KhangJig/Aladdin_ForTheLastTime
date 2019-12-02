#include "AladdinState.h"
#include <math.h>

AladdinState *AladdinState::__instance = NULL;

AladdinState *AladdinState::GetInstance(Aladdin *aladdin)
{
	if (__instance == NULL)
		__instance = new AladdinState(aladdin);
	return __instance;
}

AladdinState::AladdinState(Aladdin *aladdin)
{
	this->aladdin = aladdin;
	this->stateAladdin = STATE_FALL;
	this->aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	this->startJumpY = 95;
}

StateAladdin AladdinState::GetState()
{
	return this->stateAladdin;
}

void AladdinState::SetState(StateAladdin state)
{	
	this->stateAladdin = state;
}


void AladdinState::stateStanding()
{
	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT) && (!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT)))
	{
		startJumpY = aladdin->GetPositionY();
		aladdin->SetSpeedY(ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_STAND_JUMP);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) || Keyboard::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		this->SetState(STATE_RUN);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_UP))
	{
		this->SetState(STATE_HEAD_UP);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		this->SetState(STATE_SIT);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		this->SetState(STATE_STAND_HIT);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_STAND_THROW);
			aladdin->SetIsApple(false);
			return;
		}

		//this->SetState(STATE_STAND_THROW);
		//return;
	}

	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[IDLE_STAND];
}

// con xu ly tiep
void AladdinState::stateHeadUp()
{
	if (Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) || Keyboard::GetInstance()->IsKeyDown(DIK_LEFT) ||
		Keyboard::GetInstance()->IsKeyDown(DIK_DOWN) || !Keyboard::GetInstance()->IsKeyDown(DIK_UP))
	{
		this->SetState(IDLE_STAND);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE) && Keyboard::GetInstance()->IsKeyDown(DIK_UP))
	{
		this->SetState(STATE_DOUBLE_HIT);
		return;
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT))
	{
		this->SetState(STATE_STAND_JUMP);
		return;
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_STAND_THROW);
			aladdin->SetIsApple(false);
			return;
		}

		//this->SetState(STATE_STAND_THROW);
		//return;
	}

	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_HEAD_UP];

	if (anim->IsDone())
	{
		anim->SetCurFrame(2);
	}
}

// con xu ly tiep
void AladdinState::stateWalking()
{

	if (!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		anim->Reset();
		anim->isSetAniRunning(false);
		this->SetState(IDLE_STAND);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT))
	{
		anim->Reset();
		startJumpY = aladdin->GetPositionY();
		aladdin->SetSpeedY(ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_RUN_JUMP);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		this->SetState(STATE_RUN_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_RUN_THROW);
			aladdin->SetIsApple(false);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}

		//this->SetState(STATE_JUMP_THROW);
		//anim->isSetFrame(false);
		//anim->Reset();
		//return;
	}

	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_RUN];

	if (anim->IsDone())
	{
		anim->isSetAniRunning(true);
		anim->SetCurFrame(2);
	}
}

// con xu ly tiep
void AladdinState::stateJumping()
{
	if ((!Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT)) || (this->startJumpY != NULL && (int)(aladdin->GetPositionY() - this->startJumpY) >= ALADDIN_JUMP_MAX))
	{
		aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		anim->Reset();
		this->SetState(STATE_FALL);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		this->SetState(STATE_JUMP_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_JUMP_THROW);
			aladdin->SetIsApple(false);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}

		//this->SetState(STATE_JUMP_THROW);
		//anim->isSetFrame(false);
		//anim->Reset();
		//return;
	}

	anim = aladdin->GetAnimationsList()[STATE_STAND_JUMP];

	if (anim->IsDone())
	{
		this->SetState(STATE_FALL);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}
}

// con xu ly tiep
void AladdinState::stateFalling()
{
	if ((int)aladdin->GetPositionY() == (int)this->startJumpY)
	{
		this->SetState(STATE_TOUCH_GROUND);
		anim->Reset();
		return;
	}
	else
	{
		aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		anim = aladdin->GetAnimationsList()[STATE_FALL];
	}
}

void AladdinState::stateTouchGround()
{
	anim = aladdin->GetAnimationsList()[STATE_TOUCH_GROUND];
	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(IDLE_STAND);
		return;
	}
}

void AladdinState::stateSitting()
{
	if (!Keyboard::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		this->SetState(IDLE_STAND);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT))
	{
		this->SetState(STATE_STAND_JUMP);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_SIT_THROW);
			aladdin->SetIsApple(false);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}

		//this->SetState(STATE_SIT_THROW);
		//anim->isSetFrame(false);
		//anim->Reset();
		//return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		this->SetState(STATE_SIT_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_UP))
	{
		this->SetState(STATE_HEAD_UP);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_SIT];

	if (anim->IsDone())
	{
		this->SetState(IDLE_SIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}
}

void AladdinState::stateSittingIdle()
{
	if (!Keyboard::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		this->SetState(IDLE_STAND);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT))
	{
		this->SetState(STATE_STAND_JUMP);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_SIT_THROW);
			aladdin->SetIsApple(false);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}

		//this->SetState(STATE_SIT_THROW);
		//anim->isSetFrame(false);
		//anim->Reset();
		//return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		this->SetState(STATE_SIT_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_UP))
	{
		this->SetState(STATE_HEAD_UP);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[IDLE_SIT];
}

void AladdinState::stateStandHit()
{
	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_STAND_HIT];

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(IDLE_STAND);
		return;
	}
}

void AladdinState::stateStandThrow()
{
	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_STAND_THROW];

	if (anim->IsDone())
	{
		if (!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT))
		{
			anim->Reset();
			this->SetState(IDLE_STAND);
			return;
		}
		else
		{
			anim->Reset();
			this->SetState(STATE_RUN);
			return;
		}

	}
}

void AladdinState::stateSitHit()
{
	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_SIT_HIT];

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(IDLE_SIT);
		return;
	}
}

void AladdinState::stateSitThrow()
{
	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_SIT_THROW];

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(IDLE_SIT);
		return;
	}
}

void AladdinState::stateRunJump()
{
	anim = aladdin->GetAnimationsList()[STATE_RUN_JUMP];
	if (anim->IsDone())
	{
		anim->SetCurFrame(2);
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		this->SetState(STATE_JUMP_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_JUMP_THROW);
			aladdin->SetIsApple(false);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}

		//this->SetState(STATE_JUMP_THROW);
		//anim->isSetFrame(false);
		//anim->Reset();
		//return;
	}

	if ((!Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT)) || (this->startJumpY != NULL && (int)(aladdin->GetPositionY() - this->startJumpY) >= ALADDIN_JUMP_MAX + 8))
	{
		aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_FALL_2);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}
}

void AladdinState::stateFall2()
{
	anim = aladdin->GetAnimationsList()[STATE_FALL_2];
	if (anim->IsDone()) 
	{
		anim->SetCurFrame(2);
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		this->SetState(STATE_JUMP_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple())
		{
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_JUMP_THROW);
			aladdin->SetIsApple(false);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}

		//this->SetState(STATE_JUMP_THROW);
		//anim->isSetFrame(false);
		//anim->Reset();
		//return;
	}

	if ((!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT)) && ((int)aladdin->GetPositionY() == (int)this->startJumpY))
	{
		this->SetState(STATE_TOUCH_GROUND);
		aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}
	else
	{
		if ((int)aladdin->GetPositionY() == (int)this->startJumpY)
		{
			this->SetState(IDLE_STAND);
			aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}
	}
}

void AladdinState::stateJumpHit()
{
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_JUMP_HIT];

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(STATE_FALL_2);
		return;
	}
}

void AladdinState::stateJumpThrow()
{
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_JUMP_THROW];

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(STATE_FALL_2);
		return;
	}
}

void AladdinState::stateDoubleHit()
{
	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_DOUBLE_HIT];

	anim->isSetDoubleHit(true);

	if (anim->IsDone())
	{
		anim->Reset();
		anim->isSetDoubleHit(false);
		this->SetState(IDLE_STAND);
		return;
	}
}

// con xu ly tiep
void AladdinState::stateRunHit()
{
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_RUN_HIT];

	if (anim->IsDone())
	{
		if (!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT))
		{
			anim->Reset();
			anim->isSetAniRunning(false);
			this->SetState(IDLE_STAND);
			return;
		}
		else {
			anim->Reset();
			this->SetState(STATE_RUN);
			return;
		}
	}
}

// con xu ly tiep
void AladdinState::stateRunThrow()
{
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_RUN_THROW];

	if (anim->IsDone())
	{
		if (!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT))
		{
			anim->Reset();
			anim->isSetAniRunning(false);
			this->SetState(IDLE_STAND);
			return;
		}
		else {
			anim->Reset();
			this->SetState(STATE_RUN);
			return;
		}
	}
}

void AladdinState::KeyHandle()
{
}

void AladdinState::Colision()
{
	if (!aladdin->GetIsGrounded())
	{
		if (this->GetState() == STATE_FALL)
		{
			this->stateFalling();
		}
		else if (this->GetState() == STATE_FALL_2)
		{
			this->stateFall2();
		}
	}
	else
	{
		if (this->GetState() == STATE_FALL || this->GetState() == STATE_FALL_2)
		{
			if (aladdin->GetSpeedY() < 0)
			{
				this->SetState(IDLE_STAND);
				this->stateStanding();
			}
		}

	}

	aladdin->SetIsGrounded(false);
}

void AladdinState::Update(DWORD dt)
{
	timeCount += dt;
	//Kiểm tra tốc độ trục X
	if (Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		aladdin->setIsLeft(false);
		aladdin->SetSpeedX(ALADDIN_WALK_SPEED * (aladdin->IsLeft() ? -1 : 1));
	}
	else if (Keyboard::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		aladdin->setIsLeft(true);
		aladdin->SetSpeedX(ALADDIN_WALK_SPEED * (aladdin->IsLeft() ? -1 : 1));
	}
	else
		aladdin->SetSpeedX(0);

	if (aladdin->GetPositionX() < 10)
		aladdin->SetPositionX(10);

	switch (stateAladdin)
	{
	case IDLE_STAND:
		this->stateStanding();
		break;

	case STATE_HEAD_UP:
		this->stateHeadUp();
		break;

	case STATE_RUN:
		this->stateWalking();
		break;

	case STATE_STAND_JUMP:
		this->stateJumping();
		break;

	case STATE_FALL:
		this->stateFalling();
		break;

	case STATE_TOUCH_GROUND:
		this->stateTouchGround();
		break;

	case STATE_SIT:
		this->stateSitting();
		break;

	case IDLE_SIT:
		this->stateSittingIdle();
		break;

	case STATE_STAND_HIT:
		this->stateStandHit();
		break;

	case STATE_STAND_THROW:
		this->stateStandThrow();
		break;

	case STATE_SIT_HIT:
		this->stateSitHit();
		break;

	case STATE_SIT_THROW:
		this->stateSitThrow();
		break;

	case STATE_RUN_JUMP:
		this->stateRunJump();
		break;

	case STATE_FALL_2:
		this->stateFall2();
		break;

	case STATE_JUMP_HIT:
		this->stateJumpHit();
		break;

	case STATE_JUMP_THROW:
		this->stateJumpThrow();
		break;

	case STATE_DOUBLE_HIT:
		this->stateDoubleHit();
		break;

	case STATE_RUN_HIT:
		this->stateRunHit();
		break;

	case STATE_RUN_THROW:
		this->stateRunThrow();
		break;

	default:
		break;
	}
}

void AladdinState::Render()
{
	SpriteData spriteData;
	if (this->aladdin != NULL)
	{
		spriteData.width = ALADDIN_SPRITE_WIDTH;
		spriteData.height = ALADDIN_SPRITE_HEIGHT;
		spriteData.x = aladdin->GetPositionX();
		spriteData.y = aladdin->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = aladdin->IsLeft();
		spriteData.isFlipped = !aladdin->IsFlipped();
	}

	anim->Render(spriteData);
}

AladdinState::~AladdinState()
{
	delete anim;
	delete listSprite;
}
