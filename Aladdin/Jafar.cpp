#include "Jafar.h"

vector<Animation *> Jafar::animations = vector<Animation *>();

Jafar::Jafar(int x, int y)
{
	this->state = new JafarState(this);

	this->x = x;
	this->y = y;
	this->width = JAFAR_SPRITE_WIDTH;
	this->height = JAFAR_SPRITE_HEIGHT;

	this->HP = 1000;
	this->Dmg = 50;
	this->SnakePower = false;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = JAFAR_SPRITE_WIDTH;
	collider.height = JAFAR_SPRITE_HEIGHT;

	this->disable = false;
}

void Jafar::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Boss\\Jafar.txt");
	Sprite * jafar = new Sprite(JAFAR_TEXTURE_SPRITE, TEXTURE_TRANS_COLOR_7);

#pragma region JAFAR IDLE
	Animation * anim = new Animation(100);
	Sprite *jafar_0 = new Sprite(jafar->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_0);

	animations.push_back(anim);
#pragma endregion

#pragma region JAFAR HURT
	anim = new Animation(80);
	Sprite *jafar_hurt_0 = new Sprite(jafar->GetTexture(), listSprite[37], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_hurt_0);
	Sprite *jafar_hurt_1 = new Sprite(jafar->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_hurt_1);
	Sprite *jafar_hurt_2 = new Sprite(jafar->GetTexture(), listSprite[37], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_hurt_2);
	Sprite *jafar_hurt_3 = new Sprite(jafar->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_hurt_3);

	animations.push_back(anim);
#pragma endregion

#pragma region JAFAR HIT
	anim = new Animation(140);
	Sprite *jafar_1 = new Sprite(jafar->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_1);
	Sprite *jafar_2 = new Sprite(jafar->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_7);
	jafar_2->SetOffSetX(-1);
	jafar_2->SetOffSetY(-1);
	anim->AddFrame(jafar_2);
	Sprite *jafar_3 = new Sprite(jafar->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_7);
	jafar_3->SetOffSetX(-1);
	jafar_3->SetOffSetY(-2);
	anim->AddFrame(jafar_3);
	Sprite *jafar_4 = new Sprite(jafar->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_7);
	jafar_4->SetOffSetX(-1);
	jafar_4->SetOffSetY(-3);
	anim->AddFrame(jafar_4);
	Sprite *jafar_5 = new Sprite(jafar->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_7);
	jafar_5->SetOffSetX(-1);
	jafar_5->SetOffSetY(-2);
	anim->AddFrame(jafar_5);
	Sprite *jafar_6 = new Sprite(jafar->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_7);
	jafar_6->SetOffSetX(-1);
	jafar_6->SetOffSetY(-2);
	anim->AddFrame(jafar_6);
	Sprite *jafar_7 = new Sprite(jafar->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_7);
	jafar_7->SetOffSetX(-2);
	jafar_7->SetOffSetY(-2);
	anim->AddFrame(jafar_7);
	Sprite *jafar_8 = new Sprite(jafar->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_7);
	jafar_8->SetOffSetX(-2);
	jafar_8->SetOffSetY(-2);
	anim->AddFrame(jafar_8);

	animations.push_back(anim);
#pragma endregion

#pragma region SNAKE IDLE
	anim = new Animation(140);
	Sprite *snake_1 = new Sprite(jafar->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(snake_1);

	animations.push_back(anim);
#pragma endregion

#pragma region SNAKE HURT
	anim = new Animation(80);
	Sprite *snake_hurt_0 = new Sprite(jafar->GetTexture(), listSprite[37], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(snake_hurt_0);
	Sprite *snake_hurt_1 = new Sprite(jafar->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(snake_hurt_1);
	Sprite *snake_hurt_2 = new Sprite(jafar->GetTexture(), listSprite[37], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(snake_hurt_2);
	Sprite *snake_hurt_3 = new Sprite(jafar->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(snake_hurt_3);

	animations.push_back(anim);
#pragma endregion

#pragma region SNAKE HIT
	anim = new Animation(140);
	Sprite *snake_hit_1 = new Sprite(jafar->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_7);
	snake_hit_1->SetOffSetX(-31);
	snake_hit_1->SetOffSetY(-25);
	anim->AddFrame(snake_hit_1);
	Sprite *snake_hit_2 = new Sprite(jafar->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_7);
	snake_hit_2->SetOffSetX(-18);
	snake_hit_2->SetOffSetY(-19);
	anim->AddFrame(snake_hit_2);
	Sprite *snake_hit_3 = new Sprite(jafar->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_7);
	snake_hit_3->SetOffSetX(-5);
	snake_hit_3->SetOffSetY(-11);
	anim->AddFrame(snake_hit_3);
	Sprite *snake_hit_4 = new Sprite(jafar->GetTexture(), listSprite[11], TEXTURE_TRANS_COLOR_7);
	snake_hit_4->SetOffSetX(1);
	snake_hit_4->SetOffSetY(-11);
	anim->AddFrame(snake_hit_4);
	Sprite *snake_hit_5 = new Sprite(jafar->GetTexture(), listSprite[12], TEXTURE_TRANS_COLOR_7);
	snake_hit_5->SetOffSetY(1);
	anim->AddFrame(snake_hit_5);
	Sprite *snake_hit_6 = new Sprite(jafar->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_7);
	snake_hit_6->SetOffSetX(-1);
	anim->AddFrame(snake_hit_6);
	Sprite *snake_hit_7 = new Sprite(jafar->GetTexture(), listSprite[14], TEXTURE_TRANS_COLOR_7);
	snake_hit_6->SetOffSetY(-1);
	anim->AddFrame(snake_hit_7);
	Sprite *snake_hit_8 = new Sprite(jafar->GetTexture(), listSprite[15], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(snake_hit_8);
	Sprite *snake_hit_9 = new Sprite(jafar->GetTexture(), listSprite[16], TEXTURE_TRANS_COLOR_7);
	snake_hit_9->SetOffSetX(-5);
	snake_hit_9->SetOffSetY(2);
	anim->AddFrame(snake_hit_9);
	Sprite *snake_hit_10 = new Sprite(jafar->GetTexture(), listSprite[17], TEXTURE_TRANS_COLOR_7);
	snake_hit_10->SetOffSetX(-21);
	anim->AddFrame(snake_hit_10);
	Sprite *snake_hit_11 = new Sprite(jafar->GetTexture(), listSprite[18], TEXTURE_TRANS_COLOR_7);
	snake_hit_11->SetOffSetX(-32);
	snake_hit_11->SetOffSetY(-21);
	anim->AddFrame(snake_hit_11);

	animations.push_back(anim);
#pragma endregion
}

void Jafar::Update(DWORD dt)
{
	if (this->disable)
		return;

	if (this->GetX() > Aladdin::GetInstance()->GetPositionX())
	{
		this->setIsLeft(false);
	}
	else
	{
		this->setIsLeft(true);
	}

	bool isCollideAladdin = Collision::GetInstance()->AABB(this->GetCollider(), Aladdin::GetInstance()->GetCollider());
	bool isCollideApple = Collision::GetInstance()->AABB(this->GetCollider(), Apple::GetInstance()->GetCollider());

	if (isCollideAladdin)
	{
		if (Aladdin::GetInstance()->GetAttacking())
		{
			this->SetHP(this->GetHP() - Aladdin::GetInstance()->GetDmgAttack());
			DebugOut(L"HP Jafar : %d \n", this->GetHP());
			if (this->GetHP() > 0)
			{
				if (this->GetHP() >= 300)
				{
					this->state->SetState(JAFAR_HURT);
				}
				else if (this->GetHP() < 300 || this->SnakePower)
				{
					this->state->SetState(SNAKE_HURT);
				}
				else
				{
					this->state->SetState(SNAKE_IDLE);
					this->SnakePower = true;
					this->Dmg += 20;

					this->width = SNAKE_SPRITE_WIDTH;
					this->height = SNAKE_SPRITE_HEIGHT;
					collider.width = SNAKE_SPRITE_WIDTH;
					collider.height = SNAKE_SPRITE_HEIGHT;
				}
			}
			else
			{
				//DEAD
			}
		}
	}
	if (isCollideApple)
	{
		this->SetHP(this->GetHP() - Aladdin::GetInstance()->GetDmgAttack());
		DebugOut(L"HP Jafar : %d \n", this->GetHP());
		if (this->GetHP() > 0)
		{
			if (this->GetHP() >= 300)
			{
				this->state->SetState(JAFAR_HURT);
			}
			else if (this->GetHP() < 300 || this->SnakePower)
			{
				this->state->SetState(SNAKE_HURT);
			}
			else
			{
				this->state->SetState(SNAKE_IDLE);
				this->SnakePower = true;
				this->Dmg += 20;

				this->width = SNAKE_SPRITE_WIDTH;
				this->height = SNAKE_SPRITE_HEIGHT;
				collider.width = SNAKE_SPRITE_WIDTH;
				collider.height = SNAKE_SPRITE_HEIGHT;
			}
		}
		else
		{
			//DEAD
		}
	}

	state->Colision();
	state->Update(dt);
}

void Jafar::Render()
{
	if (this->disable)
		return;

	state->Render();
}

void Jafar::OnCollision()
{
	((JafarState*)state)->timeCount = 0;
}

Jafar::~Jafar()
{

}