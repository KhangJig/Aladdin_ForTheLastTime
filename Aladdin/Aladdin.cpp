#include "Aladdin.h"

vector<Animation *> Aladdin::animations = vector<Animation *>();
Aladdin *Aladdin::__instance = NULL;

Aladdin *Aladdin::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Aladdin();
	}
	return __instance;
}

Aladdin::Aladdin()
{
	LoadResources();
	state = AladdinState::GetInstance(this);

	apple = Apple::GetInstance();
	itemEffect = new ItemEffect(-100, -100);
	this->SetIsApple(true);

	this->x = 50;
	this->y = 150;
	this->AladdinHP = 500;
	this->AppleNumber = 5;
	this->DiamondNumber = 0;
	this->DmgAttack = 20;
	this->Attacking = false;
	this->width = ALADDIN_SPRITE_WIDTH;
	this->height = ALADDIN_SPRITE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = ALADDIN_SPRITE_WIDTH;
	collider.height = ALADDIN_SPRITE_HEIGHT;
}

void Aladdin::LoadResources()
{
	LoadTXT loadTXT;
	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Character\\Aladdin.txt");
	Sprite * aladdin2 = new Sprite(ALADDIN_TEXTURE_LOCATION, TEXTURE_TRANS_COLOR);

#pragma region STAND
	Animation * anim = new Animation(150);
	Sprite * stand = new Sprite(aladdin2->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	anim->AddFrame(stand);
	
	animations.push_back(anim);
#pragma endregion

#pragma region HEAD UP
	anim = new Animation(130);

	Sprite * head_up_1 = new Sprite(aladdin2->GetTexture(), listSprite[50], TEXTURE_TRANS_COLOR);
	head_up_1->SetOffSetY(3);
	anim->AddFrame(head_up_1);
	Sprite * head_up_2 = new Sprite(aladdin2->GetTexture(), listSprite[51], TEXTURE_TRANS_COLOR);
	head_up_2->SetOffSetX(4);
	head_up_2->SetOffSetY(9);
	anim->AddFrame(head_up_2);
	Sprite * head_up_3 = new Sprite(aladdin2->GetTexture(), listSprite[52], TEXTURE_TRANS_COLOR);
	head_up_3->SetOffSetX(7);
	head_up_3->SetOffSetY(8);
	anim->AddFrame(head_up_3);

	animations.push_back(anim);
#pragma endregion

#pragma region RUN
	anim = new Animation(100);

	Sprite * run_1 = new Sprite(aladdin2->GetTexture(), listSprite[141], TEXTURE_TRANS_COLOR);
	run_1->SetOffSetX(0);
	run_1->SetOffSetY(-2);
	anim->AddFrame(run_1);
	Sprite * run_2 = new Sprite(aladdin2->GetTexture(), listSprite[142], TEXTURE_TRANS_COLOR);
	run_2->SetOffSetX(1);
	run_2->SetOffSetY(1);
	anim->AddFrame(run_2);
	Sprite * run_3 = new Sprite(aladdin2->GetTexture(), listSprite[143], TEXTURE_TRANS_COLOR);
	run_3->SetOffSetX(0);
	run_3->SetOffSetY(3);
	anim->AddFrame(run_3);
	Sprite * run_4 = new Sprite(aladdin2->GetTexture(), listSprite[144], TEXTURE_TRANS_COLOR);
	run_4->SetOffSetX(0);
	run_4->SetOffSetY(7);
	anim->AddFrame(run_4);
	Sprite * run_5 = new Sprite(aladdin2->GetTexture(), listSprite[145], TEXTURE_TRANS_COLOR);
	run_5->SetOffSetX(6);
	run_5->SetOffSetY(7);
	anim->AddFrame(run_5);
	Sprite * run_6 = new Sprite(aladdin2->GetTexture(), listSprite[146], TEXTURE_TRANS_COLOR);
	run_6->SetOffSetX(2);
	run_6->SetOffSetY(4);
	anim->AddFrame(run_6);
	Sprite * run_7 = new Sprite(aladdin2->GetTexture(), listSprite[147], TEXTURE_TRANS_COLOR);
	run_7->SetOffSetX(1);
	run_7->SetOffSetY(8);
	anim->AddFrame(run_7);
	Sprite * run_8 = new Sprite(aladdin2->GetTexture(), listSprite[148], TEXTURE_TRANS_COLOR);
	run_8->SetOffSetX(0);
	run_8->SetOffSetY(2);
	anim->AddFrame(run_8);
	Sprite * run_9 = new Sprite(aladdin2->GetTexture(), listSprite[149], TEXTURE_TRANS_COLOR);
	run_9->SetOffSetX(-3);
	run_9->SetOffSetY(4);
	anim->AddFrame(run_9);
	Sprite * run_10 = new Sprite(aladdin2->GetTexture(), listSprite[150], TEXTURE_TRANS_COLOR);
	run_10->SetOffSetX(4);
	run_10->SetOffSetY(8);
	anim->AddFrame(run_10);
	Sprite * run_11 = new Sprite(aladdin2->GetTexture(), listSprite[152], TEXTURE_TRANS_COLOR);
	run_11->SetOffSetX(7);
	run_11->SetOffSetY(5);
	anim->AddFrame(run_11);
	Sprite * run_12 = new Sprite(aladdin2->GetTexture(), listSprite[153], TEXTURE_TRANS_COLOR);
	run_12->SetOffSetX(2);
	run_12->SetOffSetY(7);
	anim->AddFrame(run_12);

	animations.push_back(anim);
#pragma endregion

#pragma region JUMP
	anim = new Animation(80);

	Sprite * jump_1 = new Sprite(aladdin2->GetTexture(), listSprite[91], TEXTURE_TRANS_COLOR);
	jump_1->SetOffSetX(15);
	jump_1->SetOffSetY(12);
	anim->AddFrame(jump_1);
	Sprite * jump_2 = new Sprite(aladdin2->GetTexture(), listSprite[92], TEXTURE_TRANS_COLOR);
	jump_2->SetOffSetX(12);
	jump_2->SetOffSetY(11);
	anim->AddFrame(jump_2);
	Sprite * jump_3 = new Sprite(aladdin2->GetTexture(), listSprite[93], TEXTURE_TRANS_COLOR);
	jump_3->SetOffSetX(9);
	jump_3->SetOffSetY(19);
	anim->AddFrame(jump_3);
	Sprite * jump_4 = new Sprite(aladdin2->GetTexture(), listSprite[94], TEXTURE_TRANS_COLOR);
	jump_4->SetOffSetX(6);
	jump_4->SetOffSetY(24);
	anim->AddFrame(jump_4);
	Sprite * jump_5 = new Sprite(aladdin2->GetTexture(), listSprite[95], TEXTURE_TRANS_COLOR);
	jump_5->SetOffSetX(-3);
	jump_5->SetOffSetY(16);
	anim->AddFrame(jump_5);

	animations.push_back(anim);
#pragma endregion

#pragma region FALL
	anim = new Animation(70);

	Sprite * fall_1 = new Sprite(aladdin2->GetTexture(), listSprite[96], TEXTURE_TRANS_COLOR);
	fall_1->SetOffSetY(29);
	anim->AddFrame(fall_1);
	Sprite * fall_2 = new Sprite(aladdin2->GetTexture(), listSprite[97], TEXTURE_TRANS_COLOR);
	fall_2->SetOffSetX(-1);
	fall_2->SetOffSetY(43);
	anim->AddFrame(fall_2);
	Sprite * fall_3 = new Sprite(aladdin2->GetTexture(), listSprite[98], TEXTURE_TRANS_COLOR);
	fall_3->SetOffSetX(1);
	fall_3->SetOffSetY(43);
	anim->AddFrame(fall_3);
	Sprite * fall_4 = new Sprite(aladdin2->GetTexture(), listSprite[99], TEXTURE_TRANS_COLOR);
	fall_4->SetOffSetX(1);
	fall_4->SetOffSetY(43);
	anim->AddFrame(fall_4);

	animations.push_back(anim);
#pragma endregion

#pragma region TOUCH ON THE GROUND
	anim = new Animation(190);

	Sprite * on_ground_1 = new Sprite(aladdin2->GetTexture(), listSprite[108], TEXTURE_TRANS_COLOR);
	on_ground_1->SetOffSetX(7);
	on_ground_1->SetOffSetY(35);
	anim->AddFrame(on_ground_1);
	Sprite * on_ground_2 = new Sprite(aladdin2->GetTexture(), listSprite[90], TEXTURE_TRANS_COLOR);
	on_ground_2->SetOffSetX(14);
	on_ground_2->SetOffSetY(-7);
	anim->AddFrame(on_ground_2);

	animations.push_back(anim);
#pragma endregion

#pragma region SIT
	anim = new Animation(100);

	Sprite * sit_1 = new Sprite(aladdin2->GetTexture(), listSprite[74], TEXTURE_TRANS_COLOR);
	sit_1->SetOffSetX(6);
	sit_1->SetOffSetY(-1);
	anim->AddFrame(sit_1);
	Sprite * sit_2 = new Sprite(aladdin2->GetTexture(), listSprite[75], TEXTURE_TRANS_COLOR);
	sit_2->SetOffSetX(8);
	sit_2->SetOffSetY(-10);
	anim->AddFrame(sit_2);
	Sprite * sit_3 = new Sprite(aladdin2->GetTexture(), listSprite[76], TEXTURE_TRANS_COLOR);
	sit_3->SetOffSetX(8);
	sit_3->SetOffSetY(-20);
	anim->AddFrame(sit_3);
	Sprite * sit_4 = new Sprite(aladdin2->GetTexture(), listSprite[77], TEXTURE_TRANS_COLOR);
	sit_4->SetOffSetX(3);
	sit_4->SetOffSetY(-15);
	anim->AddFrame(sit_4);

	animations.push_back(anim);
#pragma endregion

#pragma region IDLE_SIT
	anim = new Animation(100);

	Sprite * sit_idle = new Sprite(aladdin2->GetTexture(), listSprite[77], TEXTURE_TRANS_COLOR);
	sit_idle->SetOffSetX(3);
	sit_idle->SetOffSetY(-15);
	anim->AddFrame(sit_idle);

	animations.push_back(anim);
#pragma endregion

#pragma region STAND-HIT
	anim = new Animation(100);

	Sprite * stand_hit_1 = new Sprite(aladdin2->GetTexture(), listSprite[45], TEXTURE_TRANS_COLOR);
	stand_hit_1->SetOffSetX(8);
	stand_hit_1->SetOffSetY(1);
	anim->AddFrame(stand_hit_1);
	Sprite * stand_hit_2 = new Sprite(aladdin2->GetTexture(), listSprite[46], TEXTURE_TRANS_COLOR);
	stand_hit_2->SetOffSetX(10);
	stand_hit_2->SetOffSetY(12);
	anim->AddFrame(stand_hit_2);
	Sprite * stand_hit_3 = new Sprite(aladdin2->GetTexture(), listSprite[47], TEXTURE_TRANS_COLOR);
	stand_hit_3->SetOffSetX(4);
	stand_hit_3->SetOffSetY(24);
	anim->AddFrame(stand_hit_3);
	Sprite * stand_hit_4 = new Sprite(aladdin2->GetTexture(), listSprite[48], TEXTURE_TRANS_COLOR);
	stand_hit_4->SetOffSetY(19);
	anim->AddFrame(stand_hit_4);
	Sprite * stand_hit_5 = new Sprite(aladdin2->GetTexture(), listSprite[49], TEXTURE_TRANS_COLOR);
	stand_hit_5->SetOffSetX(8);
	stand_hit_5->SetOffSetY(3);
	anim->AddFrame(stand_hit_5);

	animations.push_back(anim);
#pragma endregion

#pragma region STAND-THROW
	anim = new Animation(80);

	Sprite * stand_throw_1 = new Sprite(aladdin2->GetTexture(), listSprite[39], TEXTURE_TRANS_COLOR);
	stand_throw_1->SetOffSetY(6);
	anim->AddFrame(stand_throw_1);
	Sprite * stand_throw_2 = new Sprite(aladdin2->GetTexture(), listSprite[40], TEXTURE_TRANS_COLOR);
	stand_throw_2->SetOffSetY(9);
	anim->AddFrame(stand_throw_2);
	Sprite * stand_throw_3 = new Sprite(aladdin2->GetTexture(), listSprite[41], TEXTURE_TRANS_COLOR);
	stand_throw_3->SetOffSetY(8);
	anim->AddFrame(stand_throw_3);
	Sprite * stand_throw_4 = new Sprite(aladdin2->GetTexture(), listSprite[42], TEXTURE_TRANS_COLOR);
	stand_throw_4->SetOffSetX(1);
	stand_throw_4->SetOffSetY(10);
	anim->AddFrame(stand_throw_4);
	Sprite * stand_throw_5 = new Sprite(aladdin2->GetTexture(), listSprite[43], TEXTURE_TRANS_COLOR);
	stand_throw_5->SetOffSetY(8);
	anim->AddFrame(stand_throw_5);
	Sprite * stand_throw_6 = new Sprite(aladdin2->GetTexture(), listSprite[44], TEXTURE_TRANS_COLOR);
	stand_throw_6->SetOffSetX(2);
	stand_throw_6->SetOffSetY(2);
	anim->AddFrame(stand_throw_6);

	animations.push_back(anim); 
#pragma endregion

#pragma region SIT-THROW
	anim = new Animation(80);

	Sprite * sit_throw_1 = new Sprite(aladdin2->GetTexture(), listSprite[78], TEXTURE_TRANS_COLOR);
	sit_throw_1->SetOffSetX(0);
	sit_throw_1->SetOffSetY(-6);
	anim->AddFrame(sit_throw_1);
	Sprite * sit_throw_2 = new Sprite(aladdin2->GetTexture(), listSprite[79], TEXTURE_TRANS_COLOR);
	sit_throw_2->SetOffSetX(0);
	sit_throw_2->SetOffSetY(-2);
	anim->AddFrame(sit_throw_2);
	Sprite * sit_throw_3 = new Sprite(aladdin2->GetTexture(), listSprite[80], TEXTURE_TRANS_COLOR);
	sit_throw_3->SetOffSetX(0);
	sit_throw_3->SetOffSetY(-2);
	anim->AddFrame(sit_throw_3);
	Sprite * sit_throw_4 = new Sprite(aladdin2->GetTexture(), listSprite[81], TEXTURE_TRANS_COLOR);
	sit_throw_4->SetOffSetX(12);
	sit_throw_4->SetOffSetY(-13);
	anim->AddFrame(sit_throw_4);
	Sprite * sit_throw_5 = new Sprite(aladdin2->GetTexture(), listSprite[82], TEXTURE_TRANS_COLOR);
	sit_throw_5->SetOffSetX(7);
	sit_throw_5->SetOffSetY(-13);
	anim->AddFrame(sit_throw_5);

	animations.push_back(anim);
#pragma endregion

#pragma region SIT-HIT
	anim = new Animation(80);

	Sprite * sit_hit_1 = new Sprite(aladdin2->GetTexture(), listSprite[83], TEXTURE_TRANS_COLOR);
	sit_hit_1->SetOffSetY(-17);
	anim->AddFrame(sit_hit_1);
	Sprite * sit_hit_2 = new Sprite(aladdin2->GetTexture(), listSprite[84], TEXTURE_TRANS_COLOR);
	sit_hit_2->SetOffSetY(-19);
	anim->AddFrame(sit_hit_2);
	Sprite * sit_hit_3 = new Sprite(aladdin2->GetTexture(), listSprite[85], TEXTURE_TRANS_COLOR);
	sit_hit_3->SetOffSetY(-17);
	anim->AddFrame(sit_hit_3);
	Sprite * sit_hit_4 = new Sprite(aladdin2->GetTexture(), listSprite[86], TEXTURE_TRANS_COLOR);
	sit_hit_4->SetOffSetY(-16);
	anim->AddFrame(sit_hit_4);
	Sprite * sit_hit_5 = new Sprite(aladdin2->GetTexture(), listSprite[87], TEXTURE_TRANS_COLOR);
	sit_hit_5->SetOffSetY(-17);
	anim->AddFrame(sit_hit_5);
	Sprite * sit_hit_6 = new Sprite(aladdin2->GetTexture(), listSprite[88], TEXTURE_TRANS_COLOR);
	sit_hit_6->SetOffSetY(-17);
	anim->AddFrame(sit_hit_6);
	Sprite * sit_hit_7 = new Sprite(aladdin2->GetTexture(), listSprite[89], TEXTURE_TRANS_COLOR);
	sit_hit_7->SetOffSetY(-19);
	anim->AddFrame(sit_hit_7);

	animations.push_back(anim);
#pragma endregion

#pragma region RUN-JUMP
	anim = new Animation(150);

	Sprite * run_jump_1 = new Sprite(aladdin2->GetTexture(), listSprite[102], TEXTURE_TRANS_COLOR);
	run_jump_1->SetOffSetX(4);
	run_jump_1->SetOffSetY(26);
	anim->AddFrame(run_jump_1);
	Sprite * run_jump_2 = new Sprite(aladdin2->GetTexture(), listSprite[103], TEXTURE_TRANS_COLOR);
	run_jump_2->SetOffSetX(10);
	run_jump_2->SetOffSetY(7);
	anim->AddFrame(run_jump_2);
	Sprite * run_jump_3 = new Sprite(aladdin2->GetTexture(), listSprite[104], TEXTURE_TRANS_COLOR);
	run_jump_3->SetOffSetX(11);
	run_jump_3->SetOffSetY(-8);
	anim->AddFrame(run_jump_3);

	animations.push_back(anim);
#pragma endregion

#pragma region FALL 2
	anim = new Animation(100);

	Sprite * fall2_1 = new Sprite(aladdin2->GetTexture(), listSprite[105], TEXTURE_TRANS_COLOR);
	fall2_1->SetOffSetX(12);
	fall2_1->SetOffSetY(-2);
	anim->AddFrame(fall2_1);
	Sprite * fall2_2 = new Sprite(aladdin2->GetTexture(), listSprite[106], TEXTURE_TRANS_COLOR);
	fall2_2->SetOffSetX(10);
	fall2_2->SetOffSetY(3);
	anim->AddFrame(fall2_2);
	Sprite * fall2_3 = new Sprite(aladdin2->GetTexture(), listSprite[107], TEXTURE_TRANS_COLOR);
	fall2_3->SetOffSetX(8);
	fall2_3->SetOffSetY(8);
	anim->AddFrame(fall2_3);

	animations.push_back(anim);
#pragma endregion

#pragma region JUMP-THROW
	anim = new Animation(50);

	Sprite * jump_throw_1 = new Sprite(aladdin2->GetTexture(), listSprite[122], TEXTURE_TRANS_COLOR);
	jump_throw_1->SetOffSetX(6);
	jump_throw_1->SetOffSetY(5);
	anim->AddFrame(jump_throw_1);
	Sprite * jump_throw_2 = new Sprite(aladdin2->GetTexture(), listSprite[123], TEXTURE_TRANS_COLOR);
	jump_throw_2->SetOffSetX(1);
	jump_throw_2->SetOffSetY(2);
	anim->AddFrame(jump_throw_2);
	Sprite * jump_throw_3 = new Sprite(aladdin2->GetTexture(), listSprite[124], TEXTURE_TRANS_COLOR);
	jump_throw_3->SetOffSetX(3);
	jump_throw_3->SetOffSetY(3);
	anim->AddFrame(jump_throw_3);
	Sprite * jump_throw_4 = new Sprite(aladdin2->GetTexture(), listSprite[125], TEXTURE_TRANS_COLOR);
	jump_throw_4->SetOffSetX(8);
	jump_throw_4->SetOffSetY(3);
	anim->AddFrame(jump_throw_4);
	Sprite * jump_throw_5 = new Sprite(aladdin2->GetTexture(), listSprite[126], TEXTURE_TRANS_COLOR);
	jump_throw_5->SetOffSetX(2);
	jump_throw_5->SetOffSetY(2);
	anim->AddFrame(jump_throw_5);

	animations.push_back(anim);
#pragma endregion

#pragma region JUMP-HIT
	anim = new Animation(50);

	Sprite * jump_hit_1 = new Sprite(aladdin2->GetTexture(), listSprite[127], TEXTURE_TRANS_COLOR);
	jump_hit_1->SetOffSetX(8);
	jump_hit_1->SetOffSetY(4);
	anim->AddFrame(jump_hit_1);
	Sprite * jump_hit_2 = new Sprite(aladdin2->GetTexture(), listSprite[128], TEXTURE_TRANS_COLOR);
	jump_hit_2->SetOffSetX(7);
	jump_hit_2->SetOffSetY(2);
	anim->AddFrame(jump_hit_2);
	Sprite * jump_hit_3 = new Sprite(aladdin2->GetTexture(), listSprite[129], TEXTURE_TRANS_COLOR);
	jump_hit_3->SetOffSetX(5);
	jump_hit_3->SetOffSetY(16);
	anim->AddFrame(jump_hit_3);
	Sprite * jump_hit_4 = new Sprite(aladdin2->GetTexture(), listSprite[130], TEXTURE_TRANS_COLOR);
	jump_hit_4->SetOffSetX(7);
	jump_hit_4->SetOffSetY(6);
	anim->AddFrame(jump_hit_4);
	Sprite * jump_hit_5 = new Sprite(aladdin2->GetTexture(), listSprite[131], TEXTURE_TRANS_COLOR);
	jump_hit_5->SetOffSetX(23);
	jump_hit_5->SetOffSetY(10);
	anim->AddFrame(jump_hit_5);
	Sprite * jump_hit_6 = new Sprite(aladdin2->GetTexture(), listSprite[132], TEXTURE_TRANS_COLOR);
	jump_hit_6->SetOffSetX(5);
	jump_hit_6->SetOffSetY(5);
	anim->AddFrame(jump_hit_6);

	animations.push_back(anim);
#pragma endregion

#pragma region DOUBLE HIT
	anim = new Animation(90);

	Sprite * double_hit_1 = new Sprite(aladdin2->GetTexture(), listSprite[62], TEXTURE_TRANS_COLOR);
	double_hit_1->SetOffSetX(0);
	double_hit_1->SetOffSetY(3);
	anim->AddFrame(double_hit_1);
	Sprite * double_hit_2 = new Sprite(aladdin2->GetTexture(), listSprite[63], TEXTURE_TRANS_COLOR);
	double_hit_2->SetOffSetX(-1);
	double_hit_2->SetOffSetY(10);
	anim->AddFrame(double_hit_2);
	Sprite * double_hit_3 = new Sprite(aladdin2->GetTexture(), listSprite[64], TEXTURE_TRANS_COLOR);
	double_hit_3->SetOffSetX(29);
	double_hit_3->SetOffSetY(11);
	anim->AddFrame(double_hit_3);
	Sprite * double_hit_4 = new Sprite(aladdin2->GetTexture(), listSprite[65], TEXTURE_TRANS_COLOR);
	double_hit_4->SetOffSetX(12);
	double_hit_4->SetOffSetY(8);
	anim->AddFrame(double_hit_4);
	Sprite * double_hit_5 = new Sprite(aladdin2->GetTexture(), listSprite[66], TEXTURE_TRANS_COLOR);
	double_hit_5->SetOffSetX(11);
	double_hit_5->SetOffSetY(4);
	anim->AddFrame(double_hit_5);
	Sprite * double_hit_6 = new Sprite(aladdin2->GetTexture(), listSprite[67], TEXTURE_TRANS_COLOR);
	double_hit_6->SetOffSetX(18);
	double_hit_6->SetOffSetY(-2);
	anim->AddFrame(double_hit_6);
	Sprite * double_hit_7 = new Sprite(aladdin2->GetTexture(), listSprite[68], TEXTURE_TRANS_COLOR);
	double_hit_7->SetOffSetX(0);
	double_hit_7->SetOffSetY(21);
	anim->AddFrame(double_hit_7);

	animations.push_back(anim);
#pragma endregion

#pragma region HURT
	anim = new Animation(40);

	Sprite * hurt_1 = new Sprite(aladdin2->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	anim->AddFrame(hurt_1);
	Sprite * hurt_2 = new Sprite(aladdin2->GetTexture(), listSprite[287], TEXTURE_TRANS_COLOR);
	anim->AddFrame(hurt_2);
	Sprite * hurt_3 = new Sprite(aladdin2->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR);
	anim->AddFrame(hurt_3);
	Sprite * hurt_4 = new Sprite(aladdin2->GetTexture(), listSprite[287], TEXTURE_TRANS_COLOR);
	anim->AddFrame(hurt_4);

	animations.push_back(anim);
#pragma endregion

	listSprite = loadTXT.LoadRect((char*)"Resource\\Character\\run-hit-n-throw.txt");
	Sprite * aladdin3 = new Sprite(ALADDIN_TEXTURE_LOCATION2, TEXTURE_TRANS_COLOR_2);

#pragma region RUN-HIT
	anim = new Animation(80);
	
	Sprite * run_throw_1 = new Sprite(aladdin3->GetTexture(), listSprite[0], TEXTURE_TRANS_COLOR_2);
	run_throw_1->SetOffSetY(2);
	anim->AddFrame(run_throw_1);
	Sprite * run_throw_2 = new Sprite(aladdin3->GetTexture(), listSprite[1], TEXTURE_TRANS_COLOR_2);
	run_throw_2->SetOffSetX(6);
	run_throw_2->SetOffSetY(10);
	anim->AddFrame(run_throw_2);
	Sprite * run_throw_3 = new Sprite(aladdin3->GetTexture(), listSprite[2], TEXTURE_TRANS_COLOR_2);
	run_throw_3->SetOffSetX(10);
	run_throw_3->SetOffSetY(3);
	anim->AddFrame(run_throw_3);
	Sprite * run_throw_4 = new Sprite(aladdin3->GetTexture(), listSprite[3], TEXTURE_TRANS_COLOR_2);
	run_throw_4->SetOffSetX(7);
	run_throw_4->SetOffSetY(10);
	anim->AddFrame(run_throw_4);
	Sprite * run_throw_5 = new Sprite(aladdin3->GetTexture(), listSprite[4], TEXTURE_TRANS_COLOR_2);
	run_throw_5->SetOffSetX(5);
	run_throw_5->SetOffSetY(5);
	anim->AddFrame(run_throw_5);
	Sprite * run_throw_6 = new Sprite(aladdin3->GetTexture(), listSprite[5], TEXTURE_TRANS_COLOR_2);
	run_throw_6->SetOffSetX(1);
	anim->AddFrame(run_throw_6);

	animations.push_back(anim);
#pragma endregion

#pragma region RUN-THROW
	anim = new Animation(80);

	Sprite * run_hit_1 = new Sprite(aladdin3->GetTexture(), listSprite[6], TEXTURE_TRANS_COLOR_2);
	run_hit_1->SetOffSetY(6);
	anim->AddFrame(run_hit_1);
	Sprite * run_hit_2 = new Sprite(aladdin3->GetTexture(), listSprite[7], TEXTURE_TRANS_COLOR_2);
	run_hit_2->SetOffSetX(16);
	run_hit_2->SetOffSetY(8);
	anim->AddFrame(run_hit_2);
	Sprite * run_hit_3 = new Sprite(aladdin3->GetTexture(), listSprite[8], TEXTURE_TRANS_COLOR_2);
	run_hit_3->SetOffSetX(18);
	run_hit_3->SetOffSetY(6);
	anim->AddFrame(run_hit_3);
	Sprite * run_hit_4 = new Sprite(aladdin3->GetTexture(), listSprite[9], TEXTURE_TRANS_COLOR_2);
	run_hit_4->SetOffSetX(15);
	run_hit_4->SetOffSetY(12);
	anim->AddFrame(run_hit_4);
	Sprite * run_hit_5 = new Sprite(aladdin3->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_2);
	run_hit_5->SetOffSetX(11);
	run_hit_5->SetOffSetY(12);
	anim->AddFrame(run_hit_5);
	Sprite * run_hit_6 = new Sprite(aladdin3->GetTexture(), listSprite[10], TEXTURE_TRANS_COLOR_2);
	run_hit_6->SetOffSetX(6);
	run_hit_6->SetOffSetY(2);
	anim->AddFrame(run_hit_6);

	animations.push_back(anim);
#pragma endregion
}

void Aladdin::Reset()
{
	this->SetPositionX(200);
	this->SetPositionY(200);
	Viewport::GetInstance()->Reset();
}

void Aladdin::Update(DWORD dt)
{
	//DebugOut(L"Aladdin %d %d \n", (int)this->GetPositionX(), (int)this->GetPositionY());
	timeCount += dt;

	if (this->GetSpeedX() > 0 && this->GetPositionX() > TileMap::GetInstance()->currentMap->size * 100 - 50)
	{
		if (Game::GetInstance()->GetStage() < 2)
		{
			Game::GetInstance()->SetStage(Game::GetInstance()->GetStage() + 1);
			if (STAGE_2 == Game::GetInstance()->GetStage())
			{
				Grid::GetInstance()->DisableAllObject();

				this->SetPositionX(280);
				this->SetPositionY(900);
				Viewport::GetInstance()->Reset();

				TileMap::GetInstance()->SetCurrentMap(STAGE_2);
				Grid::GetInstance()->InitializeMapGrid(TileMap::GetInstance());
			}
		}
		else this->SetSpeedX(0);
	}

	if (Keyboard::GetInstance()->IsKeyDown(DIK_F1))
	{
		Grid::GetInstance()->DisableAllObject();
		Game::GetInstance()->SetStage(STAGE_1);

		this->SetPositionX(50);
		this->SetPositionY(150);
		Viewport::GetInstance()->Reset();

		TileMap::GetInstance()->SetCurrentMap(STAGE_1);
		Grid::GetInstance()->InitializeMapGrid(TileMap::GetInstance());
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_F2))
	{
		Grid::GetInstance()->DisableAllObject();
		Game::GetInstance()->SetStage(STAGE_2);

		this->SetPositionX(100);
		this->SetPositionY(150);
		Viewport::GetInstance()->Reset();

		TileMap::GetInstance()->SetCurrentMap(STAGE_2);
		Grid::GetInstance()->InitializeMapGrid(TileMap::GetInstance());
	}
	if (Keyboard::GetInstance()->IsKeyDown(DIK_F3))
	{
		trueImortal = !trueImortal;
	}

	vector<ColliedEvent*> coEvents;
	vector<ColliedEvent*> coEventsResult;

#pragma region	Collide with map
	vector<TileObjectMap *> tiles = Grid::GetInstance()->GetNearbyObjectTiles();
	vector<TileObjectMap *> tilesRope = Grid::GetInstance()->GetNearbyObjectTilesThorn();
	coEvents.clear();


	this->SetDt(dt);
	this->UpdateObjectCollider();
	this->collider.x += 5;
	this->MapCollisions(tiles, coEvents);

#pragma region	ROPE
	// Dang xu ly va cham day xich
	//if (tilesRope.size() != 0)
	//{
	//	Collider a;
	//	for (int i = 0; i < tilesRope.size(); i++)
	//	{
	//		a.x = tilesRope.at(i)->x;
	//		a.y = tilesRope.at(i)->y;
	//		a.width = tilesRope.at(i)->width;
	//		a.height = tilesRope.at(i)->height;

	//		if (Collision::GetInstance()->AABB(a, this->GetCollider()))
	//		{
	//			if (!this->GetIsGrounded())
	//			{
	//				this->SetIsClimb(true);
	//			}
	//		}
	//		else
	//		{
	//			this->SetIsClimb(false);
	//		}
	//	}
	//}
#pragma endregion

#pragma region	BRICK & WALL
	if (coEvents.size() == 0)
	{
		float moveX = trunc(this->GetSpeedX()* dt);
		float moveY = trunc(this->GetSpeedY()* dt);
		this->SetPositionX(this->GetPositionX() + moveX);
		this->SetPositionY(this->GetPositionY() + moveY);
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		Collision::GetInstance()->GetNearestCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		float moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
		float moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;

		this->SetPositionX(this->GetPositionX() + moveX);
		this->SetPositionY(this->GetPositionY() + moveY);
		if (coEventsResult[0]->collisionID == ObjectType::BRICK)
		{
			if (ny == 1)
			{
				this->SetIsGrounded(true);
			}
		}

		if (coEventsResult[0]->collisionID == ObjectType::WALL)
		{
			if (nx == 1 || nx == -1)
			{
				this->SetSpeedX(0);
				this->SetIsGrounded(true);
			}
		}
	}
	for (int i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
#pragma endregion

#pragma endregion

	apple->Update(dt);
	apple->UpdateCollision(tiles);
	state->Colision();
	state->Update(dt);
}

void Aladdin::UpdateCollision(DWORD dt)
{
	if (trueImortal)
		return;

	if (bImortal)
	{
		if (timeCount > 700)
		{
			timeCount = 0;
			bImortal = false;
		}
		return;
	}

	vector<OnUpdateObject> listUpdateObject = Grid::GetInstance()->GetListUpdateObject();

	for (int i = 0; i < listUpdateObject.size(); i++)
	{
		if (!listUpdateObject.at(i).isGenerated || !listUpdateObject.at(i).isLife)
			continue;

		bool isCollide = Collision::GetInstance()->AABB(this->GetCollider(), listUpdateObject.at(i).object->GetCollider());
	
		if (!isCollide)
			continue;

		switch (listUpdateObject.at(i).ene.SpawnObjectID)
		{
		case ObjectAndEnemies::GUARD1:
		{
			if (((Guard1*)listUpdateObject.at(i).object)->GetAttacking())
			{
				this->AladdinHP = this->AladdinHP - ((Guard1*)listUpdateObject.at(i).object)->GetGuard1DmgAttack();
				DebugOut(L"Aladdin HP :  %d \n", this->AladdinHP);
				this->state->SetState(STATE_HURT);
			}
		}break;
		case ObjectAndEnemies::GUARD2:
		{

		}break;
		case ObjectAndEnemies::BOMBBER:
		{

		}break;
		case ObjectAndEnemies::BAT:
		{

		}break;
		case ObjectAndEnemies::THORN:
		{

		}break;
		case ObjectAndEnemies::WALL_BRICK:
		{

		}break;
		case ObjectAndEnemies::APPLE:
		{
			Grid::GetInstance()->SetisLifeListObject(((AppleItem*)listUpdateObject.at(i).object)->GetID(), false);
			itemEffect->SetPos(listUpdateObject.at(i).ene.x, listUpdateObject.at(i).ene.y, false);
			this->AppleNumber++;
		}break;
		case ObjectAndEnemies::DIAMOND:
		{
			Grid::GetInstance()->SetisLifeListObject(((DiamondItem*)listUpdateObject.at(i).object)->GetID(), false);
			itemEffect->SetPos(listUpdateObject.at(i).ene.x, listUpdateObject.at(i).ene.y, false);
			this->DiamondNumber++;
		}break;
		case ObjectAndEnemies::BOTTLE:
		{

		}break;
		case ObjectAndEnemies::GENIE_FACE:
		{

		}break;
		case ObjectAndEnemies::SHOP:
		{

		}break;
		}
	}
}

void Aladdin::Render()
{
	state->Render();
	apple->Render();
	itemEffect->Render();
}