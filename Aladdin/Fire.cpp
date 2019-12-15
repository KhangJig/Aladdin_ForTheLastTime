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
	Sprite *fire;
	Animation * anim = new Animation(80);
	//fire = new Sprite(items->GetTexture(), listSprite[30], TEXTURE_TRANS_COLOR_5);
	//anim->AddFrame(fire);
	//fire = new Sprite(items->GetTexture(), listSprite[31], TEXTURE_TRANS_COLOR_5);
	//anim->AddFrame(fire);
	//fire = new Sprite(items->GetTexture(), listSprite[32], TEXTURE_TRANS_COLOR_5);
	//anim->AddFrame(fire);
	//fire = new Sprite(items->GetTexture(), listSprite[33], TEXTURE_TRANS_COLOR_5);
	//anim->AddFrame(fire);
	//fire = new Sprite(items->GetTexture(), listSprite[34], TEXTURE_TRANS_COLOR_5);
	//anim->AddFrame(fire);
	//fire = new Sprite(items->GetTexture(), listSprite[35], TEXTURE_TRANS_COLOR_5);
	//anim->AddFrame(fire);
	fire = new Sprite(items->GetTexture(), listSprite[36], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(fire);
	fire = new Sprite(items->GetTexture(), listSprite[37], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(fire);
	animations.push_back(anim);
}

void Fire::Update(DWORD dt)
{
	this->UpdateCollision(dt);
	if (this->Direction)
	{
		this->setIsLeft(false);
		this->SetSpeedX(JFIRE2_SPEED);
		collider.x = x - 10;
	}
	else
	{
		this->setIsLeft(true);
		this->SetSpeedX(-JFIRE2_SPEED);
		collider.x = x + 49;
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