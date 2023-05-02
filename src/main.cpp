#include "include/game_state.h"
#include "include/util.h"
#include <cstdlib>
#include <cstdint>

int main() {
	init_lib();

	GameState game;
	if (game.init() != 0)
		return 1;

	bool quit = false;
	SDL_Event e;

	uint32_t now, last_game_step = SDL_GetTicks();
	float delta_time;

	while (!quit) {
		now = SDL_GetTicks();

		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;

		if(last_game_step < now) {
			delta_time = (now - last_game_step) / 1000.0f;
			game.clear();
			game.update(delta_time);
			game.display();
		}
		else SDL_Delay(1);
		last_game_step = now;
	}

	return 0;
}
