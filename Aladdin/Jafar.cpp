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

	Animation * anim = new Animation(100);
	Sprite *jafar_0 = new Sprite(jafar->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_0);
	animations.push_back(anim);

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

	anim = new Animation(120);
	Sprite *jafar_1 = new Sprite(jafar->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_1);
	Sprite *jafar_2 = new Sprite(jafar->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_2);
	Sprite *jafar_3 = new Sprite(jafar->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_3);
	Sprite *jafar_4 = new Sprite(jafar->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_4);
	Sprite *jafar_5 = new Sprite(jafar->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_5);
	Sprite *jafar_6 = new Sprite(jafar->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_6);
	Sprite *jafar_7 = new Sprite(jafar->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_7);
	anim->AddFrame(jafar_7);

	animations.push_back(anim);
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

			if (this->GetHP() > 0)
			{
				this->state->SetState(JAFAR_HURT);
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

		if (this->GetHP() > 0)
		{
			this->state->SetState(JAFAR_HURT);
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