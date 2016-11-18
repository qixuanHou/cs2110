#include "myLib.h"




int main() {
	REG_DISPCNT = MODE_3 | BG2_EN;
	enum GBAState state = TITLE;
	int x = NODRAW;

	while(1) {
		waitForVBlank();

		switch(state) {
		case TITLE:
			drawImage3(0, 0, TITLE_WIDTH, TITLE_HEIGHT, title_data);
			
			while(KEY_DOWN_NOW(BUTTON_START)) {
			}
			while(KEY_DOWN_NOW(BUTTON_A)) {
			}
			state = NODRAW;
			x = NODRAW;
			break;
		
		case NODRAW:
			if(KEY_DOWN_NOW(BUTTON_START)) {
				state = GAME;
			}
			if(KEY_DOWN_NOW(BUTTON_A)) {
				state = TITLE;			
			}
			if (x == GAMEOVER) {
				state = GAMEOVER;			
			}
			if (x == CONGRA) {
				state = CONGRA;
			}
			if (x == TITLE) {
	
				state = TITLE;
			}
			break;

		case GAME:
			
			x = gameInit();

			while(KEY_DOWN_NOW(BUTTON_START)) {
			}
			while(KEY_DOWN_NOW(BUTTON_A)) {
			}
			state = NODRAW;	
			break;	

		case GAMEOVER:
			drawImage3(0, 0, GAMEOVER_WIDTH, GAMEOVER_HEIGHT, gameOver_data);
			drawString(5, 5, "Press A(Z)", BLACK);
			drawString(20, 5, "to TITLE", BLACK);
			while(KEY_DOWN_NOW(BUTTON_START)) {
			}
			while(KEY_DOWN_NOW(BUTTON_A)) {
			}
			state = NODRAW;	
			x = NODRAW;
			break;

		case CONGRA:
			drawImage3(0, 0, CONGRA_WIDTH, CONGRA_HEIGHT, congra_data);
			drawString(5, 5, "Press A(Z) to Home", BLACK);
			while(KEY_DOWN_NOW(BUTTON_START)) {
			}
			while(KEY_DOWN_NOW(BUTTON_A)) {
			}
			state = NODRAW;	
			x = NODRAW;
			break;
			
		}
	}
	return 0;	
}
