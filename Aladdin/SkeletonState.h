#pragma once
#include "Constants.h"
#include "Debug.h"
#include "State.h"
#include "Skeleton.h"

class Skeleton;
enum StateSkeleton
{
	SKELETON_IDLE,
	SKELETON_STAND,
	SKELETON_BOOM,
	SKELETON_DEAD
};

class SkeletonState : public State
{
protected:
	static SkeletonState * __instance;
	StateSkeleton stateSkeleton;
	Skeleton *skeleton;
	Animation * anim;
public:
	float timeCount;

	SkeletonState(Skeleton *skeleton);
	~SkeletonState();

	static SkeletonState * GetInstance(Skeleton *skeleton);

	StateSkeleton GetState();
	void SetState(StateSkeleton State);

	void stateIdle();
	void stateStand();
	void stateBoom();
	void stateDead();

	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;
};
