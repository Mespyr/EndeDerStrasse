#include "include/texture.h"
#include "include/window.h"
#include "include/util.h"
#include <cstdlib>
#include <cstdint>

int main() {
	init_lib();

	Window window;
	if (window.init() != 0)
		return 1;

	bool quit = false;
	SDL_Event e;
	const uint8_t *kbd_state;
	Texture maurice("assets/maurice.png");

	uint32_t now, last_game_step = SDL_GetTicks();
	float delta_time;

	uint32_t x = 0, y = 0;

	while (!quit) {
		now = SDL_GetTicks();
		kbd_state = SDL_GetKeyboardState(nullptr);

		if (kbd_state[SDL_SCANCODE_W])
			y -= 1;
		else if (kbd_state[SDL_SCANCODE_A])
			x -= 1;
		else if (kbd_state[SDL_SCANCODE_S])
			y += 1;
		else if (kbd_state[SDL_SCANCODE_D])
			x += 1;

		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;

		if(last_game_step < now) {
			delta_time = (now - last_game_step) / 1000.0f;
			window.clear();
			window.render(x, y, maurice);
			window.display();
		}
		else SDL_Delay(1);
		last_game_step = now;
	}

	return 0;
}
