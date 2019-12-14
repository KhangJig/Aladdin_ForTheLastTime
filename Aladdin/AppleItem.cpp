#include "AppleItem.h"
#include "Guard1State.h"

vector<Animation *> AppleItem::animations = vector<Animation *>();

AppleItem::AppleItem(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = APPLE_ITEM_WIDTH;
	collider.height = APPLE_ITEM_HEIGHT;
}

void AppleItem::LoadResources(RECT* listSprite, Sprite * items)
{
	Animation * anim = new Animation(100);
	Sprite *apple = new Sprite(items->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(apple);
	animations.push_back(anim);
}

void AppleItem::Update(DWORD dt)
{

}

void AppleItem::Render()
{
	SpriteData spriteData;

	spriteData.width = APPLE_ITEM_WIDTH;
	spriteData.height = APPLE_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = true;

	this->animations[0]->Render(spriteData);
}

AppleItem::~AppleItem()
{

}