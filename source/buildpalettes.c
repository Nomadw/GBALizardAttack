void BuildPalettes() {
		unsigned short * BackgroundPalette = ((unsigned short *) 0x05000000); //Palette 0
		                       //R         //G          //B
		BackgroundPalette[0] = ((10 << 0) | (10 << 5) | (10 << 10));
		
	unsigned short * TilePalette15 = ((unsigned short *) 0x050001E2); //Palette 15BG
	
		                       //R         //G          //B
		TilePalette15[0] = ((31 << 0) | (31 << 5) | (31 << 10));
		TilePalette15[1] = ((20 << 0) | (10 << 5) | (15 << 10));
		TilePalette15[2] = ((18 << 0) | (30 << 5) | (9 << 10));
		TilePalette15[3] = ((31 << 0) | (16 << 5) | (0 << 10));
		TilePalette15[4] = ((29 << 0) | (30 << 5) | (1 << 10));
		TilePalette15[5] = ((8 << 0) | (9 << 5) | (25 << 10));
		
	unsigned short * TilePalette2 = ((unsigned short *) 0x05000042); //Palette 2BG
	
		                       //R         //G          //B
		TilePalette2[0] = ((21 << 0) | (21 << 5) | (21 << 10));
		TilePalette2[1] = ((10 << 0) | (1 << 5) | (5 << 10));
		TilePalette2[2] = ((18 << 0) | (20 << 5) | (9 << 10));
		TilePalette2[3] = ((11 << 0) | (6 << 5) | (0 << 10));
		TilePalette2[4] = ((29 << 0) | (20 << 5) | (21 << 10));
		TilePalette2[5] = ((31 << 0) | (31 << 5) | (31 << 10));
		
	unsigned short * TilePalette3 = ((unsigned short *) 0x05000062); //Palette 3BG
	
		                       //R         //G          //B
		TilePalette3[0] = ((4 << 0) | (21 << 5) | (10 << 10));
		TilePalette3[1] = ((7 << 0) | (8 << 5) | (31 << 10));
		TilePalette3[2] = ((8 << 0) | (25 << 5) | (4 << 10));
		TilePalette3[3] = ((1 << 0) | (18 << 5) | (25 << 10));
		TilePalette3[4] = ((10 << 0) | (26 << 5) | (14 << 10));
		TilePalette3[5] = ((8 << 0) | (1 << 5) | (25 << 10));
		
	unsigned short * TilePalette4 = ((unsigned short *) 0x050000A2); //Palette 4BG
	
		                       //R         //G          //B
		TilePalette4[0] = ((31 << 0) | (31 << 5) | (31 << 10));
		TilePalette4[1] = ((31 << 0) | (31 << 5) | (31 << 10));
		TilePalette4[2] = ((31 << 0) | (31 << 5) | (31 << 10));
		TilePalette4[3] = ((31 << 0) | (31 << 5) | (31 << 10));
		TilePalette4[4] = ((31 << 0) | (31 << 5) | (31 << 10));
		TilePalette4[5] = ((31 << 0) | (31 << 5) | (31 << 10));
		
	unsigned short * TilePalette5 = ((unsigned short *) 0x050000C2); //Palette 5BG
	
		                       //R         //G          //B
		TilePalette5[0] = ((31 << 0) | (31 << 5) | (0 << 10));
		TilePalette5[1] = ((31 << 0) | (31 << 5) | (0 << 10));
		TilePalette5[2] = ((31 << 0) | (31 << 5) | (0 << 10));
		TilePalette5[3] = ((31 << 0) | (31 << 5) | (0 << 10));
		TilePalette5[4] = ((31 << 0) | (31 << 5) | (0 << 10));
		TilePalette5[5] = ((31 << 0) | (31 << 5) | (0 << 10));
		
	unsigned short * TilePalette6 = ((unsigned short *) 0x050000E2); //Palette 6BG
	
		                       //R         //G          //B
		TilePalette6[0] = ((31 << 0) | (31 << 5) | (31 << 10));
		TilePalette6[1] = ((0 << 0) | (0 << 5) | (0 << 10));
		TilePalette6[2] = ((4 << 0) | (22 << 5) | (9 << 10));
		TilePalette6[3] = ((22 << 0) | (28 << 5) | (4 << 10));
		TilePalette6[4] = ((31 << 0) | (31 << 5) | (0 << 10));
		TilePalette6[5] = ((31 << 0) | (31 << 5) | (0 << 10));
		
	unsigned short * SpritePalette0 = ((unsigned short *) 0x05000202); //Palette 0OBJ
	
		                       //R         //G          //B
		SpritePalette0[0] = ((4 << 0) | (21 << 5) | (10 << 10));
		SpritePalette0[1] = ((7 << 0) | (8 << 5) | (31 << 10));
		SpritePalette0[2] = ((8 << 0) | (25 << 5) | (4 << 10));
		SpritePalette0[3] = ((1 << 0) | (18 << 5) | (25 << 10));
		SpritePalette0[4] = ((10 << 0) | (26 << 5) | (14 << 10));
		SpritePalette0[5] = ((8 << 0) | (1 << 5) | (25 << 10));
		
	unsigned short * SpritePalette1 = ((unsigned short *) 0x05000222); //Palette 1OBJ
	
		                       //R         //G          //B
		SpritePalette1[0] = ((7 << 0) | (8 << 5) | (31 << 10));
		SpritePalette1[1] = ((4 << 0) | (21 << 5) | (10 << 10));
		SpritePalette1[2] = ((1 << 0) | (18 << 5) | (25 << 10));
		SpritePalette1[3] = ((8 << 0) | (25 << 5) | (4 << 10));
		SpritePalette1[4] = ((8 << 0) | (1 << 5) | (25 << 10));
		SpritePalette1[5] = ((10 << 0) | (26 << 5) | (14 << 10));
		
	unsigned short * SpritePalette2 = ((unsigned short *) 0x05000242); //Palette 2OBJ
	
		                       //R         //G          //B
		SpritePalette2[0] = ((31 << 0) | (31 << 5) | (31 << 10));
		SpritePalette2[1] = ((31 << 0) | (0 << 5) | (0 << 10));
		SpritePalette2[2] = ((0 << 0) | (31 << 5) | (0 << 10));
		SpritePalette2[3] = ((0 << 0) | (0 << 5) | (31 << 10));
		SpritePalette2[4] = ((0 << 0) | (0 << 5) | (0 << 10));
		SpritePalette2[5] = ((0 << 0) | (0 << 5) | (0 << 10));
		
	unsigned short * SpritePalette3 = ((unsigned short *) 0x05000082); //Palette 3OBJ
		                       //R         //G          //B
		SpritePalette3[0] = ((31 << 0) | (0 << 5) | (0 << 10));
		SpritePalette3[1] = ((31 << 0) | (31 << 5) | (0 << 10));
		SpritePalette3[2] = ((4 << 0) | (13 << 5) | (22 << 10));
		SpritePalette3[3] = ((15 << 0) | (24 << 5) | (17 << 10));
		SpritePalette3[4] = ((31 << 0) | (31 << 5) | (31 << 10));
		SpritePalette3[5] = ((8 << 0) | (6 << 5) | (16 << 10));
		SpritePalette3[6] = ((6 << 0) | (14 << 5) | (7 << 10));
		SpritePalette3[7] = ((27 << 0) | (18 << 5) | (5 << 10));
		SpritePalette3[8] = ((4 << 0) | (0 << 5) | (0 << 10));
		SpritePalette3[9] = ((0 << 0) | (25 << 5) | (14 << 10));
		SpritePalette3[10] = ((0 << 0) | (15 << 5) | (0 << 10));		
		SpritePalette3[11] = ((0 << 0) | (15 << 5) | (31 << 10));
		SpritePalette3[12] = ((0 << 0) | (0 << 5) | (0 << 10));
		SpritePalette3[13] = ((0 << 0) | (0 << 5) | (0 << 10));
		SpritePalette3[14] = ((0 << 0) | (0 << 5) | (0 << 10));
		SpritePalette3[15] = ((0 << 0) | (0 << 5) | (0 << 10));	

	unsigned short * SpritePalette4 = ((unsigned short *) 0x05000262); //Palette 3OBJ
	
		                       //R         //G          //B
		SpritePalette4[0] = ((31 << 0) | (31 << 5) | (31 << 10));
		SpritePalette4[1] = ((0 << 0) | (0 << 5) | (31 << 10));
		SpritePalette4[2] = ((0 << 0) | (31 << 5) | (0 << 10));
		SpritePalette4[3] = ((0 << 0) | (0 << 5) | (31 << 10));
		SpritePalette4[4] = ((0 << 0) | (0 << 5) | (0 << 10));
		SpritePalette4[5] = ((0 << 0) | (0 << 5) | (0 << 10));		
}

