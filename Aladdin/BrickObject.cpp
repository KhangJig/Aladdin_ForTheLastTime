#include "BrickObject.h"
#include "Guard1State.h"

vector<Animation *> BrickObject::animations = vector<Animation *>();

BrickObject::BrickObject(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = BRICK_ITEM_WIDTH;
	collider.height = BRICK_ITEM_HEIGHT;
}

void BrickObject::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Background\\MapObjects.txt");
	Sprite * items = new Sprite(MAPOBJECTS_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_6);

	Animation * anim = new Animation(700);
	Sprite *brick_1 = new Sprite(items->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_1);
	Sprite *brick_2 = new Sprite(items->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_2);
	Sprite *brick_3 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_3);
	Sprite *brick_4 = new Sprite(items->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_4);
	Sprite *brick_5 = new Sprite(items->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_5);
	Sprite *brick_6 = new Sprite(items->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_6);
	Sprite *brick_7 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_7);
	Sprite *brick_8 = new Sprite(items->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_8);
	Sprite *brick_9 = new Sprite(items->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(brick_9);

	animations.push_back(anim);
}

void BrickObject::Update(DWORD dt)
{

}

void BrickObject::Render()
{
	SpriteData spriteData;

	spriteData.width = BRICK_ITEM_WIDTH;
	spriteData.height = BRICK_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	this->animations[0]->Render(spriteData);
}

BrickObject::~BrickObject()
{

}