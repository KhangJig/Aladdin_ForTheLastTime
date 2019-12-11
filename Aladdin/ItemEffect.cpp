#include "ItemEffect.h"

vector<Animation *> ItemEffect::animations = vector<Animation *>();

ItemEffect::ItemEffect(int x, int y)
{
	this->x = x;
	this->y = y;
	this->hidden = true;
}

void ItemEffect::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Miscellaneous\\GetItem.txt");
	Sprite * faded = new Sprite(GET_ITEMS_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR_3);

	Animation * anim = new Animation(70);
	Sprite *get_items_1 = new Sprite(faded->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_6);
	anim->AddFrame(get_items_1);
	Sprite *get_items_2 = new Sprite(faded->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_6);
	get_items_2->SetOffSetX(-3);
	get_items_2->SetOffSetY(10);
	anim->AddFrame(get_items_2);
	Sprite *get_items_3 = new Sprite(faded->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_6);
	get_items_3->SetOffSetX(-3);
	get_items_3->SetOffSetY(12);
	anim->AddFrame(get_items_3);
	Sprite *get_items_4 = new Sprite(faded->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_6);
	get_items_4->SetOffSetX(-9);
	get_items_4->SetOffSetY(18);
	anim->AddFrame(get_items_4);
	Sprite *get_items_5 = new Sprite(faded->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_6);
	get_items_5->SetOffSetX(-13);
	get_items_5->SetOffSetY(26);
	anim->AddFrame(get_items_5);
	Sprite *get_items_6 = new Sprite(faded->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_6);
	get_items_6->SetOffSetX(-23);
	get_items_6->SetOffSetY(32);
	anim->AddFrame(get_items_6);
	Sprite *get_items_7 = new Sprite(faded->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_6);
	get_items_7->SetOffSetX(-14);
	get_items_7->SetOffSetY(24);
	anim->AddFrame(get_items_7);
	Sprite *get_items_8 = new Sprite(faded->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_6);
	get_items_8->SetOffSetX(18);
	get_items_8->SetOffSetY(20);
	anim->AddFrame(get_items_8);
	Sprite *get_items_9 = new Sprite(faded->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_6);
	get_items_9->SetOffSetX(-12);
	get_items_9->SetOffSetY(16);
	anim->AddFrame(get_items_9);
	Sprite *get_items_10 = new Sprite(faded->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	get_items_10->SetOffSetX(-12);
	get_items_10->SetOffSetY(14);
	anim->AddFrame(get_items_10);
	animations.push_back(anim);
	Sprite *get_items_11 = new Sprite(faded->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_6);
	get_items_11->SetOffSetX(-3);
	get_items_11->SetOffSetY(8);
	anim->AddFrame(get_items_11);
	animations.push_back(anim);
}

void ItemEffect::Render()
{
	SpriteData spriteData;

	spriteData.width = APPLE_WIDTH;
	spriteData.height = APPLE_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;
	spriteData.isFlipped = true;

	if (!this->hidden)
	{
		this->animations[0]->Render(spriteData);
		if (this->animations[0]->IsDone()) {
			this->hidden = true;
		}
	}
}

ItemEffect::~ItemEffect()
{

}