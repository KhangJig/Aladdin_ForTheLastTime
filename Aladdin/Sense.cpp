#include "Sense.h"
#include "Guard1State.h"

Sense *Sense::__instance = NULL;
vector<Animation *> Sense::animations = vector<Animation *>();

Sense *Sense::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Sense();
	}
	return __instance;
}

Sense::Sense()
{
	LoadResources();
	x = 0;
	y = 0;
}

void Sense::LoadResources()
{
	Sprite * items = new Sprite(SENSE_FRONT_MAP, TEXTURE_TRANS_COLOR_8);

	RECT *image = new RECT();
	image->left= 0;
	image->top = 0;
	image->right = 2271;
	image->bottom = 1152;

	Animation *anim = new Animation(150);
	Sprite *sense = new Sprite(items->GetTexture(), *image, TEXTURE_TRANS_COLOR_8);
	anim->AddFrame(sense);
	animations.push_back(anim);
}

void Sense::Update(DWORD dt)
{

}

void Sense::Render()
{
	SpriteData spriteData;

	spriteData.width = TILE_SIZE;
	spriteData.height = TILE_SIZE;
	spriteData.x = 0;
	spriteData.y = 1116;

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;

	this->animations[0]->Render(spriteData);
}

Sense::~Sense()
{

}