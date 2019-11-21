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
	ON_BUTTON,
	RIVER,
	ROPE_SWING,
	THORN
};

#define EVENT_BRICK 1
#define EVENT_WATER 2
#define EVENT_ROPE_SWING 3
#define EVENT_THORN 4
#define EVENT_WALL 5

//TiledMap
//

// MAP
#define TILES_MATRIX_STAGE_1 L"Resource\\Background\\4x100\\bg-tiled.txt"
#define TILES_SET_MATRIX_STAGE_1 L"Resource\\Background\\4x100\\bg-tiled.png"

//#define BACKGROUND_1 L"Resources\\Maps\\CharlestonMap.png"
#define BACKGROUND_2 L"Resources\\Maps\\PittsburghMap.png"

// TILE
//#define TILES_MATRIX_STAGE_1 L"Resources\\Maps\\CharlestonMapMatrix.txt"
#define TILES_MATRIX_STAGE_2 L"Resources\\Maps\\PittsburghMapMatrix.txt"

// TILE SET
//#define TILES_SET_MATRIX_STAGE_1 L"Resources\\Maps\\CharlestonMapTiles.png"
#define TILES_SET_MATRIX_STAGE_2 L"Resources\\Maps\\PittsburghMapTiles.png"


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

#define ALADDIN_TEXTURE_LOCATION L"Resource\\Character\\Aladdin_.png"
#define TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define TEXTURE_TRANS_COLOR_1 D3DCOLOR_XRGB(0, 91, 127)
#define TEXTURE_TRANS_COLOR_2 D3DCOLOR_XRGB(0, 166, 81)
#define ALADDIN_SPRITE_WIDTH 37
#define ALADDIN_SPRITE_HEIGHT 49
