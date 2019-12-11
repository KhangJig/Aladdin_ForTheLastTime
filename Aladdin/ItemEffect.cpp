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
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Enemies\\EnemiesDead.txt");
	Sprite * faded = new Sprite(ENEMIES_TEXTURE_DEAD, TEXTURE_TRANS_COLOR_3);

	Animation * anim = new Animation(200);
	Sprite *item_collison = new Sprite(faded->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_3);
	anim->AddFrame(item_collison);
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