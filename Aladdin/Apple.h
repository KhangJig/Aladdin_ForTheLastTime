#pragma once
//#include "GameObject.h"
//#include "Debug.h"
//#include "AppleState.h"
//
//class Apple : public GameObject
//{
//	Apple();
//
//	static Apple *__instance;
//	State *state;
//
//	bool isGrounded = false;
//	static vector<Animation *> animations;
//	DWORD lastFrameTime;
//
//	bool bImortal;
//	float timeCount;
//	bool trueImortal;
//
//public:
//
//
//	void LoadResources();
//	static Apple *GetInstance();
//
//	DWORD GetLastFrameTime() { return this->lastFrameTime; }
//	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
//
//	void SetColliderDemension(float width, float height)
//	{
//		this->collider.width = width;
//		this->collider.height = height;
//	}
//
//	vector<Animation *> GetAnimationsList() { return animations; }
//
//	void Update(DWORD dt) override;
//
//	//void UpdateCollision(DWORD dt);
//
//	void Render() override;
//
//	~Apple();
//};
//
