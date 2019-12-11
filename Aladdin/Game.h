#pragma once
#include "Constants.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "TileMap.h"
#include "Grid.h"
#include "Aladdin.h"

#include "HP.h"
#include "AppleMenu.h"
#include "DiamondMenu.h"

#include <chrono>

class Graphics;
class Keyboard;

class Game
{
	bool initialized = false;

	static Game *__instance;
	static HINSTANCE hInstance;
	HWND hWnd;

	Keyboard *keyboard;
	Graphics *graphics;
	Aladdin *aladdin;
	Viewport *viewport;
	TileMap *tileMap;
	HP *hp;
	AppleMenu *appleMenu;
	DiamondMenu *diamondMenu;
	Stage stage;

public:
	Stage GetStage() { return this->stage; }
	void SetStage(int stage) { this->stage = (Stage)stage; }

	void Init();
	HWND CreateGameWindow(HINSTANCE hInstance, int ScreenWidth, int ScreenHeight);
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void LoadResources();


	void Update(DWORD dt);
	void Render();
	int Run();

	static Game *GetInstance();
	~Game();
};


