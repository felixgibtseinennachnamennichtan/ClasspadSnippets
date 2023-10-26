#include <appdef.hpp>
#include <sdk/calc/calc.hpp>
#include <sdk/os/debug.hpp>
#include <sdk/os/file.hpp>
#include <sdk/os/mem.hpp>
#include "refresh.h"
#define WIDTH 100
#define HEIGHT 100
/*
	To use this with your own project just copy "refresh.s" and "refresh.h" into your directory and include refresh.h
 */
APP_NAME("Imagethingy")
APP_DESCRIPTION("Reads a 100x100 texture from flash and blits it onto the screen quickly")
APP_AUTHOR("Felix")
APP_VERSION("1.0.0")

extern "C"
void main() {
	calcInit();
	int fd = open("\\fls0\\test.bin", OPEN_READ); //Just an array of 565 color values
	uint16_t* file = (uint16_t*)malloc(2*WIDTH*HEIGHT);
	read(fd, file, WIDTH*HEIGHT*2);
	prepare_lcd(5,5,5+WIDTH, 5+HEIGHT); //required before every refresh
	refresh(file, WIDTH, HEIGHT); //refreshes the screen
	close(fd);
	Debug_WaitKey();
	free(file);
	calcEnd(); 	//restores the old screen, but it's not really necessary bc as soon as LCD_Refresh gets called the texture's gone anyway
				//The texture isnt stored anywhere in VRAM and thus just vanishes without a trace
}
