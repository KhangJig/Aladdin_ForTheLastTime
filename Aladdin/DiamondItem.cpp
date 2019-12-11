#include "DiamondItem.h"
#include "Guard1State.h"

vector<Animation *> DiamondItem::animations = vector<Animation *>();

DiamondItem::DiamondItem(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = DIAMOND_ITEM_WIDTH;
	collider.height = DIAMOND_ITEM_HEIGHT;
}

void DiamondItem::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Miscellaneous\\Items.txt");
	Sprite * items = new Sprite(ITEMS_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_5);

	Animation * anim = new Animation(100);
	Sprite *diamond_1 = new Sprite(items->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(diamond_1);
	Sprite *diamond_2 = new Sprite(items->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(diamond_2);
	Sprite *diamond_3 = new Sprite(items->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(diamond_3);
	Sprite *diamond_4 = new Sprite(items->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(diamond_4);
	Sprite *diamond_5 = new Sprite(items->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_5);
	diamond_5->SetOffSetY(1);
	anim->AddFrame(diamond_5);
	Sprite *diamond_6 = new Sprite(items->GetTexture(), listSprite[11], TEXTURE_TRANS_COLOR_5);
	diamond_6->SetOffSetX(6);
	diamond_6->SetOffSetY(4);
	anim->AddFrame(diamond_6);
	Sprite *diamond_7 = new Sprite(items->GetTexture(), listSprite[12], TEXTURE_TRANS_COLOR_5);
	diamond_7->SetOffSetY(2);
	anim->AddFrame(diamond_7);
	Sprite *diamond_8 = new Sprite(items->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(diamond_8);
	Sprite *diamond_9 = new Sprite(items->GetTexture(), listSprite[14], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(diamond_9);

	animations.push_back(anim);
}

void DiamondItem::Update(DWORD dt)
{

}

void DiamondItem::Render()
{
	SpriteData spriteData;

	spriteData.width = DIAMOND_ITEM_WIDTH;
	spriteData.height = DIAMOND_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = true;

	this->animations[0]->Render(spriteData);
}

DiamondItem::~DiamondItem()
{

}