//#include "AppleState.h"
//#include <math.h>
//
//AppleState *AppleState::__instance = NULL;
//
//AppleState *AppleState::GetInstance(Apple *apple)
//{
//	if (__instance == NULL)
//		__instance = new AppleState(apple);
//	return __instance;
//}
//
//AppleState::AppleState(Apple *apple)
//{
//	this->apple = apple;
//	this->stateApple = NONE;
//	this->apple->SetSpeedY(-APPLE_SPEED);
//}
//
//StateApple AppleState::GetState()
//{
//	return this->stateApple;
//}
//
//void AppleState::SetState(StateApple state)
//{
//	this->stateApple = state;
//}
//
//void AppleState::stateNone()
//{
//
//}
//
//void AppleState::stateFlying()
//{
//	
//}
//
//void AppleState::stateBoom()
//{
//
//	
//}
//
//void AppleState::Update(DWORD dt)
//{
//	timeCount += dt;
//	////Kiểm tra tốc độ trục X
//	//if (Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT))
//	//{
//	//	apple->setIsLeft(false);
//	//	apple->SetSpeedX(ALADDIN_WALK_SPEED * (apple->IsLeft() ? -1 : 1));
//	//}
//	//else if (Keyboard::GetInstance()->IsKeyDown(DIK_LEFT))
//	//{
//	//	apple->setIsLeft(true);
//	//	apple->SetSpeedX(ALADDIN_WALK_SPEED * (apple->IsLeft() ? -1 : 1));
//	//}
//	//else
//	//	apple->SetSpeedX(0);
//
//	//if (apple->GetPositionX() < 10)
//	//	apple->SetPositionX(10);
//
//	switch (stateApple)
//	{
//	case NONE:
//		this->stateNone();
//		break;
//
//	case APPLE_IS_FLYING:
//		this->stateFlying();
//		break;
//
//	case APPLE_IS_BOOM:
//		this->stateBoom();
//		break;
//	default:
//		break;
//	}
//}
//
//void AppleState::Render()
//{
//	if (stateApple != NONE)
//	{
//		SpriteData spriteData;
//		if (this->apple != NULL)
//		{
//			spriteData.width = APPLE_WIDTH;
//			spriteData.height = APPLE_HEIGHT;
//			spriteData.x = apple->GetPositionX();
//			spriteData.y = apple->GetPositionY();
//			spriteData.scale = 1;
//			spriteData.angle = 0;
//			spriteData.isLeft = apple->IsLeft();
//			spriteData.isFlipped = !apple->IsFlipped();
//		}
//
//		anim->Render(spriteData);
//	}
//}
//
//AppleState::~AppleState()
//{
//	delete anim;
//	delete listSprite;
//}
