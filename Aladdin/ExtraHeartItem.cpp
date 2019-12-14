#include "ExtraHeartItem.h"
#include "Guard1State.h"

vector<Animation *> ExtraHeartItem::animations = vector<Animation *>();

ExtraHeartItem::ExtraHeartItem(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = EXTRA_HEART_ITEM_WIDTH;
	collider.height = EXTRA_HEART_ITEM_HEIGHT;
}

void ExtraHeartItem::LoadResources(RECT* listSprite, Sprite * items)
{
	Animation * anim = new Animation(300);
	Sprite *extra_heart_1 = new Sprite(items->GetTexture(), listSprite[17], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(extra_heart_1);
	Sprite *extra_heart_2 = new Sprite(items->GetTexture(), listSprite[18], TEXTURE_TRANS_COLOR_5);
	extra_heart_2->SetOffSetX(-2);
	extra_heart_2->SetOffSetY(-2);
	anim->AddFrame(extra_heart_2);
	Sprite *extra_heart_3 = new Sprite(items->GetTexture(), listSprite[19], TEXTURE_TRANS_COLOR_5);
	extra_heart_3->SetOffSetX(-2);
	extra_heart_3->SetOffSetY(-3);
	anim->AddFrame(extra_heart_3);
	Sprite *extra_heart_4 = new Sprite(items->GetTexture(), listSprite[20], TEXTURE_TRANS_COLOR_5);
	extra_heart_4->SetOffSetX(-2);
	extra_heart_4->SetOffSetY(-3);
	anim->AddFrame(extra_heart_4);
	Sprite *extra_heart_5 = new Sprite(items->GetTexture(), listSprite[21], TEXTURE_TRANS_COLOR_5);
	extra_heart_5->SetOffSetX(-1);
	extra_heart_5->SetOffSetY(-2);
	anim->AddFrame(extra_heart_5);
	Sprite *extra_heart_6 = new Sprite(items->GetTexture(), listSprite[22], TEXTURE_TRANS_COLOR_5);
	extra_heart_6->SetOffSetX(-1);
	extra_heart_6->SetOffSetY(-3);
	anim->AddFrame(extra_heart_6);
	Sprite *extra_heart_7 = new Sprite(items->GetTexture(), listSprite[23], TEXTURE_TRANS_COLOR_5);
	extra_heart_7->SetOffSetX(-2);
	extra_heart_7->SetOffSetY(-4);
	anim->AddFrame(extra_heart_7);
	Sprite *extra_heart_8 = new Sprite(items->GetTexture(), listSprite[24], TEXTURE_TRANS_COLOR_5);
	extra_heart_8->SetOffSetX(-2);
	extra_heart_8->SetOffSetY(-4);
	anim->AddFrame(extra_heart_8);
	animations.push_back(anim);
}

void ExtraHeartItem::Update(DWORD dt)
{

}

void ExtraHeartItem::Render()
{
	SpriteData spriteData;

	spriteData.width = EXTRA_HEART_ITEM_WIDTH;
	spriteData.height = EXTRA_HEART_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	this->animations[0]->Render(spriteData);
}

ExtraHeartItem::~ExtraHeartItem()
{

}