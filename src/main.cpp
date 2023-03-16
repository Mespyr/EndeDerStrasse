#include "include/window.h"
#include "include/util.h"
#include <cstdlib>
#include <cstdint>

#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"


int main() {
	init_lib();

	Window window;
	if (window.init() != 0)
		return 1;

	bool quit = false;
	SDL_Event e;
	//const uint8_t *kbd_state;

	uint32_t now, last_game_step = SDL_GetTicks();
	float delta_time;

	int32_t width, height, channels;
	uint8_t* image_data = stbi_load("assets/maurice.png", &width, &height, &channels, 0);
	uint32_t size = width * height * channels;

	int32_t x = 0, y = 0;
	uint8_t alpha;
	uint32_t pixel;
	
	while (!quit) {
		now = SDL_GetTicks();

		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;

		if(last_game_step < now) {
			delta_time = (now - last_game_step) / 1000.0f;
			window.clear();

			x = 0;
			y = 0;
			for (uint32_t pixel_start = 0; pixel_start < size; pixel_start += channels) {
				alpha = image_data[pixel_start+3];
				if (alpha > 0) {
					pixel = (alpha * 16 * 16 * 16 * 16 * 16 * 16)
						+ (image_data[pixel_start+2] * 16 * 16 * 16 * 16)
						+ (image_data[pixel_start+1] * 16 * 16)
						+ image_data[pixel_start];
					window.set_pixel(x, y, pixel);
				}

				if (x == width-1) {
					x = 0;
					y += 1;
				} else x++;
			}

			window.display();
		}
		else SDL_Delay(1);
		last_game_step = now;
	}

	stbi_image_free(image_data);
	return 0;
}
