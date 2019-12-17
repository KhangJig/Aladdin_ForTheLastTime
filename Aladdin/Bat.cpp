#include "Bat.h"

vector<Animation *> Bat::animations = vector<Animation *>();

Bat::Bat(float x, float y, int CellID, int id)
{
	this->state = new BatState(this);

	this->x = x;
	this->y = y;
	this->width = BAT_SPRITE_WIDTH;
	this->height = BAT_SPRITE_HEIGHT;

	this->CellID = CellID;
	this->id = id;

	this->BatHP = BAT_HP;
	this->Dmg = BAT_DAMAGE;
	this->disable = false;
	this->ReadyAttack = true;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = BAT_SPRITE_WIDTH;
	collider.height = BAT_SPRITE_HEIGHT;

	enemiesDeadEffect = new EnemiesDeadEffect(0, 0);
}

void Bat::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Enemies\\Bat.txt");
	Sprite * bat = new Sprite(BAT_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR);

#pragma region IDLE
	Animation * anim = new Animation(100);

	Sprite * bat_idle_1 = new Sprite(bat->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_idle_1);

	animations.push_back(anim);
#pragma endregion

#pragma region START FLY
	anim = new Animation(100);

	Sprite * bat_start_fly_1 = new Sprite(bat->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_start_fly_1);
	Sprite * bat_start_fly_2 = new Sprite(bat->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_start_fly_2);
	Sprite * bat_start_fly_3 = new Sprite(bat->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_start_fly_3);

	animations.push_back(anim);
#pragma endregion

#pragma region FLYING
	anim = new Animation(50);

	Sprite * bat_stand_1 = new Sprite(bat->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_stand_1);
	Sprite * bat_stand_2 = new Sprite(bat->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_stand_2);
	Sprite * bat_stand_3 = new Sprite(bat->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_stand_3);
	Sprite * bat_stand_4 = new Sprite(bat->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_stand_4);
	Sprite * bat_stand_5 = new Sprite(bat->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_stand_5);
	Sprite * bat_stand_6 = new Sprite(bat->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_stand_6);
	Sprite * bat_stand_7 = new Sprite(bat->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_stand_7);

	animations.push_back(anim);
#pragma endregion

#pragma region Be kill by Apple
	anim = new Animation(80);

	Sprite * bat_bekill_by_apple_1 = new Sprite(bat->GetTexture(), listSprite[11], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_1);
	Sprite * bat_bekill_by_apple_2 = new Sprite(bat->GetTexture(), listSprite[12], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_2);
	Sprite * bat_bekill_by_apple_3 = new Sprite(bat->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_3);
	Sprite * bat_bekill_by_apple_4 = new Sprite(bat->GetTexture(), listSprite[14], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_4);
	Sprite * bat_bekill_by_apple_5 = new Sprite(bat->GetTexture(), listSprite[15], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_5);
	Sprite * bat_bekill_by_apple_6 = new Sprite(bat->GetTexture(), listSprite[16], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_6);
	Sprite * bat_bekill_by_apple_7 = new Sprite(bat->GetTexture(), listSprite[17], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_7);
	Sprite * bat_bekill_by_apple_8 = new Sprite(bat->GetTexture(), listSprite[18], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_8);
	Sprite * bat_bekill_by_apple_9 = new Sprite(bat->GetTexture(), listSprite[19], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_apple_9);
	animations.push_back(anim);
#pragma endregion

#pragma region Be kill by Sword
	anim = new Animation(80);

	Sprite * bat_bekill_by_sword = new Sprite(bat->GetTexture(), listSprite[20], TEXTURE_TRANS_COLOR);
	anim->AddFrame(bat_bekill_by_sword);

	animations.push_back(anim);
#pragma endregion

}

void Bat::Update(DWORD dt)
{
	if (!this->ReadyAttack)
	{
		this->timeStop += dt;
	}

	if (this->GetPositionX() > Aladdin::GetInstance()->GetPositionX())
		this->setIsLeft(true);
	else
		this->setIsLeft(false);

	this->UpdateCollision(dt);
	if (this->disable)
		return;

	this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	this->SetPositionY((float)(this->GetPositionY() + this->GetSpeedY()* dt));
	this->collider.x = this->GetPositionX();
	this->collider.y = this->GetPositionY();

	state->Colision();
	state->Update(dt);
}

void Bat::Render()
{
	if (this->disable)
		return;

	if (this->timeStop > 5000)
	{
		this->ReadyAttack = true;
		this->timeStop = 0;
	}

	state->Render();
	enemiesDeadEffect->Render();
}

void Bat::UpdateCollision(DWORD dt)
{
	bool isCollideAladdin = Collision::GetInstance()->AABB(this->GetCollider(), Aladdin::GetInstance()->GetCollider());
	bool isCollideApple = Collision::GetInstance()->AABB(this->GetCollider(), Apple::GetInstance()->GetCollider());

	if (this->ReadyAttack && isCollideAladdin)
	{
		this->ReadyAttack = false;
		this->state->SetState(BAT_FLYING);
	}

	if (isCollideAladdin)
	{
		if (Aladdin::GetInstance()->GetAttacking())
		{
			this->SetBatHP(this->GetBatHP() - Aladdin::GetInstance()->GetDmgAttack());

			if (this->GetBatHP() <= 0)
			{
				enemiesDeadEffect->SetPos(this->GetPositionX() + BAT_SPRITE_WIDTH, this->GetPositionY() + BAT_SPRITE_HEIGHT * 2, false);
				this->state->SetState(BAT_BE_KILL_SWORD);
			}
		}
	}
	if (isCollideApple)
	{
		this->SetBatHP(this->GetBatHP() - Aladdin::GetInstance()->GetDmgAttack());

		if (this->GetBatHP() <= 0)
		{
			this->state->SetState(BAT_BE_KILL_APPLE);
		}
	}
}

void Bat::OnCollision()
{

}