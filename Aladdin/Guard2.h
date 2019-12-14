#pragma once
#include "Debug.h"
#include "GameObject.h"
#include "Constants.h"
#include "Sound.h"
#include "Game.h"
#include "SpawnProjectTile.h"
#include "State.h"
#include "Guard2State.h"
#include "EnemiesDeadEffect.h"

class Guard2State;
class Guard2 : public GameObject
{
	Guard2();

	Guard2State *state;

	static vector<Animation *> animations;

	EnemiesDeadEffect *enemiesDeadEffect;

	GSound *guardHit;

	GSound *guardHurt;

	GSound *headBop;

	DWORD lastFrameTime;

	int CellID;

	int Guard2HP;

	int Guard2Dmg;

	bool Attacking;

	bool Dead;

	int id;

public:
	Guard2(float x, float y, int CellID, int temp);

	static void LoadResources();

	bool isOnGround = false;

	float posx, posy;

#pragma region	GET/SET
	int GetGuard2HP() { return this->Guard2HP; }
	int GetGuard2DmgAttack() { return this->Guard2Dmg; }
	int GetID() { return this->id; }
	void SetGuard2HP(int hp) { this->Guard2HP = hp; }
	void SetGuard2DmgAttack(int dmg) { this->Guard2Dmg = dmg; }
	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetColliderDemension(float width, float height) { this->collider.width = width; this->collider.height = height; }
	vector<Animation *> GetAnimationsList() { return animations; }
	bool GetAttacking() { return this->Attacking; }
	void SetAttacking(bool attack) { this->Attacking = attack; }
	bool GetDie() { return this->Dead; }
	void SetDie(bool die) { this->Dead = die; }
	int GetCellID() { return this->CellID; }
	EnemiesDeadEffect *GetEnemiesDeadEffect() { return this->enemiesDeadEffect; }
	GSound *GetSoundGuardHit() { return this->guardHit; }
#pragma endregion

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;

	void OnCollision();
};