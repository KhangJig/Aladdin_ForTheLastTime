#include "Guard1.h"

vector<Animation *> Guard1::animations = vector<Animation *>();
Guard1 *Guard1::__instance = NULL;

Guard1 *Guard1::GetInstance()
{
	if (__instance == NULL)
		__instance = new Guard1();
	return __instance;
}

Guard1::Guard1()
{
	LoadResources();

	state = Guard1State::GetInstance(this);

	this->x = 250;
	this->y = 150;
	this->width = GUARD1_SPRITE_WIDTH;
	this->height = GUARD1_SPRITE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = GUARD1_SPRITE_WIDTH;
	collider.height = GUARD1_SPRITE_HEIGHT;
}

Guard1::Guard1(float x, float y)
{
	this->state = new Guard1State(this);

	this->posx = x;
	this->posy = y;

	this->x = x;
	this->y = y;
	this->width = GUARD1_SPRITE_WIDTH;
	this->height = GUARD1_SPRITE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = GUARD1_SPRITE_WIDTH;
	collider.height = GUARD1_SPRITE_HEIGHT;

	this->disable = false;
}

void Guard1::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Enemies\\Guards.txt");

#pragma region IDLE
	Animation * anim = new Animation(100);

	Sprite * guard1_idle_1 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[14], TEXTURE_TRANS_COLOR_3);
	anim->AddFrame(guard1_idle_1);

	animations.push_back(anim);
#pragma endregion

#pragma region HURT
	anim = new Animation(100);

	Sprite * guard1_hurt_2 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[15], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_2->SetOffSetX(-6);
	guard1_hurt_2->SetOffSetY(-10);
	anim->AddFrame(guard1_hurt_2);
	Sprite * guard1_hurt_3 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[16], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_3->SetOffSetX(-2);
	guard1_hurt_3->SetOffSetY(15);
	anim->AddFrame(guard1_hurt_3);
	Sprite * guard1_hurt_4 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[17], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_4->SetOffSetX(-4);
	guard1_hurt_4->SetOffSetY(10);
	anim->AddFrame(guard1_hurt_4);
	Sprite * guard1_hurt_5 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[18], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_5->SetOffSetX(7);
	guard1_hurt_5->SetOffSetY(4);
	anim->AddFrame(guard1_hurt_5);
	Sprite * guard1_hurt_6 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[19], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_6->SetOffSetX(4);
	guard1_hurt_6->SetOffSetY(13);
	anim->AddFrame(guard1_hurt_6);
	Sprite * guard1_hurt_7 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[20], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_7->SetOffSetX(3);
	guard1_hurt_7->SetOffSetY(-9);
	anim->AddFrame(guard1_hurt_7);
	Sprite * guard1_hurt_8 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[21], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_8->SetOffSetX(-3);
	guard1_hurt_8->SetOffSetY(-10);
	anim->AddFrame(guard1_hurt_8);
	Sprite * guard1_hurt_9 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[22], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_9->SetOffSetX(-4);
	guard1_hurt_9->SetOffSetY(9);
	anim->AddFrame(guard1_hurt_9);

	animations.push_back(anim);
#pragma endregion

#pragma region WALKING
	anim = new Animation(100);

	Sprite * guard1_walking_1 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[0], TEXTURE_TRANS_COLOR_3);
	guard1_walking_1->SetOffSetX(1);
	guard1_walking_1->SetOffSetY(1);
	anim->AddFrame(guard1_walking_1);
	Sprite * guard1_walking_2 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[1], TEXTURE_TRANS_COLOR_3);
	guard1_walking_2->SetOffSetX(1);
	guard1_walking_2->SetOffSetY(1);
	anim->AddFrame(guard1_walking_2);
	Sprite * guard1_walking_3 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[2], TEXTURE_TRANS_COLOR_3);
	guard1_walking_3->SetOffSetX(1);
	guard1_walking_3->SetOffSetY(1);
	anim->AddFrame(guard1_walking_3);
	Sprite * guard1_walking_4 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[3], TEXTURE_TRANS_COLOR_3);
	guard1_walking_4->SetOffSetX(1);
	guard1_walking_4->SetOffSetY(1);
	anim->AddFrame(guard1_walking_4);
	Sprite * guard1_walking_5 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[4], TEXTURE_TRANS_COLOR_3);
	guard1_walking_5->SetOffSetX(1);
	guard1_walking_5->SetOffSetY(1);
	anim->AddFrame(guard1_walking_5);
	Sprite * guard1_walking_6 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[5], TEXTURE_TRANS_COLOR_3);
	guard1_walking_6->SetOffSetX(1);
	guard1_walking_6->SetOffSetY(1);
	anim->AddFrame(guard1_walking_6);
	Sprite * guard1_walking_7 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[6], TEXTURE_TRANS_COLOR_3);
	guard1_walking_7->SetOffSetX(1);
	guard1_walking_7->SetOffSetY(1);
	anim->AddFrame(guard1_walking_7);
	Sprite * guard1_walking_8 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[7], TEXTURE_TRANS_COLOR_3);
	guard1_walking_8->SetOffSetX(1);
	guard1_walking_8->SetOffSetY(1);
	anim->AddFrame(guard1_walking_8);

	animations.push_back(anim);
#pragma endregion

#pragma region HIT
	anim = new Animation(100);

	Sprite * guard1_hit_1 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[8], TEXTURE_TRANS_COLOR_3);
	guard1_hit_1->SetOffSetX(1);
	guard1_hit_1->SetOffSetY(1);
	anim->AddFrame(guard1_hit_1);
	Sprite * guard1_hit_2 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[9], TEXTURE_TRANS_COLOR_3);
	guard1_hit_2->SetOffSetX(1);
	guard1_hit_2->SetOffSetY(1);
	anim->AddFrame(guard1_hit_2);
	Sprite * guard1_hit_3 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[10], TEXTURE_TRANS_COLOR_3);
	guard1_hit_3->SetOffSetX(1);
	guard1_hit_3->SetOffSetY(1);
	anim->AddFrame(guard1_hit_3);
	Sprite * guard1_hit_4 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[11], TEXTURE_TRANS_COLOR_3);
	guard1_hit_4->SetOffSetX(1);
	guard1_hit_4->SetOffSetY(1);
	anim->AddFrame(guard1_hit_4);
	Sprite * guard1_hit_5 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[12], TEXTURE_TRANS_COLOR_3);
	guard1_hit_5->SetOffSetX(1);
	guard1_hit_5->SetOffSetY(1);
	anim->AddFrame(guard1_hit_5);
	Sprite * guard1_hit_6 = new Sprite(GUARD_TEXTURE_LOCATION, listSprite[13], TEXTURE_TRANS_COLOR_3);
	guard1_hit_6->SetOffSetX(1);
	guard1_hit_6->SetOffSetY(1);
	anim->AddFrame(guard1_hit_6);

	animations.push_back(anim);
#pragma endregion

}

void Guard1::Update(DWORD dt)
{

	if (this->disable)
		return;

	if (this->GetPositionX() > Aladdin::GetInstance()->GetPositionX())
		this->setIsLeft(true);
	else
		this->setIsLeft(false);

	vector<ColliedEvent*> coEvents;
	vector<ColliedEvent*> coEventsResult;

#pragma region	Collide with map
	vector<Tile *> tiles = Grid::GetInstance()->GetNearbyTiles(this->GetRect());

	coEvents.clear();
	this->SetDt(dt);
	this->UpdateObjectCollider();
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

		Collision::GetInstance()->GetNearestCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		float moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
		float moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;

		this->SetPositionX(this->GetPositionX() + moveX);
		this->SetPositionY(this->GetPositionY() + moveY);

		if (coEventsResult[0]->collisionID == 1)
		{
			if (ny == 1)
			{
				this->isOnGround = true;
			}
		}
	}
	for (int i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
#pragma endregion

	state->Colision();
	state->Update(dt);
}

void Guard1::Render()
{
	if (this->disable)
		return;

	state->Render();
}

void Guard1::OnCollision()
{
	((Guard1State*)state)->timeCount = 0;
	((Guard1State*)state)->stateHit();
}
