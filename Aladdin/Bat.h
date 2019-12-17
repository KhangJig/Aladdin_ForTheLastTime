#pragma once
#include "Debug.h"
#include "GameObject.h"
#include "Constants.h"
#include "Sound.h"
#include "Game.h"
#include "SpawnProjectTile.h"
#include "State.h"
#include "BatState.h"
#include "EnemiesDeadEffect.h"

class BatState;
class Bat : public GameObject
{
	Bat();

	BatState *state;

	static vector<Animation *> animations;

	EnemiesDeadEffect *enemiesDeadEffect;

	DWORD lastFrameTime;

	int CellID;

	int BatHP;

	int Dmg;

	int id;

	float timeStop;

	bool ReadyAttack;

public:
	Bat(float x, float y, int CellID, int temp);

	static void LoadResources();

#pragma region	GET/SET
	int GetBatHP() { return this->BatHP; }
	int GetID() { return this->id; }
	void SetBatHP(int hp) { this->BatHP = hp; }
	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetColliderDemension(float width, float height) { this->collider.width = width; this->collider.height = height; }
	vector<Animation *> GetAnimationsList() { return animations; }
	int GetCellID() { return this->CellID; }
	int GetDmg() { return this->Dmg; }
	void SetDmg(int num) { this->Dmg = num; }
	bool GetReadyAttack() { return this->ReadyAttack; }
	void SetReadyAttack(bool value) { this->ReadyAttack = value; }
	EnemiesDeadEffect *GetEnemiesDeadEffect() { return this->enemiesDeadEffect; }
#pragma endregion

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;

	void OnCollision();
};