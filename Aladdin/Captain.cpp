#include "Captain.h"

vector<Animation *> Captain::animations = vector<Animation *>();
Captain *Captain::__instance = NULL;

Captain::Captain()
{
	LoadResources();

	state = CaptainState::GetInstance(this);

	shield = new Shield();

	this->x = 50;
	this->y = 200;
	this->width = CAPTAIN_SPRITE_WIDTH;
	this->height = CAPTAIN_SPRITE_HEIGHT;

	collider.x = x - 10;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = CAPTAIN_SPRITE_WIDTH;
	collider.height = CAPTAIN_SPRITE_HEIGHT;
}

Captain *Captain::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Captain();
	}
	return __instance;
}

void Captain::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resources\\Captain\\Captain.txt");

	// CAPTAIN_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_STADING_UP
	anim = new Animation(100);
	for (int i = 5; i < 6; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_WALK
	anim = new Animation(100);
	for (int i = 1; i < 5; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);

	}
	animations.push_back(anim);

	// CAPTAIN_ANI_JUMP
	anim = new Animation(100);
	for (int i = 7; i < 8; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);

	}
	animations.push_back(anim);

	// CAPTAIN_ANI_JUMP_ROLE
	anim = new Animation(50);
	for (int i = 8; i < 10; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_CROUCH
	anim = new Animation(100);
	for (int i = 6; i < 7; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_SWIM
	anim = new Animation(100);
	for (int i = 44; i < 46; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_THROW_SHIELD
	anim = new Animation(100);

	Sprite * sprite3 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[11], TEXTURE_TRANS_COLOR_2);
	sprite3->SetOffSetX(-4);
	anim->AddFrame(sprite3);

	Sprite * sprite4 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[12], TEXTURE_TRANS_COLOR_2);

	sprite4->SetOffSetX(12);
	anim->AddFrame(sprite4);

	animations.push_back(anim);

	// CAPTAIN_ANI_PUNCH
	anim = new Animation(100);

	Sprite * sprite1 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[13], TEXTURE_TRANS_COLOR_2);
	sprite1->SetOffSetX(12);
	anim->AddFrame(sprite1);

	Sprite * sprite2 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[14], TEXTURE_TRANS_COLOR_2);
	sprite2->SetOffSetX(3);
	anim->AddFrame(sprite2);

	animations.push_back(anim);

	// CAPTAIN_ANI_KICK
	anim = new Animation(500);
	for (int i = 10; i < 11; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);

		sprite->SetOffSetX(12);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_CROUCH_PUNCH
	anim = new Animation(100);

	Sprite * sprite5 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[15], TEXTURE_TRANS_COLOR_2);
	sprite5->SetOffSetX(9);
	anim->AddFrame(sprite5);

	Sprite * sprite6 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[16], TEXTURE_TRANS_COLOR_2);
	anim->AddFrame(sprite6);

	animations.push_back(anim);

	// CAPTAIN_ANI_CROUCH_SHIELD
	anim = new Animation(300);
	for (int i = 19; i < 20; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_DASH
	anim = new Animation(300);
	for (int i = 18; i < 19; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_THROW_SHIELD_2
	anim = new Animation(300);
	for (int i = 11; i < 13; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_BLEEING
	anim = new Animation(100);
	for (int i = 33; i < 34; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_DIEING
	anim = new Animation(300);
	for (int i = 34; i < 36; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_DIVING
	anim = new Animation(200);
	for (int i = 41; i < 44; i++)
	{
		Sprite * sprite = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[i], TEXTURE_TRANS_COLOR_2);
		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// CAPTAIN_ANI_SWING
	anim = new Animation(200);

	Sprite * sprite9 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[27], TEXTURE_TRANS_COLOR_2);
	sprite9->SetOffSetX(4);
	anim->AddFrame(sprite9);

	Sprite * sprite10 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[28], TEXTURE_TRANS_COLOR_2);
	sprite10->SetOffSetX(5);
	anim->AddFrame(sprite10);

	Sprite * sprite11 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[29], TEXTURE_TRANS_COLOR_2);
	sprite11->SetOffSetX(1);
	anim->AddFrame(sprite11);

	animations.push_back(anim);

	// CAPTAIN_ANI_BLEEING_2
	anim = new Animation(10);

	Sprite * sprite7 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[30], TEXTURE_TRANS_COLOR_2);
	anim->AddFrame(sprite7);

	Sprite * sprite8 = new Sprite(CAPTAIN_TEXTURE_LOCATION, listSprite[0], TEXTURE_TRANS_COLOR_2);
	anim->AddFrame(sprite8);
	animations.push_back(anim);
}

void Captain::Reset()
{
	this->SetPositionX(200);
	this->SetPositionY(200);
	Viewport::GetInstance()->Reset();
}

void Captain::Update(DWORD dt)
{
	timeCount += dt;

	if (this->GetSpeedX() > 0 && this->GetPositionX() > TileMap::GetInstance()->currentMap->size * 100 - 50)
	{
		if (Game::GetInstance()->GetStage() < 2)
		{
			Game::GetInstance()->SetStage(Game::GetInstance()->GetStage() + 1);
			if (STAGE_2 == Game::GetInstance()->GetStage())
			{
				Grid::GetInstance()->DisableAllObject();

				this->SetPositionX(280);
				this->SetPositionY(900);
				Viewport::GetInstance()->Reset();

				TileMap::GetInstance()->SetCurrentMap(STAGE_2);
				Grid::GetInstance()->InitializeMapGrid(TileMap::GetInstance());
			}
		}
		else this->SetSpeedX(0);
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_F1))
	{
		Grid::GetInstance()->DisableAllObject();
		Game::GetInstance()->SetStage(STAGE_1);

		this->SetPositionX(50);
		this->SetPositionY(200);
		Viewport::GetInstance()->Reset();

		TileMap::GetInstance()->SetCurrentMap(STAGE_1);
		Grid::GetInstance()->InitializeMapGrid(TileMap::GetInstance());
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_F2))
	{
		Grid::GetInstance()->DisableAllObject();
		Game::GetInstance()->SetStage(STAGE_2);

		this->SetPositionX(280);
		this->SetPositionY(950);
		Viewport::GetInstance()->Reset();

		TileMap::GetInstance()->SetCurrentMap(STAGE_2);
		Grid::GetInstance()->InitializeMapGrid(TileMap::GetInstance());
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_F3))
	{
		trueImortal = !trueImortal;
	}

	vector<ColliedEvent*> coEvents;
	vector<ColliedEvent*> coEventsResult;

#pragma region	Collide with map
	vector<Tile *> tiles = Grid::GetInstance()->GetNearbyTiles(this->GetRect());

	coEvents.clear();
	this->SetDt(dt);
	this->UpdateObjectCollider();
	this->collider.x += 5;
	this->MapCollisions(tiles, coEvents);

	if (coEvents.size() == 0)
	{
		float moveX = trunc(this->GetSpeedX()* dt);
		float moveY = trunc(this->GetSpeedY()* dt);
		this->SetPositionX(this->GetPositionX() + moveX);
		this->SetPositionY(this->GetPositionY() + moveY);
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		Collision::GetInstance()->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		float moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
		float moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;

		this->SetPositionX(this->GetPositionX() + moveX);
		this->SetPositionY(this->GetPositionY() + moveY);

		if (coEventsResult[0]->collisionID == 1)
		{
			if (ny == 1)
			{
				this->SetIsGrounded(true);
			}
		}

		if (coEventsResult[0]->collisionID == 2)
		{
			if (ny == 1)
			{
				this->SetIsGrounded(false);
				this->SetIsSwimming(true);
				this->SetPositionX(this->GetPositionX() - 1);
			}
		}

		if (coEventsResult[0]->collisionID == 3)
		{
			if (ny == 1)
			{
				this->SetIsSwing(true);
			}
		}

		if (coEventsResult[0]->collisionID == 4)
		{
			if (ny == 1)
			{
				this->SetIsGrounded(true);
				this->SetIsBleeding(true);
			}
		}

		if (coEventsResult[0]->collisionID == 5)
		{
			if (nx == 1 || nx == -1)
			{
				this->SetIsGrounded(true);
			}
		}
	}
	for (int i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
#pragma endregion

	shield->UpdateObjectCollider();
	shield->Update(dt);
	state->Colision();
	state->Update(dt);
}
void Captain::UpdateCollision(DWORD dt)
{
	if (trueImortal)
		return;

	if (bImortal)
	{
		if (timeCount > 700)
		{
			timeCount = 0;
			bImortal = false;
		}
		return;
	}
}
void Captain::Render()
{
	state->Render();
	shield->Render();
}