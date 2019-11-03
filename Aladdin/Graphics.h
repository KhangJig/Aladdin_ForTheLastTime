#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Viewport.h"
#include "Sprite.h"

class Sprite;

class Graphics
{
	static Graphics *__instance;
	static Viewport *viewport;
	HWND hWnd;

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddv = NULL;

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;

public:
	void Init(HWND hWnd);
	HRESULT LoadTexture(LPCWSTR filePath, D3DCOLOR transColor, LPDIRECT3DTEXTURE9 &texture);
	void Draw(Sprite *sprite, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }
	static Graphics *GetInstance();
	~Graphics();
};