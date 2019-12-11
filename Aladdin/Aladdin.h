#pragma once
#include "GameObject.h"
#include "AladdinState.h"
#include "Constants.h"
#include "Game.h"
#include "State.h"
#include "Apple.h"

class AladdinState;
class Aladdin : public GameObject
{
	Aladdin();

	static Aladdin *__instance;
	State  *stateApple;
	AladdinState *state;

	Apple *apple;

	bool isGrounded = false;
	static vector<Animation *> animations;
	DWORD lastFrameTime;

	bool bImortal;
	float timeCount;
	bool trueImortal;
	bool isApple;

	int posXAladdinThrowing;
	int posYAladdinThrowing;

	int AladdinHP;
	int AppleNumber;

	int DmgAttack;
	bool Attacking;

public:
	void LoadResources();

	static Aladdin *GetInstance();

	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetIsGrounded(bool isGrounded) { this->isGrounded = isGrounded; }
	bool GetIsGrounded() { return isGrounded; }

	void SetPosAladdinThrowing(int x, int y) {
		this->posXAladdinThrowing = x;
		this->posYAladdinThrowing = y;
	}

	int GetPosXAladdinThrowing() { return this->posXAladdinThrowing; }
	int GetPosYAladdinThrowing() { return this->posYAladdinThrowing; }
	bool GetAttacking() { return this->Attacking; }
	void SetAttacking(bool isAttack) { this->Attacking = isAttack; }
	int GetAppleNumber() { return this->AppleNumber; }
	void SetAppleNumber(int num) { this->AppleNumber = num; }

	void SetIsApple(bool isApple) { this->isApple = isApple; }
	bool GetisApple() { return isApple; }

	void SetColliderDemension(float width, float height)
	{
		this->collider.width = width;
		this->collider.height = height;
	}

	int GetAladdinHP() { return this->AladdinHP; }
	int GetDmgAttack() { return this->DmgAttack; }

	void SetAladdinHP(int hp) { this->AladdinHP = hp; }
	void SetDmgAttack(int dmg) { this->DmgAttack = dmg; }

	void Reset();

	vector<Animation *> GetAnimationsList() { return animations; }

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;
};