#include "Keyboard.h" 
Keyboard *Keyboard::__instance = NULL;

Keyboard::~Keyboard()
{
}

bool Keyboard::InitKeyboard(HWND hwnd)
{
	this->Hwnd = hwnd;
	this->Di8 = 0;
	this->DiD8 = 0;
	ZeroMemory(&this->key_buffer, sizeof(this->key_buffer));

	HRESULT hr = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&this->Di8,
		NULL);

	if (FAILED(hr))
	{
		return false;
	}

	hr = this->Di8->CreateDevice(GUID_SysKeyboard, &this->DiD8, NULL);
	if (FAILED(hr))
	{
		return false;
	}
	
	hr = this->DiD8->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		return false;
	}

	hr = this->DiD8->SetCooperativeLevel(this->Hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE); //DISCL_FOREGROUND chỉ hoạt động khi của sổ hWnd đang được handle
	if (FAILED(hr))
	{
		return false;
	}

	hr = this->DiD8->Acquire();
	if (FAILED(hr))
	{
		return false;
	}
	return true;
}

void Keyboard::Update()
{
	HRESULT hr = this->DiD8->GetDeviceState(sizeof(this->key_buffer), (LPVOID)&this->key_buffer);

	if (FAILED(hr))
	{
		while (this->DiD8->Acquire() == DIERR_INPUTLOST);
	}
}

bool Keyboard::IsKeyDown(int key)
{
	return key_buffer[key] & 0x80;
}

bool Keyboard::IsKeyUp(int key)
{
	return !(key_buffer[key] & 0x80);
}

void Keyboard::KillKeyboard()
{
	if (DiD8 != NULL)
	{
		this->DiD8->Unacquire();
		this->DiD8->Release();
		this->DiD8 = NULL;
	}
}

Keyboard *Keyboard::GetInstance()
{
	if (__instance == NULL) __instance = new Keyboard();
	return __instance;
}