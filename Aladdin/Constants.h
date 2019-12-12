#pragma once

#define WINDOW_CLASS_NAME L"Aladdin"
#define MAIN_WINDOW_TITLE L"Aladdin"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 325
#define SCREEN_HEIGHT 225

#define MAX_FRAME_RATE 90


enum Stage {
	STAGE_1,
	STAGE_2,
};

enum ObjectType
{
	DEFAULT,
	BRICK,
	WALL,
	ROPE
};

enum EventCollison
{
	EVENT_DEFAULT,
	EVENT_BRICK,
	EVENT_WALL,
	EVENT_ROPE
};

enum ObjectAndEnemies
{
	NOTHING,
	GUARD1, // Enemies
	GUARD2,
	BOMBBER,
	BAT,
	THORN, 	// Objects
	BALL,
	WALL_BRICK,
	APPLE, 	// Items
	DIAMOND,
	BOTTLE,
	GENIE_FACE,
	SHOP,
	JAFAR
};

// MAP
#define TILES_MATRIX_STAGE_1 L"Resource\\Background\\4x100\\bg-tiled.txt"
#define TILES_SET_MATRIX_STAGE_1 L"Resource\\Background\\4x100\\bg-tiled.png"
#define POSSISION_MAPOBJECT_1 L"Resource\\Background\\4x100\\ObjectMap.txt"
#define POSSISION_ENEMIES_1 L"Resource\\Background\\4x100\\Enemies.txt"

#define TILES_MATRIX_STAGE_2 L"Resource\\Background\\4x100\\bg-tiled-2.txt"
#define TILES_SET_MATRIX_STAGE_2 L"Resource\\Background\\4x100\\bg-tiled-2.png"
#define POSSISION_MAPOBJECT_2 L"Resource\\Background\\4x100\\ObjectMap-2.txt"
#define POSSISION_ENEMIES_2 L"Resource\\Background\\4x100\\Enemies-2.txt"


#define TILES_TRANSCOLOR D3DCOLOR_XRGB(255, 255,255)

#define TILE_SIZE 100
#define GRID_SIZE 400 /*NOTEs*/

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define ALADDIN_WALK_SPEED		0.125f
#define ALADDIN_JUMP_SPEED_Y	0.3f
#define ALADDIN_GRAVITY			0.04f
#define ALADDIN_JUMP_MAX		110

#define APPLE_WIDTH 7
#define APPLE_HEIGHT 6

#define APPLE_FLYING 0
#define APPLE_BANG 1

#define TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define TEXTURE_TRANS_COLOR_2 D3DCOLOR_XRGB(106, 148, 189)
#define TEXTURE_TRANS_COLOR_3 D3DCOLOR_XRGB(120, 193, 152)
#define TEXTURE_TRANS_COLOR_4 D3DCOLOR_XRGB(186, 254, 202)
#define TEXTURE_TRANS_COLOR_5 D3DCOLOR_XRGB(248, 0, 248)
#define TEXTURE_TRANS_COLOR_6 D3DCOLOR_XRGB(220, 84, 151)
#define TEXTURE_TRANS_COLOR_7 D3DCOLOR_XRGB(186, 254, 202)

// Aladdin
#define ALADDIN_TEXTURE_LOCATION L"Resource\\Character\\Aladdin_.png"
#define ALADDIN_TEXTURE_LOCATION2 L"Resource\\Character\\run-hit-n-throw.png"
#define ALADDIN_SPRITE_WIDTH 37
#define ALADDIN_SPRITE_HEIGHT 49

// Enemies
#define ENEMIES_TEXTURE_DEAD  L"Resource\\Enemies\\EnemiesDead.png"
#define GUARD_TEXTURE_LOCATION L"Resource\\Enemies\\Guards.png"

#define GUARD1_SPRITE_WIDTH 44
#define GUARD1_SPRITE_HEIGHT 57
#define GUARD1_WALK_SPEED 0.045f

// Jafar
#define JAFAR_TEXTURE_SPRITE  L"Resource\\Boss\\Jafar.png"
#define JAFAR_SPRITE_WIDTH 57
#define JAFAR_SPRITE_HEIGHT 69

// EFFECTS
#define EFFECT_JAFAR_SPRITE_WIDTH 13
#define EFFECT_JAFAR_SPRITE_HEIGHT 12

// BULLET
#define BULLET_JAFAR_SPRITE_WIDTH 27
#define BULLET_JAFAR_SPRITE_HEIGHT 13

// SNAKE
#define SNAKE_SPRITE_WIDTH 69
#define SNAKE_SPRITE_HEIGHT 81

// FIRE 1
#define FIRE1_SPRITE_WIDTH 24
#define JFIRE1_SPRITE_HEIGHT 46

// FIRE 2
#define FIRE2_SPRITE_WIDTH 74
#define JFIRE2_SPRITE_HEIGHT 49

// Items
#define ITEMS_TEXTURE_LOCATION L"Resource\\Miscellaneous\\Items.png"
#define GET_ITEMS_TEXTURE_LOCATION L"Resource\\Miscellaneous\\GetItem.png"
#define APPLE_ITEM_WIDTH 11
#define APPLE_ITEM_HEIGHT 11
#define DIAMOND_ITEM_WIDTH 17
#define DIAMOND_ITEM_HEIGHT 15

// Map Objects
#define MAPOBJECTS_TEXTURE_LOCATION L"Resource\\Background\\MapObjects.png"
#define THORN_ITEM_WIDTH 23
#define THORN_ITEM_HEIGHT 19
#define BALL_ITEM_WIDTH 17
#define BALL_ITEM_HEIGHT 64
#define BRICK_ITEM_WIDTH 31
#define BRICK_ITEM_HEIGHT 14

// Game Menu
#define HP_TEXTURE_LOCATION L"Resource\\Miscellaneous\\HP.png"
#define TEXT_TEXTURE_LOCATION L"Resource\\Miscellaneous\\Text.png"
#define TEXT_ITEM_WIDTH 14
#define TEXT_ITEM_HEIGHT 13