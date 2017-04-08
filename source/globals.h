// enumerate a list of game states

//enum key{A, DOWN, LEFT, RIGHT, START, SELECT, UP} key;
//char keys[] = {0, 0, 0, 0, 0, 0, 0};



// display layers
unsigned short* textdisplay = ((unsigned short* ) 0x06005800);
unsigned short* BGdisplay = ((unsigned short* ) 0x06004000);
unsigned short* FGdisplay = ((unsigned short* ) 0x06004800);
unsigned short* tiledisplay = ((unsigned short*) 0x06005000);

//Prototype functions
void ShowTitle();
void StartGame();
void DrawPause();
void ResetGame();
void BuildPalettes();
void BuildTiles();
void BuildSprites();
void ClearText();
void DrawScore();
void DrawTimer();
void PlayTitle();
void PlayGame();
void PlayPause();
void PlayGameOver();
void CheckCollisions();
//void AddPoint(); //--Deprecated - All point addition now in newscore.s
void TimerUpdate();
void DrawHUD();
void DrawGameOver();
void EasyEnemiesUpdate();
void HardEnemiesUpdate();
void Backgroundcleantocolour(short paletteno);
//char CheckCollisions(struct* item1, struct* item2);
extern void swapani(unsigned char* anipos);
//extern void clearscreenasm(unsigned short* array[]);
//extern void addscore(int* score); //--Deprecated - All point addition now in newscore.s. addscore.s kept for reference
extern void newscore(char* score, char* scoreten, char* scorehundred);
extern void timered(char* time);
extern void newtime(char* timer, char* timerten, char* timerhundred, char* timerthousand);
extern void movementupdateX(unsigned char* xdir, unsigned char* xpos, unsigned char* xspeed);
//extern void GravityUpdate(char* ypos, char groundpos);
//extern void ChangeState(char* CurrState, char NewState);



	