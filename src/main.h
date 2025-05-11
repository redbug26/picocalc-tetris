#include "G_credits_scr.h"
#include "G_gameA_scr.h"
#include "G_gameB_scr.h"
#include "G_gametype_scr.h"
#include "G_levelA_scr.h"
#include "G_levelB_scr.h"
#include "G_main_scr.h"
#include "pkklib.h"

typedef enum {
    SC_GAME,
    SC_CREDITS,
    SC_LEVEL,
    SC_GAMETYPE,
    SC_END,
    SC_INTRO,
    SC_SCORE
} GAME_SCENE;

extern u8 cfg_game;
extern u8 cfg_music;
extern u8 cfg_level;
extern u8 cfg_high;