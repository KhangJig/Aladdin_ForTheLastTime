#include "Guard1.h"

vector<Animation *> Guard1::animations = vector<Animation *>();

Guard1::Guard1(float x, float y, int CellID, int id)
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

	this->CellID = CellID;
	this->id = id;

	this->disable = false;
	this->Guard1HP = 50;
	this->Guard1Dmg = 20;
	this->Attacking = false;
	this->Dead = false;

	enemiesDeadEffect = new EnemiesDeadEffect(0, 0);

	this->guardHit = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_GUARD_HIT_2);

	this->guardHurt = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_GUARDS_PANTS);

	this->headBop = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_HEAD_BOP);
}

void Guard1::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Enemies\\Guards.txt");
	Sprite * guard1 = new Sprite(GUARD_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_3);

#pragma region IDLE
	Animation * anim = new Animation(100);

	Sprite * guard1_idle_1 = new Sprite(guard1->GetTexture(), listSprite[14], TEXTURE_TRANS_COLOR_3);
	anim->AddFrame(guard1_idle_1);

	animations.push_back(anim);
#pragma endregion

#pragma region HURT
	anim = new Animation(100);

	Sprite * guard1_hurt_2 = new Sprite(guard1->GetTexture(), listSprite[15], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_2->SetOffSetX(-6);
	guard1_hurt_2->SetOffSetY(-10);
	anim->AddFrame(guard1_hurt_2);
	Sprite * guard1_hurt_3 = new Sprite(guard1->GetTexture(), listSprite[16], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_3->SetOffSetX(-2);
	guard1_hurt_3->SetOffSetY(15);
	anim->AddFrame(guard1_hurt_3);
	Sprite * guard1_hurt_4 = new Sprite(guard1->GetTexture(), listSprite[17], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_4->SetOffSetX(-4);
	guard1_hurt_4->SetOffSetY(10);
	anim->AddFrame(guard1_hurt_4);
	Sprite * guard1_hurt_5 = new Sprite(guard1->GetTexture(), listSprite[18], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_5->SetOffSetX(7);
	guard1_hurt_5->SetOffSetY(4);
	anim->AddFrame(guard1_hurt_5);
	Sprite * guard1_hurt_6 = new Sprite(guard1->GetTexture(), listSprite[19], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_6->SetOffSetX(4);
	guard1_hurt_6->SetOffSetY(13);
	anim->AddFrame(guard1_hurt_6);
	Sprite * guard1_hurt_7 = new Sprite(guard1->GetTexture(), listSprite[20], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_7->SetOffSetX(3);
	guard1_hurt_7->SetOffSetY(-9);
	anim->AddFrame(guard1_hurt_7);
	Sprite * guard1_hurt_8 = new Sprite(guard1->GetTexture(), listSprite[21], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_8->SetOffSetX(-3);
	guard1_hurt_8->SetOffSetY(-10);
	anim->AddFrame(guard1_hurt_8);
	Sprite * guard1_hurt_9 = new Sprite(guard1->GetTexture(), listSprite[22], TEXTURE_TRANS_COLOR_3);
	guard1_hurt_9->SetOffSetX(-4);
	guard1_hurt_9->SetOffSetY(9);
	anim->AddFrame(guard1_hurt_9);

	animations.push_back(anim);
#pragma endregion

#pragma region WALKING
	anim = new Animation(100);

	Sprite * guard1_walking_1 = new Sprite(guard1->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_3);
	guard1_walking_1->SetOffSetY(9);
	anim->AddFrame(guard1_walking_1);
	Sprite * guard1_walking_2 = new Sprite(guard1->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_3);
	guard1_walking_2->SetOffSetY(8);
	anim->AddFrame(guard1_walking_2);
	Sprite * guard1_walking_3 = new Sprite(guard1->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_3);
	guard1_walking_3->SetOffSetY(7);
	anim->AddFrame(guard1_walking_3);
	Sprite * guard1_walking_4 = new Sprite(guard1->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_3);
	guard1_walking_4->SetOffSetY(7);
	anim->AddFrame(guard1_walking_4);
	Sprite * guard1_walking_5 = new Sprite(guard1->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_3);
	guard1_walking_5->SetOffSetX(2);
	guard1_walking_5->SetOffSetY(8);
	anim->AddFrame(guard1_walking_5);
	Sprite * guard1_walking_6 = new Sprite(guard1->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_3);
	guard1_walking_6->SetOffSetY(9);
	anim->AddFrame(guard1_walking_6);
	Sprite * guard1_walking_7 = new Sprite(guard1->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_3);
	guard1_walking_7->SetOffSetX(2);
	guard1_walking_7->SetOffSetY(9);
	anim->AddFrame(guard1_walking_7);
	Sprite * guard1_walking_8 = new Sprite(guard1->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_3);
	guard1_walking_8->SetOffSetY(7);
	anim->AddFrame(guard1_walking_8);

	animations.push_back(anim);
#pragma endregion

#pragma region HIT
	anim = new Animation(120);

	Sprite * guard1_hit_1 = new Sprite(guard1->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_3);
	guard1_hit_1->SetOffSetX(-3);
	guard1_hit_1->SetOffSetY(16);
	anim->AddFrame(guard1_hit_1);
	Sprite * guard1_hit_2 = new Sprite(guard1->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_3);
	guard1_hit_2->SetOffSetX(1);
	guard1_hit_2->SetOffSetY(2);
	anim->AddFrame(guard1_hit_2);
	Sprite * guard1_hit_3 = new Sprite(guard1->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_3);
	guard1_hit_3->SetOffSetX(53);
	anim->AddFrame(guard1_hit_3);
	Sprite * guard1_hit_4 = new Sprite(guard1->GetTexture(), listSprite[11], TEXTURE_TRANS_COLOR_3);
	guard1_hit_4->SetOffSetX(48);
	guard1_hit_4->SetOffSetY(1);
	anim->AddFrame(guard1_hit_4);
	Sprite * guard1_hit_5 = new Sprite(guard1->GetTexture(), listSprite[12], TEXTURE_TRANS_COLOR_3);
	guard1_hit_5->SetOffSetX(37);
	guard1_hit_5->SetOffSetY(2);
	anim->AddFrame(guard1_hit_5);
	Sprite * guard1_hit_6 = new Sprite(guard1->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_3);
	guard1_hit_6->SetOffSetX(1);
	guard1_hit_6->SetOffSetY(2);
	anim->AddFrame(guard1_hit_6);

	animations.push_back(anim);
#pragma endregion

#pragma region DEAD
	anim = new Animation(80);

	Sprite * guard1_dead_1 = new Sprite(guard1->GetTexture(), listSprite[54], TEXTURE_TRANS_COLOR_3);
	anim->AddFrame(guard1_dead_1);

	animations.push_back(anim);
#pragma endregion
}

void Guard1::Update(DWORD dt)
{
	this->UpdateCollision(dt);
	if (this->disable)
		return;

	if (this->GetPositionX() > Aladdin::GetInstance()->GetPositionX())
		this->setIsLeft(true);
	else
		this->setIsLeft(false);

	this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	this->SetPositionY((float)(this->GetPositionY() + this->GetSpeedY()* dt));
	this->collider.x = this->GetPositionX();
	this->collider.y = this->GetPositionY();

//#pragma region	Collide with map
//	vector<ColliedEvent*> coEvents;
//	vector<ColliedEvent*> coEventsResult;
//
//
//	vector<TileObjectMap *> tiles = Grid::GetInstance()->GetNearbyObjectTilesForEnemies(this->GetCellID());
//
//	coEvents.clear();
//	this->SetDt(dt);
//	this->UpdateObjectCollider();
//	this->MapCollisions(tiles, coEvents);
//
//	if (coEvents.size() == 0)
//	{
//		float moveX = trunc(this->GetSpeedX()* dt);
//		float moveY = trunc(this->GetSpeedY()* dt);
//		this->SetPositionX(this->GetPositionX() + moveX);
//		this->SetPositionY(this->GetPositionY() + moveY);
//	}
//	else
//	{
//		float min_tx, min_ty, nx = 0, ny;
//
//		Collision::GetInstance()->GetNearestCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
//
//		float moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
//		float moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;
//
//		this->SetPositionX(this->GetPositionX() + moveX);
//		this->SetPositionY(this->GetPositionY() + moveY);
//
//		if (coEventsResult[0]->collisionID == 1)
//		{
//			if (ny == 1)
//			{
//				this->isOnGround = true;
//			}
//		}
//	}
//	for (int i = 0; i < coEvents.size(); i++)
//		delete coEvents[i];
//#pragma endregion

	state->Colision();
	state->Update(dt);

#pragma region Set new area collision when Guard1 is attacking

	if (this->GetAttacking())
	{
		if (this->isLeft)
			this->collider.x = x - 35;
		this->collider.width = GUARD1_SPRITE_WIDTH + 35;
	}
	else
	{
		this->collider.width = GUARD1_SPRITE_WIDTH;
		this->collider.x = x;
	}

#pragma endregion
}

void Guard1::Render()
{
	if (this->disable)
		return;

	state->Render();
	enemiesDeadEffect->Render();
}

void Guard1::UpdateCollision(DWORD dt)
{
	bool isCollideAladdin = Collision::GetInstance()->AABB(this->GetCollider(), Aladdin::GetInstance()->GetCollider());
	bool isCollideApple = Collision::GetInstance()->AABB(this->GetCollider(), Apple::GetInstance()->GetCollider());

	if (isCollideAladdin)
	{
		if (Aladdin::GetInstance()->GetAttacking())
		{
			this->SetGuard1HP(this->GetGuard1HP() - Aladdin::GetInstance()->GetDmgAttack());

			if (this->GetGuard1HP() > 0)
			{
				Sound::GetInstance()->PlaySound(guardHurt);
				this->state->SetState(GUARD1_HURT);
			}
			else
			{
				enemiesDeadEffect->SetPos(this->GetPositionX() + 20, this->GetPositionY(), false);
				this->state->SetState(GUARD1_DEAD);
			}
		}
	}
	if (isCollideApple)
	{
		this->SetGuard1HP(this->GetGuard1HP() - Aladdin::GetInstance()->GetDmgAttack());

		if (this->GetGuard1HP() > 0)
		{
			Sound::GetInstance()->PlaySound(headBop);
			this->state->SetState(GUARD1_HURT);
		}
		else
		{
			enemiesDeadEffect->SetPos(this->GetPositionX() + 20, this->GetPositionY(), false);
			this->state->SetState(GUARD1_DEAD);
		}
	}
}

void Guard1::OnCollision()
{
	((Guard1State*)state)->timeCount = 0;
}
