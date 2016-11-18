#include "myLib.h"

u16 *videoBuffer = (u16 *)0x6000000;


void setPixel(int r, int c, u16 color)
{
	videoBuffer[OFFSET(r, c, 240)] = color;
}

void drawImage3(int row, int col, int width, int height, const u16* image)
{
	for(int r=0; r<height; r++)
	{
		DMA[3].src = image + OFFSET(r, 0, width);
		DMA[3].dst = videoBuffer + OFFSET(r + row, col, 240);
		DMA[3].cnt = width | DMA_ON;
	}
}

void clearImage() {
	volatile u16 color = BLACK;
	DMA[DMA_CHANNEL_3].src = &color;
	DMA[DMA_CHANNEL_3].dst = videoBuffer;
	DMA[DMA_CHANNEL_3].cnt = 240 * 160 | DMA_ON | DMA_SOURCE_FIXED;
}

void delay(int n)
{
	volatile int x = 0;
	for(int i=0; i<n*10000; i++)
	{
		x++;
	}
}

void waitForVBlank()
{
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}


void drawChar(int row, int col, char ch, u16 color) {
	for (int r = 0; r < 8; r++) {

		for (int c = 0; c < 6; c++) {
			if (fontdata_6x8[OFFSET(r,c,6) + 48*ch]) {
				setPixel(r+row, c+col, color);	
			}
		}
	}
}

void drawString(int row, int col, char *str, u16 color) {
	while(*str) {
		drawChar(row, col, *str++, color);
		col +=6;
	}

}

void drawRect(int r, int c, int width, int height, u16 color) {
	for (int x = 0; x < height; x++) {
		DMA[3].src = &color;
		DMA[3].dst = &videoBuffer[OFFSET(r+x, c, 240)];
		DMA[3].cnt = (width) | DMA_SOURCE_FIXED | DMA_ON;
		
	}
	
}






































