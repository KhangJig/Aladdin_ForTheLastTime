#pragma once
#include "Constants.h"
#include "State.h"
#include "Captain.h"

enum StateCaptain
{
	STATE_STANDING,//Đứng yên
	STATE_STANDING_UP,//Nhìn lên trên
	STATE_WALKING,//Di chuyển
	STATE_JUMPING,//Nhảy thường
	STATE_JUMPING_ROLE,//Nhảy cao và xoay
	STATE_CROUCH,//Ngồi
	STATE_SWIMMING,//lội
	STATE_THROW_SHIELD,//Ném khiên
	STATE_PUNCH,//Đứng đấm (khi không có khiên)
	STATE_JUMPING_KICK,//Nhảy đá
	STATE_CROUCH_PUNCH,//Ngồi đấm
	STATE_CROUCH_SHIELD,// Ngồi lên khiên
	STATE_DASH,//Dash
	STATE_THROW_SHIELD_2,//Ném khiên quay lại ra sau lưng level cao hơn chắc không cần cái này đâu
	STATE_BLEEING, //Bị thương và bất tử trong mấy giây
	STATE_DIEING, //Chết
	STATE_DIVING, //Lặn
	STATE_SWING, //Đu dây
	STATE_BLEEING_2
};

class CaptainState : public State
{
protected:
	static CaptainState * __instance;
	StateCaptain stateCaptain;
	Captain *captain;
	Animation * anim;
	RECT* listSprite;
	float startJumpY;
	float startDash;

public:
	float timeCount;
	CaptainState(Captain *captain);
	~CaptainState();

	static CaptainState * GetInstance(Captain *captain);

	StateCaptain GetState();

	void SetState(StateCaptain State);

	void state_standing();
	void state_standing_up();
	void state_walking();
	void state_jumping();
	void state_jumping_role();
	void state_crouch();
	void state_swimming();
	void state_throw_shield();
	void state_punch();
	void state_jumping_kick();
	void state_crouch_punch();
	void state_crouch_shield();
	void state_dash();
	void state_throw_shield_2();
	void state_bleeing();
	void state_dieing();
	void state_diving();
	void state_swing();
	void state_bleeing_2();

	void KeyHandle();
	void Colision() override;
	void Update(DWORD dt) override;
	void Render() override;
};
