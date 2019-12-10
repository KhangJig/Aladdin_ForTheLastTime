#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>
#include "Sprite.h"
#include "Graphics.h"
using namespace std;

class Animation
{
	DWORD lastFrameTime;
	DWORD defaultDelayTime;

	vector< pair<Sprite *, DWORD> > frames;
	int curFrame;
	bool done = false;
	bool isSetCurentFrame = false;
	bool isAniRunning = false;
	bool isDoubleHit = false;

public:
	Animation(DWORD defaultDelayTime) { this->defaultDelayTime = defaultDelayTime; };

	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }

	DWORD GetLastFrameTime() { return this->lastFrameTime; }

	void SetCurFrame(int frame) { this->curFrame = frame; }

	int GetCurFrame() {return  this->curFrame; }

	void isSetFrame(bool isSet) { this->isSetCurentFrame = isSet; }

	void isSetAniRunning(bool isSetRunning) { this->isAniRunning = isSetRunning; }

	void isSetDoubleHit(bool isDoubleHit) { this->isDoubleHit = isDoubleHit; }

	//int GetCurFrame() { isSetCurentFrame = true; return curFrame; }

	bool IsDone() { return done; }

	void SetIsDone(bool done) { this->done = done; }

	void Reset() { curFrame = -1; }

	void AddFrame(Sprite *sprite, DWORD time = 0);

	void Render(SpriteData spriteData);
};

