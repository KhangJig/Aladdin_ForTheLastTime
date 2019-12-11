#pragma once
#include "GameObject.h"
#include "Debug.h"

class ItemEffect : public GameObject
{
	static vector<Animation *> animations;

	int x, y;

	bool hidden;

public:
	ItemEffect(int x, int y);

	void SetHidden(bool hidden) { this->hidden = hidden; }

	void SetPos(int x, int y, bool hidden) { this->x = x; this->y = y; this->hidden = hidden; }

	bool GetHidden() { return this->hidden; }

	static void LoadResources();

	void Render();

	~ItemEffect();
};