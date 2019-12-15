#pragma once
#include "GameObject.h"
#include "AladdinState.h"
#include "Constants.h"
#include "Sound.h"
#include "Game.h"
#include "State.h"
#include "Apple.h"
#include "ItemEffect.h"
#include "HP.h"
#include "AppleMenu.h"
#include "DiamondMenu.h"
#include "LifeMenu.h"
#include "Score.h"

class AladdinState;
class Aladdin : public GameObject
{
	Aladdin();

	static Aladdin *__instance;

	State  *stateApple;

	AladdinState *state;

	Apple *apple;

	ItemEffect *itemEffect;

	GSound* theme1;
	GSound* theme2;

	GSound* aladdinHurt;
	GSound* aladdinOof;
	GSound* aladdinPush;
	GSound* bodyCrunch;
	GSound* bonesTinkle;
	GSound* boxingBell;
	GSound* cashRegister;

	GSound* appleCollect;
	GSound* gemCollect;

	GSound* highSword;
	GSound* lowSword;
	GSound* throwApple;

	bool isGrounded = false;
	bool isClimb = false;
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
	int DiamondNumber;
	int LifeNumber;
	int ScoreNumber;

	int DmgAttack;
	bool Attacking;

	bool JumpOnBrick;
	bool OnBrick;
	bool JumpOnRope;
	bool OnCollisonRope;
	bool OnTopRope;
	bool OnBotRope;

	int GeneratePosX;
	int GeneratePosY;
	int GeneratePosCameraX;
	int GeneratePosCameraY;

	int LV;

public:
	void LoadResources();

	static Aladdin *GetInstance();

	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetIsGrounded(bool isGrounded) { this->isGrounded = isGrounded; }
	bool GetIsGrounded() { return isGrounded; }
	void SetIsClimb(bool isClimb) { this->isClimb = isClimb; }
	bool GetIsClimb() { return this->isClimb; }

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
	int GetDiamondNumber() { return this->DiamondNumber; }
	void SetDiamondNumber(int num) { this->DiamondNumber = num; }
	bool GetJumpOnBrick() { return this->JumpOnBrick; }
	void SetJumpOnBrick(bool value) { this->JumpOnBrick = value; }
	bool GetOnBrick() { return this->OnBrick; }
	void SetOnBrick(bool value) { this->OnBrick = value; }
	int GetLifeNumber() { return this->LifeNumber; }
	void SetLifeNumber(int num) { this->LifeNumber = num; }
	int GetLV() { return this->LV; }
	void SetLV(int num) { this->LV = num; }
	bool GetJumpOnRope() { return this->JumpOnRope; }
	void SetJumpOnRope(bool value) { this->JumpOnRope = value; }
	bool GetOnCollisonRope() { return this->OnCollisonRope; }
	void SetOnCollisonRope(bool value) { this->OnCollisonRope = value; }
	bool GetOnTopRope() { return this->OnTopRope; }
	void SetOnTopRope(bool value) { this->OnTopRope = value; }
	bool GetOnBotRope() { return this->OnBotRope; }
	void SetOnBotRope(bool value) { this->OnBotRope = value; }
	GSound *GetSoundHighSword() { return this->highSword; }
	GSound *GetSoundLowSword() { return this->lowSword; }
	GSound *GetSoundThrowApple() { return this->throwApple; }

	void SetIsApple(bool isApple) { this->isApple = isApple; }
	bool GetisApple() { return isApple; }

	void SetColliderDemension(float width, float height)
	{
		this->collider.width = width;
		this->collider.height = height;
	}

	int GetAladdinHP() { return this->AladdinHP; }
	int GetDmgAttack() { return this->DmgAttack; }

	int GetScoreNumber() { return this->ScoreNumber; }
	void SetScoreNumber(int num) { this->ScoreNumber = num; }

	void ResetHP() { this->AladdinHP = ALADDIN_DEFAULT_HP; }
	void ResetSettings() 
	{
		this->Attacking = false;
		this->JumpOnBrick = false;
		this->JumpOnRope = false;
		this->OnCollisonRope = false;
		this->OnTopRope = false;
		this->OnBotRope = false;
		this->isApple = false;
	}

	void ResetPosisionAladdin() { this->x = this->GeneratePosX; this->y = this->GeneratePosY; }
	void ResetPosisionCamera() { Viewport::GetInstance()->ResetPosision(this->GeneratePosCameraX, this->GeneratePosCameraY); }

	void SetAladdinHP(int hp) { this->AladdinHP = hp; }
	void SetDmgAttack(int dmg) { this->DmgAttack = dmg; }

	void SetState(AladdinState *state) { this->state = state; }
	AladdinState *GetState() { return this->state; }

	void Reset();

	vector<Animation *> GetAnimationsList() { return animations; }

	void Update(DWORD dt) override;

	void UpdateCollision(DWORD dt);

	void Render() override;
};