#include "Aladdin.h"

vector<Animation *> Aladdin::animations = vector<Animation *>();
Aladdin *Aladdin::__instance = NULL;

Aladdin *Aladdin::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Aladdin();
	}
	return __instance;
}

Aladdin::Aladdin()
{
	LoadResources();
	state = AladdinState::GetInstance(this);

	this->x = 50;
	this->y = 200;
	this->width = ALADDIN_SPRITE_WIDTH;
	this->height = ALADDIN_SPRITE_HEIGHT;

	collider.x = x - 10;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = ALADDIN_SPRITE_WIDTH;
	collider.height = ALADDIN_SPRITE_HEIGHT;
}

void Aladdin::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Character\\Aladdin.txt");

#pragma region STAND
	Animation * anim = new Animation(150);

	Sprite * stand = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[0], TEXTURE_TRANS_COLOR);
	anim->AddFrame(stand);
	
	animations.push_back(anim);
#pragma endregion

#pragma region HEAD UP
	anim = new Animation(130);

	Sprite * head_up_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[50], TEXTURE_TRANS_COLOR);
	head_up_1->SetOffSetY(3);
	anim->AddFrame(head_up_1);
	Sprite * head_up_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[51], TEXTURE_TRANS_COLOR);
	head_up_2->SetOffSetX(4);
	head_up_2->SetOffSetY(9);
	anim->AddFrame(head_up_2);
	Sprite * head_up_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[52], TEXTURE_TRANS_COLOR);
	head_up_3->SetOffSetX(7);
	head_up_3->SetOffSetY(8);
	anim->AddFrame(head_up_3);

	animations.push_back(anim);
#pragma endregion

#pragma region RUN
	anim = new Animation(65);

	Sprite * run_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[141], TEXTURE_TRANS_COLOR);
	run_1->SetOffSetX(0);
	run_1->SetOffSetY(-2);
	anim->AddFrame(run_1);
	Sprite * run_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[142], TEXTURE_TRANS_COLOR);
	run_2->SetOffSetX(1);
	run_2->SetOffSetY(1);
	anim->AddFrame(run_2);
	Sprite * run_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[143], TEXTURE_TRANS_COLOR);
	run_3->SetOffSetX(0);
	run_3->SetOffSetY(3);
	anim->AddFrame(run_3);
	Sprite * run_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[144], TEXTURE_TRANS_COLOR);
	run_4->SetOffSetX(0);
	run_4->SetOffSetY(7);
	anim->AddFrame(run_4);
	Sprite * run_5 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[145], TEXTURE_TRANS_COLOR);
	run_5->SetOffSetX(6);
	run_5->SetOffSetY(7);
	anim->AddFrame(run_5);
	Sprite * run_6 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[146], TEXTURE_TRANS_COLOR);
	run_6->SetOffSetX(2);
	run_6->SetOffSetY(4);
	anim->AddFrame(run_6);
	Sprite * run_7 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[147], TEXTURE_TRANS_COLOR);
	run_7->SetOffSetX(1);
	run_7->SetOffSetY(8);
	anim->AddFrame(run_7);
	Sprite * run_8 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[148], TEXTURE_TRANS_COLOR);
	run_8->SetOffSetX(0);
	run_8->SetOffSetY(2);
	anim->AddFrame(run_8);
	Sprite * run_9 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[149], TEXTURE_TRANS_COLOR);
	run_9->SetOffSetX(-3);
	run_9->SetOffSetY(4);
	anim->AddFrame(run_9);
	Sprite * run_10 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[150], TEXTURE_TRANS_COLOR);
	run_10->SetOffSetX(4);
	run_10->SetOffSetY(8);
	anim->AddFrame(run_10);
	Sprite * run_11 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[152], TEXTURE_TRANS_COLOR);
	run_11->SetOffSetX(7);
	run_11->SetOffSetY(5);
	anim->AddFrame(run_11);
	Sprite * run_12 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[153], TEXTURE_TRANS_COLOR);
	run_12->SetOffSetX(2);
	run_12->SetOffSetY(7);
	anim->AddFrame(run_12);

	animations.push_back(anim);
#pragma endregion

#pragma region JUMP
	anim = new Animation(80);

	Sprite * jump_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[91], TEXTURE_TRANS_COLOR);
	jump_1->SetOffSetX(15);
	jump_1->SetOffSetY(12);
	anim->AddFrame(jump_1);
	Sprite * jump_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[92], TEXTURE_TRANS_COLOR);
	jump_2->SetOffSetX(12);
	jump_2->SetOffSetY(11);
	anim->AddFrame(jump_2);
	Sprite * jump_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[93], TEXTURE_TRANS_COLOR);
	jump_3->SetOffSetX(9);
	jump_3->SetOffSetY(19);
	anim->AddFrame(jump_3);
	Sprite * jump_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[94], TEXTURE_TRANS_COLOR);
	jump_4->SetOffSetX(6);
	jump_4->SetOffSetY(24);
	anim->AddFrame(jump_4);
	Sprite * jump_5 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[95], TEXTURE_TRANS_COLOR);
	jump_5->SetOffSetX(-3);
	jump_5->SetOffSetY(16);
	anim->AddFrame(jump_5);

	animations.push_back(anim);
#pragma endregion

#pragma region FALL
	anim = new Animation(70);

	Sprite * fall_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[96], TEXTURE_TRANS_COLOR);
	fall_1->SetOffSetY(29);
	anim->AddFrame(fall_1);
	Sprite * fall_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[97], TEXTURE_TRANS_COLOR);
	fall_2->SetOffSetX(-1);
	fall_2->SetOffSetY(43);
	anim->AddFrame(fall_2);
	Sprite * fall_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[98], TEXTURE_TRANS_COLOR);
	fall_3->SetOffSetX(1);
	fall_3->SetOffSetY(43);
	anim->AddFrame(fall_3);
	Sprite * fall_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[99], TEXTURE_TRANS_COLOR);
	fall_4->SetOffSetX(1);
	fall_4->SetOffSetY(43);
	anim->AddFrame(fall_4);

	animations.push_back(anim);
#pragma endregion

#pragma region TOUCH ON THE GROUND
	anim = new Animation(150);

	Sprite * on_ground = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[90], TEXTURE_TRANS_COLOR);
	on_ground->SetOffSetX(14);
	on_ground->SetOffSetY(-7);
	anim->AddFrame(on_ground);

	animations.push_back(anim);
#pragma endregion

#pragma region SIT
	anim = new Animation(100);

	Sprite * sit_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[74], TEXTURE_TRANS_COLOR);
	sit_1->SetOffSetX(6);
	sit_1->SetOffSetY(-1);
	anim->AddFrame(sit_1);
	Sprite * sit_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[75], TEXTURE_TRANS_COLOR);
	sit_2->SetOffSetX(8);
	sit_2->SetOffSetY(-10);
	anim->AddFrame(sit_2);
	Sprite * sit_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[76], TEXTURE_TRANS_COLOR);
	sit_3->SetOffSetX(8);
	sit_3->SetOffSetY(-20);
	anim->AddFrame(sit_3);
	Sprite * sit_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[77], TEXTURE_TRANS_COLOR);
	sit_4->SetOffSetX(3);
	sit_4->SetOffSetY(-15);
	anim->AddFrame(sit_4);

	animations.push_back(anim);
#pragma endregion

#pragma region IDLE_SIT
	anim = new Animation(100);

	Sprite * sit_idle = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[77], TEXTURE_TRANS_COLOR);
	sit_idle->SetOffSetX(3);
	sit_idle->SetOffSetY(-15);
	anim->AddFrame(sit_idle);

	animations.push_back(anim);
#pragma endregion

#pragma region STAND-HIT
	anim = new Animation(100);

	Sprite * stand_hit_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[45], TEXTURE_TRANS_COLOR);
	stand_hit_1->SetOffSetX(8);
	stand_hit_1->SetOffSetY(1);
	anim->AddFrame(stand_hit_1);
	Sprite * stand_hit_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[46], TEXTURE_TRANS_COLOR);
	stand_hit_2->SetOffSetX(10);
	stand_hit_2->SetOffSetY(12);
	anim->AddFrame(stand_hit_2);
	Sprite * stand_hit_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[47], TEXTURE_TRANS_COLOR);
	stand_hit_3->SetOffSetX(4);
	stand_hit_3->SetOffSetY(24);
	anim->AddFrame(stand_hit_3);
	Sprite * stand_hit_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[48], TEXTURE_TRANS_COLOR);
	stand_hit_4->SetOffSetY(19);
	anim->AddFrame(stand_hit_4);
	Sprite * stand_hit_5 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[49], TEXTURE_TRANS_COLOR);
	stand_hit_5->SetOffSetX(8);
	stand_hit_5->SetOffSetY(3);
	anim->AddFrame(stand_hit_5);

	animations.push_back(anim);
#pragma endregion

#pragma region STAND-THROW
	anim = new Animation(80);

	Sprite * stand_throw_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[39], TEXTURE_TRANS_COLOR);
	stand_throw_1->SetOffSetY(6);
	anim->AddFrame(stand_throw_1);
	Sprite * stand_throw_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[40], TEXTURE_TRANS_COLOR);
	stand_throw_2->SetOffSetY(9);
	anim->AddFrame(stand_throw_2);
	Sprite * stand_throw_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[41], TEXTURE_TRANS_COLOR);
	stand_throw_3->SetOffSetY(8);
	anim->AddFrame(stand_throw_3);
	Sprite * stand_throw_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[42], TEXTURE_TRANS_COLOR);
	stand_throw_4->SetOffSetX(1);
	stand_throw_4->SetOffSetY(10);
	anim->AddFrame(stand_throw_4);
	Sprite * stand_throw_5 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[43], TEXTURE_TRANS_COLOR);
	stand_throw_5->SetOffSetY(8);
	anim->AddFrame(stand_throw_5);
	Sprite * stand_throw_6 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[44], TEXTURE_TRANS_COLOR);
	stand_throw_6->SetOffSetX(2);
	stand_throw_6->SetOffSetY(2);
	anim->AddFrame(stand_throw_6);

	animations.push_back(anim); 
#pragma endregion

#pragma region SIT-THROW
	anim = new Animation(80);

	Sprite * sit_throw_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[78], TEXTURE_TRANS_COLOR);
	sit_throw_1->SetOffSetX(0);
	sit_throw_1->SetOffSetY(-6);
	anim->AddFrame(sit_throw_1);
	Sprite * sit_throw_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[79], TEXTURE_TRANS_COLOR);
	sit_throw_2->SetOffSetX(0);
	sit_throw_2->SetOffSetY(-2);
	anim->AddFrame(sit_throw_2);
	Sprite * sit_throw_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[80], TEXTURE_TRANS_COLOR);
	sit_throw_3->SetOffSetX(0);
	sit_throw_3->SetOffSetY(-2);
	anim->AddFrame(sit_throw_3);
	Sprite * sit_throw_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[81], TEXTURE_TRANS_COLOR);
	sit_throw_4->SetOffSetX(12);
	sit_throw_4->SetOffSetY(-13);
	anim->AddFrame(sit_throw_4);
	Sprite * sit_throw_5 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[82], TEXTURE_TRANS_COLOR);
	sit_throw_5->SetOffSetX(7);
	sit_throw_5->SetOffSetY(-13);
	anim->AddFrame(sit_throw_5);

	animations.push_back(anim);
#pragma endregion

#pragma region SIT-HIT
	anim = new Animation(80);

	Sprite * sit_hit_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[83], TEXTURE_TRANS_COLOR);
	sit_hit_1->SetOffSetY(-17);
	anim->AddFrame(sit_hit_1);
	Sprite * sit_hit_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[84], TEXTURE_TRANS_COLOR);
	sit_hit_2->SetOffSetY(-19);
	anim->AddFrame(sit_hit_2);
	Sprite * sit_hit_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[85], TEXTURE_TRANS_COLOR);
	sit_hit_3->SetOffSetY(-17);
	anim->AddFrame(sit_hit_3);
	Sprite * sit_hit_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[86], TEXTURE_TRANS_COLOR);
	sit_hit_4->SetOffSetY(-16);
	anim->AddFrame(sit_hit_4);
	Sprite * sit_hit_5 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[87], TEXTURE_TRANS_COLOR);
	sit_hit_5->SetOffSetY(-17);
	anim->AddFrame(sit_hit_5);
	Sprite * sit_hit_6 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[88], TEXTURE_TRANS_COLOR);
	sit_hit_6->SetOffSetY(-17);
	anim->AddFrame(sit_hit_6);
	Sprite * sit_hit_7 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[89], TEXTURE_TRANS_COLOR);
	sit_hit_7->SetOffSetY(-19);
	anim->AddFrame(sit_hit_7);

	animations.push_back(anim);
#pragma endregion

}

void Aladdin::Reset()
{
	this->SetPositionX(200);
	this->SetPositionY(200);
	Viewport::GetInstance()->Reset();
}

void Aladdin::Update(DWORD dt)
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
				this->SetPositionX(this->GetPositionX() - 1);
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

	state->Colision();
	state->Update(dt);
}

void Aladdin::UpdateCollision(DWORD dt)
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

void Aladdin::Render()
{
	state->Render();
}