#pragma once
#include "Debug.h"
#include "GameObject.h"
#include "Constants.h"
#include "Game.h"
#include "SpawnProjectTile.h"
#include "State.h"
#include "Guard1State.h"
#include "EnemiesDeadEffect.h"

class Guard1State;
class Guard1 : public GameObject
{
	Guard1();

	Guard1State *state;

	static vector<Animation *> animations;

	EnemiesDeadEffect *enemiesDeadEffect;

	DWORD lastFrameTime;

	int CellID;

	int Guard1HP;

	int Guard1Dmg;

	bool Attacking;

	bool Dead;

	int id;

public:
	Guard1(float x, float y, int CellID, int temp);

	static void LoadResources();

	bool isOnGround = false;

	float posx, posy;

#pragma region	GET/SET
	int GetGuard1HP() { return this->Guard1HP; }
	int GetGuard1DmgAttack() { return this->Guard1Dmg; }
	int GetID() { return this->id; }
	void SetGuard1HP(int hp) { this->Guard1HP = hp; }
	void SetGuard1DmgAttack(int dmg) { this->Guard1Dmg = dmg; }
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
#pragma endregion

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;

	void OnCollision();
};