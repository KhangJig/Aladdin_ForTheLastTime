#include "EnemiesDeadEffect.h"

vector<Animation *> EnemiesDeadEffect::animations = vector<Animation *>();

EnemiesDeadEffect::EnemiesDeadEffect(int x, int y)
{
	this->x = x;
	this->y = y;
	this->hidden = true;
}

void EnemiesDeadEffect::LoadResources()
{
	LoadTXT loadTXT;

	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Enemies\\EnemiesDead.txt");
	Sprite * guard1_2 = new Sprite(ENEMIES_TEXTURE_DEAD, TEXTURE_TRANS_COLOR_3);

#pragma region DEAD
	Animation *anim = new Animation(80);

	Sprite * enemies_dead_1 = new Sprite(guard1_2->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_3);
	enemies_dead_1->SetOffSetX(-12);
	enemies_dead_1->SetOffSetY(-45);
	anim->AddFrame(enemies_dead_1);
	Sprite * enemies_dead_2 = new Sprite(guard1_2->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_3);
	enemies_dead_2->SetOffSetX(-6);
	enemies_dead_2->SetOffSetY(-30);
	anim->AddFrame(enemies_dead_2);
	Sprite * enemies_dead_3 = new Sprite(guard1_2->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_3);
	enemies_dead_3->SetOffSetX(-2);
	enemies_dead_3->SetOffSetY(-19);
	anim->AddFrame(enemies_dead_3);
	Sprite * enemies_dead_4 = new Sprite(guard1_2->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_3);
	enemies_dead_4->SetOffSetX(5);
	enemies_dead_4->SetOffSetY(-15);
	anim->AddFrame(enemies_dead_4);
	Sprite * enemies_dead_5 = new Sprite(guard1_2->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_3);
	enemies_dead_5->SetOffSetX(13);
	enemies_dead_5->SetOffSetY(-8);
	anim->AddFrame(enemies_dead_5);
	Sprite * enemies_dead_6 = new Sprite(guard1_2->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_3);
	enemies_dead_6->SetOffSetX(19);
	enemies_dead_6->SetOffSetY(-6);
	anim->AddFrame(enemies_dead_6);
	Sprite * enemies_dead_7 = new Sprite(guard1_2->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_3);
	enemies_dead_7->SetOffSetX(23);
	enemies_dead_7->SetOffSetY(1);
	anim->AddFrame(enemies_dead_7);
	Sprite * enemies_dead_8 = new Sprite(guard1_2->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_3);
	enemies_dead_8->SetOffSetX(29);
	enemies_dead_8->SetOffSetY(8);
	anim->AddFrame(enemies_dead_8);

	animations.push_back(anim);
#pragma endregion
}

void EnemiesDeadEffect::Render()
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

EnemiesDeadEffect::~EnemiesDeadEffect()
{

}