#include <gba_console.h>
#include <gba_video.h>
#include <gba_sprites.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <maxmod.h>		// maxmod library
#include "soundbank.h"		// created by building project
#include "soundbank_bin.h"	// created by building project 

#define scorerollover 10
#define timerollover 0

#define offscreenx 254
#define offscreeny 115

#define playertitlescreeny 60
#define playertitlescreenx 100
#define shieldtitlescreenx 110

#define ground 112
#define enemyground 120

#define ceiling 30

#define playergameinitx 100
#define shieldgameinitx 120

#define SCROLL_DELAY_MAX 3
#define SCROLL2_DELAY_MAX 4