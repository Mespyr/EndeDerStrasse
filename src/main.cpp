#include "include/window.h"
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
#include <cstdint>

int main() {
	Window window;
	if (window.init() != 0)
		return 1;

	bool quit = false;
	SDL_Event e;
	const uint8_t *kbd_state;

	int x = 5, y = 10;

	while (!quit) {
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;

		kbd_state = SDL_GetKeyboardState(nullptr);
		if (kbd_state[SDL_SCANCODE_W])
			y -= 1;
		else if (kbd_state[SDL_SCANCODE_A])
			x -= 1;
		else if (kbd_state[SDL_SCANCODE_S])
			y += 1;
		else if (kbd_state[SDL_SCANCODE_D])
			x += 1;

		// hardcode sum jizz
		memset(window.pixels, 0, sizeof(window.pixels));

		window.set_pixel(x,   y,   0xFFAAFFBB);
		window.set_pixel(x+1, y,   0xFFAAFFBB);
		window.set_pixel(x+2, y,   0xFFAAFFBB);
		window.set_pixel(x+3, y,   0xFFAAFFBB);
		window.set_pixel(x,   y+1, 0xFFAAFFBB);
		window.set_pixel(x+1, y+1, 0xFFAAFFBB);
		window.set_pixel(x+2, y+1, 0xFFAAFFBB);
		window.set_pixel(x+3, y+1, 0xFFAAFFBB);

		window.set_pixel(x+10, y,   0xFFAAFFBB);
		window.set_pixel(x+11, y,   0xFFAAFFBB);
		window.set_pixel(x+12, y,   0xFFAAFFBB);
		window.set_pixel(x+13, y,   0xFFAAFFBB);
		window.set_pixel(x+10, y+1, 0xFFAAFFBB);
        window.set_pixel(x+11, y+1, 0xFFAAFFBB);		
		window.set_pixel(x+12, y+1, 0xFFAAFFBB);
        window.set_pixel(x+13, y+1, 0xFFAAFFBB);

		window.set_pixel(x+2,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+3,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+4,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+5,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+6,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+7,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+8,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+9,  y+5, 0xFFAAFFBB);
		window.set_pixel(x+10, y+5, 0xFFAAFFBB);

		window.set_pixel(x+2,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+3,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+4,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+5,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+6,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+7,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+8,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+9,  y+6, 0xFFAAFFBB);
		window.set_pixel(x+10, y+6, 0xFFAAFFBB);
		
		window.display();
	}

	return 0;
}
