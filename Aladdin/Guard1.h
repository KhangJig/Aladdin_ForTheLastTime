#pragma once
#include "Debug.h"
#include "GameObject.h"
#include "Constants.h"
#include "Game.h"
#include "SpawnProjectTile.h"
#include "State.h"
#include "Guard1State.h"

class Guard1State;
class Guard1 : public GameObject
{
	Guard1();

	static Guard1 *__instance;

	Guard1State *state;

	static vector<Animation *> animations;

	DWORD lastFrameTime;

	int CellID;

	int Guard1HP;

	int Guard1Dmg;

	bool Attacking;

	bool Dead;

public:
	Guard1(float x, float y, int CellID);
	static void LoadResources();

	bool isOnGround = false;

	float posx, posy;

	int GetGuard1HP() { return this->Guard1HP; }
	int GetGuard1DmgAttack() { return this->Guard1Dmg; }

	void SetGuard1HP(int hp) { this->Guard1HP = hp; }
	void SetGuard1DmgAttack(int dmg) { this->Guard1Dmg = dmg; }

	static Guard1 *GetInstance();

	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }

	void SetColliderDemension(float width, float height)
	{
		this->collider.width = width;
		this->collider.height = height;
	}

	bool GetAttacking() { return this->Attacking; }

	void SetAttacking(bool attack) { this->Attacking = attack; }

	bool GetDie() { return this->Dead; }

	void SetDie(bool die) { this->Dead = die; }

	int GetCellID() { return this->CellID; }

	vector<Animation *> GetAnimationsList() { return animations; }

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;

	void OnCollision();
};