#pragma once
extern "C" void refresh(uint16_t* ptr, int width, int height);
// I copied this from Diddyholz, but he copied it from me, so its fine
void prepare_lcd(int startx, int starty, int Width, int Height) 
{
  ((void(*)(int, int, int, int))0x80038068)(startx, Width - 1, starty, Height - 1);
  ((void(*)(int))0x80038040)(0x2c);
}