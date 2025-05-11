#include <stdlib.h>

#include "main.h"

#include "ym_TETRISA.h"
#include "ym_TETRISB.h"
#include "ym_TETRISC.h"
#include "ym_TETRISGAMEOVER.h"
#include "ym_TETRISSCORE.h"
#include "ym_TETRISTITLESCREEN.h"
#include "ym_EMPTYSONG.h"

GAME_SCENE partGame;

u32 score;

void updateMusic(u8 music, u8 force);

// sprite


const unsigned char G_font8x8[848] = {
    0xFF, 0xFF,
    0xCC, 0x33,
    0xBB, 0x11,
    0xBB, 0x11,
    0x88, 0x11,
    0xBB, 0x11,
    0xBB, 0x11,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x33,
    0x99, 0x99,
    0x88, 0x33,
    0x99, 0x99,
    0x99, 0x99,
    0x88, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0x99,
    0x99, 0xFF,
    0x99, 0xFF,
    0x99, 0x99,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x33,
    0xBB, 0x11,
    0xBB, 0x11,
    0xBB, 0x11,
    0xBB, 0x11,
    0x88, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x11,
    0x99, 0xFF,
    0x88, 0x33,
    0x99, 0xFF,
    0x99, 0xFF,
    0x88, 0x11,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x11,
    0x99, 0xFF,
    0x99, 0xFF,
    0x88, 0x33,
    0x99, 0xFF,
    0x99, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0x99,
    0x99, 0xFF,
    0x99, 0x11,
    0x99, 0x99,
    0xCC, 0x11,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBB, 0x99,
    0xBB, 0x99,
    0x88, 0x11,
    0xBB, 0x99,
    0xBB, 0x99,
    0xBB, 0x99,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0xEE, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xEE, 0x11,
    0xFF, 0x33,
    0xFF, 0x33,
    0x99, 0x33,
    0x99, 0x33,
    0xCC, 0x77,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x99, 0x99,
    0x99, 0x33,
    0x88, 0x77,
    0x88, 0x77,
    0x99, 0x33,
    0x99, 0x99,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x99, 0xFF,
    0x99, 0xFF,
    0x99, 0xFF,
    0x99, 0xFF,
    0x99, 0xFF,
    0x88, 0x11,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBB, 0x99,
    0x99, 0x11,
    0x88, 0x11,
    0xAA, 0x99,
    0xBB, 0x99,
    0xBB, 0x99,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBB, 0x99,
    0x99, 0x99,
    0x88, 0x99,
    0xAA, 0x11,
    0xBB, 0x11,
    0xBB, 0x99,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0x99,
    0x99, 0x99,
    0x99, 0x99,
    0x99, 0x99,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x33,
    0x99, 0x99,
    0x99, 0x99,
    0x88, 0x33,
    0x99, 0xFF,
    0x99, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0xDD,
    0x99, 0xDD,
    0x99, 0x55,
    0x99, 0xBB,
    0xCC, 0x55,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x33,
    0x99, 0x99,
    0x99, 0x99,
    0x88, 0x33,
    0x99, 0x77,
    0x99, 0x99,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0xFF,
    0xCC, 0x33,
    0xFF, 0x11,
    0xBB, 0x11,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x11,
    0xEE, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBB, 0x99,
    0xBB, 0x99,
    0xBB, 0x99,
    0xBB, 0x99,
    0xBB, 0x11,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBB, 0x99,
    0xBB, 0x99,
    0xBB, 0x99,
    0xBB, 0x99,
    0xDD, 0x33,
    0xEE, 0x77,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBB, 0x99,
    0xBB, 0x99,
    0xAA, 0x99,
    0x88, 0x11,
    0x99, 0x11,
    0xBB, 0x99,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBB, 0x99,
    0xDD, 0x33,
    0xEE, 0x77,
    0xCC, 0x77,
    0x99, 0xBB,
    0xBB, 0xDD,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x99, 0x99,
    0x99, 0x99,
    0xCC, 0x33,
    0xEE, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x11,
    0xFF, 0x11,
    0xEE, 0x33,
    0xCC, 0x77,
    0x88, 0xFF,
    0x88, 0x11,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x99, 0xFF,
    0x99, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xDD, 0xDD,
    0xEE, 0xBB,
    0xFF, 0x77,
    0xEE, 0xBB,
    0xDD, 0xDD,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0x99,
    0x99, 0x99,
    0x99, 0x99,
    0x99, 0x99,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xEE, 0x77,
    0xCC, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xEE, 0x77,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0xBB, 0x11,
    0xFF, 0x11,
    0xCC, 0x33,
    0x88, 0xFF,
    0x88, 0x11,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x33,
    0xFF, 0x11,
    0xCC, 0x33,
    0xFF, 0x11,
    0xFF, 0x11,
    0x88, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0x33,
    0xBB, 0x33,
    0xBB, 0x11,
    0x88, 0x11,
    0xFF, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x33,
    0x99, 0xFF,
    0x88, 0x33,
    0xFF, 0x11,
    0xBB, 0x11,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0x99, 0xFF,
    0x88, 0x33,
    0x99, 0x99,
    0x99, 0x99,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x88, 0x11,
    0xFF, 0x99,
    0xFF, 0x33,
    0xEE, 0x77,
    0xCC, 0x77,
    0xCC, 0x77,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0xBB, 0x11,
    0xCC, 0x33,
    0xBB, 0x11,
    0xBB, 0x11,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x33,
    0xBB, 0x11,
    0xBB, 0x11,
    0xCC, 0x11,
    0xFF, 0x11,
    0xCC, 0x33,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xAA, 0xAA,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0x00,
    0xEE, 0x00,
    0xCC, 0x77,
    0xCC, 0xCF,
    0xCC, 0x9F,
    0xCC, 0xBF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x00, 0x00,
    0x00, 0x00,
    0xFF, 0xFF,
    0x0F, 0x0F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x00, 0xFF,
    0x00, 0x77,
    0xEE, 0x33,
    0x3F, 0x33,
    0x9F, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0xDF, 0x33,
    0x9F, 0x33,
    0x3F, 0x33,
    0xEE, 0x33,
    0x00, 0x77,
    0x00, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0xBF,
    0xCC, 0x9F,
    0xCC, 0xCF,
    0xCC, 0x77,
    0xEE, 0x00,
    0xFF, 0x00,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0x99,
    0xAB, 0x06,
    0xAB, 0x0E,
    0x8B, 0x0E,
    0xCD, 0x1D,
    0xEE, 0x3B,
    0xFF, 0x77,
    0x0F, 0x0F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCC, 0xBF,
    0xCC, 0xBF,
    0xCC, 0xBF,
    0xCC, 0xBF,
    0xCC, 0xBF,
    0xCC, 0xBF,
    0xCC, 0xBF,
    0xCC, 0xBF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x0F, 0x0F,
    0xFF, 0xFF,
    0x00, 0x00,
    0x00, 0x00,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x55, 0x55,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xDD,
    0xFF, 0xDD,
    0xEE, 0xDD,
    0xCC, 0xDD,
    0x88, 0x11,
    0xCC, 0xFF,
    0xEE, 0xFF
};


const unsigned char G_font8x8_off[640] = {
    0xFF, 0xFF,
    0xCF, 0x3F,
    0xBF, 0x1F,
    0xBF, 0x1F,
    0x8F, 0x1F,
    0xBF, 0x1F,
    0xBF, 0x1F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x3F,
    0x9F, 0x9F,
    0x8F, 0x3F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0x8F, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0x9F,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0x9F, 0x9F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x3F,
    0xBF, 0x1F,
    0xBF, 0x1F,
    0xBF, 0x1F,
    0xBF, 0x1F,
    0x8F, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x1F,
    0x9F, 0xFF,
    0x8F, 0x3F,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0x8F, 0x1F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x1F,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0x8F, 0x3F,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0x9F,
    0x9F, 0xFF,
    0x9F, 0x1F,
    0x9F, 0x9F,
    0xCF, 0x1F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0x8F, 0x1F,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xEF, 0x1F,
    0xFF, 0x3F,
    0xFF, 0x3F,
    0x9F, 0x3F,
    0x9F, 0x3F,
    0xCF, 0x7F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x9F, 0x9F,
    0x9F, 0x3F,
    0x8F, 0x7F,
    0x8F, 0x7F,
    0x9F, 0x3F,
    0x9F, 0x9F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0x8F, 0x1F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBF, 0x9F,
    0x9F, 0x1F,
    0x8F, 0x1F,
    0xAF, 0x9F,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBF, 0x9F,
    0x9F, 0x9F,
    0x8F, 0x9F,
    0xAF, 0x1F,
    0xBF, 0x1F,
    0xBF, 0x9F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x3F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0x8F, 0x3F,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0xDF,
    0x9F, 0xDF,
    0x9F, 0x5F,
    0x9F, 0xBF,
    0xCF, 0x5F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x3F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0x8F, 0x3F,
    0x9F, 0x7F,
    0x9F, 0x9F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0xFF,
    0xCF, 0x3F,
    0xFF, 0x1F,
    0xBF, 0x1F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x1F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xBF, 0x1F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xDF, 0x3F,
    0xEF, 0x7F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBF, 0x9F,
    0xBF, 0x9F,
    0xAF, 0x9F,
    0x8F, 0x1F,
    0x9F, 0x1F,
    0xBF, 0x9F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xBF, 0x9F,
    0xDF, 0x3F,
    0xEF, 0x7F,
    0xCF, 0x7F,
    0x9F, 0xBF,
    0xBF, 0xDF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0xCF, 0x3F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x1F,
    0xFF, 0x1F,
    0xEF, 0x3F,
    0xCF, 0x7F,
    0x8F, 0xFF,
    0x8F, 0x1F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x9F, 0xFF,
    0x9F, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xDF, 0xDF,
    0xEF, 0xBF,
    0xFF, 0x7F,
    0xEF, 0xBF,
    0xDF, 0xDF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xEF, 0x7F,
    0xCF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xEF, 0x7F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0xBF, 0x1F,
    0xFF, 0x1F,
    0xCF, 0x3F,
    0x8F, 0xFF,
    0x8F, 0x1F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x3F,
    0xFF, 0x1F,
    0xCF, 0x3F,
    0xFF, 0x1F,
    0xFF, 0x1F,
    0x8F, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0x3F,
    0xBF, 0x3F,
    0xBF, 0x1F,
    0x8F, 0x1F,
    0xFF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x3F,
    0x9F, 0xFF,
    0x8F, 0x3F,
    0xFF, 0x1F,
    0xBF, 0x1F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0x9F, 0xFF,
    0x8F, 0x3F,
    0x9F, 0x9F,
    0x9F, 0x9F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x8F, 0x1F,
    0xFF, 0x9F,
    0xFF, 0x3F,
    0xEF, 0x7F,
    0xCF, 0x7F,
    0xCF, 0x7F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0xBF, 0x1F,
    0xCF, 0x3F,
    0xBF, 0x1F,
    0xBF, 0x1F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xCF, 0x3F,
    0xBF, 0x1F,
    0xBF, 0x1F,
    0xCF, 0x1F,
    0xFF, 0x1F,
    0xCF, 0x3F,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF
};


const unsigned char G_tetramino[224] = {
    0x00, 0x00,
    0x25, 0x4B,
    0x07, 0x0F,
    0x43, 0xA5,
    0x07, 0x0F,
    0x25, 0x2D,
    0x07, 0x87,
    0x00, 0x00,
    0x00, 0x00,
    0xA5, 0x87,
    0x0F, 0x2D,
    0x2D, 0x0F,
    0x87, 0x4B,
    0x1E, 0x1E,
    0x4B, 0x4B,
    0x00, 0x00,
    0x00, 0x00,
    0x87, 0x86,
    0x2D, 0x0E,
    0x0F, 0x4A,
    0x5A, 0x0E,
    0x0F, 0x2C,
    0x2D, 0x86,
    0x00, 0x00,
    0x00, 0x00,
    0x07, 0x86,
    0x25, 0x2C,
    0x07, 0x0E,
    0x43, 0x86,
    0x07, 0x2C,
    0x25, 0x86,
    0x07, 0x0E,
    0x16, 0x2C,
    0x43, 0x0E,
    0x07, 0xA4,
    0x25, 0x0E,
    0x07, 0x2C,
    0x52, 0x0E,
    0x07, 0x4A,
    0x25, 0x0E,
    0x07, 0x2C,
    0x16, 0x0E,
    0x43, 0x4A,
    0x16, 0x0E,
    0x43, 0x2C,
    0x07, 0x86,
    0x25, 0x0E,
    0x00, 0x00,
    0x00, 0x00,
    0x77, 0xEE,
    0x44, 0x22,
    0x44, 0x22,
    0x44, 0x22,
    0x44, 0x22,
    0x77, 0xEE,
    0x00, 0x00,
    0x00, 0x00,
    0x07, 0x0E,
    0x04, 0x02,
    0x15, 0x8A,
    0x15, 0x8A,
    0x04, 0x02,
    0x07, 0x0E,
    0x00, 0x00,
    0x00, 0x00,
    0x70, 0xE0,
    0x70, 0xE0,
    0x70, 0xE0,
    0x70, 0xE0,
    0x70, 0xE0,
    0x70, 0xE0,
    0x00, 0x00,
    0x00, 0x00,
    0x07, 0x0E,
    0x07, 0x0E,
    0x06, 0x06,
    0x06, 0x06,
    0x07, 0x0E,
    0x07, 0x0E,
    0x00, 0x00,
    0x00, 0x00,
    0x70, 0xE0,
    0x40, 0x20,
    0x41, 0x28,
    0x41, 0x28,
    0x40, 0x20,
    0x70, 0xE0,
    0x00, 0x00,
    0x00, 0x00,
    0x07, 0x0E,
    0x37, 0xCE,
    0x27, 0x0A,
    0x27, 0x0A,
    0x04, 0x02,
    0x07, 0x0E,
    0x00, 0x00,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0x00, 0x00,
    0x77, 0xEE,
    0x47, 0x2C,
    0x47, 0x2C,
    0x47, 0x2C,
    0x47, 0x2C,
    0x74, 0xE0,
    0x00, 0x00
};


const unsigned char G_main_select[32] = {
    0xFF, 0xFF,
    0x99, 0xFF,
    0x88, 0xFF,
    0x88, 0x77,
    0x88, 0x77,
    0x88, 0xFF,
    0x99, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF,
    0xFF, 0xFF
};



// cpcput

// get value of the bit x in y
#define bit(x, y) (((y) >> (x)) & 1)

u8 R_palette[4] = {0x10, 0x31, 0x8C, 0x9C};
u8 G_palette[4] = {0x3A, 0x63, 0xAD, 0xBD};
u8 B_palette[4] = {0x10, 0x31, 0x10, 0x10};

// cpc buffer is 16 bytes length (2x8 pixels)
// rgb buffer is 16x16*3 pixels length
void convertCPCtoRGB(unsigned char *cpc, unsigned char *rgb)
{
    u8 x, y;

    u16 *rgb0 = (u16 *)rgb;

    for (y = 0; y < 16; y++) {
        for (x = 0; x < 2; x++) {
            u8 c = cpc[(y / 2) * 2 + x];

            u8 c0 = bit(7, c) + bit(3, c) * 2;
            u8 c1 = bit(6, c) + bit(2, c) * 2;
            u8 c2 = bit(5, c) + bit(1, c) * 2;
            u8 c3 = bit(4, c) + bit(0, c) * 2;

            *rgb0 = RGB565(R_palette[c0], G_palette[c0], B_palette[c0]); rgb0++;
            *rgb0 = RGB565(R_palette[c0], G_palette[c0], B_palette[c0]); rgb0++;
            *rgb0 = RGB565(R_palette[c1], G_palette[c1], B_palette[c1]); rgb0++;
            *rgb0 = RGB565(R_palette[c1], G_palette[c1], B_palette[c1]); rgb0++;
            *rgb0 = RGB565(R_palette[c2], G_palette[c2], B_palette[c2]); rgb0++;
            *rgb0 = RGB565(R_palette[c2], G_palette[c2], B_palette[c2]); rgb0++;
            *rgb0 = RGB565(R_palette[c3], G_palette[c3], B_palette[c3]); rgb0++;
            *rgb0 = RGB565(R_palette[c3], G_palette[c3], B_palette[c3]); rgb0++;

            // *rgb0 = R_palette[c0]; rgb0++;
            // *rgb0 = G_palette[c0]; rgb0++;
            // *rgb0 = B_palette[c0]; rgb0++;

            // *rgb0 = R_palette[c0]; rgb0++;
            // *rgb0 = G_palette[c0]; rgb0++;
            // *rgb0 = B_palette[c0]; rgb0++;

            // *rgb0 = R_palette[c1]; rgb0++;
            // *rgb0 = G_palette[c1]; rgb0++;
            // *rgb0 = B_palette[c1]; rgb0++;

            // *rgb0 = R_palette[c1]; rgb0++;
            // *rgb0 = G_palette[c1]; rgb0++;
            // *rgb0 = B_palette[c1]; rgb0++;

            // *rgb0 = R_palette[c2]; rgb0++;
            // *rgb0 = G_palette[c2]; rgb0++;
            // *rgb0 = B_palette[c2]; rgb0++;

            // *rgb0 = R_palette[c2]; rgb0++;
            // *rgb0 = G_palette[c2]; rgb0++;
            // *rgb0 = B_palette[c2]; rgb0++;

            // *rgb0 = R_palette[c3]; rgb0++;
            // *rgb0 = G_palette[c3]; rgb0++;
            // *rgb0 = B_palette[c3]; rgb0++;

            // *rgb0 = R_palette[c3]; rgb0++;
            // *rgb0 = G_palette[c3]; rgb0++;
            // *rgb0 = B_palette[c3]; rgb0++;
        }
    }

} /* convertCPCtoRGB */

void pkk_PutTile2x8(const char *sprite, unsigned char x, unsigned char y)
{
    u8 dest[16 * 16 * 2];

    u16 x1, y1;

    x1 = x * 8;
    y1 = y * 2 + 16;

    convertCPCtoRGB((unsigned char *)sprite, dest);
    pkk_draw_buf_spi(x1, y1, 16, 16, dest);
}

// sound

void PlaySfx(u8 sfx)
{
    // if (cfg_music) {
    //     switch (sfx) {
    //     case 0:
    //         sound_play(0);
    //         break;
    //     case 1:
    //         sound_play(1);
    //         break;
    //     case 2:
    //         sound_play(2);
    //         break;
    //     case 3:
    //         sound_play(3);
    //         break;
    //     }
    // }
} /* PlaySfx */


// functions



void displayFooter(void)
{

    u16 y;

    for (y = 0; y < 6; y++) {
        // pkk_PutSp(G_footer + y * 320, 8, 40, pkk_GetScrAddress(0, 152 + y * 8));
    }
}


void k_PrintGphStr8x8(char *text, u8 posx, u8 posy, u8 active)
{
    u8 *car = text;

    while (*car != 0) {
        const u8 *sprite = 0;
        u16 pos = 0;

        if ((*car >= 'A') && (*car <= 'Z')) {
            pos = (((u16)(*car) - 'A') + 0) * 16;
        } else if (*car == '.') {
            pos = 26 * 16;
        } else if (*car == '-') {
            pos = 27 * 16;
        } else if (*car == '*') {
            pos = 28 * 16;
        } else if ((*car >= '0') && (*car <= '9')) {
            pos = (((u16)(*car) - '0') + 29) * 16;
        } else if ((*car >= 'a') && (*car <= 'z')) {
            pos = (((u16)(*car) - 'a') + 40) * 16;
        } else if (*car == '\\') {
            pos = 52 * 16;
        } else {
            pos = 39 * 16;
        }

        if (active) {
            sprite = G_font8x8 + pos;
        } else {
            sprite = G_font8x8_off + pos;
        }
        pkk_PutTile2x8((char *)sprite, posx, posy);

        posx += 2;
        car++;
    }

    // pkk_lcd_waitVSYNC();
}     /* k_PrintGphStr */

void k_PrintGphStr8x8WithPad(char *text, u8 posx, u8 posy, u8 active, u8 len, u8 pad)
{
    u8 n;
    u8 padStr[2];

    u8 lenStr = 0;
    u8 *str = text;

    while (*str != 0) {
        lenStr++;
        str++;
    }

    padStr[1] = 0;
    padStr[0] = pad;

    for (n = 0; n < len - lenStr; n++) {
        k_PrintGphStr8x8(padStr,  posx + n * 2,  posy,  active);
    }

    k_PrintGphStr8x8(text,  posx + (len - lenStr) * 2,  posy,  active);
} /* k_PrintGphStr8x8WithPad */

void inttostring(unsigned int value, char *string, signed char padding, u8 pad)
{
    signed char index = 0, i = 0;

    /* generate the number in reverse order */
    do {
        string[index] = '0' + (value % 10);
        if (string[index] > '9')
            string[index] += 'A' - '9' - 1;
        value /= 10;
        index++;
    } while (value != 0);

    while (index < padding) {
        string[index] = pad;
        index++;
    }

    /* null terminate the string */
    string[index--] = '\0';

    /* reverse the order of digits */
    while (index > i) {
        char tmp = string[i];
        string[i] = string[index];
        string[index] = tmp;
        i++;
        index--;
    }
} /* inttostring */

void int32tostring(u32 value, char *string, signed char padding, u8 pad)
{
    signed char index = 0, i = 0;

    /* generate the number in reverse order */
    do {
        string[index] = '0' + (value % 10);
        if (string[index] > '9')
            string[index] += 'A' - '9' - 1;
        value /= 10;
        index++;
    } while (value != 0);

    while (index < padding) {
        string[index] = pad;
        index++;
    }

    /* null terminate the string */
    string[index--] = '\0';

    /* reverse the order of digits */
    while (index > i) {
        char tmp = string[i];
        string[i] = string[index];
        string[index] = tmp;
        i++;
        index--;
    }
} /* inttostring */

void drawInteger(u16 x, u16 y, u16 i, u8 len, u8 pad)
{
    char text[len + 1];;

    inttostring(i, text, len, pad);

    k_PrintGphStr8x8(text, x, y, 1);


}

void drawInteger32(u16 x, u16 y, u32 i, u8 len, u8 pad)
{
    char text[12];

    int32tostring(i, text, len, pad);

    k_PrintGphStr8x8(text, x, y, 1);


}


int credits(void)
{
    int retour = 0;

    pkk_displayGIF((unsigned char *)&G_credits_scr, G_credits_scr_length);

    u16 frame = 0;

    while (frame < 50 * 5) {

        pkk_lcd_waitVSYNC();

        if (pkk_key_pressed(KEY_A) == 1) {
            return 1;
        }

        if (pkk_key_pressed(KEY_SELECT) == 1) {     // Escape
            return 99;       // VERIFIY: accept to ESCAPE the game ????
        }

        frame++;
    }

    return 0;

} /* credits */

// intro

char intro(void)
{
    u16 frame = 0;

    GAME_SCENE retour = SC_INTRO;


    cfg_game = 0;
    cfg_music = 0;
    cfg_level = 0;
    cfg_high = 0;

    // loadHighScore();

    // _TETRISTITLESCREEN_START
    updateMusic(4, 0);

    pkk_displayGIF((unsigned char *)&G_main_scr, G_main_scr_length);

    // displayFooter();



    u8 player = 1;

    while (retour == SC_INTRO) {                // Repeat until ESC pressed - Small scrolling effect

        pkk_lcd_waitVSYNC();


        if (pkk_key_pressed_withWait(KEY_LEFT)) {
            player = 1;
            pkk_PutTile2x8(G_main_select + 0 * 16, 2, 112);
            pkk_PutTile2x8(G_main_select + 1 * 16, 22, 112);
        }

        if (pkk_key_pressed_withWait(KEY_RIGHT)) {
            player = 2;
            pkk_PutTile2x8(G_main_select + 0 * 16, 22, 112);
            pkk_PutTile2x8(G_main_select + 1 * 16, 2, 112);
        }

        if (pkk_key_pressed_withWait(KEY_A) == 1) {

            if (player == 2) {     // Player 2 not available
                player = 1;
                pkk_PutTile2x8(G_main_select + 0 * 16, 2, 112);
                pkk_PutTile2x8(G_main_select + 1 * 16, 22, 112);
            } else {
                retour = SC_GAMETYPE;     // main game
            }
        }

        if (pkk_key_pressed_withWait(KEY_SELECT)) {      // Escape
            return SC_END;       // VERIFIY: accept to ESCAPE the game ????
        }

        rand();

    }


    return (char)retour;

}     /* intro */

// gametype
u8 currentMusic;


void updateMusic(u8 music, u8 force)
{

    if ((music == currentMusic) && (!force)) {
        return;
    }

    currentMusic = music;

    if (music == 0) {  // _TETRISA_START
        pkk_loadSoundYM(ym_TETRISA, ym_TETRISA_length, 1);
    }

    if (music == 1) { // _TETRISB_START
        pkk_loadSoundYM(ym_TETRISB, ym_TETRISB_length, 1);
    }

    if (music == 2) {  // _TETRISC_START
        pkk_loadSoundYM(ym_TETRISC, ym_TETRISC_length, 1);
    }

    if (music == 3) {  // _EMPTYSONG_START
        pkk_loadSoundYM(ym_EMPTYSONG, ym_EMPTYSONG_length, 1);
    }

    if (music == 4) {  // _TETRISTITLESCREEN_START
        pkk_loadSoundYM(ym_TETRISTITLESCREEN, ym_TETRISTITLESCREEN_length, 1);
    }

    if (music == 5) {  // _TETRISSCORE_START
        pkk_loadSoundYM(ym_TETRISSCORE, ym_TETRISSCORE_length, 1);
    }

    if (music == 6) {  // _TETRISGAMEOVER_START
        pkk_loadSoundYM(ym_TETRISGAMEOVER, ym_TETRISGAMEOVER_length, 1);
    }


} /* updateMusic */

void updatePart(u8 part, u8 type, u8 state)
{
    if (part == 1) {
        if (type == 0) {
            k_PrintGphStr8x8("A-TYPE", 24 / 4, 40, state);
        } else {
            k_PrintGphStr8x8("B-TYPE", 88 / 4, 40, state);
        }
    } else if (part == 2) {
        if (type == 0) {
            k_PrintGphStr8x8("A-TYPE", 24 / 4, 96, state);
        } else if (type == 1) {
            k_PrintGphStr8x8("B-TYPE", 88 / 4, 96, state);
        } else if (type == 2) {
            k_PrintGphStr8x8("C-TYPE", 24 / 4, 112, state);
        } else {
            k_PrintGphStr8x8(" OFF  ", 88 / 4, 112, state);
        }

        if (state == 1) {
            updateMusic(type, 0);
        }
    } else if (part == 3) {
        if (type == 0) {
            k_PrintGphStr8x8("A-TYPE", 16 / 4, 8, state);
        } else {
            k_PrintGphStr8x8("ABTYPE", 16 / 4, 8, state);
        }
    }


} /* updatePart */


char gametype(void)
{
    u16 frame = 0;

    GAME_SCENE retour = SC_GAMETYPE;

// GameType

    // updateMusic(cfg_music, 1);

    pkk_displayGIF((unsigned char *)&G_gametype_scr, G_gametype_scr_length);

    displayFooter();

    u8 part = 1;

    updatePart(1, 0, 1);
    updatePart(1, 1, 0);


    updatePart(2, 0, (cfg_music == 0));
    updatePart(2, 1, (cfg_music == 1));
    updatePart(2, 2, (cfg_music == 2));
    updatePart(2, 3, (cfg_music == 3));


    frame = 0;

    u8 off = 0;

    while (retour == SC_GAMETYPE) {                // Repeat until ESC pressed - Small scrolling effect

        pkk_lcd_waitVSYNC();

        frame++;

        if (frame == 10) {
            frame = 0;

            if (off) {
                off = 0;
            } else {
                off = 1;
            }

            if (part == 1) {
                updatePart(1, cfg_game, off);
            } else {
                updatePart(2, cfg_music, off);
            }
        }

        // Keyboard

        if (pkk_key_pressed_withWait(KEY_LEFT)) {
            if (part == 1) {
                if (cfg_game == 1) {
                    updatePart(part, cfg_game, 0);
                    cfg_game = 0;
                    updatePart(part, cfg_game, 1);
                }
            }
            if (part == 2) {
                if (cfg_music == 1) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 0;
                    updatePart(part, cfg_music, 1);
                }
                if (cfg_music == 3) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 2;
                    updatePart(part, cfg_music, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_RIGHT)) {
            if (part == 1) {
                if (cfg_game == 0) {
                    updatePart(part, cfg_game, 0);
                    cfg_game = 1;
                    updatePart(part, cfg_game, 1);
                }
            }
            if (part == 2) {
                if (cfg_music == 0) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 1;
                    updatePart(part, cfg_music, 1);
                }
                if (cfg_music == 2) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 3;
                    updatePart(part, cfg_music, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_UP)) {
            if (part == 2) {
                if (cfg_music == 2) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 0;
                    updatePart(part, cfg_music, 1);
                }
                if (cfg_music == 3) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 1;
                    updatePart(part, cfg_music, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_DOWN)) {
            if (part == 2) {
                if (cfg_music == 0) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 2;
                    updatePart(part, cfg_music, 1);
                }
                if (cfg_music == 1) {
                    updatePart(part, cfg_music, 0);
                    cfg_music = 3;
                    updatePart(part, cfg_music, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_A) == 1) {
            if (part == 1) {
                part = 2;
            } else {
                retour = SC_LEVEL;     // main game
            }
        }

        if (pkk_key_pressed_withWait(KEY_SELECT)) {      // Escape
            return SC_INTRO;       // VERIFIY: accept to ESCAPE the game ????
        }

    }

    while (pkk_AnyKeyPressed()) {

    }


    return (char)retour;

}     /* intro */


// levelScene & levelSceneScore


u16 highscore[2][10][3];
u8 highscoreName[2][10][3][6];

void updateHigh(u8 high, u8 state)
{
    u8 posx, posy;
    u8 str[2];

    str[1] = 0;
    if (high < 3) {
        posx = high * 4 + (104 / 4);
        posy = 48;
    } else {
        posx = (high - 3) * 4 + (104 / 4);
        posy = 64;
    }

    str[0] = '0' + high;

    k_PrintGphStr8x8(str, posx, posy, state);
}

void updateHighScoreName(u8 x, u8 y, u8 state)
{
    u8 posx, posy;
    u8 str[2];

    posx = 32 / 4 + x * 2;
    posy = 104 + (y * 8);

    if (state == 0) {
        str[0] = ' ';
    } else {
        str[0] = highscoreName[cfg_game][cfg_level][y][x];
    }
    str[1] = 0;

    k_PrintGphStr8x8(str, posx, posy, 1);
}

void updateLevel(u8 level, u8 state, u8 withScore)
{
    u8 posx, posy;
    u8 str[2], i;

    str[1] = 0;
    if (level < 5) {
        posx = level * 4 + ((cfg_game == 0) ? 10 : 4);
        posy = 48;
    } else {
        posx = (level - 5) * 4 + ((cfg_game == 0) ? 10 : 4);
        posy = 64;
    }

    str[0] = '0' + level;

    k_PrintGphStr8x8(str, posx, posy, state);


    if (withScore) {
        for (i = 0; i < 3; i++) {
            pkk_lcd_waitVSYNC();

            if (highscore[cfg_game][level][i] != 0) {
                u8 j;
                char str[7];
                str[6] = 0;
                for (j = 0; j < 6; j++) {
                    str[j] = highscoreName[cfg_game][level][i][j];
                }
                k_PrintGphStr8x8("llllll", 32 / 4, 104 + i * 8, 1);
                k_PrintGphStr8x8(str, 32 / 4, 104 + i * 8, 1);
                drawInteger(96 / 4, 104 + i * 8, highscore[cfg_game][level][i], 6, 'l');
            } else {
                k_PrintGphStr8x8("llllll", 32 / 4, 104 + i * 8, 1);
                k_PrintGphStr8x8("llllll", 96 / 4, 104 + i * 8, 1);
            }
        }
    }


} /* updateLevel */

void loadHighScore(void)
{
    u8 x, y, i;

    for (x = 0; x < 2; x++) {
        for (y = 0; y < 10; y++) {
            for (i = 0; i < 3; i++) {
                highscoreName[x][y][i][0] = y + '0';
                highscoreName[x][y][i][1] = 0;
                highscore[x][y][i] = (y + 1) * (i + 1);

                if (y == 3) {
                    highscoreName[x][y][i][0] = 'R';
                    highscoreName[x][y][i][1] = 'E';
                    highscoreName[x][y][i][2] = 'D';
                    highscoreName[x][y][i][3] = 0;
                }
            }
        }
    }
}

char levelScene(void)
{
    u16 frame = 0;
    u8 highScorePlaceX = 0;
    u8 highScorePlaceY = 0;

    GAME_SCENE retour = SC_LEVEL;

    updateMusic(cfg_music, 1);


    if (cfg_game == 0) {
        pkk_displayGIF((unsigned char *)&G_levelA_scr, G_levelA_scr_length);
    } else {
        pkk_displayGIF((unsigned char *)&G_levelB_scr, G_levelB_scr_length);
    }
    displayFooter();

// . -> <

    if (cfg_level != 0) {
        updateLevel(0, 0, 1);
    }
    updateLevel(cfg_level, 1, 1);


    if (cfg_game == 1) {
        if (cfg_high != 0) {
            updateHigh(0, 0);
            updateHigh(cfg_high, 1);
        }
    }

    frame = 0;

    u8 partLevel = 0;

    u8 off = 0;


    while (retour == SC_LEVEL) {                // Repeat until ESC pressed - Small scrolling effect

        pkk_lcd_waitVSYNC();

        frame++;

        if (frame == 5) {
            frame = 0;

            if (off) {
                off = 0;
            } else {
                off = 1;
            }


            if (partLevel == 0) {
                updateLevel(cfg_level, off, 0);
            } else {
                updateHigh(cfg_high, off);
            }

        }



        // Keyboard







        if (pkk_key_pressed_withWait(KEY_LEFT)) {
            if (partLevel == 0) {
                if (cfg_level != 0) {
                    updateLevel(cfg_level, 0, 0);
                    cfg_level--;
                    updateLevel(cfg_level, 1, 1);
                }
            } else {
                if (cfg_high != 0) {
                    updateHigh(cfg_high, 0);
                    cfg_high--;
                    updateHigh(cfg_high, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_RIGHT)) {
            if (partLevel == 0) {
                if (cfg_level != 9) {
                    updateLevel(cfg_level, 0, 0);
                    cfg_level++;
                    updateLevel(cfg_level, 1, 1);
                }
            } else {
                if (cfg_high != 5) {
                    updateHigh(cfg_high, 0);
                    cfg_high++;
                    updateHigh(cfg_high, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_UP)) {
            if (partLevel == 0) {
                if (cfg_level >= 5) {
                    updateLevel(cfg_level, 0, 0);
                    cfg_level -= 5;
                    updateLevel(cfg_level, 1, 1);
                }
            } else {
                if (cfg_high >= 3) {
                    updateHigh(cfg_high, 0);
                    cfg_high -= 3;
                    updateHigh(cfg_high, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_DOWN)) {
            if (partLevel == 0) {
                if (cfg_level < 5) {
                    updateLevel(cfg_level, 0, 0);
                    cfg_level += 5;
                    updateLevel(cfg_level, 1, 1);
                }
            } else {
                if (cfg_high < 3) {
                    updateHigh(cfg_high, 0);
                    cfg_high += 3;
                    updateHigh(cfg_high, 1);
                }
            }
        }

        if (pkk_key_pressed_withWait(KEY_A) == 1) {
            if ((cfg_game == 0) || ((cfg_game == 1) && (partLevel == 1))) {
                retour = SC_GAME;
            } else {
                partLevel++;
            }
        }

        if (pkk_key_pressed_withWait(KEY_SELECT)) {      // Escape
            if (partLevel == 1) {
                partLevel = 0;
            } else {
                return SC_GAMETYPE;     // VERIFIY: accept to ESCAPE the game ????
            }
        }

    }

    while (pkk_AnyKeyPressed()) {

    }


    return (char)retour;

}     /* intro */

void kmemcpy(int dest, int src)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        highscoreName[cfg_game][cfg_level][dest][i] = highscoreName[cfg_game][cfg_level][src][i];
    }
    highscore[cfg_game][cfg_level][dest] = highscore[cfg_game][cfg_level][src];

}

char levelSceneScore(void)
{
    u16 frame = 0;
    u8 highScorePlaceX = 0;
    u8 highScorePlaceY = 0;
    u8 i;

    GAME_SCENE retour = SC_SCORE;

    // _TETRISSCORE_START
    updateMusic(5, 0);

    if (score > highscore[cfg_game][cfg_level][0]) {
        kmemcpy(2, 1);
        kmemcpy(1, 0);
        highScorePlaceY = 0;
    } else if (score > highscore[cfg_game][cfg_level][1]) {
        kmemcpy(2, 1);
        highScorePlaceY = 1;
    } else if (score > highscore[cfg_game][cfg_level][2]) {
        highScorePlaceY = 2;
    } else {
        return (char)SC_LEVEL;
    }

    for (i = 0; i < 6; i++) {
        highscoreName[cfg_game][cfg_level][highScorePlaceY][i] = 0;
    }

    highScorePlaceX = 0;

    highscoreName[cfg_game][cfg_level][highScorePlaceY][0] = 'A';
    highscore[cfg_game][cfg_level][highScorePlaceY] = score;

    k_PrintGphStr8x8WithPad("", 32 / 4, 104 + highScorePlaceY * 8, 1, 6, 'l');


    if (cfg_game == 0) {
        pkk_displayGIF((unsigned char *)&G_levelA_scr, G_levelA_scr_length);
    } else {
        pkk_displayGIF((unsigned char *)&G_levelB_scr, G_levelB_scr_length);
    }
    displayFooter();

// . -> <

    if (cfg_level != 0) {
        updateLevel(0, 0, 1);
    }
    updateLevel(cfg_level, 1, 1);


    if (cfg_game == 1) {
        if (cfg_high != 0) {
            updateHigh(0, 0);
            updateHigh(cfg_high, 1);
        }
    }

    frame = 0;

    u8 partLevel = 0;

    u8 off = 0;


    while (retour == SC_SCORE) {                // Repeat until ESC pressed - Small scrolling effect

        pkk_lcd_waitVSYNC();

        frame++;

        if (frame == 5) {
            frame = 0;

            if (off) {
                off = 0;
            } else {
                off = 1;
            }

            updateHighScoreName(highScorePlaceX, highScorePlaceY, off);
        }



        // Keyboard




        if (pkk_key_pressed_withWait(KEY_UP)) {
            if (highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX] != 'A') {
                highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX]--;
            } else {
                highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX] = '\\';
            }
        }

        if (pkk_key_pressed_withWait(KEY_DOWN)) {
            if (highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX] != '\\') {
                highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX]++;
            } else {
                highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX] = 'A';
            }
        }

        if (pkk_key_pressed_withWait(KEY_A) == 1) {
            if (highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX] == '\\') {
                highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX] = 0;
                retour = SC_LEVEL;
            } else {
                updateHighScoreName(highScorePlaceX, highScorePlaceY, 1);
                highScorePlaceX++;
                if (highScorePlaceX == 6) {
                    retour = SC_LEVEL;
                }
                highscoreName[cfg_game][cfg_level][highScorePlaceY][highScorePlaceX] = 'A';
            }
        }


    }

    while (pkk_AnyKeyPressed()) {

    }


    return (char)retour;

}     /* intro */



// mainGame


// Field is 10x22 (+ 2 for the column)

#define FIELD_WIDTH  10
#define FIELD_HEIGHT 19
#define NBPLAYER     1

#define FIELD_HEADER 1

void getNext(void);

void updateScoreValue(void);
void updateLevelValue(void);
void updateLinesValue(void);


char Field[NBPLAYER][FIELD_HEIGHT][FIELD_WIDTH];
u8 cur_shape[NBPLAYER], cur_y[NBPLAYER], cur_rot[NBPLAYER], cur_pas[NBPLAYER];
s8 cur_x[NBPLAYER]; // could by negative

// Config
u8 cfg_game;
u8 cfg_music;
u8 cfg_level;
u8 cfg_high;

u8 waitrelrotate[NBPLAYER];
u8 waitrelrotateB[NBPLAYER];
u8 framearrow[NBPLAYER];

u8 next;
u8 waitDown;                                                                                                                            // Wait the down key is UP before accepting next down

u8 dropLine;

u8 frame;

u8 inGame;

u32 score;
u8 level;
u8 lines;

u16 scoreB4, scoreB3, scoreB2, scoreB1, scoreBD;

const u8 speedLevel[21] = {53, 49, 45,   41,  37,   33,  28,   22,   17,   11,   10,   9,   8,   7,   6,   6,   5,   5,   4,   4,   3}; // as described in https://tetris.fandom.com/wiki/Tetris_(Game_Boy)

const u8 shapes[7 * 4 * 4 * 4 + 1] =
    ".....D.......D.." \
    "ABBC.E..ABBC.E.." \
    ".....E.......E.." \
    ".....F.......F.." \

    "................" \
    ".GG..GG..GG..GG." \
    ".GG..GG..GG..GG." \
    "................" \

    ".....H..H....HH." \
    "HHH..H..HHH..H.." \
    "..H.HH.......H.." \
    "................"  \

    "....II....I..I.." \
    "III..I..III..I.." \
    "I....I.......II." \
    "................"  \

    ".....J.......J.." \
    "JJ..JJ..JJ..JJ.." \
    ".JJ.J....JJ.J..." \
    "................"  \

    "....K.......K..." \
    ".KK.KK...KK.KK.." \
    "KK...K..KK...K.." \
    "................"  \

    ".....L...L...L.." \
    "LLL.LL..LLL..LL." \
    ".L...L.......L.." \
    "................";


// y: multiple de 8









#define ORIGX1 8
#define ORIGX2 68

void DrawPiece(u8 myhandle, s8 cur_x0, u8 cur_y0, u8 cur_shape0, u8 cur_rot0, u8 disp)
{
    u8 y;
    s8 x;
    u8 sel;

    u8 origx = myhandle * 32;       // Just to avoid warning of myhandle ;)

    for (y = 0; y < 4; y++) {
        if (cur_y0 + y >= FIELD_HEADER) {
            for (x = 0; x < 4; x++) {
                u8 posX = 4 + (cur_x0 + x) * 2;
                u8 posY = (cur_y0 + y - FIELD_HEADER) * 8;

                u16 pos = (u16)(cur_shape0 - 1) * 4 * 4 * 4 + (u16)cur_rot0 * 4 + (u16)x + (u16)y * 4 * 4;

                sel = shapes[pos];

                if (sel != '.') {
                    if (disp) {
                        pkk_PutTile2x8(G_tetramino + (sel - 'A') * 16, posX, posY);
                    } else {
                        pkk_PutTile2x8(G_tetramino + ('M' - 'A') * 16, posX, posY);
                    }
                }
            }
        }
    }


} /* DrawPiece */

void drawLineLost(u8 y, u8 piece)
{
    u8 x;

    if (y >= FIELD_HEADER) {

        for (x = 0; x < FIELD_WIDTH; x++) {
            u8 posX = 4 + x * 2;
            u8 posY = (y - FIELD_HEADER) * 8;

            pkk_PutTile2x8(G_tetramino + piece * 16, posX, posY);
        }
    }
}

void redrawLine(u8 y)
{
    u8 x;

    if (y >= FIELD_HEADER) {

        for (x = 0; x < FIELD_WIDTH; x++) {
            u8 posX = 4 + x * 2;
            u8 posY = (y - FIELD_HEADER) * 8;

            u8 piece = Field[0][y][x];

            pkk_PutTile2x8(G_tetramino + (piece - 'A') * 16, posX, posY);
        }
    }
}


void redraw(u8 i)
{
    u8 x, y;

    u8 origx = (i == 0) ? ORIGX1 : ORIGX2;

    for (y = 0; y < FIELD_HEIGHT; y++) {
        if ( y >= FIELD_HEADER) {

            u8 posY =  (y - FIELD_HEADER) * 8;

            for (x = 0; x < FIELD_WIDTH; x++) {
                u8 posX = 4 + x * 2;

                u8 piece = Field[i][y][x];

                if (piece != 0) {
                    pkk_PutTile2x8(G_tetramino + (piece - 'A') * 16, posX, posY);
                } else {
                    pkk_PutTile2x8(G_tetramino + ('M' - 'A') * 16, posX, posY);
                }


            }
        }
    }

} /* redraw */



int TestMove(u8 myhandle, u8 shape0, s8 x0, u8 y0, u8 rot)
{
    u8 y;
    s8 x;

    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            u8 sel = shapes[((shape0 - 1) * 4 * 4 * 4) + (rot * 4) + x + (y * 4 * 4)];

            if (sel != '.') {
                if ( (x  + x0 < 0) |
                     (x  + x0 >= FIELD_WIDTH) |
                     (y  + y0 < 0) |
                     (y  + y0 >= FIELD_HEIGHT) ) {
                    return 0;
                }

                if (Field[myhandle][y  + y0][x  + x0] != 0) {
                    return 0;
                }
            }
        }
    }

    return 1;

} /* TestMove */


u8 myRandMax(u8 max, u8 mask)
{
    u8 value;

    do {
        value = rand() & mask;
    }   while (value >= max);

    return value;
}


void checkFullLine(u8 myhandle)
{
    u8 x, y;
    u8 erase[FIELD_HEIGHT];

    for (x = 0; x < FIELD_HEIGHT; x++) {
        erase[x] = 0;
    }

    u8 nbline = 0;

    for (y = 0; y < FIELD_HEIGHT; y++) {
        u8 fullline = 0;
        for (x = 0; x < FIELD_WIDTH; x++) {
            u8 sel = Field[myhandle][y][x];

            if (sel != 0)
                fullline++;
        }
        if (fullline == FIELD_WIDTH) {
            erase[y] = 1;

            // int add_action;

            nbline++;
        }
    }

    // Attribution des bonus

    if (cfg_game == 0) {
        if (nbline == 1) {
            score += 40 * (level + 1);
        } else if (nbline == 2) {
            score += 100 * (level + 1);
        } else if (nbline == 3) {
            score += 300 * (level + 1);
        } else if (nbline == 4) {
            score += 1200 * (level + 1);
        }
        updateScoreValue();
    } else {
        if (nbline == 1) {
            scoreB1++;
        } else if (nbline == 2) {
            scoreB2++;
        } else if (nbline == 3) {
            scoreB3++;
        } else if (nbline == 4) {
            scoreB4++;
        }
    }

    if (nbline != 0) {      // Changement de lignes
        u8 n, m;

        for (n = 0; n < nbline; n++) {

            if (cfg_game == 0) {      // check if level up
                lines++;

                m = 0;
                if (lines == 10) {
                    m = 1;
                } else if (lines == 20) {
                    m = 2;
                } else if (lines == 30) {
                    m = 3;
                } else if (lines == 40) {
                    m = 4;
                } else if (lines == 50) {
                    m = 5;
                } else if (lines == 60) {
                    m = 6;
                } else if (lines == 70) {
                    m = 7;
                } else if (lines == 80) {
                    m = 8;
                } else if (lines == 90) {
                    m = 9;
                } else if (lines == 100) {
                    m = 10;
                } else if (lines == 110) {
                    m = 11;
                } else if (lines == 120) {
                    m = 12;
                } else if (lines == 130) {
                    m = 13;
                } else if (lines == 140) {
                    m = 14;
                } else if (lines == 150) {
                    m = 15;
                } else if (lines == 160) {
                    m = 16;
                } else if (lines == 170) {
                    m = 17;
                } else if (lines == 180) {
                    m = 19;
                } else if (lines == 190) {
                    m = 19;
                } else if (lines == 200) {
                    m = 20;
                }
                if (m > level) {
                    level = m;
                    updateLevelValue();
                }
            } else {
                lines--;
                if (lines == 0) {
                    updateLinesValue();


                    y = FIELD_HEIGHT;
                    do {
                        y--;

                        u8 n;

                        for (n = 0; n < 3; n++) {
                            pkk_lcd_waitVSYNC();
                            drawLineLost(y, ('N' - 'A'));
                        }


                    } while (y != 0);


                    y = FIELD_HEIGHT;
                    do {
                        y--;

                        pkk_lcd_waitVSYNC();
                        drawLineLost(y, ('M' - 'A'));


                    } while (y != 0);

                    u16 bonus;

                    score = 0;

                    bonus =  40 * ((u16)level + 1);
                    k_PrintGphStr8x8("SINGLE", 16 / 4, 0, 1);
                    k_PrintGphStr8x8("   *", 16 / 4, 8, 1);
                    drawInteger(16 / 4, 8, scoreB1, 2, ' ');
                    drawInteger(56 / 4, 8, bonus, 0, ' ');
                    drawInteger(24 / 4, 16, (u16)scoreB1 * bonus, 8, ' ');
                    score += (u16)scoreB1 * bonus;

                    bonus = 100 * ((u16)level + 1);
                    k_PrintGphStr8x8("DOUBLE", 16 / 4, 24, 1);  // aaa
                    k_PrintGphStr8x8("   *", 16 / 4, 32, 1);
                    drawInteger(16 / 4, 32, scoreB2, 2, ' ');
                    drawInteger(56 / 4, 32, bonus, 0, ' ');
                    drawInteger(24 / 4, 40, (u16)scoreB2 * bonus, 8, ' ');
                    score += (u16)scoreB2 * bonus;

                    bonus = 300 * ((u16)level + 1);
                    k_PrintGphStr8x8("TRIPLE", 16 / 4, 48, 1);
                    k_PrintGphStr8x8("   *", 16 / 4, 56, 1);
                    drawInteger(16 / 4, 56, scoreB3, 2, ' ');
                    drawInteger(56 / 4, 56, bonus, 0, ' ');
                    drawInteger(24 / 4, 64, (u16)scoreB3 * bonus, 8, ' ');
                    score += (u16)scoreB3 * bonus;

                    bonus = 1200 * ((u16)level + 1);
                    k_PrintGphStr8x8("TETRIS", 16 / 4, 72, 1);
                    k_PrintGphStr8x8("   *", 16 / 4, 80, 1);
                    drawInteger(16 / 4, 80, scoreB4, 2, ' ');
                    drawInteger(56 / 4, 80, bonus, 0, ' ');
                    drawInteger(24 / 4, 88, (u16)scoreB4 * bonus, 8, ' ');
                    score += (u16)scoreB4 * bonus;

                    k_PrintGphStr8x8("DROPS", 16 / 4, 96, 1);
                    drawInteger(32 / 4, 104, scoreBD, 7, ' ');
                    score += scoreBD;

                    k_PrintGphStr8x8("aaaaaaaaaa", 16 / 4, 112, 1);
                    k_PrintGphStr8x8("THIS STAGE", 16 / 4, 128, 1);
                    drawInteger(32 / 4, 136, score, 7, ' ');

                    while (pkk_AnyKeyPressed()) {

                    }

                    while (inGame == 1) {
                        pkk_lcd_waitVSYNC();

                        if (pkk_key_pressed(KEY_A) == 1) {
                            inGame = 0;
                        }

                    }


                }
            }
        }

        updateLinesValue();


        PlaySfx(4);

        for (n = 0; n < 5; n++) {

            for (y = 0; y < FIELD_HEIGHT; y++) {
                if (erase[y] == 1) {
                    drawLineLost(y, ('M' - 'A'));
                }
            }

            for (m = 0; m < 2; m++) {
                pkk_lcd_waitVSYNC();
                updateScoreValue(); // Just to wait
            }

            for (y = 0; y < FIELD_HEIGHT; y++) {
                if (erase[y] == 1) {
                    redrawLine(y);
                }
            }

            for (m = 0; m < 2; m++) {
                pkk_lcd_waitVSYNC();
                updateScoreValue(); // Just to wait
            }

        }

        PlaySfx(0);


        for (y = 0; y < FIELD_HEIGHT; y++) {

            if (erase[y] == 1) {

                // for (x = 0; x < FIELD_WIDTH; x++) {
                //     if (Field[myhandle][y][x] > 7) {
                //         add_action = -1;
                //         for (y0 = 0; y0 < MAXACTION; y0++) {
                //             if (action[y0] == 0) {
                //                 add_action = y0;
                //                 break;
                //             }
                //         }
                //         if (add_action != -1) {
                //             char *action_tile = "cansrbgqo";
                //             action[add_action] = action_tile[Field[myhandle][y][x] - 8];
                //         }
                //     }
                // }

                // do {
                //     x = (int)((10 * rand()) / RAND_MAX);
                // } while (bonus_still[x] != 0);
                // bonus_still[x] = 200;
                // bonus_score[x] = 50 * nbline;
                // score += bonus_score[x];
                // bonus_place[x] = y * SIZE_Y + BEGINY;

                u8 y0;
                for (y0 = y; y0 > 0; y0--) {
                    for (x = 0; x < FIELD_WIDTH; x++) {
                        Field[myhandle][y0][x] = Field[myhandle][y0 - 1][x];
                    }
                }                 // End For

            }
        }


        redraw(myhandle);

        //     nbbrick = 0;
        //     for (y = 0; y < FIELD_HEIGHT; y++) {
        //         for (x = 0; x < FIELD_WIDTH; x++) {
        //             sel = Field[myhandle][y][x];

        //             if ((sel > 0) & (sel <= 7))
        //                 nbbrick++;
        //         }
        //     }
        //     for (y = 0; y < FIELD_HEIGHT; y++) {
        //         for (x = 0; x < FIELD_WIDTH; x++) {
        //             int r;

        //             sel = Field[myhandle][y][x];

        //             r = (int)((nbbrick * rand()) / RAND_MAX);

        //             if (((sel > 0) & (sel <= 7)) & (r < nbline))
        //                 Field[myhandle][y][x] = (char)((9 * rand()) / RAND_MAX) + 8;
        //         }
        //     }
    }


}     /* checkNewline */

void dropPiece(void)
{
    u8 speedLevel0;

    if (cfg_game == 0) {
        speedLevel0 = speedLevel[level];
    } else {
        speedLevel0 = speedLevel[level * 2];
    }

    frame++;
    if (frame >= speedLevel0) {
        u8 myhandle;
        for (myhandle = 0; myhandle < NBPLAYER; myhandle++) {

            if (TestMove(myhandle, cur_shape[myhandle], cur_x[myhandle], cur_y[myhandle] + 1, cur_rot[myhandle])) {
                DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 0);
                cur_y[myhandle]++;
                DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 1);
            } else {

                PlaySfx(3);

                u8 x, y;

                for (x = 0; x < 4; x++) {
                    for (y = 0; y < 4; y++) {
                        u8 sel = shapes[(cur_shape[myhandle] - 1) * 4 * 4 * 4 + cur_rot[myhandle] * 4 + x + y * 4 * 4];

                        if (sel != '.') {
                            Field[myhandle][y + cur_y[myhandle]][x + cur_x[myhandle]] = sel;     // (u8)cur_shape[myhandle];
                        }
                    }
                }

                checkFullLine(myhandle);
                if (!inGame) {
                    return;
                }

                if (cfg_game == 0) {
                    score += dropLine;
                    updateScoreValue();
                } else {
                    scoreBD += dropLine;
                }

                cur_shape[0] = next;     // De 1 a 7
                getNext();

                cur_x[myhandle] = 4;
                cur_y[myhandle] = 0;
                cur_rot[myhandle] = 0;

                if (TestMove(myhandle, cur_shape[myhandle], cur_x[myhandle], cur_y[myhandle], cur_rot[myhandle]) == 0) {

                    // _TETRISGAMEOVER_START
                    updateMusic(6, 0);

                    y = FIELD_HEIGHT;
                    do {
                        y--;

                        u8 n;

                        for (n = 0; n < 3; n++) {
                            pkk_lcd_waitVSYNC();
                            drawLineLost(y, ('N' - 'A'));
                        }


                    } while (y != 0);


                    y = FIELD_HEIGHT;
                    do {
                        y--;

                        pkk_lcd_waitVSYNC();
                        drawLineLost(y, ('M' - 'A'));


                    } while (y != 0);

                    k_PrintGphStr8x8("bccccccd", 24 / 4, 16, 1);
                    k_PrintGphStr8x8("j      e", 24 / 4, 24, 1);
                    k_PrintGphStr8x8("j GAME e", 24 / 4, 32, 1);
                    k_PrintGphStr8x8("j iiii e", 24 / 4, 40, 1);
                    k_PrintGphStr8x8("j OVER e", 24 / 4, 48, 1);
                    k_PrintGphStr8x8("j iiii e", 24 / 4, 56, 1);
                    k_PrintGphStr8x8("gkkkkkkf", 24 / 4, 64, 1);

                    k_PrintGphStr8x8("PLEASE", 24 / 4, 96, 1);
                    k_PrintGphStr8x8("aaaaaa", 24 / 4, 104, 1);
                    k_PrintGphStr8x8("TRY", 32 / 4, 112, 1);
                    k_PrintGphStr8x8("aaa", 32 / 4, 120, 1);
                    k_PrintGphStr8x8("AGAINh", 40 / 4, 128, 1);
                    k_PrintGphStr8x8("aaaaa", 40 / 4, 136, 1);

                    while (pkk_AnyKeyPressed()) {

                    }

                    while (inGame == 1) {
                        pkk_lcd_waitVSYNC();

                        if (pkk_key_pressed(KEY_A) == 1) {
                            inGame = 0;

                            return;
                        }

                    }


                    // for (y = 0; y < 5; y++) {
                    //     k_PrintGphStr8x8("j      e", 24 / 4, 24 + y * 8, 1);
                    // } // 24 to 56


                }

                DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 1);

            }
        }

        frame = 0;

    }
}     /* dropPiece */

void updateScoreValue(void)
{
    if (cfg_game == 0) {
        drawInteger32(104 / 4, 24, score, 6, ' ');
    }
}

void updateHighValue(void)
{
    drawInteger(112 / 4, 40, cfg_high, 4, ' ');
}

void updateLevelValue(void)
{
    if (cfg_game == 0) {
        drawInteger(112 / 4, 56, level, 4, ' ');
    } else {
        drawInteger(112 / 4, 16, level, 4, ' ');
    }
}

void updateLinesValue(void)
{
    drawInteger(112 / 4, 80, lines, 4, ' ');
}


void getNext(void)
{
    next = myRandMax(7, 7) + 1;

    u8 y;
    s8 x;

    u8 sel;
    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            u8 posX = (120 / 4) + x * 2;
            u8 posY = 104 + y * 8;

            u16 pos = (u16)(next - 1) * 4 * 4 * 4 + (u16)x + (u16)y * 4 * 4;

            sel = shapes[pos];

            if (sel != '.') {
                pkk_PutTile2x8(G_tetramino + (sel - 'A') * 16, posX, posY);
            } else {

                pkk_PutTile2x8(G_tetramino + ('M' - 'A') * 16, posX, posY);
            }
        }
    }

    waitDown = 1;
}     /* getNext */


char mainGame(void)
{

    if (cfg_game == 0) {
        pkk_displayGIF((unsigned char *)&G_gameA_scr, G_gameA_scr_length);
    } else {
        pkk_displayGIF((unsigned char *)&G_gameB_scr, G_gameB_scr_length);
    }
    displayFooter();

// w: 10, h: 16

// 10x22
// 192x256 -> 96 -> 8 * 10 + 16


    u16 x, y;
    u8 i;

    for (i = 0; i < NBPLAYER; i++) {
        for (x = 0; x < FIELD_WIDTH; x++) {
            for (y = 0; y < FIELD_HEIGHT; y++) {
                Field[i][y][x] = 0;
            }
        }
    }


    if (cfg_high != 0) {

        u8 i;

        for (i = 0; i < cfg_high * 2; i++) {
            u8 x, y;

            for (y = 1; y < FIELD_HEIGHT; y++) {
                for (x = 0; x < FIELD_WIDTH; x++) {
                    Field[0][y - 1][x] = Field[0][y][x];
                }
            }
            for (x = 0; x < FIELD_WIDTH; x++) {
                u8 r;

                r = rand() & 3;
                if (r != 0) {
                    u8 shape = rand() & 7;
                    Field[0][FIELD_HEIGHT - 1][x] = (char)shape + 'E';
                }
            }

            // Add a space to avoid a full line

            u8 r = myRandMax(FIELD_WIDTH, 15);
            Field[0][FIELD_HEIGHT - 1][r] = 0;

        }
        redraw(0);

    }


    getNext();
    cur_shape[0] = next;             // De 1 a 7
    getNext();

    cur_x[0] = 4;
    cur_y[0] = 0;
    cur_rot[0] = 0;
    cur_pas[0] = 0;

    waitrelrotate[0] = 0;
    waitrelrotateB[0] = 0;

    framearrow[0] = 0;

    score = 0;
    scoreB4 = 0;
    scoreB3 = 0;
    scoreB2 = 0;
    scoreB1 = 0;
    scoreBD = 0;

    level = cfg_level;

    if (cfg_game == 0) {
        lines = 0;
    } else {
        lines =  25;
    }

    frame = 0;

    DrawPiece(0, cur_x[0], cur_y[0], cur_shape[0], cur_rot[0], 1);

    inGame = 1;

    updateLevelValue();
    updateLinesValue();

    if (cfg_game == 0) {
        updateScoreValue();
    } else {
        updateHighValue();
    }

    while (inGame) {               // Repeat until ESC pressed
        pkk_lcd_waitVSYNC();

        dropPiece();

        if (!inGame) {
            break;
        }

        // Scans whole keyboard

        if (pkk_key_pressed_withWait(KEY_SELECT)) { // pause
            u8 y;

            y = FIELD_HEIGHT;
            do {
                y--;

                drawLineLost(y, ('M' - 'A'));
            } while (y != 0);

            u8 a = 3;

            k_PrintGphStr8x8("HIT", (10 - 3) + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("aaa", (10 - 3) + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("FIRE1 TO", (10 - 8) + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("aaaaaaaa", (10 - 8) + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("CONTINUE", (10 - 8)  + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("aaaaaaaa", (10 - 8)  + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("OR FIRE2", (10 - 8)  + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("aaaaaaaa", (10 - 8)  + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("TO MENU", (10 - 7)  + 4, a * 8, 1); a++;
            k_PrintGphStr8x8("aaaaaaa", (10 - 7)  + 4, a * 8, 1); a++;

            while (pkk_AnyKeyPressed());

            while (1) {
                pkk_lcd_waitVSYNC();

                // Scans whole keyboard

                if (pkk_key_pressed(KEY_A)) {
                    break;
                }

                if (pkk_key_pressed(KEY_B)) {
                    while (pkk_AnyKeyPressed());

                    return (char)SC_INTRO;
                }
            }

            while (pkk_AnyKeyPressed());

            redraw(0);

            DrawPiece(0, cur_x[0], cur_y[0], cur_shape[0], cur_rot[0], 1);
        }


        u8 myhandle;
        for (myhandle = 0; myhandle < NBPLAYER; myhandle++) {
            if (pkk_key_pressed(KEY_A)) {    // Rotate clock
                if (waitrelrotate[myhandle] == 0) {
                    u8 nextRot = cur_rot[myhandle];
                    nextRot = ((cur_rot[myhandle]  + 1) & 3);

                    if (TestMove(myhandle, cur_shape[myhandle], cur_x[myhandle], cur_y[myhandle], nextRot)) {
                        PlaySfx(5);
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 0);
                        cur_rot[myhandle] = nextRot;
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 1);
                    }
                    waitrelrotate[myhandle] = 1;
                }
            } else {
                waitrelrotate[myhandle] = 0;
            }

            if (pkk_key_pressed(KEY_B)) {     // Up - Rotate
                if (waitrelrotateB[myhandle] == 0) {
                    u8 nextRot = cur_rot[myhandle];
                    nextRot = (nextRot == 0) ? 3 : (nextRot - 1);

                    if (TestMove(myhandle, cur_shape[myhandle], cur_x[myhandle], cur_y[myhandle], nextRot)) {
                        PlaySfx(5);
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 0);
                        cur_rot[myhandle] = nextRot;
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 1);
                    }
                    waitrelrotateB[myhandle] = 1;
                }
            } else {
                waitrelrotateB[myhandle] = 0;
            }



            if (pkk_key_pressed(KEY_RIGHT)) {
                if (framearrow[myhandle]  == 0) {
                    if (TestMove(myhandle, cur_shape[myhandle], cur_x[myhandle] + 1, cur_y[myhandle], cur_rot[myhandle])) {
                        PlaySfx(1);
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 0);
                        cur_x[myhandle]++;
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 1);
                    }
                    framearrow[myhandle] = 10;
                } else {
                    framearrow[myhandle]--;
                }
            } else if (pkk_key_pressed(KEY_LEFT)) {
                if (framearrow[myhandle]  == 0) {
                    if (TestMove(myhandle, cur_shape[myhandle], cur_x[myhandle] - 1, cur_y[myhandle], cur_rot[myhandle])) {
                        PlaySfx(1);
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 0);
                        cur_x[myhandle]--;
                        DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 1);
                    }
                    framearrow[myhandle] = 10;
                } else {
                    framearrow[myhandle]--;
                }
            } else if (pkk_key_pressed(KEY_DOWN)) {                // Down
                if (waitDown == 0) {
                    if (framearrow[myhandle]  == 0) {
                        if (TestMove(myhandle, cur_shape[myhandle], cur_x[myhandle], cur_y[myhandle] + 1, cur_rot[myhandle])) {
                            DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 0);
                            cur_y[myhandle]++;
                            DrawPiece(myhandle, cur_x[myhandle], cur_y[myhandle], cur_shape[myhandle], cur_rot[myhandle], 1);
                            dropLine++;
                        }
                        framearrow[myhandle] = 1;
                    } else {
                        framearrow[myhandle]--;
                    }
                }
            } else {
                framearrow[myhandle] = 0;
                waitDown = 0;
                dropLine = 0;
            }

        }




    }

    while (pkk_AnyKeyPressed()) {

    }


    return (char)SC_SCORE;


}     /* mainGame */


extern void draw_rect_spi(int x1, int y1, int x2, int y2, int c);

int main()
{
    extern uint32_t pwm_clock_khz;

    pwm_clock_khz = 125000;

    pkk_init();

// test

    if (1 == 0) {
        pkk_lcd_clear();

        // display pwm_clock_khz

        extern uint32_t pwm_clock_khz;

        char str[20];
        sprintf(str, "PWM %ld kHz\n", pwm_clock_khz);
        pkk_draw_text(0, 0, str, 0xFFFF, 0x0000);

        while (!pkk_key_pressed_withWait(KEY_SELECT)) {

        }
    }


    if (1 == 0) {
        pkk_lcd_clear();

        while (!pkk_key_pressed_withWait(KEY_SELECT)) {
            // trace un rectangle aleatoire dans la zone 0-319, 0-319 a l'aide de la fonction draw_rect_spi

            int x1 = rand() % 320;
            int y1 = rand() % 320;
            int x2 = rand() % 320;
            int y2 = rand() % 320;
            u16 color = rand() % 0xFFFF;

            draw_rect_spi(x1, y1, x2, y2, color);
        }

        pkk_lcd_clear();

        draw_rect_spi(0, 0, 319, 319, RGB565(128,  128,    128));

        while (!pkk_key_pressed_withWait(KEY_SELECT)) {
        }

        draw_rect_spi(0, 0, 319, 319, RGB565(255,  255,    255));

        while (!pkk_key_pressed_withWait(KEY_SELECT)) {
        }
    }

// end test

    pkk_lcd_clear();

    // pkk_loadSoundModule(mod_tetris_time, mod_tetris_time_length, 1);

    partGame = SC_INTRO;

    updateMusic(0, 1);

    credits();

    while (partGame != SC_END) {

        if (partGame == SC_INTRO) {
            partGame = intro();
        }

        if (partGame == SC_GAMETYPE) {
            partGame = gametype();
        }

        if (partGame == SC_LEVEL) {
            partGame = levelScene();
        }

        if (partGame == SC_SCORE) {
            partGame = levelSceneScore();
        }

        if (partGame == SC_GAME) {
            partGame = mainGame();
        }

        if (partGame == SC_END) {

        }

    }

    pkk_guru_meditation("End of game");

    pkk_reboot();


    // pkk_displayGIF((unsigned char *)&G_main_scr, G_main_scr_length);

    // sleep_ms(1000 * 30);

    // lcd_clear();

    // while (true) {

    //     // trace un rectangle aleatoire dans la zone 0-319, 0-319 a l'aide de la fonction draw_rect_spi

    //     int x1 = rand() % 320;
    //     int y1 = rand() % 320;
    //     int x2 = rand() % 320;
    //     int y2 = rand() % 320;
    //     int color = rand() % 0xFFFFFF;

    //     draw_rect_spi(x1, y1, x2, y2, color);

    //     // lcd_print_string("Hello World PicoCalc\n");
    //     // sleep_ms(1000);
    // }
} /* main */