#include "BottleItem.h"
#include "Guard1State.h"

vector<Animation *> BottleItem::animations = vector<Animation *>();

BottleItem::BottleItem(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = BOTTLE_ITEM_WIDTH;
	collider.height = BOTTLE_ITEM_HEIGHT;

	this->state = BottleState::BottleState1;
	this->check = false;
}

void BottleItem::LoadResources(RECT* listSprite, Sprite * items)
{
	Animation * anim = new Animation(1000);
	Sprite *bottle_idle = new Sprite(items->GetTexture(), listSprite[35], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_idle);
	animations.push_back(anim);

	anim = new Animation(40);
	Sprite *bottle_active_1 = new Sprite(items->GetTexture(), listSprite[35], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_1);
	Sprite *bottle_active_2 = new Sprite(items->GetTexture(), listSprite[36], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_2);
	Sprite *bottle_active_3 = new Sprite(items->GetTexture(), listSprite[37], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_3);
	Sprite *bottle_active_4 = new Sprite(items->GetTexture(), listSprite[38], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_4);
	Sprite *bottle_active_5 = new Sprite(items->GetTexture(), listSprite[39], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_5);
	Sprite *bottle_active_6 = new Sprite(items->GetTexture(), listSprite[40], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_6);
	Sprite *bottle_active_7 = new Sprite(items->GetTexture(), listSprite[41], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_7);
	Sprite *bottle_active_8 = new Sprite(items->GetTexture(), listSprite[42], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_8);
	Sprite *bottle_active_9 = new Sprite(items->GetTexture(), listSprite[43], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_9);
	Sprite *bottle_active_10 = new Sprite(items->GetTexture(), listSprite[44], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_active_10);
	animations.push_back(anim);

	anim = new Animation(1000);
	Sprite *bottle_actived = new Sprite(items->GetTexture(), listSprite[44], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(bottle_actived);

	animations.push_back(anim);
}

void BottleItem::Update(DWORD dt)
{
	if (this->check && this->state != BottleState::BottleState3)
	{
		this->state = BottleState::BottleState2;
	}
}

void BottleItem::Render()
{
	SpriteData spriteData;

	spriteData.width = BOTTLE_ITEM_WIDTH;
	spriteData.height = BOTTLE_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	switch (this->state)
	{
	case BottleState::BottleState1:
	{
		this->animations[0]->Render(spriteData);
	}break;
	case BottleState::BottleState2:
	{
		this->animations[1]->Render(spriteData);
		if (this->animations[1]->IsDone())
		{
			this->state = BottleState::BottleState3;
		}
	}break;
	case BottleState::BottleState3:
	{
		this->animations[2]->Render(spriteData);
	}break;
	}
}

BottleItem::~BottleItem()
{

}