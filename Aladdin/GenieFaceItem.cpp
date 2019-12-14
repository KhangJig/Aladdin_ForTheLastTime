#include "GenieFaceItem.h"
#include "Guard1State.h"

vector<Animation *> GenieFaceItem::animations = vector<Animation *>();

GenieFaceItem::GenieFaceItem(int x, int y, int CellID, int id)
{
	this->x = x;
	this->y = y;
	this->CellID = CellID;
	this->id = id;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = GENIE_FACE_ITEM_WIDTH;
	collider.height = GENIE_FACE_ITEM_HEIGHT;

	this->state = GenieFaceState::GenieFace1;
	this->check = false;
}

void GenieFaceItem::LoadResources(RECT* listSprite, Sprite * items)
{
	Animation * anim = new Animation(200);
	Sprite *genie_face_1 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(genie_face_1);
	Sprite *genie_face_2 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	genie_face_2->SetOffSetY(1);
	anim->AddFrame(genie_face_2);
	Sprite *genie_face_3 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	genie_face_3->SetOffSetY(2);
	anim->AddFrame(genie_face_3);
	Sprite *genie_face_4 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	genie_face_4->SetOffSetY(3);
	anim->AddFrame(genie_face_4);
	Sprite *genie_face_5 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	genie_face_5->SetOffSetY(2);
	anim->AddFrame(genie_face_5);
	Sprite *genie_face_6 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	genie_face_6->SetOffSetY(1);
	anim->AddFrame(genie_face_6);
	Sprite *genie_face_7 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	genie_face_7->SetOffSetY(0);
	anim->AddFrame(genie_face_7);
	animations.push_back(anim);

	anim = new Animation(270);
	Sprite *genie2_face_2 = new Sprite(items->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(genie2_face_2);
	Sprite *genie2_face_3 = new Sprite(items->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(genie2_face_3);
	Sprite *genie2_face_4 = new Sprite(items->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(genie2_face_4);
	animations.push_back(anim);
}

void GenieFaceItem::Update(DWORD dt)
{
	if (!this->check)
	{
		if (abs(Aladdin::GetInstance()->GetPositionX() - this->x) <= 60 && abs(Aladdin::GetInstance()->GetPositionY() - this->y) <= 30)
		{
			this->state = GenieFaceState::GenieFace2;
		}
	}
}

void GenieFaceItem::Render()
{
	SpriteData spriteData;

	spriteData.width = GENIE_FACE_ITEM_WIDTH;
	spriteData.height = GENIE_FACE_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	switch (this->state)
	{
	case GenieFaceState::GenieFace1:
	{
		this->animations[0]->Render(spriteData);
	}break;
	case GenieFaceState::GenieFace2:
	{
		this->animations[1]->Render(spriteData);
		this->check = true;
		if (this->animations[1]->IsDone())
		{
			this->state = GenieFaceState::GenieFace1;
		}
	}break;
	}
}

GenieFaceItem::~GenieFaceItem()
{

}