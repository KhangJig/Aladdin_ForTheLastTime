#include "Score.h"
#include "Guard1State.h"

Score *Score::__instance = NULL;
vector<Animation *> Score::animations = vector<Animation *>();

Score *Score::GetInstance()
{
	if (__instance == NULL)
		__instance = new Score();
	return __instance;
}

Score::Score()
{
	this->LoadResources();
	this->x = 0;
	this->y = 0;
	this->num = 0;
}

void Score::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Miscellaneous\\Text.txt");
	Sprite * text = new Sprite(TEXT_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_5);

	Animation *anim = new Animation(100);
	Sprite *word_0 = new Sprite(text->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_0);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_1 = new Sprite(text->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_5);
	word_1->SetOffSetX(-4);
	anim->AddFrame(word_1);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_2 = new Sprite(text->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_2);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_3 = new Sprite(text->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_3);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_4 = new Sprite(text->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_4);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_5 = new Sprite(text->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_5);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_6 = new Sprite(text->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_6);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_7 = new Sprite(text->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_7);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_8 = new Sprite(text->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_8);
	animations.push_back(anim);

	anim = new Animation(100);
	Sprite *word_9 = new Sprite(text->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_5);
	anim->AddFrame(word_9);
	animations.push_back(anim);
}

void Score::Update(DWORD dt)
{
	this->x = Viewport::GetInstance()->GetX() + 280;
	this->y = Viewport::GetInstance()->GetY() - 17;
}

void Score::Render()
{
	SpriteData spriteData;

	spriteData.width = TEXT_ITEM_WIDTH;
	spriteData.height = TEXT_ITEM_HEIGHT;
	spriteData.y = this->y - 5;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = false;

	int number = this->num;
	int dv = 0;
	int hc = 0;
	int ht = 0;
	int hn = 0;
	int hcn = 0;

	if (number > 0)
	{
		dv = number % 10;
		number /= 10;
		if (number > 0)
		{
			hc = number % 10;
			number /= 10;
			if (number > 0)
			{
				ht = number % 10;
				number /= 10;
				if (number > 0)
				{
					hn = number % 10;
					number /= 10;
					if (number > 0)
					{
						hcn = number % 10;
						number /= 10;
					}
				}
			}
		}
	}


	if (this->num > 0)
	{
		if (dv >= 0)
		{
			spriteData.x = this->x;
			switch (dv)
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
		}

		if (hc >= 0 && this->num >= 10)
		{
			spriteData.x = this->x - 15;
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
		}

		if (ht >= 0 && this->num >= 100)
		{
			spriteData.x = this->x - 30;
			switch (ht)
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
		}

		if (hn >= 0 && this->num >= 1000)
		{
			spriteData.x = this->x - 45;
			switch (hn)
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
		}

		if (hcn >= 0 && this->num >= 10000)
		{
			spriteData.x = this->x - 60;
			switch (hcn)
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
		}
	}
}

Score::~Score()
{

}