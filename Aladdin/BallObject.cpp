#include "BallObject.h"
#include "Guard1State.h"

vector<Animation *> BallObject::animations = vector<Animation *>();

BallObject::BallObject(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = BALL_ITEM_WIDTH + 10;
	collider.height = BALL_ITEM_HEIGHT;
}

void BallObject::LoadResources(RECT* listSprite, Sprite * items)
{
	Animation * anim = new Animation(100);
	Sprite *ball_1 = new Sprite(items->GetTexture(), listSprite[11], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_1);
	Sprite *ball_2 = new Sprite(items->GetTexture(), listSprite[12], TEXTURE_TRANS_COLOR_6);
	ball_2->SetOffSetX(1);
	anim->AddFrame(ball_2);
	Sprite *ball_3 = new Sprite(items->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_6);
	ball_3->SetOffSetX(1);
	anim->AddFrame(ball_3);
	Sprite *ball_4 = new Sprite(items->GetTexture(), listSprite[14], TEXTURE_TRANS_COLOR_6);
	ball_4->SetOffSetX(1);
	anim->AddFrame(ball_4);
	Sprite *ball_5 = new Sprite(items->GetTexture(), listSprite[15], TEXTURE_TRANS_COLOR_6);
	ball_5->SetOffSetX(1);
	anim->AddFrame(ball_5);
	Sprite *ball_6 = new Sprite(items->GetTexture(), listSprite[16], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_6);
	Sprite *ball_7 = new Sprite(items->GetTexture(), listSprite[17], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_7);
	Sprite *ball_8 = new Sprite(items->GetTexture(), listSprite[18], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_8);
	Sprite *ball_9 = new Sprite(items->GetTexture(), listSprite[19], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_9);
	Sprite *ball_10 = new Sprite(items->GetTexture(), listSprite[20], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_10);
	Sprite *ball_11 = new Sprite(items->GetTexture(), listSprite[21], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_11);
	Sprite *ball_12 = new Sprite(items->GetTexture(), listSprite[22], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_12);
	Sprite *ball_13 = new Sprite(items->GetTexture(), listSprite[23], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_13);
	Sprite *ball_14 = new Sprite(items->GetTexture(), listSprite[24], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_14);
	Sprite *ball_16 = new Sprite(items->GetTexture(), listSprite[24], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_16);
	Sprite *ball_17 = new Sprite(items->GetTexture(), listSprite[23], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_17);
	Sprite *ball_18 = new Sprite(items->GetTexture(), listSprite[22], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_18);
	Sprite *ball_19 = new Sprite(items->GetTexture(), listSprite[21], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_19);
	Sprite *ball_20 = new Sprite(items->GetTexture(), listSprite[20], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_20);
	Sprite *ball_21 = new Sprite(items->GetTexture(), listSprite[19], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_21);
	Sprite *ball_22 = new Sprite(items->GetTexture(), listSprite[18], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_22);
	Sprite *ball_23 = new Sprite(items->GetTexture(), listSprite[17], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_23);
	Sprite *ball_25 = new Sprite(items->GetTexture(), listSprite[16], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(ball_25);
	Sprite *ball_26 = new Sprite(items->GetTexture(), listSprite[15], TEXTURE_TRANS_COLOR_6);
	ball_26->SetOffSetX(1);
	anim->AddFrame(ball_26);
	Sprite *ball_27 = new Sprite(items->GetTexture(), listSprite[14], TEXTURE_TRANS_COLOR_6);
	ball_27->SetOffSetX(1);
	anim->AddFrame(ball_27);
	Sprite *ball_28 = new Sprite(items->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR_6);
	ball_28->SetOffSetX(1);
	anim->AddFrame(ball_28);
	Sprite *ball_29 = new Sprite(items->GetTexture(), listSprite[12], TEXTURE_TRANS_COLOR_6);
	ball_29->SetOffSetX(1);
	anim->AddFrame(ball_29);

	animations.push_back(anim);
}

void BallObject::Update(DWORD dt)
{

}

void BallObject::Render()
{
	SpriteData spriteData;

	spriteData.width = BALL_ITEM_WIDTH;
	spriteData.height = BALL_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	this->animations[0]->Render(spriteData);
}

BallObject::~BallObject()
{

}