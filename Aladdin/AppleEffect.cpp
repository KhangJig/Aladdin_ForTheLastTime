#include "AppleEffect.h"

vector<Animation *> AppleEffect::animations = vector<Animation *>();

AppleEffect::AppleEffect(int x, int y)
{
	this->x = x;
	this->y = y;
	this->hidden = true;
}

void AppleEffect::LoadResources() 
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Character\\Apple.txt");
	Sprite * boom = new Sprite(ALADDIN_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR);

	Animation * anim = new Animation(100);
	Sprite *apple_collision_1 = new Sprite(boom->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR);
	apple_collision_1->SetOffSetY(3);
	anim->AddFrame(apple_collision_1);
	Sprite * apple_collision_2 = new Sprite(boom->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR);
	apple_collision_2->SetOffSetX(6);
	apple_collision_2->SetOffSetY(11);
	anim->AddFrame(apple_collision_2);
	Sprite * apple_collision_3 = new Sprite(boom->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR);
	apple_collision_3->SetOffSetX(10);
	apple_collision_3->SetOffSetY(15);
	anim->AddFrame(apple_collision_3);
	Sprite * apple_collision_4 = new Sprite(boom->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR);
	apple_collision_4->SetOffSetX(11);
	apple_collision_4->SetOffSetY(18);
	anim->AddFrame(apple_collision_4);
	Sprite * apple_collision_5 = new Sprite(boom->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR);
	apple_collision_5->SetOffSetX(10);
	apple_collision_5->SetOffSetY(20);
	anim->AddFrame(apple_collision_5);
	animations.push_back(anim);
}

void AppleEffect::Render()
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

AppleEffect::~AppleEffect()
{

}