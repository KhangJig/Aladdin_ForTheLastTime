//#include "Apple.h"
//#include "Grid.h"
//
//vector<Animation *> Aladdin::animations = vector<Animation *>();
//Apple * Apple::__instance = NULL;
//
//Apple * Apple::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new Apple();
//	return __instance;
//}
//
//Apple::Apple()
//{
//	LoadResources();
//	state = AppleState::GetInstance(this);
//
//	width = APPLE_WIDTH;
//	height = APPLE_HEIGHT;
//
//	vx = APPLE_SPEED;
//
//	collider.x = x;
//	collider.y = y;
//	collider.vx = 0;
//	collider.vy = 0;
//	collider.width = APPLE_WIDTH;
//	collider.height = APPLE_HEIGHT;
//}
//
//void Apple::LoadResources()
//{
//	LoadTXT loadTXT;
//	RECT* listSprite = loadTXT.LoadRect((char*)"Resource\\Character\\Aladdin.txt");
//
//	// Apple flying
//	Animation * anim = new Animation(100);
//	Sprite * apple_flying = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[280], TEXTURE_TRANS_COLOR);
//	anim->AddFrame(apple_flying);
//	animations.push_back(anim);
//
//	// Apple collision
//	anim = new Animation(100);
//	Sprite *apple_collision_1 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[281], TEXTURE_TRANS_COLOR);
//	apple_collision_1->SetOffSetY(3);
//	anim->AddFrame(apple_collision_1);
//	Sprite * apple_collision_2 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[282], TEXTURE_TRANS_COLOR);
//	apple_collision_2->SetOffSetX(6);
//	apple_collision_2->SetOffSetY(11);
//	anim->AddFrame(apple_collision_2);
//	Sprite * apple_collision_3 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[283], TEXTURE_TRANS_COLOR);
//	apple_collision_3->SetOffSetX(10);
//	apple_collision_3->SetOffSetY(15);
//	anim->AddFrame(apple_collision_3);
//	Sprite * apple_collision_4 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[284], TEXTURE_TRANS_COLOR);
//	apple_collision_4->SetOffSetX(11);
//	apple_collision_4->SetOffSetY(18);
//	anim->AddFrame(apple_collision_4);
//	animations.push_back(anim);
//	Sprite * apple_collision_5 = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[285], TEXTURE_TRANS_COLOR);
//	apple_collision_5->SetOffSetX(10);
//	apple_collision_5->SetOffSetY(20);
//	anim->AddFrame(apple_collision_5);
//	animations.push_back(anim);
//
//	// Apple none
//	Animation * anim = new Animation(100);
//	Sprite * apple_none = new Sprite(ALADDIN_TEXTURE_LOCATION, listSprite[280], TEXTURE_TRANS_COLOR);
//	anim->AddFrame(apple_none);
//	animations.push_back(anim);
//}
//
//void Apple::Update(DWORD dt)
//{
//	timeCount += dt;
//
//	state->Colision();
//	state->Update(dt);
//
//	//this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt*(isLeft == true ? -1 : 1)));
//	//this->SetPositionY((float)(this->GetPositionY() + this->GetSpeedY()* dt));
//}
//
//void Apple::Render()
//{
//	state->Render();
//}
//
//Apple::~Apple()
//{
//}
