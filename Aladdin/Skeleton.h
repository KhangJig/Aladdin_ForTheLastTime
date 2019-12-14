#pragma once
#include "Debug.h"
#include "GameObject.h"
#include "Constants.h"
#include "Sound.h"
#include "Game.h"
#include "SpawnProjectTile.h"
#include "State.h"
#include "SkeletonState.h"
#include "EnemiesDeadEffect.h"

class SkeletonState;
class Skeleton : public GameObject
{
	Skeleton();

	SkeletonState *state;

	static vector<Animation *> animations;

	EnemiesDeadEffect *enemiesDeadEffect;

	DWORD lastFrameTime;

	int CellID;

	int SkeletonHP;

	int id;

	GSound *skeletonFire;

	GSound *skeletonBoom;

	GSound *fireAndBoom;

public:
	Skeleton(float x, float y, int CellID, int temp);

	static void LoadResources();

#pragma region	GET/SET
	int GetSkeletonHP() { return this->SkeletonHP; }
	int GetID() { return this->id; }
	void SetSkeletonHP(int hp) { this->SkeletonHP = hp; }
	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetColliderDemension(float width, float height) { this->collider.width = width; this->collider.height = height; }
	vector<Animation *> GetAnimationsList() { return animations; }
	int GetCellID() { return this->CellID; }
	EnemiesDeadEffect *GetEnemiesDeadEffect() { return this->enemiesDeadEffect; }
	GSound *GetSoundSkeletonFire() { return this->skeletonFire; }
	GSound *GetSoundSkeletonBoom() { return this->skeletonBoom; }
	GSound *GetSoundSkeletonFirenBoom() { return this->fireAndBoom; }
#pragma endregion

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;

	void OnCollision();
};