# What is this?
A collection of classpad2 c and asm code I wanna use more frequently in my projects

# What does this contain?
For now just a function that can blit an image onto the classpad's screen without the usage of the VRAM.
This is faster than the usually seen method of using setPixel to copy stuff into VRAM and then calling LCD_Refresh
because you only have to send the pixels you actually wanna update and skip everything outside of that rectangle and
because you save the writing operations that are usually required to send pixel to VRAM. This not only gives you the
VRAM back as free to use RAM that doesnt even need dynamic allocation to be used, but also makes blitting the 
to the screen about twice as fast as before. The downside is that there is no backbuffer from which you can get the
pixels on the screen and you also have to overwrite anything within the rectangle you specify. This makes things
like drawing a triangle to s acreen harder, but nothing stops you from using this to update the screen using a
frgment of VRAM rather than all of it. This way you may keep your backbuffer and still squeeze some performance
out of the classpad.
