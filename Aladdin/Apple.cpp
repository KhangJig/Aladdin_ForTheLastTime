#include "Apple.h"
#include "Grid.h"

#define APPLE_NONE 1
#define APPLE_FLYING 2
#define APPLE_BOOM 3
#define APPLE_SPEED 0.279f

Apple * Apple::__instance = NULL;

Apple * Apple::GetInstance()
{
	if (__instance == NULL)
		__instance = new Apple();
	return __instance;
}

Apple::Apple()
{
	LoadResources();

	width = APPLE_WIDTH;
	height = APPLE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = APPLE_WIDTH;
	collider.height = APPLE_HEIGHT;

	maxDistance = SCREEN_WIDTH / 2.5;
}

void Apple::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Character\\Apple.txt");
	Sprite * aladdin2 = new Sprite(ALADDIN_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR);

	// Apple flying
	Animation * anim = new Animation(100);
	Sprite * apple_flying = new Sprite(aladdin2->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	anim->AddFrame(apple_flying);
	animations.push_back(anim);

	// Apple collision
	anim = new Animation(100);
	Sprite *apple_collision_1 = new Sprite(aladdin2->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR);
	apple_collision_1->SetOffSetY(3);
	anim->AddFrame(apple_collision_1);
	Sprite * apple_collision_2 = new Sprite(aladdin2->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR);
	apple_collision_2->SetOffSetX(6);
	apple_collision_2->SetOffSetY(11);
	anim->AddFrame(apple_collision_2);
	Sprite * apple_collision_3 = new Sprite(aladdin2->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR);
	apple_collision_3->SetOffSetX(10);
	apple_collision_3->SetOffSetY(15);
	anim->AddFrame(apple_collision_3);
	Sprite * apple_collision_4 = new Sprite(aladdin2->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR);
	apple_collision_4->SetOffSetX(11);
	apple_collision_4->SetOffSetY(18);
	anim->AddFrame(apple_collision_4);
	Sprite * apple_collision_5 = new Sprite(aladdin2->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR);
	apple_collision_5->SetOffSetX(10);
	apple_collision_5->SetOffSetY(20);
	anim->AddFrame(apple_collision_5);
	animations.push_back(anim);

	// Apple none
	anim = new Animation(100);
	Sprite * apple_none = new Sprite(aladdin2->GetTexture(), listSprite[280], TEXTURE_TRANS_COLOR);
	anim->AddFrame(apple_none);
	animations.push_back(anim);
}

void Apple::Update(DWORD dt)
{
	this->SetSpeedY(0);
	Aladdin* aladdin = Aladdin::GetInstance();
	AladdinState* aladdinState = AladdinState::GetInstance(aladdin);
	aladdinState->GetState();

	if (!aladdin->GetisApple())
	{
		this->state = APPLE_FLYING;
		this->SetIsFlying(true);
		this->AppleFlying();
	}
	else
	{
		this->SetIsFlying(false);
		this->SetSpeedX(0);
		this->state = APPLE_NONE;
	}

	this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt*(isLeft == true ? -1 : 1)));

	this->SetPositionY((float)this->ParabolCurrentX(aladdin->GetPosXAladdinThrowing(), aladdin->GetPosYAladdinThrowing(), this->GetPositionX()));
}

float Apple::ParabolCurrentX(float posX, float posY, float currentX) {

	return ((-49 * currentX*currentX) / pow(125, 2)) + ((98 * posX * currentX) / pow(125, 2)) + (posY - (49 * pow(posX, 2)) / pow(125, 2));
}

void Apple::AppleFlying()
{
	Aladdin* aladdin = Aladdin::GetInstance();
	if (isStartThrow)
	{
		this->isAladdinLeft = aladdin->IsLeft();
		if (aladdin->IsLeft())
			this->SetPositionX(aladdin->GetPositionX());
		else
			this->SetPositionX(aladdin->GetPositionX());
		this->distance = aladdin->GetPositionX() + maxDistance * (isAladdinLeft ? -1 : 1);
		this->SetSpeedX(APPLE_SPEED * 1 * (isAladdinLeft ? -1 : 1));

		this->SetPositionY(aladdin->GetPositionY() + 10);
		 
		this->isStartThrow = false;
		aladdin->SetIsApple(false);
	}
	else
	{
		if (this->GetPositionY() < -5) {
			this->state = APPLE_BOOM;
		}
	}
}

void Apple::Render()
{
	int state = this->state;
	Aladdin * aladdin = Aladdin::GetInstance();
	AladdinState * aladdinState = AladdinState::GetInstance(aladdin);

	SpriteData spriteData;

	spriteData.width = APPLE_WIDTH;
	spriteData.height = APPLE_HEIGHT;
	spriteData.x = this->GetPositionX();
	spriteData.y = this->GetPositionY();

	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = aladdin->IsLeft();
	spriteData.isFlipped = aladdin->IsFlipped();

	switch (state)
	{
	case APPLE_NONE:
	{
		this->SetSpeedX(0);
		this->SetSpeedY(0);
		this->SetPositionX(0);
		this->SetPositionY(0);
		this->animations[2]->Render(spriteData);
	}
	break;
	case APPLE_FLYING:
	{
		this->animations[0]->Render(spriteData);
	}
	break;
	case APPLE_BOOM:
	{
		this->animations[1]->Render(spriteData);
		this->SetSpeedX(0);
		this->SetSpeedY(0);
		if (this->animations[1]->IsDone()) {
			this->state = APPLE_NONE;
			isStartThrow = true;
			aladdin->SetIsApple(true);

			this->animations[1]->Reset();
		}
	}
	break;
	}
}

Apple::~Apple()
{
}
