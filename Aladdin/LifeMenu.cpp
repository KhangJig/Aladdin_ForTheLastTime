#include "LifeMenu.h"
#include "Guard1State.h"

LifeMenu *LifeMenu::__instance = NULL;
vector<Animation *> LifeMenu::animations = vector<Animation *>();

LifeMenu *LifeMenu::GetInstance()
{
	if (__instance == NULL)
		__instance = new LifeMenu();
	return __instance;
}

LifeMenu::LifeMenu()
{
	this->LoadResources();
	this->x = 0;
	this->y = 0;
	this->num = 0;
}

void LifeMenu::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Miscellaneous\\Text.txt");
	Sprite * text = new Sprite(TEXT_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_5);

	Animation *anim = new Animation(100);
	Sprite *word_0 = new Sprite(text->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_5);
	word_0->SetOffSetX(-30);
	anim->AddFrame(word_0);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_1 = new Sprite(text->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_5);
	word_1->SetOffSetX(-34);
	anim->AddFrame(word_1);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_2 = new Sprite(text->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	word_2->SetOffSetX(-30);
	anim->AddFrame(word_2);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_3 = new Sprite(text->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_5);
	word_3->SetOffSetX(-30);
	anim->AddFrame(word_3);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_4 = new Sprite(text->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_5);
	word_4->SetOffSetX(-30);
	anim->AddFrame(word_4);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_5 = new Sprite(text->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_5);
	word_5->SetOffSetX(-30);
	anim->AddFrame(word_5);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_6 = new Sprite(text->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_5);
	word_6->SetOffSetX(-30);
	anim->AddFrame(word_6);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_7 = new Sprite(text->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_5);
	word_7->SetOffSetX(-30);
	anim->AddFrame(word_7);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_8 = new Sprite(text->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_5);
	word_8->SetOffSetX(-30);
	anim->AddFrame(word_8);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_9 = new Sprite(text->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_5);
	word_9->SetOffSetX(-30);
	anim->AddFrame(word_9);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_0 = new Sprite(text->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_5);
	word_0_0->SetOffSetX(-45);
	anim->AddFrame(word_0_0);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_1 = new Sprite(text->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_5);
	word_0_1->SetOffSetX(-49);
	anim->AddFrame(word_0_1);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_2 = new Sprite(text->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	word_0_2->SetOffSetX(-45);
	anim->AddFrame(word_0_2);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_3 = new Sprite(text->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_5);
	word_0_3->SetOffSetX(-45);
	anim->AddFrame(word_0_3);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_4 = new Sprite(text->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_5);
	word_0_4->SetOffSetX(-45);
	anim->AddFrame(word_0_4);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_5 = new Sprite(text->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_5);
	word_0_5->SetOffSetX(-45);
	anim->AddFrame(word_0_5);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_6 = new Sprite(text->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_5);
	word_0_6->SetOffSetX(-45);
	anim->AddFrame(word_0_6);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_7 = new Sprite(text->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_5);
	word_0_7->SetOffSetX(-45);
	anim->AddFrame(word_0_7);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_8 = new Sprite(text->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_5);
	word_0_8->SetOffSetX(-45);
	anim->AddFrame(word_0_8);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_0_9 = new Sprite(text->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_5);
	word_0_9->SetOffSetX(-45);
	anim->AddFrame(word_0_9);
	animations.push_back(anim);

	listSprite = loadTXT.LoadRect((char*)"Resource\\Miscellaneous\\Items.txt");
	Sprite * items = new Sprite(ITEMS_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_5);

	anim = new Animation(100);
	Sprite *apple = new Sprite(items->GetTexture(), listSprite[15], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(apple);
	animations.push_back(anim);


}

void LifeMenu::Update(DWORD dt)
{
	this->x = Viewport::GetInstance()->GetX() + 15;
	this->y = Viewport::GetInstance()->GetY() - 200;
}

void LifeMenu::Render()
{
	SpriteData spriteData;

	spriteData.width = TEXT_ITEM_WIDTH;
	spriteData.height = TEXT_ITEM_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y - 5;

	spriteData.scale = 0.75;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	int dv = this->num % 10;
	int hc = this->num / 10;

	if (this->num < 10)
	{
		hc = dv;
	}

	switch (hc)
	{
	case 0: this->animations[0]->Render(spriteData); break;
	case 1: this->animations[1]->Render(spriteData); break;
	case 2: this->animations[2]->Render(spriteData); break;
	case 3: this->animations[3]->Render(spriteData); break;
	case 4: this->animations[4]->Render(spriteData); break;
	case 5: this->animations[5]->Render(spriteData); break;
	case 6: this->animations[6]->Render(spriteData); break;
	case 7: this->animations[7]->Render(spriteData); break;
	case 8: this->animations[8]->Render(spriteData); break;
	case 9: this->animations[9]->Render(spriteData); break;
	}

	if (this->num >= 10)
	{
		switch (dv)
		{
		case 0: this->animations[10]->Render(spriteData); break;
		case 1: this->animations[11]->Render(spriteData); break;
		case 2: this->animations[12]->Render(spriteData); break;
		case 3: this->animations[13]->Render(spriteData); break;
		case 4: this->animations[14]->Render(spriteData); break;
		case 5: this->animations[15]->Render(spriteData); break;
		case 6: this->animations[16]->Render(spriteData); break;
		case 7: this->animations[17]->Render(spriteData); break;
		case 8: this->animations[18]->Render(spriteData); break;
		case 9: this->animations[19]->Render(spriteData); break;
		}
	}

	spriteData.width = APPLE_ITEM_WIDTH;
	spriteData.height = APPLE_ITEM_HEIGHT;
	spriteData.x = this->x + 2;
	spriteData.y = this->y;

	spriteData.scale = 0.75;
	this->animations[20]->Render(spriteData);
}

LifeMenu::~LifeMenu()
{

}