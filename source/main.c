#include "includes.h"
#include "globals.h"
#include "gamestructs.h"

//---------------------------------------------------------------------------------
int main(void) 
{
//---------------------------------------------------------------------------------
	
	//initial values for player - not listed = 0
	player.x = playertitlescreenx;
	player.y = playertitlescreeny;
	player.height = 6;
	player.width = 3;
	player.movespeed = 1;
	
	//initial values for shield - not listed = 0
	shield.x = shieldtitlescreenx;
	shield.y = playertitlescreeny;
	shield.height = 6;
	shield.width = 3;
	shield.movespeed = 1;
	
	//initial values for enemy 1 - not listed = 0
	enemy1.x = offscreenx;
	enemy1.y = offscreeny;
	enemy1.height = 3;
	enemy1.width = 6;
	enemy1.movedir = 2;
	enemy1.init = 0;

	
	//initial values for enemy 2 - not listed = 0
	enemy2.x = offscreenx;
	enemy2.y = offscreeny;
	enemy2.height = 3;
	enemy2.width = 6;
	enemy2.movedir = 1;
	enemy2.init = 0;
	
	//initial values for enemy 3 - not listed = 0 - copying enemy 1 values as same initialisation
	enemy3.x = enemy1.x;
	enemy3.y = enemy1.y;
	enemy3.height = enemy1.x;
	enemy3.width = enemy1.width;
	enemy3.movedir = enemy1.movedir;
	enemy3.init = 0;
	
	//initial values for enemy 4 - not listed = 0 - copying enemy 2 values as same initialisation
	enemy4.x = enemy2.x;
	enemy4.y = enemy2.y;
	enemy4.height = enemy2.x;
	enemy4.width = enemy2.width;
	enemy4.movedir = enemy2.movedir;
	enemy4.init = 0;
	
	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	irqInit();
	irqEnable(IRQ_VBLANK);
	
	unsigned short* DISPCNT = (unsigned short*) 0x04000000;
		DISPCNT[0] = (1 << 12) | (1 << 11) | (1 << 10) | (1 << 9) | (1 << 8) | (1 << 6) | (0 << 2) | (0 << 1) | (0 << 0);
	
	// BG Controllers
	//unsigned short* BG0CNT = (unsigned short*) 0x04000008;
		BGCTRL[0] = (0 << 0) | (0 << 2) | (0 << 7) | (11 << 8) | (0 << 14);

	//unsigned short* BG1CNT = (unsigned short*) 0x0400000A;
		BGCTRL[1] = (1 << 0) | (0 << 2) | (0 << 7) | (10 << 8) | (0 << 14);

	//unsigned short* BG2CNT = (unsigned short*) 0x0400000C;
		BGCTRL[2] = (2 << 0) | (0 << 2) | (0 << 7) | (9 << 8) | (0 << 14);

	//unsigned short* BG3CNT = (unsigned short*) 0x0400000E;
		BGCTRL[3] = (3 << 0) | (0 << 2) | (0 << 7) | (8 << 8) | (0 << 14);
	
	//Loading in pallettes and characters
		BuildPalettes();
		BuildTiles();
		BuildSprites();
		
	//Loading in music and sounds	
	mmInitDefault( (mm_addr)soundbank_bin, 8 );
	
	unsigned short* TILEOFFSET = ((unsigned short *) (0x04000014)); //BG1 horizontal scrolling
		TILEOFFSET[0] = ((BG1horizontaloffset << 0));
		
	unsigned short* FGHOFFSET = ((unsigned short *) (0x04000018)); //BG2 horizontal scrolling
		FGHOFFSET[0] = ((BG2horizontaloffset << 0));
	
	unsigned short* BGHOFFSET = ((unsigned short *) (0x0400001c)); //BG3 horizontal scrolling
		BGHOFFSET[0] = ((BG3horizontaloffset << 0));
		
	unsigned short* BGVOFFSET = ((unsigned short *) (0x0400001e)); //BG3 vertical scrolling
		BGVOFFSET[0] = ((BG3verticaloffset << 0));
		
	unsigned short* playersprite = ((unsigned short *) (0x07000000)); //Player OBJ
		playersprite[0] = ((player.y << 0) | (0 << 8) | (2 << 14));
		playersprite[1] = ((player.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		playersprite[2] = ((1 << 0) | (0 << 10) | (0 << 12));
	
	unsigned short* shieldsprite = ((unsigned short *) (0x07000008)); //Shield OBJ
		shieldsprite[0] = ((shield.y << 0) | (0 << 8) | (2 << 14));
		shieldsprite[1] = ((shield.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		shieldsprite[2] = ((5 << 0) | (0 << 10) | (0 << 12));

	unsigned short* enemysprite = ((unsigned short *) (0x07000010)); //Enemy 1 OBJ
		enemysprite[0] = ((enemy1.y << 0) | (0 << 8) | (1 << 14));
		enemysprite[1] = ((enemy1.x << 0) | (0 << 9) | (1 << 12) | (0 << 13) | (0 << 14));
		enemysprite[2] = ((7 << 0) | (0 << 10) | (2 << 12));
		
	unsigned short* enemy2sprite = ((unsigned short *) (0x07000018)); //Enemy 2 OBJ
		enemy2sprite[0] = ((enemy2.y << 0) | (0 << 8) | (1 << 14));
		enemy2sprite[1] = ((enemy2.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		enemy2sprite[2] = ((7 << 0) | (0 << 10) | (2 << 12));
		
	unsigned short* enemy3sprite = ((unsigned short *) (0x07000020)); //Enemy 3 OBJ
		enemy3sprite[0] = ((enemy3.y << 0) | (0 << 8) | (1 << 14));
		enemy3sprite[1] = ((enemy3.x << 0) | (0 << 9) | (1 << 12) | (0 << 13) | (0 << 14));
		enemy3sprite[2] = ((7 << 0) | (0 << 10) | (3 << 12));
		
	unsigned short* enemy4sprite = ((unsigned short *) (0x07000028)); //Enemy 2 OBJ
		enemy4sprite[0] = ((enemy4.y << 0) | (0 << 8) | (1 << 14));
		enemy4sprite[1] = ((enemy4.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		enemy4sprite[2] = ((7 << 0) | (0 << 10) | (3 << 12));
		
		// main loop
	while (1) 
	{
		VBlankIntrWait(); //Wait before all of previous frame is drawn before continuing
		mmFrame(); //Next frame of sound
		ClearText(); //Clear text every frame

		//Redraw all sprites every frame
		playersprite[0] = ((player.y << 0) | (0 << 8) | (2 << 14));
		playersprite[1] = ((player.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		playersprite[2] = (((1 + (player.animation * 2)) << 0) | (0 << 10) | (0 << 12));
		
		shieldsprite[0] = ((shield.y << 0) | (0 << 8) | (2 << 14));
		shieldsprite[1] = ((shield.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		
		enemysprite[0] = ((enemy1.y << 0) | (0 << 8) | (1 << 14));
		enemysprite[1] = ((enemy1.x << 0) | (0 << 9) | (1 << 12) | (0 << 13) | (0 << 14));
		enemysprite[2] = (((7 + (enemy1.animation * 2)) << 0) | (0 << 10) | (2 << 12));
		
		enemy2sprite[0] = ((enemy2.y << 0) | (0 << 8) | (1 << 14));
		enemy2sprite[1] = ((enemy2.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		enemy2sprite[2] = (((7 + (enemy2.animation * 2)) << 0) | (0 << 10) | (2 << 12));
		
		enemy3sprite[0] = ((enemy3.y << 0) | (0 << 8) | (1 << 14));
		enemy3sprite[1] = ((enemy3.x << 0) | (0 << 9) | (1 << 12) | (0 << 13) | (0 << 14));
		enemy3sprite[2] = (((7 + (enemy3.animation * 2)) << 0) | (0 << 10) | (3 << 12));
		
		enemy4sprite[0] = ((enemy4.y << 0) | (0 << 8) | (1 << 14));
		enemy4sprite[1] = ((enemy4.x << 0) | (0 << 9) | (0 << 12) | (0 << 13) | (0 << 14));
		enemy4sprite[2] = (((7 + (enemy4.animation * 2)) << 0) | (0 << 10) | (3 << 12));	
		
		//Update graphic scrolling every frame
		TILEOFFSET[0] = ((BG1horizontaloffset << 0));
		BGHOFFSET[0] = ((BG3horizontaloffset << 0));
		BGVOFFSET[0] = ((BG3verticaloffset << 0));
		FGHOFFSET[0] = ((BG2horizontaloffset << 0));
	
	if(GSTATE == TITLE) 
	{
		PlayTitle(); //Run title screen
	}
	else if(GSTATE == PLAYING) 
	{	
		PlayGame(); //Run game
	}
	else if(GSTATE == PAUSE) 
	{ 
		PlayPause(); //Run pause
	}
	else if(GSTATE == GAME_OVER) 
	{ 
		PlayGameOver(); //Run game over
	} 
	
	}
}

void PlayTitle() 
{
	ShowTitle();
			
			scanKeys();
			unsigned short downkeys = keysDown();
			
		if(downkeys & KEY_START)
		{ 
			if(menuoption == 1) {
			GSTATE = PLAYING;
			StartGame();
			//ChangeState(&state, PLAYING);
			}
		}
		if(downkeys & KEY_UP)
		{
		menuoption -= 1;
		if(menuoption == 0) {menuoption = 3;}
		}
		if(downkeys & KEY_DOWN)
		{
		menuoption += 1;
		if(menuoption >= 4) {menuoption = 0;}
		}
		if(downkeys & KEY_LEFT)
		{
		if(menuoption == 2) {
			if(musicmode == 1) {
				musicmode = 0;
			} else {musicmode = 1;}
		}
		if(menuoption == 3) {
			if(hardmode == 1) {
				hardmode = 0;
			} else {hardmode = 1;}
		}
		}
		if(downkeys & KEY_RIGHT)
		{
		if(menuoption == 2) {
			if(musicmode == 1) {
				musicmode = 0;
			} else {musicmode = 1;}
		}
		if(menuoption == 3) {
			if(hardmode == 1) {
				hardmode = 0;
			} else {hardmode = 1;}
		}
		}
}

void PlayGame() 
{
		DrawHUD();
		//DrawScore();
		scanKeys();
		unsigned short mykeys = keysHeld();
		unsigned short downkeys = keysDown();
		
		if(downkeys & KEY_A)
		{
			if(player.y == ground) 
			{
					player.y -= 30;
					mmEffect( MOD_SOUND1 );
				if (player.y > ground) { player.y = ground;}
			} 
			else {player.y += 1;}
		} 
		else
		{
			player.y += 1;
			if (player.y > ground) { player.y = ground;}
			if (player.y > enemyground) {player.y = enemyground;}
		}
		if(mykeys & KEY_B)
		{
			shield.movedir = 0;
			shield.movespeed = 2;
			shield.y = player.y;
		}  else {shield.movespeed = 2; if(GSTATE == PLAYING) shield.y = ground;}
		if(mykeys & KEY_LEFT)
		{
				player.movedir = 1;				
			if(player.y == ground) 
				swapani(&player.animation);
				
			//if (player.x < 20) { player.x = 20;} 
		}
		if(mykeys & KEY_RIGHT)
		{
				player.movedir = 2;
			if(player.y == ground) 
				swapani(&player.animation);
			//if (player.x > 200) { player.x = 200;} 
		}
		if(downkeys & KEY_START)
		{
				DrawPause();
				if(musicmode == 1)
				mmStart( MOD_CT5PROGC_SND, MM_PLAY_ONCE );
				//ChangeState(&state, PAUSE);
				GSTATE = PAUSE;
		}
		if(mykeys & KEY_L)
		{
			shield.movedir = 1;
		}
		if(mykeys & KEY_R)
		{
			shield.movedir = 2;
		}
		if(!((mykeys & KEY_RIGHT)) && !((mykeys & KEY_LEFT)))
		{
			player.movedir = 0;
		}
	
		TimerUpdate(); //Update timer on-screen
		if(timerthousand == 1 && timerhundred == 1 && timerten == 1 && timer == 1) {
		GSTATE = GAME_OVER;
		}

		//Shield following code
			if((player.x - shield.x) > 15)
				shield.movedir = 2;
			else if((shield.x - player.x) > 15)
				shield.movedir = 1;
				
		//Enemy running code --initialisation and deinitialisation
			EasyEnemiesUpdate();

			//swap all enemy animations - constant
			swapani(&enemy1.animation);
			swapani(&enemy2.animation);
			swapani(&enemy3.animation);
			swapani(&enemy4.animation);
		
		//Update all object's x positions - All done in assembly	

		movementupdateX(&player.movedir, &player.x, &player.movespeed);
		movementupdateX(&shield.movedir, &shield.x, &shield.movespeed);
		
		if (player.x < 30) 
		{
		player.x = 30;
		BG1horizontaloffset--;
		BG2horizontaloffset--;
		}
		if (player.x > 190) 
		{ 
		player.x = 190;
		BG1horizontaloffset++;
		BG2horizontaloffset++;
		}
		
		timered(&scrolldelay);
		if(scrolldelay == 0) 
		{
		scrolldelay = SCROLL_DELAY_MAX;
		BG3horizontaloffset++;
		BG3verticaloffset--;
		}
		timered(&BG2scrolldelay);
		if(BG2scrolldelay == 0)
		{
		BG2scrolldelay = SCROLL2_DELAY_MAX;
		BG2horizontaloffset--;
		}
		
		CheckCollisions();
		
		if(hardmode == 1) // -- blue enemy run code - Only runs if hard mode is turned on at main menu
		{
			HardEnemiesUpdate();
		}
		//GravityUpdate(&player.y, ground);
}

void PlayPause() 
{
	DrawPause();
	DrawHUD();
		//DrawScore();
	
		scanKeys();
		unsigned short downkeys = keysDown();
		
		if(downkeys & KEY_SELECT )
		{
				ResetGame();
		}
		if(downkeys & KEY_START)
		{

				//ClearText();
				if(musicmode == 1)
				mmStart( MOD_SPACEDEB, MM_PLAY_LOOP );
				GSTATE = PLAYING;
				//ChangeState(&state, PLAYING);
				//ClearText();
			
		}
}

void PlayGameOver() 
{
		DrawHUD();
		DrawGameOver();
		
		scanKeys();
		unsigned short downkeys = keysDown();
		
	if(downkeys & KEY_START)
	{ 
		mmStart(MOD_SILENCE, MM_PLAY_ONCE);
		GSTATE = TITLE;
		ResetGame();
		//ChangeState(&state, TITLE);
	}
}

void ShowTitle() 
{
	
	Backgroundcleantocolour(1);
	player.x = playertitlescreenx;
	player.y = playertitlescreeny;
	shield.x = shieldtitlescreenx;
	shield.y = playertitlescreeny;
	mmStart( MOD_SILENCE, MM_PLAY_ONCE );
	textdisplay[(5 * 32)+8] = ((16 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+9] = ((13 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+10] = ((30 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+11] = ((5 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+12] = ((22 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+13] = ((8 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+15] = ((5 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+16] = ((24 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+17] = ((24 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+18] = ((5 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+19] = ((7 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(5 * 32)+20] = ((15 << 0) | (0<<10) | (0<<11) | (5<<12));
	
	if(menuoption == 1) {
	textdisplay[(10 * 32)+10] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+11] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+12] = ((5 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+13] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+14] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+16] = ((11 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+17] = ((5 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+18] = ((17 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(10 * 32)+19] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	} else {
	textdisplay[(10 * 32)+10] = ((23 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+11] = ((24 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+12] = ((5 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+13] = ((22 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+14] = ((24 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+16] = ((11 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+17] = ((5 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+18] = ((17 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(10 * 32)+19] = ((9 << 0) | (0<<10) | (0<<11) | (5<<12));
	}
	
	if(menuoption == 2) {
	textdisplay[(11 * 32)+9] = ((42 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+10] = ((17 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+11] = ((25 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+12] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+13] = ((13 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+14] = ((7 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+16] = ((43 << 0) | (0<<10) | (0<<11) | (6<<12));
	if(musicmode == 1) {
	textdisplay[(11 * 32)+18] = ((19 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+19] = ((18 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+21] = ((41 << 0) | (0<<10) | (0<<11) | (6<<12));
	} else {
	textdisplay[(11 * 32)+18] = ((19 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+19] = ((10 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+20] = ((10 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(11 * 32)+21] = ((41 << 0) | (0<<10) | (0<<11) | (6<<12));
	}
	} else {
	textdisplay[(11 * 32)+10] = ((17 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+11] = ((25 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+12] = ((23 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+13] = ((13 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+14] = ((7 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+16] = ((43 << 0) | (0<<10) | (0<<11) | (5<<12));
	if(musicmode == 1) {
	textdisplay[(11 * 32)+18] = ((19 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+19] = ((18 << 0) | (0<<10) | (0<<11) | (5<<12));
	} else {
	textdisplay[(11 * 32)+18] = ((19 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+19] = ((10 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(11 * 32)+20] = ((10 << 0) | (0<<10) | (0<<11) | (5<<12));
	}
	}
	
	if(menuoption == 3) {
	textdisplay[(12 * 32)+7] = ((42 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+8] = ((8 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+9] = ((13 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+10] = ((10 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+11] = ((10 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+12] = ((13 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+13] = ((7 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+14] = ((25 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+15] = ((16 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+16] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+17] = ((29 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+18] = ((43 << 0) | (0<<10) | (0<<11) | (6<<12));
	if(hardmode == 0) {
	textdisplay[(12 * 32)+20] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+21] = ((5 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+22] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+23] = ((29 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+24] = ((41 << 0) | (0<<10) | (0<<11) | (6<<12));
	} else {
	textdisplay[(12 * 32)+20] = ((12 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+21] = ((5 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+22] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+23] = ((8 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+24] = ((41 << 0) | (0<<10) | (0<<11) | (6<<12));
	}
	} else {
	textdisplay[(12 * 32)+8] = ((8 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+9] = ((13 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+10] = ((10 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+11] = ((10 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+12] = ((13 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+13] = ((7 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+14] = ((25 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+15] = ((16 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+16] = ((24 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+17] = ((29 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+18] = ((43 << 0) | (0<<10) | (0<<11) | (5<<12));
	if(hardmode == 0) {
	textdisplay[(12 * 32)+20] = ((9 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+21] = ((5 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+22] = ((23 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+23] = ((29 << 0) | (0<<10) | (0<<11) | (5<<12));
	} else {
	textdisplay[(12 * 32)+20] = ((12 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+21] = ((5 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+22] = ((22 << 0) | (0<<10) | (0<<11) | (5<<12));
	textdisplay[(12 * 32)+23] = ((8 << 0) | (0<<10) | (0<<11) | (5<<12));
	}
	}
	
}

void StartGame() 
{
	player.x = playergameinitx;
	player.y = ground;
	shield.x = shieldgameinitx;
	shield.y = ground;
	if(musicmode == 1)
	mmStart( MOD_SPACEDEB, MM_PLAY_LOOP );
	int i;
	int iy;
	for(i = 0; i < 32; i++)
	{
		tiledisplay[(16 * 32)+i] = ((2 << 0) | (0<<10) | (0<<11) | (2<<12));
	}
	for (iy = 17; iy < 23; iy++) 
	{
	for(i = 0; i < 32; i +=2)
	{
		tiledisplay[(iy * 32)+i] = ((1 << 0) | (0<<10) | (0<<11) | (2<<12));
	}
	}
	for(iy = 0; iy < 32; iy +=2 )
	{
	for(i = 0; i < 32; i ++)
	{
		BGdisplay[(iy * 32)+i] = ((48 << 0) | (0<<10) | (0<<11) | (7<<12));
	}
	}
	for(iy = 0; iy < 32; iy ++)
	{
	for(i = 0; i < 32; i += 2)
	{
		BGdisplay[(iy * 32)+i] = ((49 << 0) | (0<<10) | (0<<11) | (7<<12));
	}
	}
	for (iy = 17; iy < 23; iy++) 
	{
	for(i = 0; i < 32; i++)
	{
		FGdisplay[(iy * 32)+i] = ((50 << 0) | (0<<10) | (0<<11) | (7<<12));
	}
	}
}

void DrawPause() 
{
	
	textdisplay[(7 * 32)+10] = ((20 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(7 * 32)+11] = ((5 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(7 * 32)+12] = ((25 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(7 * 32)+13] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(7 * 32)+14] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	
	textdisplay[(12 * 32)+2] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+3] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+4] = ((16 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+5] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+6] = ((7 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+7] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+9] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+10] = ((19 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+12] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+13] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+14] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+15] = ((25 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+16] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+17] = ((18 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+19] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+20] = ((19 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+22] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+23] = ((13 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+24] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+25] = ((16 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(12 * 32)+26] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	
	textdisplay[(13 * 32)+9] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+10] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+11] = ((5 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+12] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+13] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+15] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+16] = ((19 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+18] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+19] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+20] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+21] = ((25 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+22] = ((17 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(13 * 32)+23] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
}

void DrawHUD() 
{
DrawTimer();
DrawScore();
}

void DrawScore() 
{
	textdisplay[(0 * 32)+17] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+18] = ((7 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+19] = ((19 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+20] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+21] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	
	if(scorehundred == 10) 
	{
	textdisplay[(0 * 32)+23] = ((27 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+24] = ((13 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+25] = ((18 << 0) | (0<<10) | (0<<11) | (6<<12));
	} else {
	textdisplay[(0 * 32)+23] = (((31 + scorehundred) << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+24] = (((31 + scoreten) << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+25] = (((31 + score) << 0) | (0<<10) | (0<<11) | (6<<12));
	}
	
	if(GSTATE == GAME_OVER) {
	textdisplay[(0 * 32)+17] = ((23 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+18] = ((7 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+19] = ((19 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+20] = ((22 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+21] = ((9 << 0) | (0<<10) | (0<<11) | (2<<12));
	
	if(scorehundred == 10) {
	textdisplay[(0 * 32)+23] = ((27 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+24] = ((13 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+25] = ((18 << 0) | (0<<10) | (0<<11) | (2<<12));
	} else {
	textdisplay[(0 * 32)+23] = (((31 + scorehundred) << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+24] = (((31 + scoreten) << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+25] = (((31 + score) << 0) | (0<<10) | (0<<11) | (2<<12));
	}
	}
}

void DrawTimer() 
{
	
	textdisplay[(0 * 32)+0] = ((24 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+1] = ((13 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+2] = ((17 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+3] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+4] = ((22 << 0) | (0<<10) | (0<<11) | (6<<12));

	if(timerthousand == 1 && timerhundred == 1 && timerten == 1 && timer == 1) 
	{
	textdisplay[(0 * 32)+6] = ((16 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+7] = ((19 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+8] = ((23 << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+9] = ((9 << 0) | (0<<10) | (0<<11) | (6<<12));
	} else {
	textdisplay[(0 * 32)+6] = (((30 + timerthousand) << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+7] = (((30 + timerhundred) << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+8] = (((30 + timerten) << 0) | (0<<10) | (0<<11) | (6<<12));
	textdisplay[(0 * 32)+9] = (((30 + timer) << 0) | (0<<10) | (0<<11) | (6<<12));
	}
	
	if(GSTATE == GAME_OVER) {
	textdisplay[(0 * 32)+0] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+1] = ((13 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+2] = ((17 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+3] = ((9 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+4] = ((22 << 0) | (0<<10) | (0<<11) | (2<<12));

	if(timerthousand == 1 && timerhundred == 1 && timerten == 1 && timer == 1) 
	{
	textdisplay[(0 * 32)+6] = ((16 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+7] = ((19 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+8] = ((23 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+9] = ((9 << 0) | (0<<10) | (0<<11) | (2<<12));
	} else {
	textdisplay[(0 * 32)+6] = (((30 + timerthousand) << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+7] = (((30 + timerhundred) << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+8] = (((30 + timerten) << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(0 * 32)+9] = (((30 + timer) << 0) | (0<<10) | (0<<11) | (2<<12));
	}
	}
}

void DrawGameOver() 
{
	//ClearText();
	Backgroundcleantocolour(5);
	mmStart( MOD_SILENCE, MM_PLAY_ONCE );
	textdisplay[(5 * 32)+10] = ((11 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(5 * 32)+11] = ((5 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(5 * 32)+12] = ((17 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(5 * 32)+13] = ((9 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(5 * 32)+15] = ((19 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(5 * 32)+16] = ((26 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(5 * 32)+17] = ((9 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(5 * 32)+18] = ((22 << 0) | (0<<10) | (0<<11) | (2<<12));
	
	textdisplay[(12 * 32)+4] = ((23 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+5] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+6] = ((5 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+7] = ((22 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+8] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+10] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+11] = ((19 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+13] = ((22 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+14] = ((9 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+15] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+16] = ((25 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+17] = ((22 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+18] = ((18 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+20] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+21] = ((19 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+23] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+24] = ((13 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+25] = ((24 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+26] = ((16 << 0) | (0<<10) | (0<<11) | (2<<12));
	textdisplay[(12 * 32)+27] = ((9 << 0) | (0<<10) | (0<<11) | (2<<12));
}

void ClearText() 
{
	int textx;
	int texty;
	for(texty = 0; texty < 31; texty++) 
	{
	for(textx = 0; textx < 31; textx++)
	{
		textdisplay[(texty * 32)+textx] = ((0 << 0) | (0<<10) | (0<<11) | (0<<12));
	}
	}
}

void ResetGame() 
{
	//ClearText();
	//clearscreenasm(&textdisplay[0]);
	//clearscreenasm(&tiledisplay[0]);
	mmStop();
	score = 0;
	scoreten = 0;
	scorehundred = 0;
	msecond = 10;
	timer = 10;
	timerten = 10;
	timerhundred = 10;
	timerthousand = 2;
	BG1horizontaloffset = 0;
	BG2horizontaloffset = 0;
	BG3verticaloffset = 0;
	BG3horizontaloffset = 0;
	//player.x = playertitlescreenx;
	//player.y = playertitlescreeny;
	enemy1.x = offscreenx;
	enemy2.x = offscreenx;
	enemy1.y = offscreeny;
	enemy2.y = offscreeny;
	enemy3.x = offscreenx;
	enemy4.x = offscreenx;
	enemy3.y = offscreeny;
	enemy4.y = offscreeny;
	enemy1.init = 0;
	enemy2.init = 0;
	enemy3.init = 0;
	enemy4.init = 0;
	GSTATE = TITLE;
	//ChangeState(&state, TITLE);
	int ix;
	int iy;
	for(iy = 0; iy < 31; iy++)
	{
	for(ix = 0; ix < 31; ix++)
	{
		tiledisplay[(iy * 32)+ix] = ((0 << 0) | (0<<10) | (0<<11) | (0<<12));
	}
	}
		for(iy = 0; iy < 31; iy++)
	{
	for(ix = 0; ix < 31; ix++)
	{
		FGdisplay[(iy * 32)+ix] = ((0 << 0) | (0<<10) | (0<<11) | (0<<12));
	}
	}
}
	

void Backgroundcleantocolour(short paletteno) 
{
	int BGx;
	int BGy;
	for(BGy = 0; BGy < 33; BGy++)
	{
	for(BGx = 0; BGx < 33; BGx++)
	{
		BGdisplay[(BGy * 32)+BGx] = ((47 << 0) | (0<<10) | (0<<11) | (paletteno<<12));
	}
	}
	for(BGy = 0; BGy < 33; BGy++)
	{
	for(BGx = 0; BGx < 33; BGx++)
	{
		FGdisplay[(BGy * 32)+BGx] = ((0 << 0) | (0<<10) | (0<<11) | (0<<12));
	}
	}
}


//--Deprecated - All score updates now in newscore.asm
/*
void AddPoint() {
	addscore(&score);
	if(score == scorerollover) {
	score = 0;
	addscore(&scoreten);
	}
	if(scoreten == scorerollover) {
	scoreten = 0;
	addscore(&scorehundred);
	}
	if(scorehundred >= scorerollover) {
	scorehundred = scorerollover;
	scoreten = 0;
	score = 0;
	}
}
*/

void TimerUpdate() 
{
	timered(&msecond);
	if(msecond == timerollover) {
	msecond = 10;
	newtime(&timer, &timerten, &timerhundred, &timerthousand);
	}
}

void CheckCollisions() 
{
		if(player.x + player.width > enemy1.x - enemy1.width &&
		   player.x - player.width < enemy1.x + enemy1.width &&
		   player.y + player.height > enemy1.y - enemy1.height &&
		   player.y - player.height < enemy1.y + enemy1.height)  //Player collides with enemy 1
		   {
		   GSTATE = GAME_OVER;
		   }
		   
		if(shield.x + shield.width > enemy1.x - enemy1.width &&
		   shield.x - shield.width < enemy1.x + enemy1.width &&
		   shield.y + shield.height > enemy1.y - enemy1.height &&
		   shield.y - shield.height < enemy1.y + enemy1.height)  //Shield collides with enemy 1
		   {
				//mmEffect( MOD_ENEMY1 );
				enemy1.x = offscreenx;
				enemy1.y = offscreeny;
				enemy1.movespeed = 0;
				enemy1.init = 0;
				newscore(&score,&scoreten,&scorehundred);
		   }
		   
		if(player.x + player.width > enemy2.x - enemy2.width &&
		   player.x - player.width < enemy2.x + enemy2.width &&
		   player.y + player.height > enemy2.y - enemy2.height &&
		   player.y - player.height < enemy2.y + enemy2.height)  //Player collides with enemy 2
		   {
		   GSTATE = GAME_OVER;
		   }
		   
		if(shield.x + shield.width > enemy2.x - enemy2.width &&
		   shield.x - shield.width < enemy2.x + enemy2.width &&
		   shield.y + shield.height > enemy2.y - enemy2.height &&
		   shield.y - shield.height < enemy2.y + enemy2.height)  //Shield collides with enemy 2
		   {
				//mmEffect( MOD_ENEMY1 );
				enemy2.x = offscreenx;
				enemy2.y = offscreeny;
				enemy2.movespeed = 0;
				enemy2.init = 0;
				newscore(&score,&scoreten,&scorehundred);
		   }

		if(player.x + player.width > enemy3.x - enemy3.width &&
		   player.x - player.width < enemy3.x + enemy3.width &&
		   player.y + player.height > enemy3.y - enemy3.height &&
		   player.y - player.height < enemy3.y + enemy3.height)  //Player collides with enemy 3
		   {
		   GSTATE = GAME_OVER;
		   }
		   
		if(shield.x + shield.width > enemy3.x - enemy3.width &&
		   shield.x - shield.width < enemy3.x + enemy3.width &&
		   shield.y + shield.height > enemy3.y - enemy3.height &&
		   shield.y - shield.height < enemy3.y + enemy3.height)  //Shield collides with enemy 3
		   {
				//mmEffect( MOD_ENEMY2 );
				enemy3.x = offscreenx;
				enemy3.y = offscreeny;
				enemy3.movespeed = 0;
				enemy3.init = 0;
				newscore(&score,&scoreten,&scorehundred);
				newscore(&score,&scoreten,&scorehundred);
				newscore(&score,&scoreten,&scorehundred);
		   }
		   
		if(player.x + player.width > enemy4.x - enemy4.width &&
		   player.x - player.width < enemy4.x + enemy4.width &&
		   player.y + player.height > enemy4.y - enemy4.height &&
		   player.y - player.height < enemy4.y + enemy4.height)  //Player collides with enemy 4
		   {
		   GSTATE = GAME_OVER;
		   }
		   
		if(shield.x + shield.width > enemy4.x - enemy4.width &&
		   shield.x - shield.width < enemy4.x + enemy4.width &&
		   shield.y + shield.height > enemy4.y - enemy4.height &&
		   shield.y - shield.height < enemy4.y + enemy4.height)  //Shield collides with enemy 4
		   {
				//mmEffect( MOD_ENEMY2 );
				enemy4.x = offscreenx;
				enemy4.y = offscreeny;
				enemy4.movespeed = 0;
				enemy4.init = 0;
				newscore(&score,&scoreten,&scorehundred);
				newscore(&score,&scoreten,&scorehundred);
				newscore(&score,&scoreten,&scorehundred);
		   }
}

void EasyEnemiesUpdate()
{
			if((rand()% 254) == 1) {
				if(enemy1.init == 0) {
					enemy1.init = 1;
					enemy1.x = 199;
					enemy1.y = enemyground;
					enemy1.movespeed = 2;
				}
				}
			if((rand()% 254) == 1) {
				if(enemy2.init == 0) {
					enemy2.init = 1;
					enemy2.x = 1;
					enemy2.y = enemyground;
					enemy2.movespeed = 2;
					}
				}
			if(enemy1.x == 0) {
					enemy1.x = offscreenx;
					enemy1.y = offscreeny;
					enemy1.movespeed = 0;
					enemy1.init = 0;
				}
			if(enemy2.x == 200) {
					enemy2.x = offscreenx;
					enemy2.y = offscreeny;
					enemy2.movespeed = 0;
					enemy2.init = 0;
				}
				
				movementupdateX(&enemy1.movedir, &enemy1.x, &enemy1.movespeed);
				movementupdateX(&enemy2.movedir, &enemy2.x, &enemy2.movespeed);
}

void HardEnemiesUpdate()
{
		
			if((rand()% 254) == 1) {
				if(enemy3.init == 0) {
					enemy3.init = 1;
					enemy3.x = 1;
					enemy3.y = (enemyground - rand()% 30);
					enemy3.movespeed = 1;
				}
				}
			if((rand()% 254) == 1) {
				if(enemy4.init == 0) {
					enemy4.init = 1;
					enemy4.x = 199;
					enemy4.y = (enemyground - rand()% 30);
					enemy4.movespeed = 1;
					}
				}
			if(enemy3.x == 0) {
					enemy3.x = offscreenx;
					enemy3.y = offscreeny;
					enemy3.movespeed = 0;
					enemy3.init = 0;
				}
			if(enemy4.x == 200) {
					enemy4.x = offscreenx;
					enemy4.y = offscreeny;
					enemy4.movespeed = 0;
					enemy4.init = 0;
				}
			if(enemy3.init == 1) {
				if(enemy3.y == enemyground) {
					enemy3.y -= rand()% 60;
					}
				}
			if(enemy4.init == 1) {
				if(enemy4.y == enemyground) {
					enemy4.y -= rand()% 60;
					}
				}
			enemy3.y += 1;
			enemy4.y += 1;
			
			movementupdateX(&enemy3.movedir, &enemy3.x, &enemy3.movespeed);
			movementupdateX(&enemy4.movedir, &enemy4.x, &enemy4.movespeed);
}