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
	ROPE,
	DOOR
};

enum EventCollison
{
	EVENT_DEFAULT,
	EVENT_BRICK,
	EVENT_WALL,
	EVENT_ROPE,
	EVENT_DOOR
};

enum ObjectAndEnemies
{
	NOTHING,
	GUARD1, // Enemies
	GUARD2,
	SKELETON,
	BAT,
	THORN, 	// Objects
	BALL,
	BRICK_IN,
	BRICK_OUT,
	APPLE, 	// Items
	DIAMOND,
	BOTTLE,
	GENIE_FACE,
	EXTRA_HEART,
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

#define SENSE_FRONT_MAP L"Resource\\Background\\Images\\map-front.png"
#define SENSE_FRONT_MAP_2 L"Resource\\Background\\Images\\map-front-2.png"

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
#define TEXTURE_TRANS_COLOR_8 D3DCOLOR_XRGB(163, 73, 164)

// Aladdin
#define ALADDIN_TEXTURE_LOCATION L"Resource\\Character\\Aladdin_.png"
#define ALADDIN_TEXTURE_LOCATION2 L"Resource\\Character\\run-hit-n-throw.png"
#define ALADDIN_SPRITE_WIDTH 37
#define ALADDIN_SPRITE_HEIGHT 49
#define ALADDIN_DAMAGE 30
#define ALADDIN_DEFAULT_HP 500
#define ALADDIN_DEFAULT_APPLE 10
#define ALADDIN_DEFAULT_MAX_APPLE 100
#define ALADDIN_DEFAULT_DIAMOND 0
#define ALADDIN_DEFAULT_MAX_DIAMOND 100
#define ALADDIN_DEFAULT_HEART 3
#define ALADDIN_DEFAULT_MAX_HEART 100
#define ALADDIN_DEFAULT_SCORE 0
#define ALADDIN_DEFAULT_MAXS_SCORE 99999

// Enemies
#define ENEMIES_TEXTURE_DEAD  L"Resource\\Enemies\\EnemiesDead.png"
#define GUARD_TEXTURE_LOCATION L"Resource\\Enemies\\Guards.png"
#define SKELETON_TEXTURE_LOCATION  L"Resource\\Enemies\\Skeleton.png"
#define BAT_TEXTURE_LOCATION L"Resource\\Enemies\\Bat.png"

#define GUARD1_SPRITE_WIDTH 44
#define GUARD1_SPRITE_HEIGHT 57
#define GUARD1_WALK_SPEED 0.045f
#define GUARD1_DAMAGE 40
#define GUARD1_HP 50
#define GUARD1_POINT 20

#define GUARD2_SPRITE_WIDTH 44
#define GUARD2_SPRITE_HEIGHT 52
#define GUARD2_WALK_SPEED 0.045f
#define GUARD2_DAMAGE 30
#define GUARD2_HP 80
#define GUARD2_POINT 20

#define SKELETON_SPRITE_WIDTH 44
#define SKELETON_SPRITE_HEIGHT 52
#define SKELETON_DAMAGE 50
#define SKELETON_HP 30
#define SKELETON_POINT 20

#define BAT_SPRITE_WIDTH 23
#define BAT_SPRITE_HEIGHT 14
#define BAT_FLY_DOWN_SPEED_X 0.1f
#define BAT_FLY_DOWN_SPEED_Y 0.175f
#define BAT_FLY_UP_SPEED_X 0.015f
#define BAT_FLY_UP_SPEED_Y 0.018f
#define BAT_DIE_BY_APPLE 0.45f
#define BAT_DAMAGE 35
#define BAT_HP 20
#define BAT_POINT 20

// Jafar
#define JAFAR_TEXTURE_SPRITE  L"Resource\\Boss\\Jafar.png"
#define JAFAR_SPRITE_WIDTH 57
#define JAFAR_SPRITE_HEIGHT 69
#define JAFAR_HP 1000
#define CHANGING_POINT 300
#define JAFAR_DAMAGE 60
#define SNAKE_DAMAGE 75
#define JAFAR_POINT 5000
#define JAFAR_RADIUS 680

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
#define FIRE2_SPRITE_WIDTH 40
#define JFIRE2_SPRITE_HEIGHT 30
#define JFIRE2_RADIUS 650
#define JFIRE2_SPEED 0.105f

// Items
#define ITEMS_TEXTURE_LOCATION L"Resource\\Miscellaneous\\Items.png"
#define GET_ITEMS_TEXTURE_LOCATION L"Resource\\Miscellaneous\\GetItem.png"
#define APPLE_ITEM_WIDTH 11
#define APPLE_ITEM_HEIGHT 11
#define DIAMOND_ITEM_WIDTH 17
#define DIAMOND_ITEM_HEIGHT 15
#define DIAMOND_ITEM_POINT 150
#define GENIE_FACE_ITEM_WIDTH 38
#define GENIE_FACE_ITEM_HEIGHT 49
#define GENIE_FACE_POINT 250
#define EXTRA_HEART_ITEM_WIDTH 19
#define EXTRA_HEART_ITEM_HEIGHT 23
#define EXTRA_HEART_ITEM_POINT 300
#define BOTTLE_ITEM_WIDTH 19
#define BOTTLE_ITEM_HEIGHT 32

// Peddler Shop
#define PEDDLER_SHOP_TEXTURE_LOCATION L"Resource\\Miscellaneous\\Peddler.png"
#define PEDDLER_SHOP_WIDTH 135
#define PEDDLER_SHOP_HEIGHT 74

// Map Objects
#define MAPOBJECTS_TEXTURE_LOCATION L"Resource\\Background\\MapObjects.png"
#define THORN_ITEM_WIDTH 23
#define THORN_ITEM_HEIGHT 19
#define THORN_DAMAGE_BY_TIME 7
#define BALL_ITEM_WIDTH 27
#define BALL_ITEM_HEIGHT 64
#define BALL_DAMAGE_BY_TIME 1
#define BRICK_ITEM_WIDTH 31
#define BRICK_ITEM_HEIGHT 14

// Game Menu
#define HP_TEXTURE_LOCATION L"Resource\\Miscellaneous\\HP.png"
#define TEXT_TEXTURE_LOCATION L"Resource\\Miscellaneous\\Text.png"
#define TEXT_ITEM_WIDTH 14
#define TEXT_ITEM_HEIGHT 13

//SOUND
#define SOUND_OBJECT_THROW L"Resource\\Sounds\\Object Throw.wav"
#define SOUND_ALADDIN_HURT L"Resource\\Sounds\\AladdinHurt.wav"
#define SOUND_ALADDIN_OOF L"Resource\\Sounds\\Aladdin Oof.wav"
#define SOUND_ALADDIN_PUSH L"Resource\\Sounds\\Aladdin Push.wav"
#define SOUND_APPLE_COLLECT L"Resource\\Sounds\\Apple Collect.wav"
#define SOUND_APPLE_SLICE L"Resource\\Sounds\\Apple Slice.wav"
#define SOUND_APPLE_SPLAT L"Resource\\Sounds\\Apple Splat.wav"
#define SOUND_BALLOON_POP L"Resource\\Sounds\\Balloon Pop.wav"
#define SOUND_BODY_CRUNCH L"Resource\\Sounds\\Body Crunch.wav"
#define SOUND_BONES_TINKLE L"Resource\\Sounds\\Bones Tinkle.wav"
#define SOUND_BOXING_BELL L"Resource\\Sounds\\Boxing Bell.wav"
#define SOUND_CASH_RES1 L"Resource\\Sounds\\Cash Register (FM Only).wav"
#define SOUND_CASH_RES2 L"Resource\\Sounds\\Cash Register (Sample Only).wav"
#define SOUND_CASH_RES3 L"Resource\\Sounds\\Cash Register.wav"
#define SOUND_COMING_OUT L"Resource\\Sounds\\Coming Out.wav"
#define SOUND_COUNTINUE_POINT L"Resource\\Sounds\\Continue Point.wav"
#define SOUND_EXTRA_HEALTH L"Resource\\Sounds\\Extra Health.wav"
#define SOUND_FIRE_FROM_COAL L"Resource\\Sounds\\Fire From Coal.wav"
#define SOUND_GEM_COLLECT L"Resource\\Sounds\\Gem Collect.wav"
#define SOUND_GENIE_FUMES L"Resource\\Sounds\\Genie Fumes.wav"
#define SOUND_GUARD_BECKON L"Resource\\Sounds\\Guard Beckon.wav"
#define SOUND_GUARD_HIT_1 L"Resource\\Sounds\\Guard Hit 1.wav"
#define SOUND_GUARD_HIT_2 L"Resource\\Sounds\\Guard Hit 2.wav"
#define SOUND_GUARDS_PANTS L"Resource\\Sounds\\Guard's Pants.wav"
#define SOUND_HEAD_BOP L"Resource\\Sounds\\Head Bop.wav"
#define SOUND_JAFAR_LAUGH L"Resource\\Sounds\\Jafar Laugh.wav"
#define SOUND_JAFAR_SNAKE L"Resource\\Sounds\\Jafar Snake.wav"
#define SOUND_JAFAR_TRACTOR L"Resource\\Sounds\\Jafar Tractor.wav"
#define SOUND_HIGH_SWORD L"Resource\\Sounds\\High Sword.wav"
#define SOUND_LOW_SWORD L"Resource\\Sounds\\Low Sword.wav"
#define SOUND_THEMES L"Resource\\Sounds\\Themes.wav"
#define SOUND_A_WHOLE_NEW_WORLD L"Resource\\Sounds\\AWholeNewWorld.wav"
#define SOUND_SKELETON_FIRE L"Resource\\Sounds\\Skeleton (PSG Only).wav"
#define SOUND_SKELETON_BOOM L"Resource\\Sounds\\Skeleton (Sample Only).wav"
#define SOUND_SKELETON_FIREnBOOM L"Resource\\Sounds\\Skeleton.wav"