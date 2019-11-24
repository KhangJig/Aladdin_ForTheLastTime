#include "Game.h"
#include "Debug.h"

Game *Game::__instance = NULL;
HINSTANCE Game::hInstance = NULL;

Game *Game::GetInstance()
{
	if (__instance == NULL) __instance = new Game();
	return __instance;
}

void Game::Init()
{
	hInstance = GetModuleHandle(NULL);

	this->hWnd = CreateGameWindow(hInstance, SCREEN_WIDTH, SCREEN_HEIGHT);

	graphics = Graphics::GetInstance();
	graphics->Init(hWnd);

	keyboard = Keyboard::GetInstance();
	keyboard->InitKeyboard(hWnd);

	//this->stage = STAGE_1;
	LoadResources();
	DebugOut(L"[INFO] InitGame done;\n");
}

HWND Game::CreateGameWindow(HINSTANCE hInstance, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);
	DWORD wflags = WS_OVERLAPPEDWINDOW;
	RECT rect;
	rect.left = rect.top = 0;
	rect.right = ScreenWidth;
	rect.bottom = ScreenHeight;
	AdjustWindowRect(&rect, wflags, false);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			wflags,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rect.right - rect.left,
			rect.bottom - rect.top,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	return hWnd;
}

void Game::LoadResources()
{
	if (NULL == tileMap)
		tileMap = TileMap::GetInstance();

	tileMap->SetCurrentMap(this->stage);

	Grid::GetInstance()->InitializeMapGrid(tileMap);

	if (aladdin == NULL)
		aladdin = Aladdin::GetInstance();

	if (viewport == NULL)
		viewport = Viewport::GetInstance();

	Guard1::LoadResources();
}

void Game::Update(DWORD dt)
{
	keyboard->Update();
	Grid::GetInstance()->Update(dt);
	viewport->Update(dt);
}

void Game::Render()
{
	LPDIRECT3DDEVICE9 d3ddv = graphics->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = graphics->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = graphics->GetSpriteHandler();
	if (SUCCEEDED(d3ddv->BeginScene()))
	{

		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		Grid::GetInstance()->Render();

		spriteHandler->End();

		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);
}

int Game::Run()
{
	if (!initialized)
	{
		Init();
		initialized = true;
	}

	MSG msg;
	int done = 0;

	DWORD frameStart = GetTickCount();

	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}

LRESULT CALLBACK Game::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

Game::~Game()
{

}