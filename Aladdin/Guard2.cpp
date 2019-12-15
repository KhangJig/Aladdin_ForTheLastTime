#include "Guard2.h"

vector<Animation *> Guard2::animations = vector<Animation *>();

Guard2::Guard2(float x, float y, int CellID, int id)
{
	this->state = new Guard2State(this);

	this->posx = x;
	this->posy = y;

	this->x = x;
	this->y = y;
	this->width = GUARD2_SPRITE_WIDTH;
	this->height = GUARD2_SPRITE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = GUARD2_SPRITE_WIDTH;
	collider.height = GUARD2_SPRITE_HEIGHT;

	this->CellID = CellID;
	this->id = id;

	this->Guard2HP = GUARD2_HP;
	this->Guard2Dmg = GUARD2_DAMAGE;
	this->Attacking = false;
	this->Dead = false;
	this->disable = false;

	enemiesDeadEffect = new EnemiesDeadEffect(0, 0);

	this->guardHit = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_GUARD_HIT_1);

	this->guardHurt = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_GUARDS_PANTS);

	this->headBop = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_HEAD_BOP);
}

void Guard2::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Enemies\\Guards.txt");
	Sprite * guard2 = new Sprite(GUARD_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_3);

#pragma region IDLE
	Animation * anim = new Animation(100);

	Sprite * guard2_idle_1 = new Sprite(guard2->GetTexture(), listSprite[31], TEXTURE_TRANS_COLOR_3);
	anim->AddFrame(guard2_idle_1);

	animations.push_back(anim);
#pragma endregion

#pragma region HURT
	anim = new Animation(100);

	Sprite * guard2_hurt_2 = new Sprite(guard2->GetTexture(), listSprite[48], TEXTURE_TRANS_COLOR_3);
	guard2_hurt_2->SetOffSetX(6);
	guard2_hurt_2->SetOffSetY(-6);
	anim->AddFrame(guard2_hurt_2);
	Sprite * guard2_hurt_3 = new Sprite(guard2->GetTexture(), listSprite[49], TEXTURE_TRANS_COLOR_3);
	guard2_hurt_3->SetOffSetX(2);
	guard2_hurt_3->SetOffSetY(17);
	anim->AddFrame(guard2_hurt_3);
	Sprite * guard2_hurt_4 = new Sprite(guard2->GetTexture(), listSprite[50], TEXTURE_TRANS_COLOR_3);
	guard2_hurt_4->SetOffSetX(4);
	guard2_hurt_4->SetOffSetY(3);
	anim->AddFrame(guard2_hurt_4);
	Sprite * guard2_hurt_5 = new Sprite(guard2->GetTexture(), listSprite[51], TEXTURE_TRANS_COLOR_3);
	guard2_hurt_5->SetOffSetX(4);
	guard2_hurt_5->SetOffSetY(12);
	anim->AddFrame(guard2_hurt_5);
	Sprite * guard2_hurt_6 = new Sprite(guard2->GetTexture(), listSprite[52], TEXTURE_TRANS_COLOR_3);
	guard2_hurt_6->SetOffSetX(2);
	guard2_hurt_6->SetOffSetY(10);
	anim->AddFrame(guard2_hurt_6);

	animations.push_back(anim);
#pragma endregion

#pragma region WALKING
	anim = new Animation(100);

	Sprite * guard2_walking_1 = new Sprite(guard2->GetTexture(), listSprite[23], TEXTURE_TRANS_COLOR_3);
	guard2_walking_1->SetOffSetX(10);
	guard2_walking_1->SetOffSetY(-2);
	anim->AddFrame(guard2_walking_1);
	Sprite * guard2_walking_2 = new Sprite(guard2->GetTexture(), listSprite[24], TEXTURE_TRANS_COLOR_3);
	guard2_walking_2->SetOffSetX(2);
	anim->AddFrame(guard2_walking_2);
	Sprite * guard2_walking_3 = new Sprite(guard2->GetTexture(), listSprite[25], TEXTURE_TRANS_COLOR_3);
	guard2_walking_3->SetOffSetX(12);
	guard2_walking_3->SetOffSetY(1);
	anim->AddFrame(guard2_walking_3);
	Sprite * guard2_walking_4 = new Sprite(guard2->GetTexture(), listSprite[26], TEXTURE_TRANS_COLOR_3);
	guard2_walking_4->SetOffSetX(7);
	anim->AddFrame(guard2_walking_4);
	Sprite * guard2_walking_5 = new Sprite(guard2->GetTexture(), listSprite[27], TEXTURE_TRANS_COLOR_3);
	guard2_walking_5->SetOffSetX(-8);
	guard2_walking_5->SetOffSetY(-2);
	anim->AddFrame(guard2_walking_5);
	Sprite * guard2_walking_6 = new Sprite(guard2->GetTexture(), listSprite[28], TEXTURE_TRANS_COLOR_3);
	guard2_walking_6->SetOffSetX(-4);
	guard2_walking_6->SetOffSetY(-1);
	anim->AddFrame(guard2_walking_6);
	Sprite * guard2_walking_7 = new Sprite(guard2->GetTexture(), listSprite[29], TEXTURE_TRANS_COLOR_3);
	guard2_walking_7->SetOffSetX(-2);
	guard2_walking_7->SetOffSetY(2);
	anim->AddFrame(guard2_walking_7);
	Sprite * guard2_walking_8 = new Sprite(guard2->GetTexture(), listSprite[30], TEXTURE_TRANS_COLOR_3);
	guard2_walking_8->SetOffSetX(4);
	anim->AddFrame(guard2_walking_8);

	animations.push_back(anim);
#pragma endregion

#pragma region HIT
	anim = new Animation(120);

	Sprite * guard2_hit_1 = new Sprite(guard2->GetTexture(), listSprite[43], TEXTURE_TRANS_COLOR_3);
	guard2_hit_1->SetOffSetX(-15);
	guard2_hit_1->SetOffSetY(6);
	anim->AddFrame(guard2_hit_1);
	Sprite * guard2_hit_2 = new Sprite(guard2->GetTexture(), listSprite[44], TEXTURE_TRANS_COLOR_3);
	guard2_hit_2->SetOffSetX(-17);
	guard2_hit_2->SetOffSetY(19);
	anim->AddFrame(guard2_hit_2);
	Sprite * guard2_hit_3 = new Sprite(guard2->GetTexture(), listSprite[45], TEXTURE_TRANS_COLOR_3);
	guard2_hit_3->SetOffSetX(-16);
	guard2_hit_3->SetOffSetY(12);
	anim->AddFrame(guard2_hit_3);
	Sprite * guard2_hit_4 = new Sprite(guard2->GetTexture(), listSprite[46], TEXTURE_TRANS_COLOR_3);
	guard2_hit_4->SetOffSetX(52);
	guard2_hit_4->SetOffSetY(2);
	anim->AddFrame(guard2_hit_4);
	Sprite * guard2_hit_5 = new Sprite(guard2->GetTexture(), listSprite[47], TEXTURE_TRANS_COLOR_3);
	guard2_hit_5->SetOffSetX(33);
	guard2_hit_5->SetOffSetY(19);
	anim->AddFrame(guard2_hit_5);

	animations.push_back(anim);
#pragma endregion

#pragma region DEAD
	anim = new Animation(80);

	Sprite * guard2_dead_1 = new Sprite(guard2->GetTexture(), listSprite[54], TEXTURE_TRANS_COLOR_3);
	anim->AddFrame(guard2_dead_1);

	animations.push_back(anim);
#pragma endregion
}

void Guard2::Update(DWORD dt)
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

#pragma region	Collide with map
	//vector<ColliedEvent*> coEvents;
	//vector<ColliedEvent*> coEventsResult;

	//vector<TileObjectMap *> tiles = Grid::GetInstance()->GetNearbyObjectTilesForEnemies(this->GetCellID());

	//coEvents.clear();
	//this->SetDt(dt);
	//this->UpdateObjectCollider();
	//this->MapCollisions(tiles, coEvents);

	//if (coEvents.size() == 0)
	//{
	//	float moveX = trunc(this->GetSpeedX()* dt);
	//	float moveY = trunc(this->GetSpeedY()* dt);
	//	this->SetPositionX(this->GetPositionX() + moveX);
	//	this->SetPositionY(this->GetPositionY() + moveY);
	//}
	//else
	//{
	//	float min_tx, min_ty, nx = 0, ny;

	//	Collision::GetInstance()->GetNearestCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

	//	float moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
	//	float moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;

	//	this->SetPositionX(this->GetPositionX() + moveX);
	//	this->SetPositionY(this->GetPositionY() + moveY);

	//	if (coEventsResult[0]->collisionID == 1)
	//	{
	//		if (ny == 1)
	//		{
	//			this->isOnGround = true;
	//		}
	//	}
	//}
	//for (int i = 0; i < coEvents.size(); i++)
	//	delete coEvents[i];
#pragma endregion

	state->Colision();
	state->Update(dt);

#pragma region Set new area collision when Guard2 is attacking

	if (this->GetAttacking())
	{
		if (this->isLeft)
			this->collider.x = x - 35;
		this->collider.width = GUARD2_SPRITE_WIDTH + 35;
	}
	else
	{
		this->collider.width = GUARD2_SPRITE_WIDTH;
		this->collider.x = x;
	}

#pragma endregion
}

void Guard2::Render()
{
	if (this->disable)
		return;

	state->Render();
	enemiesDeadEffect->Render();
}

void Guard2::UpdateCollision(DWORD dt)
{
	bool isCollideAladdin = Collision::GetInstance()->AABB(this->GetCollider(), Aladdin::GetInstance()->GetCollider());
	bool isCollideApple = Collision::GetInstance()->AABB(this->GetCollider(), Apple::GetInstance()->GetCollider());

	if (isCollideAladdin)
	{
		if (Aladdin::GetInstance()->GetAttacking())
		{
			this->SetGuard2HP(this->GetGuard2HP() - Aladdin::GetInstance()->GetDmgAttack());

			if (this->GetGuard2HP() > 0)
			{
				Sound::GetInstance()->PlaySound(guardHurt);
				this->state->SetState(GUARD2_HURT);
			}
			else
			{
				enemiesDeadEffect->SetPos(this->GetPositionX() + 20, this->GetPositionY(), false);
				this->state->SetState(GUARD2_DEAD);
			}
		}
	}
	if (isCollideApple)
	{
		this->SetGuard2HP(this->GetGuard2HP() - Aladdin::GetInstance()->GetDmgAttack());

		if (this->GetGuard2HP() > 0)
		{
			Sound::GetInstance()->PlaySound(headBop);
			this->state->SetState(GUARD2_HURT);
		}
		else
		{
			enemiesDeadEffect->SetPos(this->GetPositionX() + 20, this->GetPositionY(), false);
			this->state->SetState(GUARD2_DEAD);
		}
	}
}

void Guard2::OnCollision()
{
	((Guard2State*)state)->timeCount = 0;
}