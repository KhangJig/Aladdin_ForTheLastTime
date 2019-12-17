#include "Skeleton.h"

vector<Animation *> Skeleton::animations = vector<Animation *>();

Skeleton::Skeleton(float x, float y, int CellID, int id)
{
	this->state = new SkeletonState(this);

	this->x = x;
	this->y = y;
	this->width = SKELETON_SPRITE_WIDTH;
	this->height = SKELETON_SPRITE_HEIGHT;

	this->CellID = CellID;
	this->id = id;

	this->disable = false;
	this->Attacking = false;
	this->Dmg = SKELETON_DAMAGE;
	this->SkeletonHP = SKELETON_HP;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = SKELETON_SPRITE_WIDTH;
	collider.height = SKELETON_SPRITE_HEIGHT;

	enemiesDeadEffect = new EnemiesDeadEffect(0, 0);

	this->skeletonFire = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_SKELETON_FIRE);

	this->skeletonBoom = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_SKELETON_BOOM);

	this->fireAndBoom = Sound::GetInstance()->LoadSound((LPTSTR)SOUND_SKELETON_FIREnBOOM);
}

void Skeleton::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Enemies\\Skeleton.txt");
	Sprite * skeleton = new Sprite(SKELETON_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR);

#pragma region IDLE
	Animation * anim = new Animation(100);

	Sprite * skeleton_idle_1 = new Sprite(skeleton->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	skeleton_idle_1->SetOffSetX(-11);
	skeleton_idle_1->SetOffSetY(-56);
	anim->AddFrame(skeleton_idle_1);

	animations.push_back(anim);
#pragma endregion

#pragma region STAND
	anim = new Animation(300);

	Sprite * skeleton_stand_1 = new Sprite(skeleton->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	skeleton_stand_1->SetOffSetX(-11);
	skeleton_stand_1->SetOffSetY(-56);
	anim->AddFrame(skeleton_stand_1);

	Sprite * skeleton_stand_2 = new Sprite(skeleton->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR);
	skeleton_stand_2->SetOffSetX(-10);
	skeleton_stand_2->SetOffSetY(-53);
	anim->AddFrame(skeleton_stand_2);

	Sprite * skeleton_stand_3 = new Sprite(skeleton->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR);
	skeleton_stand_3->SetOffSetX(0);
	skeleton_stand_3->SetOffSetY(-37);
	anim->AddFrame(skeleton_stand_3);

	Sprite * skeleton_stand_4 = new Sprite(skeleton->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR);
	skeleton_stand_4->SetOffSetX(12);
	skeleton_stand_4->SetOffSetY(-22);
	anim->AddFrame(skeleton_stand_4);

	Sprite * skeleton_stand_5 = new Sprite(skeleton->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR);
	skeleton_stand_5->SetOffSetX(8);
	skeleton_stand_5->SetOffSetY(-15);
	anim->AddFrame(skeleton_stand_5);

	Sprite * skeleton_stand_6 = new Sprite(skeleton->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR);
	skeleton_stand_6->SetOffSetX(5);
	skeleton_stand_6->SetOffSetY(-11);
	anim->AddFrame(skeleton_stand_6);

	Sprite * skeleton_stand_7 = new Sprite(skeleton->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR);
	skeleton_stand_7->SetOffSetX(2);
	skeleton_stand_7->SetOffSetY(-7);
	anim->AddFrame(skeleton_stand_7);

	Sprite * skeleton_stand_8 = new Sprite(skeleton->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR);
	skeleton_stand_8->SetOffSetX(1);
	skeleton_stand_8->SetOffSetY(-1);
	anim->AddFrame(skeleton_stand_8);

	Sprite * skeleton_stand_9 = new Sprite(skeleton->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR);
	skeleton_stand_9->SetOffSetX(1);
	skeleton_stand_9->SetOffSetY(-1);
	anim->AddFrame(skeleton_stand_9);

	Sprite * skeleton_stand_10 = new Sprite(skeleton->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR);
	skeleton_stand_10->SetOffSetX(1);
	skeleton_stand_10->SetOffSetY(-1);
	anim->AddFrame(skeleton_stand_10);

	Sprite * skeleton_stand_11 = new Sprite(skeleton->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR);
	skeleton_stand_11->SetOffSetX(20);
	skeleton_stand_11->SetOffSetY(-1);
	anim->AddFrame(skeleton_stand_11);

	Sprite * skeleton_stand_12 = new Sprite(skeleton->GetTexture(), listSprite[11], TEXTURE_TRANS_COLOR);
	skeleton_stand_12->SetOffSetX(16);
	skeleton_stand_12->SetOffSetY(7);
	anim->AddFrame(skeleton_stand_12);

	Sprite * skeleton_stand_13 = new Sprite(skeleton->GetTexture(), listSprite[12], TEXTURE_TRANS_COLOR);
	skeleton_stand_13->SetOffSetX(0);
	skeleton_stand_13->SetOffSetY(0);
	anim->AddFrame(skeleton_stand_13);

	Sprite * skeleton_stand_14 = new Sprite(skeleton->GetTexture(), listSprite[13], TEXTURE_TRANS_COLOR);
	skeleton_stand_14->SetOffSetX(0);
	skeleton_stand_14->SetOffSetY(-1);
	anim->AddFrame(skeleton_stand_14);

	Sprite * skeleton_stand_15 = new Sprite(skeleton->GetTexture(), listSprite[14], TEXTURE_TRANS_COLOR);
	skeleton_stand_15->SetOffSetX(22);
	skeleton_stand_15->SetOffSetY(2);
	anim->AddFrame(skeleton_stand_15);

	Sprite * skeleton_stand_16 = new Sprite(skeleton->GetTexture(), listSprite[15], TEXTURE_TRANS_COLOR);
	skeleton_stand_16->SetOffSetX(25);
	skeleton_stand_16->SetOffSetY(-7);
	anim->AddFrame(skeleton_stand_16);

	Sprite * skeleton_stand_17 = new Sprite(skeleton->GetTexture(), listSprite[16], TEXTURE_TRANS_COLOR);
	skeleton_stand_17->SetOffSetX(33);
	skeleton_stand_17->SetOffSetY(3);
	anim->AddFrame(skeleton_stand_17);

	Sprite * skeleton_stand_18 = new Sprite(skeleton->GetTexture(), listSprite[17], TEXTURE_TRANS_COLOR);
	skeleton_stand_18->SetOffSetX(33);
	skeleton_stand_18->SetOffSetY(9);
	anim->AddFrame(skeleton_stand_18);

	Sprite * skeleton_stand_19 = new Sprite(skeleton->GetTexture(), listSprite[18], TEXTURE_TRANS_COLOR);
	skeleton_stand_19->SetOffSetX(33);
	skeleton_stand_19->SetOffSetY(-5);

	Sprite * skeleton_stand_20 = new Sprite(skeleton->GetTexture(), listSprite[19], TEXTURE_TRANS_COLOR);
	skeleton_stand_20->SetOffSetX(23);
	skeleton_stand_20->SetOffSetY(-3);
	anim->AddFrame(skeleton_stand_19);

	animations.push_back(anim);
#pragma endregion

#pragma region BOOM & DEAD
	anim = new Animation(80);

	Sprite * skeleton_boom_1 = new Sprite(skeleton->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	skeleton_boom_1->SetOffSetX(-11);
	skeleton_boom_1->SetOffSetY(-56);
	anim->AddFrame(skeleton_boom_1);

	animations.push_back(anim);

	anim = new Animation(80);

	Sprite * skeleton_dead_1 = new Sprite(skeleton->GetTexture(), listSprite[24], TEXTURE_TRANS_COLOR);
	anim->AddFrame(skeleton_dead_1);

	animations.push_back(anim);
#pragma endregion

}

void Skeleton::Update(DWORD dt)
{
	this->UpdateCollision(dt);
	if (this->disable)
		return;

	state->Colision();
	state->Update(dt);
}

void Skeleton::Render()
{
	if (this->disable)
		return;

	state->Render();
	enemiesDeadEffect->Render();
}

void Skeleton::UpdateCollision(DWORD dt)
{
	bool isCollideAladdin = Collision::GetInstance()->AABB(this->GetCollider(), Aladdin::GetInstance()->GetCollider());
	bool isCollideApple = Collision::GetInstance()->AABB(this->GetCollider(), Apple::GetInstance()->GetCollider());

	if (isCollideAladdin)
	{
		if (Aladdin::GetInstance()->GetAttacking())
		{
			this->SetSkeletonHP(this->GetSkeletonHP() - Aladdin::GetInstance()->GetDmgAttack());

			if (this->GetSkeletonHP() <= 0)
			{
				enemiesDeadEffect->SetPos(this->GetPositionX() + SKELETON_SPRITE_WIDTH / 2, this->GetPositionY(), false);
				this->state->SetState(SKELETON_DEAD);
			}
		}
	}
	if (isCollideApple)
	{
		this->SetSkeletonHP(this->GetSkeletonHP() - Aladdin::GetInstance()->GetDmgAttack());

		if (this->GetSkeletonHP() <= 0)
		{
			enemiesDeadEffect->SetPos(this->GetPositionX() + SKELETON_SPRITE_WIDTH / 2, this->GetPositionY(), false);
			this->state->SetState(SKELETON_DEAD);
		}
	}
}

void Skeleton::OnCollision()
{

}