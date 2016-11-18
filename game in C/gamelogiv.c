#include "myLib.h"

int checkSpeedv(struct Square h) {
	if (h.col + h.speedv > h.righth || h.col + h.speedv < h.lefth) {
		return -h.speedv;
	} 
	return h.speedv;
}

int checkSpeedh(struct Square h) {
	if (h.row + h.speedh > h.bottomv || h.row + h.speedh < h.topv) {
		return -h.speedh;
	}
	return h.speedh;
}
void clearSquare(struct Square h) {
	drawRect(h.row, h.col, h.size, h.size, BLACK);
}

void drawSquare(struct Square h) {
	drawRect(h.row, h.col, h.size, h.size, h.color);
	
}


int gameInit() {

	clearImage();
			
	drawImage3(100, 200, GAME_WIDTH, GAME_HEIGHT, game_data);
	drawString(150, 5, "Press A(Z) to Home", WHITE);
	struct Square h1;
	h1.row = 0; h1.col = 60; h1.size = 8; h1.speedh = 2; h1.speedv = 0; h1.color = YELLOW;
	h1.lefth = 60; h1.righth = 60; h1.topv = 0; h1.bottomv = 140;
	struct Square h2;
	h2.row = 140; h2.col = 120; h2.size = 8; h2.speedh = 2; h2.speedv = 0; h2.color = YELLOW;
	h2.lefth = 120; h2.righth = 120; h2.topv = 0; h2.bottomv = 140;
	struct Square h3;
	h3.row = 0; h3.col = 180; h3.size = 8; h3.speedh = 2.5; h3.speedv = 0; h3.color = YELLOW;
	h3.lefth = 180; h3.righth = 180; h3.topv = 0; h3.bottomv = 140;

	struct Square v1;
	v1.row = 80; v1.col = 0; v1.size = 8; v1.speedh = 0; v1.speedv = 3; v1.color = YELLOW;
	v1.lefth = 0; v1.righth = 230; v1.topv = 70; v1.bottomv = 70;

	struct Square v2;
	v2.row = 30; v2.col = 230; v2.size = 8; v2.speedh = 0; v2.speedv = 4; v2.color = YELLOW;
	v2.lefth = 0; v2.righth = 230; v2.topv = 90; v2.bottomv = 90;

	struct Square self;
	self.row = 0; self.col = 0; self.size = 10; self.speedh = 0; self.speedv = 0; self.color = RED;
	self.lefth = 0; self.righth = 230; self.topv = 0; self.bottomv = 140;

	drawSquare(self);
	drawSquare(h1);
	drawSquare(h2);	
	drawSquare(h3);	
	drawSquare(v1);
	drawSquare(v2);
	while(1) {
		int x = self.col;
		int y = self.row;
		if(KEY_DOWN_NOW(BUTTON_RIGHT)) {
			x = self.col + 4;
			if (x > 230) {
				x = 230;
			}
		}
		if(KEY_DOWN_NOW(BUTTON_LEFT)) {
			x = self.col - 4;
			if (x < 0 ) {
				x = 0;
			}
		}
		if(KEY_DOWN_NOW(BUTTON_UP)) {
			y = self.row - 4;
			if (y < 0) {
				y = 0;
			}
		}
		if(KEY_DOWN_NOW(BUTTON_DOWN)) {
			y = self.row + 4;
			if (y > 140) {
				y = 140;
			}
		}
		waitForVBlank();
		clearSquare(self);
		self.col = x;
		self.row = y;

		drawSquare(self);
		clearSquare(h1);
		h1.row = h1.row + h1.speedh;
		h1.speedh = checkSpeedh(h1);
		drawSquare(h1);
		clearSquare(h2);
		h2.row = h2.row + h2.speedh;
		h2.speedh = checkSpeedh(h2);
		drawSquare(h2);	
		
		clearSquare(h3);
		h3.row = h3.row + h3.speedh;
		h3.speedh = checkSpeedh(h3);
		drawSquare(h3);	
		
		clearSquare(v1);
		v1.col = v1.col + v1.speedv;
		v1.speedv = checkSpeedv(v1);
		drawSquare(v1);

		clearSquare(v2);
		v2.col = v2.col + v2.speedv;
		v2.speedv = checkSpeedv(v2);
		drawSquare(v2);

		if ((self.row >= (h1.row - h1.size)) && (self.row <= (h1.row + self.size)) && (self.col <= (h1.col + h1.size)) && (self.col >= (h1.col - self.size))) {
			return GAMEOVER;
		}
		if ((self.row >= (h2.row - h2.size)) && (self.row <= (h2.row + self.size)) && (self.col <= (h2.col + h2.size)) && (self.col >= (h2.col - self.size))) {
			return GAMEOVER;
		}
		if ((self.row >= (h3.row - h3.size)) && (self.row <= (h3.row + self.size)) && (self.col <= (h3.col + h3.size)) && (self.col >= (h3.col - self.size))) {
			return GAMEOVER;
		}
		if ((self.row >= (v1.row - v1.size)) && (self.row <= (v1.row + self.size)) && (self.col <= (v1.col + v1.size)) && (self.col >= (v1.col - self.size))) {
			return GAMEOVER;
		}
		if ((self.row >= (v2.row - v2.size)) && (self.row <= (v2.row + self.size)) && (self.col <= (v2.col + v2.size)) && (self.col >= (v2.col - self.size))) {
			return GAMEOVER;
		}


		if (self.row >= 100 && self.row <= 160 && self.col >= 200 && self.col <= 240) {
			return CONGRA;
		}
		if (KEY_DOWN_NOW(BUTTON_A)) {
			return TITLE;		
		}
		
	}
	return 100;

	
}






