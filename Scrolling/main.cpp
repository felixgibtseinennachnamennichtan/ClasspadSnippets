#include <appdef.hpp>
#include <sdk/calc/calc.hpp>
#include <sdk/os/debug.hpp>
#include <sdk/os/file.hpp>
#include <sdk/os/mem.hpp>
#include "refresh.h"
#include <sdk/os/input.hpp>
#include "config.h"
APP_NAME("Scrolling")
APP_DESCRIPTION("Allows you to scroll through a texture using custom screen refreshs")
APP_AUTHOR("Felix")
APP_VERSION("1.0.0")

extern "C"
void main() {
	calcInit();
	int fd = open("\\fls0\\test.bin", OPEN_READ); //Just an array of 565 color values
	uint16_t* file = (uint16_t*)malloc(2*IMAGEWIDTH*IMAGEHEIGHT);
	int success = read(fd, file, IMAGEWIDTH*IMAGEHEIGHT*2);
	close(fd);
	Debug_PrintNumberHex_Dword(fd, 0,10);
	LCD_Refresh();
	bool quit = 0;
	int scrollx = 0; int scrolly = 0;
	while(!quit){
		uint32_t key1 = 0;
		uint32_t key2 = 0;
		getKey(&key1, &key2);
		if(testKey(key1, key2, KEY_LEFT)){
			scrollx-=XSCROLLSTEP;
			if (scrollx<0){scrollx=0;}
		}
		if(testKey(key1, key2, KEY_RIGHT)){
			scrollx+=XSCROLLSTEP;
			if (scrollx>MAXSCROLLX){scrollx=MAXSCROLLX;}
		}
		if(testKey(key1, key2, KEY_CLEAR)){
			quit=true;
		}
		prepare_lcd(XSTART,YSTART,XEND, YEND);
		refresh(&file[scrollx], SCREENWIDTH, SCREENHEIGHT, FINISHROW*2);
		//finalptr=&finalptr[scrollx]; 
		//finalptr=&finalptr[scrolly*IMAGEWIDTH];

		
	}
	free(file);
}
