# How do I use this?
Run make to compile everything to a .bin file.
Copy test.bin into your classpad's root folder (\\fls0\\).
Use left and right to scroll.

# How does this work?
It's a custom screen refresh function that offsets from where it gets its pixeldata a little when drawing.
This is way faster than doing this by first writing everything to VRAM and then to the screen (saves 50% of write operations).
