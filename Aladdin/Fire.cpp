#include "Fire.h"
#include "Guard1State.h"

vector<Animation *> Fire::animations = vector<Animation *>();

Fire::Fire(float x, float y, bool direction)
{
	this->x = x;
	this->y = y;
	this->Direction = direction;
	this->SetSpeedX(0);
	this->Radius = JFIRE2_RADIUS;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = FIRE2_SPRITE_WIDTH;
	collider.height = JFIRE2_SPRITE_HEIGHT;
}

void Fire::LoadResources(RECT* listSprite, Sprite * items)
{
	Animation * anim = new Animation(80);
	Sprite * fire_1 = new Sprite(items->GetTexture(), listSprite[30], TEXTURE_TRANS_COLOR);
	fire_1->SetOffSetY(0);
	anim->AddFrame(fire_1);
	Sprite * fire_2 = new Sprite(items->GetTexture(), listSprite[31], TEXTURE_TRANS_COLOR);
	fire_2->SetOffSetX(1);
	fire_2->SetOffSetY(-2);
	anim->AddFrame(fire_2);
	Sprite * fire_3 = new Sprite(items->GetTexture(), listSprite[32], TEXTURE_TRANS_COLOR);
	fire_3->SetOffSetX(2);
	fire_3->SetOffSetY(-8);
	anim->AddFrame(fire_3);
	Sprite * fire_4 = new Sprite(items->GetTexture(), listSprite[33], TEXTURE_TRANS_COLOR);
	fire_4->SetOffSetX(-3);
	fire_4->SetOffSetY(-9);
	anim->AddFrame(fire_4);
	Sprite * fire_5 = new Sprite(items->GetTexture(), listSprite[34], TEXTURE_TRANS_COLOR);
	fire_5->SetOffSetX(-7);
	fire_5->SetOffSetY(-31);
	anim->AddFrame(fire_5);
	Sprite * fire_6 = new Sprite(items->GetTexture(), listSprite[35], TEXTURE_TRANS_COLOR);
	fire_6->SetOffSetX(-6);
	fire_6->SetOffSetY(-19);
	anim->AddFrame(fire_6);
	Sprite * fire_7 = new Sprite(items->GetTexture(), listSprite[36], TEXTURE_TRANS_COLOR);
	fire_7->SetOffSetX(-4);
	fire_7->SetOffSetY(-7);
	anim->AddFrame(fire_7);
	Sprite * fire_8 = new Sprite(items->GetTexture(), listSprite[37], TEXTURE_TRANS_COLOR);
	fire_8->SetOffSetY(1);
	anim->AddFrame(fire_8);
	animations.push_back(anim);
}

void Fire::Update(DWORD dt)
{
	this->UpdateCollision(dt);
	if (this->Direction)
	{
		this->setIsLeft(false);
		this->SetSpeedX(JFIRE2_SPEED);
		collider.x = x;
	}
	else
	{
		this->setIsLeft(true);
		this->SetSpeedX(-JFIRE2_SPEED);
		collider.x = x + FIRE2_SPRITE_WIDTH;
	}

	this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	this->collider.x = this->GetPositionX();
}

void Fire::UpdateCollision(DWORD dt)
{
	bool isCollideAladdin = Collision::GetInstance()->AABB(this->GetCollider(), Aladdin::GetInstance()->GetCollider());

	if (isCollideAladdin)
	{
		Aladdin::GetInstance()->SetAladdinHP(Aladdin::GetInstance()->GetAladdinHP() - 1);

		if (Aladdin::GetInstance()->GetAladdinHP() > 0)
		{
			Aladdin::GetInstance()->GetState()->SetState(STATE_HURT);
			Aladdin::GetInstance()->SetAttacking(false);
		}
	}
}

void Fire::Render()
{
	SpriteData spriteData;

	spriteData.width = FIRE2_SPRITE_WIDTH;
	spriteData.height = JFIRE2_SPRITE_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = this->IsLeft();;
	spriteData.isFlipped = !this->IsFlipped();

	this->animations[0]->Render(spriteData);
}

Fire::~Fire()
{

}