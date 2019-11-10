#pragma once
#include "d3d9.h"
#include "Keyboard.h"

class Aladdin;
class State
{
public:
	State();
	virtual void KeyHandle();
	virtual void Colision();
	virtual void Update(DWORD dt);
	virtual void Render();
};