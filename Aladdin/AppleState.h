#pragma once
//#include "Constants.h"
//#include "Debug.h"
//#include "State.h"
//#include "Apple.h"
//
//enum StateApple
//{
//	NONE,
//	APPLE_IS_FLYING,
//	APPLE_IS_BOOM,
//};
//
//class AppleState : public State
//{
//protected:
//	static AppleState * __instance;
//	StateApple stateApple;
//	Apple *apple;
//	Animation * anim;
//	RECT* listSprite;
//
//public:
//	float timeCount;
//	AppleState(Apple *apple);
//	~AppleState();
//
//	static AppleState * GetInstance(Apple *apple);
//
//	StateApple GetState();
//
//	void SetState(StateApple State);
//
//	void stateNone();
//	void stateFlying();
//	void stateBoom();
//
//	void Colision() override;
//	void Update(DWORD dt) override;
//	void Render() override;
//};
