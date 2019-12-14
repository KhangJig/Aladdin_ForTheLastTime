#include "ThornObject.h"
#include "Guard1State.h"

vector<Animation *> ThornObject::animations = vector<Animation *>();

ThornObject::ThornObject(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x + 10;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	this->state = ThornState::ThornState1;
	collider.width = THORN_ITEM_WIDTH;
	collider.height = THORN_ITEM_HEIGHT;

	this->soundAction = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_OBJECT_THROW);
}

void ThornObject::LoadResources(RECT* listSprite, Sprite * items)
{
	Animation * anim = new Animation(200);
	Sprite *thorn_idle_1 = new Sprite(items->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_idle_1);
	animations.push_back(anim);

	anim = new Animation(60);
	Sprite *thorn_2 = new Sprite(items->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_2);
	Sprite *thorn_3 = new Sprite(items->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_3);
	Sprite *thorn_4 = new Sprite(items->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_4);
	Sprite *thorn_5 = new Sprite(items->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_5);
	Sprite *thorn_6 = new Sprite(items->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_6);
	animations.push_back(anim);

	anim = new Animation(400);
	Sprite *thorn_back_2 = new Sprite(items->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_back_2);
	Sprite *thorn_back_3 = new Sprite(items->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_back_3);
	Sprite *thorn_back_4 = new Sprite(items->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_back_4);
	Sprite *thorn_back_5 = new Sprite(items->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_back_5);
	Sprite *thorn_back_6 = new Sprite(items->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_6);
	animations.push_back(anim);
}

void ThornObject::Update(DWORD dt)
{

}

void ThornObject::Render()
{
	SpriteData spriteData;

	spriteData.width = THORN_ITEM_WIDTH;
	spriteData.height = THORN_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	switch (this->state)
	{
	case ThornState::ThornState1:
	{
		this->animations[ThornState::ThornState1]->Render(spriteData);
		if (this->animations[ThornState::ThornState1]->IsDone())
		{
			Sound::GetInstance()->PlaySound(soundAction);
			this->state = ThornState::ThornState2;
		}
	}break;
	case ThornState::ThornState2: 
	{
		this->animations[ThornState::ThornState2]->Render(spriteData);
		if (this->animations[ThornState::ThornState2]->IsDone())
		{
			this->state = ThornState::ThornState3;
		}
	}break;
	case ThornState::ThornState3:
	{
		this->animations[ThornState::ThornState3]->Render(spriteData);
		if (this->animations[ThornState::ThornState3]->IsDone())
		{
			this->state = ThornState::ThornState1;
		}
	}break;
	}
}

ThornObject::~ThornObject()
{

}