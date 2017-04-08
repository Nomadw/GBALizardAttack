#include "includes.h"

enum state{TITLE, PLAYING, PAUSE, GAME_OVER} state;

typedef struct{

	unsigned char init;
    unsigned char x;
	unsigned char y;
	unsigned char height;
	unsigned char width;
	unsigned char animation;
	unsigned char movespeed;
	unsigned char movedir;
	
}ENEMY;

typedef struct{

	unsigned char x;
	unsigned char y;
	unsigned char height;
	unsigned char width;
	unsigned char movespeed;
	unsigned char movedir;
	
}SHIELD;

typedef struct{

	unsigned char x;
	unsigned char y;
	unsigned char height;
	unsigned char width;
	unsigned char movespeed;
	unsigned char movedir;
	unsigned char animation;
	
}PLAYER;

PLAYER player;
SHIELD shield;
ENEMY enemy1;
ENEMY enemy2;
ENEMY enemy3;
ENEMY enemy4;


char score = 0;
char scoreten = 0;
char scorehundred = 0;

char msecond = 10;
char timer = 10;
char timerten = 10;
char timerhundred = 10;
char timerthousand = 2;

char hardmode = 0;
char menuoption = 1;
char musicmode = 1;

char GSTATE = TITLE;

char BG1horizontaloffset = 0;
char BG2horizontaloffset = 0;
char BG3verticaloffset = 0;
char BG3horizontaloffset = 0;

char scrolldelay = SCROLL_DELAY_MAX;
char BG2scrolldelay = SCROLL2_DELAY_MAX;