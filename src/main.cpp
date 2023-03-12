#include "include/window.h"

int main() {
	Window window;
	if (window.init() != 0)
		return 1;

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;

		// hardcode sum jizz
		memset(window.pixels, 0, sizeof(window.pixels));
		window.pixels[(10 * window.WINDOW_WIDTH) + 5] = 0xFFAAFFFF;
		window.pixels[(10 * window.WINDOW_WIDTH) + 6] = 0xFFAAFFFF;
		window.pixels[(10 * window.WINDOW_WIDTH) + 7] = 0xFFAAFFFF;
		window.pixels[(10 * window.WINDOW_WIDTH) + 8] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 5] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 6] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 7] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 8] = 0xFFAAFFFF;

		window.pixels[(10 * window.WINDOW_WIDTH) + 15] = 0xFFAAFFFF;
		window.pixels[(10 * window.WINDOW_WIDTH) + 16] = 0xFFAAFFFF;
		window.pixels[(10 * window.WINDOW_WIDTH) + 17] = 0xFFAAFFFF;
		window.pixels[(10 * window.WINDOW_WIDTH) + 18] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 15] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 16] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 17] = 0xFFAAFFFF;
		window.pixels[(11 * window.WINDOW_WIDTH) + 18] = 0xFFAAFFFF;

		window.pixels[(15 * window.WINDOW_WIDTH) + 7] =  0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 8] =  0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 9] =  0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 10] = 0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 11] = 0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 12] = 0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 13] = 0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 14] = 0xFFAAFFFF;
		window.pixels[(15 * window.WINDOW_WIDTH) + 15] = 0xFFAAFFFF;

		window.pixels[(16 * window.WINDOW_WIDTH) + 7] =  0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 8] =  0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 9] =  0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 10] = 0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 11] = 0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 12] = 0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 13] = 0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 14] = 0xFFAAFFFF;
		window.pixels[(16 * window.WINDOW_WIDTH) + 15] = 0xFFAAFFFF;
		
		window.display();
		SDL_Delay(1);
	}

	return 0;
}
