#include "ThornObject.h"
#include "Guard1State.h"

vector<Animation *> ThornObject::animations = vector<Animation *>();

ThornObject::ThornObject(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = THORN_ITEM_WIDTH;
	collider.height = THORN_ITEM_HEIGHT;
}

void ThornObject::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Background\\MapObjects.txt");
	Sprite * items = new Sprite(MAPOBJECTS_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_6);

	Animation * anim = new Animation(700);
	Sprite *thorn_1 = new Sprite(items->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_1);
	Sprite *thorn_2 = new Sprite(items->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_2);
	Sprite *thorn_3 = new Sprite(items->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_3);
	Sprite *thorn_4 = new Sprite(items->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_4);
	Sprite *thorn_5 = new Sprite(items->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_5);
	Sprite *thorn_6 = new Sprite(items->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_6);
	Sprite *thorn_7 = new Sprite(items->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_7);
	Sprite *thorn_8 = new Sprite(items->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_8);
	Sprite *thorn_9 = new Sprite(items->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_9);
	Sprite *thorn_10 = new Sprite(items->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_10);
	Sprite *thorn_11 = new Sprite(items->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(thorn_11);

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

	this->animations[0]->Render(spriteData);
}

ThornObject::~ThornObject()
{

}