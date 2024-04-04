# What is this?
A collection of classpad2 c and asm code I wanna use more frequently in my projects

# What does this contain?
- A function, that can blit an image onto the classpad's screen without the usage of the VRAM
- A function, that can scroll an image on the x axis without using VRAM
- A function, that can print a string to the screen without using VRAM.

# Why should I use this?
This is faster than the more common method of using setPixel to copy stuff into VRAM and then calling LCD_Refresh,
because you only have to send the pixels you actually wanna update and skip everything outside of that rectangle and
 you save the writing operations that are usually required to send pixels to VRAM. This not only gives you the
VRAM back as free to use RAM that doesnt even need malloc and free to be used, but also makes writing an image to the screen about twice as fast as before.
The downside is that there is no backbuffer from which you can get the
pixels, which are displayed on the screen and you also have to overwrite anything within the rectangle you specify. So if you wanted to for example display multiple polygons, that overlap each otehr to the screen, then iits propably better to go with the traditional approach to keep vram as a buffer that stores those pixels before updating the screen.
