#pragma once
#include "GameObject.h"
#include "Debug.h"
#include "Constants.h"
#include "Game.h"
#include "Sound.h"
#include "State.h"
#include "JafarState.h"
#include "Fire.h"
#include "EnemiesDeadEffect.h"

class JafarState;
class Jafar : public GameObject
{
	JafarState *state;

	static vector<Animation *> animations;

	int x, y;

	int HP;

	int Dmg;

	int CellID;

	int id;

	bool SnakePower;

	vector <Fire*> listFire;

	EnemiesDeadEffect *enemiesDeadEffect;

	GSound* jafarLaugh;
	GSound* jafarSnake;

public:

	Jafar(int x, int y, int CellID, int id);

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	int GetX() { return x; }
	int GetY() { return y; }
	int GetID() { return this->id; }
	int GetCellID() { return this->CellID; }
	void SetHP(int hp) { this->HP = hp; }
	int GetHP() { return this->HP; }
	void SetDmg(int dmg) { this->Dmg = dmg; }
	int GetDmg() { return this->Dmg; }
	void SetSnakePower(int power) { this->SnakePower = power; }
	bool GetSnakePower() { return this->SnakePower; }
	vector <Fire*> GetListFire(){ return this->listFire; }
	void AddListFire(Fire *fire) { this->listFire.push_back(fire); }
	EnemiesDeadEffect *GetEnemiesDeadEffect() { return this->enemiesDeadEffect; }

	static void LoadResources();

	vector<Animation *> GetAnimationsList() { return animations; }

	void Update(DWORD dt) override;

	void Render() override;

	void OnCollision();

	~Jafar();
};