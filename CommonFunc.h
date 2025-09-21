
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <windows.h>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

static Mix_Music* g_music = NULL;
static Mix_Chunk* g_sound_bullet = NULL;
static Mix_Chunk* g_sound_explosion = NULL;
static Mix_Chunk* g_sound_ex_main = NULL;
static Mix_Chunk* g_click = NULL;
static Mix_Chunk* g_jump = NULL;


static char g_name_audio_bullet_main1[] = { "sound//Fire.wav" };
static char g_name_audio_ex_main[] = { "sound//Explosion+1.wav" };
static char g_name_audio_ex_threats[] = { "sound//Bomb1.wav" };
//static char g_name_sound_increase[] = { "sound//two_beep_.wav" };
static char kSoundBeep[] = { "sound//beep_.wav" };
static char g_music_sound[] = {"sound//actiontheme-v3.wav"};
static char g_click_[] = { "sound//mouse_click.wav" };
static char g_jump_[] = {"sound//jump.wav"};

const int FRAME_PER_SECOND = 24;  
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0Xff;

#define PLAYER_BULLET_SPEED 20

#define BLANK_TILE 0
#define TILE_SIZE 64

#define MAX_MAP_X 400
#define MAX_MAP_Y 10

#define STATE_MONEY 4

#define IS_REPEATITIVE -1
#define NOT_REPEATITIVE 0
#define COMMON_BUTTON 2
#define SMALL_BUTTON 1
#define BUTTON_WIDTH 150
#define BUTTON_HEIGHT 98
#define MIX_CHANNEL -1

const int PLAY_BUTTON_POSX = 200;
const int PLAY_BUTTON_POSY = 402;
const int HELP_BUTTON_POSX = 565;
const int HELP_BUTTON_POSY = 402;
const int EXIT_BUTTON_POSX = 930;
const int EXIT_BUTTON_POSY = 402;
const int BACK_BUTTON_POSX = 31;
const int BACK_BUTTON_POSY = 29;
const int PAUSE_BUTTON_POSX = 31;
const int PAUSE_BUTTON_POSY = 45;
const int CONTINUE_BUTTON_POSX = 524;
const int CONTINUE_BUTTON_POSY = 266;
const int QUIT_PAUSE_BUTTON_POSX = 1169;
const int QUIT_PAUSE_BUTTON_POSY = 43;

const int PLAYER1_BUTTON_POSX = 225;
const int PLAYER1_BUTTON_POSY = 422;

const int PLAYER2_BUTTON_POSX = 564;
const int PLAYER2_BUTTON_POSY = 422;

const int PLAYER3_BUTTON_POSX = 934;
const int PLAYER3_BUTTON_POSY = 422;

const int MAP1_BUTTON_POSX = 200;
const int MAP1_BUTTON_POSY = 300;

const int MAP2_BUTTON_POSX = 565;
const int MAP2_BUTTON_POSY = 300;

const int MAP3_BUTTON_POSX = 930;
const int MAP3_BUTTON_POSY = 300;

typedef struct Input
{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};

typedef struct Map
{
    int start_x_;
    int start_y_;

    int max_x_;
    int max_y_;

    int tile[MAX_MAP_Y][MAX_MAP_X];
    std::string file_name_;
};

enum ButtonSprite
{
    BUTTON_MOUSE_OUT = 0,
    BUTTON_MOUSE_OVER = 1,
    BUTTON_TOTAL = 2
};


namespace SDLCommonFunc
{
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}

#endif