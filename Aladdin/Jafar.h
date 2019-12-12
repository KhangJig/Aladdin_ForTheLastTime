#pragma once
#include "GameObject.h"
#include "Debug.h"
#include "Constants.h"
#include "Game.h"
#include "State.h"
#include "JafarState.h"

class JafarState;
class Jafar : public GameObject
{
	JafarState *state;

	static vector<Animation *> animations;

	int x, y;

	int HP;
	int Dmg;

public:

	Jafar(int x, int y);

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetX() { return x; }
	int GetY() { return y; }
	void SetHP(int hp) { this->HP = hp; }
	int GetHP() { return this->HP; }
	void SetDmg(int dmg) { this->Dmg = dmg; }
	int GetDmg() { return this->Dmg; }

	static void LoadResources();

	vector<Animation *> GetAnimationsList() { return animations; }

	void Update(DWORD dt) override;

	void Render() override;

	void OnCollision();

	~Jafar();
};