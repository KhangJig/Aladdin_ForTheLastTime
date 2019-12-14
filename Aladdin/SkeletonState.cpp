#include "SkeletonState.h"
#include <math.h>

SkeletonState * SkeletonState::__instance = NULL;

SkeletonState *SkeletonState::GetInstance(Skeleton *skeleton)
{
	if (__instance == NULL)
		__instance = new SkeletonState(skeleton);
	return __instance;
}

SkeletonState::SkeletonState(Skeleton *skeleton)
{
	this->skeleton = skeleton;
	this->stateSkeleton = SKELETON_IDLE;
}

StateSkeleton SkeletonState::GetState()
{
	return this->stateSkeleton;
}

void SkeletonState::SetState(StateSkeleton state)
{
	this->stateSkeleton = state;
}

void SkeletonState::stateIdle() 
{
	anim = skeleton->GetAnimationsList()[SKELETON_IDLE];
	this->skeleton->SetSpeedX(0);
	this->skeleton->SetSpeedY(0);

	if (abs(Aladdin::GetInstance()->GetPositionY() - this->skeleton->GetPositionY()) <= 50)
	{
		if (abs(Aladdin::GetInstance()->GetPositionX() - this->skeleton->GetPositionX()) <= 120)
		{
			this->SetState(SKELETON_STAND);
			return;
		}
	}
}

void SkeletonState::stateStand()
{
	anim = skeleton->GetAnimationsList()[SKELETON_STAND];

	if (this->anim->IsDone())
	{
		this->SetState(SKELETON_BOOM);
		return;
	}
}

void SkeletonState::stateBoom()
{
	anim = skeleton->GetAnimationsList()[SKELETON_BOOM];
	if (this->anim->IsDone())
	{
		this->SetState(SKELETON_DEAD);
		return;
	}
}

void SkeletonState::stateDead()
{
	anim = skeleton->GetAnimationsList()[SKELETON_DEAD];

	if (this->skeleton->GetEnemiesDeadEffect()->GetHidden())
	{
		Grid::GetInstance()->SetisLifeListObject(this->skeleton->GetID(), false);
		return;
	}
}

void SkeletonState::Colision()
{

}

void SkeletonState::Update(DWORD dt)
{

	switch (stateSkeleton)
	{

	case SKELETON_IDLE:
		this->stateIdle();
		break;

	case SKELETON_STAND:
		this->stateStand();
		break;

	case SKELETON_BOOM:
		this->stateBoom();
		break;

	case SKELETON_DEAD:
		this->stateDead();
		break;

	default:
		break;
	}


	this->timeCount += dt;
}

void SkeletonState::Render()
{
	SpriteData spriteData;
	if (this->skeleton != NULL)
	{
		spriteData.width = SKELETON_SPRITE_WIDTH;
		spriteData.height = SKELETON_SPRITE_HEIGHT;
		spriteData.x = skeleton->GetPositionX();
		spriteData.y = skeleton->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = false;
		spriteData.isFlipped = false;
	}

	anim->Render(spriteData);
}

SkeletonState::~SkeletonState()
{
	delete anim;
}