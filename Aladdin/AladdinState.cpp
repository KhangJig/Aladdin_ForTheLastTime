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
		this->aladdin->SetJumpOnBrick(true);
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
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
		aladdin->SetAttacking(true);
		this->SetState(STATE_STAND_HIT);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_STAND_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			return;
		}
	}

	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[IDLE_STAND];
}

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
		aladdin->SetAttacking(true);
		this->SetState(STATE_DOUBLE_HIT);
		return;
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT))
	{
		this->aladdin->SetJumpOnBrick(true);
		this->SetState(STATE_STAND_JUMP);
		return;
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_STAND_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			return;
		}
	}

	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_HEAD_UP];

	if (anim->IsDone())
	{
		anim->SetCurFrame(2);
	}
}

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
		this->aladdin->SetJumpOnBrick(true);
		startJumpY = aladdin->GetPositionY();
		aladdin->SetSpeedY(ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_RUN_JUMP);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
		aladdin->SetAttacking(true);
		this->SetState(STATE_RUN_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_RUN_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}
	}

	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_RUN];

	if (anim->IsDone())
	{
		anim->isSetAniRunning(true);
		anim->SetCurFrame(2);
	}
}

void AladdinState::stateJumping()
{
	if ((!Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT)) || (this->startJumpY != NULL && (int)(aladdin->GetPositionY() - this->startJumpY) >= ALADDIN_JUMP_MAX))
	{
		this->aladdin->SetJumpOnBrick(true);
		aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		anim->Reset();
		this->SetState(STATE_FALL);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
		aladdin->SetAttacking(true);
		this->SetState(STATE_JUMP_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_JUMP_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}
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

void AladdinState::stateFalling()
{
	if ((int)aladdin->GetPositionY() == (int)this->startJumpY)
	{
		this->SetState(IDLE_STAND);
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
		this->aladdin->SetJumpOnBrick(true);
		this->SetState(STATE_STAND_JUMP);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_SIT_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundLowSword());
		aladdin->SetAttacking(true);
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
		this->aladdin->SetJumpOnBrick(true);
		this->SetState(STATE_STAND_JUMP);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_SIT_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundLowSword());
		aladdin->SetAttacking(true);
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
	aladdin->SetAttacking(false);
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
	aladdin->SetAttacking(false);
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
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
		aladdin->SetAttacking(true);
		this->SetState(STATE_JUMP_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_JUMP_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}
	}

	if ((!Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT)) || (this->startJumpY != NULL && (int)(aladdin->GetPositionY() - this->startJumpY) >= ALADDIN_JUMP_MAX + 8))
	{
		this->aladdin->SetJumpOnBrick(true);
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
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
		aladdin->SetAttacking(true);
		this->SetState(STATE_JUMP_HIT);
		anim->isSetFrame(false);
		anim->Reset();
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_JUMP_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			anim->isSetFrame(false);
			anim->Reset();
			return;
		}
	}

	if ((!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT)) && ((int)aladdin->GetPositionY() == (int)this->startJumpY))
	{
		this->SetState(IDLE_STAND);
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
	aladdin->SetAttacking(false);
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
	Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
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
	aladdin->SetAttacking(true);
}

void AladdinState::stateHurt()
{
	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
	anim = aladdin->GetAnimationsList()[STATE_HURT];

	if (anim->IsDone())
	{
		anim->Reset();
		this->SetState(IDLE_STAND);
		return;
	}
}

// Handling...
void AladdinState::stateClimb()
{
	if (Keyboard::GetInstance()->IsKeyDown(DIK_UP) || Keyboard::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		this->aladdin->SetIsClimb(true);
		this->aladdin->SetJumpOnRope(false);
		this->SetState(STATE_CLIMBING);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT))
	{
		this->aladdin->SetIsClimb(false);
		this->aladdin->SetJumpOnRope(true);
		aladdin->SetSpeedY(ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_CLIMB_JUMP);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
		this->aladdin->SetIsClimb(false);
		this->aladdin->SetJumpOnRope(false);
		aladdin->SetSpeedY(0);
		this->SetState(STATE_CLIMB_HIT);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_CLIMB_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			anim->Reset();
			return;
		}
	}

	if (this->aladdin->GetOnTopRope())
	{
		this->aladdin->SetIsClimb(false);
		this->aladdin->SetJumpOnRope(false);
		aladdin->SetSpeedY(ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_CLIMB_JUMP);
		return;
	}

	if (this->aladdin->GetOnBotRope())
	{
		this->aladdin->SetIsClimb(false);
		this->aladdin->SetJumpOnRope(false);
		aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_FALL);
		return;
	}

	aladdin->SetSpeedY(0);
	aladdin->SetSpeedX(0);
	this->aladdin->SetIsClimb(true);
	this->aladdin->SetJumpOnRope(false);
	startJumpY = aladdin->GetPositionY();
	anim = aladdin->GetAnimationsList()[IDLE_CLIMB];
}

void AladdinState::stateClimbHurt()
{
	anim = aladdin->GetAnimationsList()[STATE_CLIMB_HURT];
}

void AladdinState::stateClimbJump()
{
	if ((int)(aladdin->GetPositionY() - this->startJumpY) >= ALADDIN_JUMP_MAX)
	{
		this->aladdin->SetJumpOnBrick(true);
		anim->Reset();
		aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
		this->SetState(STATE_FALL);
		return;
	}

	anim = aladdin->GetAnimationsList()[STATE_CLIMB_JUMP];
}

void AladdinState::stateClimbFall()
{
	anim = aladdin->GetAnimationsList()[STATE_CLIMB_FALL];
	if (anim->IsDone())
	{
		anim->SetCurFrame(3);
	}
}

void AladdinState::stateClimbing()
{
	if (!Keyboard::GetInstance()->IsKeyDown(DIK_UP) || !Keyboard::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		anim->Reset();
		this->SetState(IDLE_CLIMB);
		return;
	}

	anim = aladdin->GetAnimationsList()[STATE_CLIMBING];
}

void AladdinState::stateClimbHit()
{
	anim = aladdin->GetAnimationsList()[STATE_CLIMBING];
}

void AladdinState::stateClimbThrow()
{
	anim = aladdin->GetAnimationsList()[STATE_CLIMB_THROW];
}
// ...

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
	aladdin->SetAttacking(false);
}

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

void AladdinState::stateStandOnBrick()
{
	if (Keyboard::GetInstance()->IsKeyDown(DIK_LSHIFT) && (!Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT) && !Keyboard::GetInstance()->IsKeyDown(DIK_LEFT)))
	{
		this->aladdin->SetJumpOnBrick(true);
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
		Sound::GetInstance()->PlaySound(this->aladdin->GetSoundHighSword());
		aladdin->SetAttacking(true);
		this->SetState(STATE_STAND_HIT);
		return;
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_Z))
	{
		if (aladdin->GetisApple() && aladdin->GetAppleNumber() > 0)
		{
			Sound::GetInstance()->PlaySound(this->aladdin->GetSoundThrowApple());
			this->aladdin->SetPosAladdinThrowing(this->aladdin->GetPositionX(), this->aladdin->GetPositionY());
			this->SetState(STATE_STAND_THROW);
			aladdin->SetIsApple(false);
			aladdin->SetAppleNumber(aladdin->GetAppleNumber() - 1);
			return;
		}
	}

	aladdin->SetSpeedX(0);
	aladdin->SetSpeedY(0);
	anim = aladdin->GetAnimationsList()[IDLE_STAND];
}

void AladdinState::KeyHandle()
{
}

void AladdinState::Colision()
{
	if (!aladdin->GetIsGrounded())
	{
		if (aladdin->GetIsClimb())
		{
			this->SetState(IDLE_CLIMB);
		}
		else
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
		if (this->GetState() == IDLE_STAND)
		{
			aladdin->SetJumpOnBrick(true);
			this->SetState(STATE_FALL);
			this->stateFalling();
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
	
	if (this->aladdin->GetIsClimb())
	{
		if (this->GetState() == IDLE_CLIMB)
		{
			if (Keyboard::GetInstance()->IsKeyDown(DIK_UP))
			{
				aladdin->SetSpeedY(ALADDIN_JUMP_SPEED_Y);
			}

			if (Keyboard::GetInstance()->IsKeyDown(DIK_DOWN))
			{
				aladdin->SetSpeedY(-ALADDIN_JUMP_SPEED_Y);
			}
		}
	}

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

	case STATE_SIT_THROW:
		this->stateSitThrow();
		break;

	case STATE_SIT_HIT:
		this->stateSitHit();
		break;

	case STATE_RUN_JUMP:
		this->stateRunJump();
		break;

	case STATE_FALL_2:
		this->stateFall2();
		break;

	case STATE_JUMP_THROW:
		this->stateJumpThrow();
		break;

	case STATE_JUMP_HIT:
		this->stateJumpHit();
		break;

	case STATE_DOUBLE_HIT:
		this->stateDoubleHit();
		break;

	case STATE_HURT:
		this->stateHurt();
		break;

	case IDLE_CLIMB:
		this->stateClimb();
		break;

	case STATE_CLIMB_HURT:
		this->stateClimbHurt();
		break;

	case STATE_CLIMB_JUMP:
		this->stateClimbJump();
		break;

	case STATE_CLIMB_FALL:
		this->stateClimbFall();
		break;

	case STATE_CLIMBING:
		this->stateClimbing();
		break;

	case STATE_CLIMB_HIT:
		this->stateClimbHit();
		break;

	case STATE_CLIMB_THROW:
		this->stateClimbThrow();
		break;

	case STATE_RUN_HIT:
		this->stateRunHit();
		break;

	case STATE_RUN_THROW:
		this->stateRunThrow();
		break;

	case STAND_ON_BRICK:
		this->stateStandOnBrick();
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
