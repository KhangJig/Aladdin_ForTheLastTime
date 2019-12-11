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

	appleEffect = new AppleEffect(0, 0);
}

void Apple::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Character\\Apple.txt");
	Sprite * aladdin2 = new Sprite(ALADDIN_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR);

#pragma region Apple flying
	Animation * anim = new Animation(100);
	Sprite * apple_flying = new Sprite(aladdin2->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	anim->AddFrame(apple_flying);
	animations.push_back(anim);
#pragma endregion

#pragma region Apple none
	anim = new Animation(100);
	Sprite * apple_none = new Sprite(aladdin2->GetTexture(), listSprite[280], TEXTURE_TRANS_COLOR);
	anim->AddFrame(apple_none);
	animations.push_back(anim);
#pragma endregion
}

void Apple::Update(DWORD dt)
{
	//this->UpdateCollision(dt);

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
		if (this->GetPositionY() < aladdin->GetPositionY() - 80) {
			this->state = APPLE_BOOM;
		}
	}
}

void Apple::UpdateCollision(vector<TileObjectMap *> tiles)
{

#pragma region Collision With Map
	//vector<TileObjectMap *> tiles = Grid::GetInstance()->GetNearbyObjectTiles();

	this->SetDt(dt);
	this->UpdateObjectCollider();
	this->collider.x += 5;
	Collider collider2;

	for (int i = 0; i < tiles.size(); i++)
	{
		collider2.x = tiles.at(i)->x;
		collider2.y = tiles.at(i)->y;
		collider2.width = tiles.at(i)->width;
		collider2.height = tiles.at(i)->height;
		bool isCollide2 = Collision::GetInstance()->AABB(this->GetCollider(), collider2);
		if (isCollide2)
		{
			if (tiles.at(i)->type == ObjectType::BRICK || tiles.at(i)->type == ObjectType::WALL)
			{
				appleEffect->SetPos(this->GetPositionX(), this->GetPositionY(), false);
				this->state = APPLE_NONE;
				this->SetSpeedX(0);
				this->SetSpeedY(0);
			}
		}
	}
#pragma endregion

#pragma region Collison With Enemies
	vector<OnUpdateObject> listUpdateObject = Grid::GetInstance()->GetListUpdateObject();

	for (int i = 0; i < listUpdateObject.size(); i++)
	{
		if (!listUpdateObject.at(i).isGenerated || !listUpdateObject.at(i).isLife)
			continue;

		bool isCollide = Collision::GetInstance()->AABB(this->GetCollider(), listUpdateObject.at(i).object->GetCollider());

		if (isCollide)
		{
			appleEffect->SetPos(this->GetPositionX(), this->GetPositionY(), false);
			this->state = APPLE_NONE;
			this->SetSpeedX(0);
			this->SetSpeedY(0);
		}
	}
#pragma endregion
}

void Apple::Render()
{
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

	switch (this->state)
	{
	case APPLE_NONE:
	{
		this->SetSpeedX(0);
		this->SetSpeedY(0);
		this->SetPositionX(-100);
		this->SetPositionY(-100);
		this->animations[1]->Render(spriteData);
	}
	break;
	case APPLE_FLYING:
	{
		this->animations[0]->Render(spriteData);
	}
	break;
	case APPLE_BOOM:
	{
		this->state = APPLE_NONE;
		isStartThrow = true;
		aladdin->SetIsApple(true);
	}
	break;
	}

	appleEffect->Render();
}

Apple::~Apple()
{
}
