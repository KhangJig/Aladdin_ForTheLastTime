#pragma once
#include <dinput.h>

class Keyboard
{
	static Keyboard *__instance;
	LPDIRECTINPUT8 Di8;
	LPDIRECTINPUTDEVICE8 DiD8;
	char key_buffer[256];
	HWND Hwnd;

public:
	~Keyboard();
	bool InitKeyboard(HWND hwnd);
	void Update();
	bool IsKeyDown(int key);
	bool IsKeyUp(int key);
	void KillKeyboard();
	static Keyboard *GetInstance();
};