#include "HP.h"
#include "Guard1State.h"

HP *HP::__instance = NULL;
vector<Animation *> HP::animations = vector<Animation *>();

HP *HP::GetInstance()
{
	if (__instance == NULL)
		__instance = new HP();
	return __instance;
}

HP::HP()
{
	LoadResources();
	x = 0;
	y = 0;
	this->State = LV_TEN;
}

void HP::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Miscellaneous\\HP.txt");
	Sprite * items = new Sprite(HP_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_6);

	Animation * anim = new Animation(150);
	Sprite *hp_0 = new Sprite(items->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_0);
	animations.push_back(anim);

	anim = new Animation(150);
	Sprite *hp_1 = new Sprite(items->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_1);
	Sprite *hp_2 = new Sprite(items->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_6);
	hp_2->SetOffSetY(-1);
	anim->AddFrame(hp_2);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_2 = new Sprite(items->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_6);
	hp_2->SetOffSetY(-1);
	anim->AddFrame(hp_2);
	Sprite *hp_3 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_3);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_3 = new Sprite(items->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_3);
	Sprite *hp_4 = new Sprite(items->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_4);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_4 = new Sprite(items->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_4);
	Sprite *hp_5 = new Sprite(items->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_6);
	hp_5->SetOffSetX(5);
	anim->AddFrame(hp_5);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_5 = new Sprite(items->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_6);
	hp_5->SetOffSetX(5);
	anim->AddFrame(hp_5);
	Sprite *hp_6 = new Sprite(items->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_6);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_6 = new Sprite(items->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_6);
	Sprite *hp_7 = new Sprite(items->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_7);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_7 = new Sprite(items->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_7);
	Sprite *hp_8 = new Sprite(items->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_8);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_8 = new Sprite(items->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_8);
	Sprite *hp_9 = new Sprite(items->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_9);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_9 = new Sprite(items->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(hp_9);
	Sprite *hp_10 = new Sprite(items->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	hp_10->SetOffSetX(2);
	animations.push_back(anim);

	anim = new Animation(150);
	hp_10 = new Sprite(items->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	hp_10->SetOffSetX(2);
	anim->AddFrame(hp_10);
	animations.push_back(anim);
}

void HP::Update(DWORD dt)
{
	this->x = Viewport::GetInstance()->GetX() + 20;
	this->y = Viewport::GetInstance()->GetY() - 17;
}

void HP::Render()
{
	SpriteData spriteData;

	spriteData.width = BRICK_ITEM_WIDTH;
	spriteData.height = BRICK_ITEM_WIDTH;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	switch (this->State)
	{
	case LV_TEN:
	{
		this->animations[10]->Render(spriteData);
	}break;
	case LV_NINE:
	{
		this->animations[9]->Render(spriteData);
	}break;
	case LV_EIGHT:
	{
		this->animations[8]->Render(spriteData);
	}break;
	case LV_SEVEN:
	{
		this->animations[7]->Render(spriteData);
	}break;
	case LV_SIX:
	{
		this->animations[6]->Render(spriteData);
	}break;
	case LV_FIVE:
	{
		this->animations[5]->Render(spriteData);
	}break;
	case LV_FOUR:
	{
		this->animations[4]->Render(spriteData);
	}break;
	case LV_THREE:
	{
		this->animations[3]->Render(spriteData);
	}break;
	case LV_TWO:
	{
		this->animations[2]->Render(spriteData);
	}break;
	case LV_ONE:
	{
		this->animations[1]->Render(spriteData);
	}break;
	case LV_ZERO:
	{
		this->animations[0]->Render(spriteData);
	}break;
	}
}

HP::~HP()
{

}