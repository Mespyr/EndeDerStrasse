#include "include/window.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

int32_t Window::init() {
	window = SDL_CreateWindow(
	    "Ende der Straße",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	if (window == nullptr) {
		log_error(std::cout, "SDL_CreateWindow");
		return 1;
	}

	renderer = SDL_CreateRenderer(
	    window,
		-1, SDL_RENDERER_ACCELERATED
	);

	if (window == nullptr) {
		log_error(std::cout, "SDL_CreateRenderer");
		return 1;
	}

	texture = SDL_CreateTexture(
	    renderer,
		SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STREAMING,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	);
	
	return 0;
}

void Window::display() {
	SDL_RenderClear(renderer);

	SDL_UpdateTexture(
	    texture,
		nullptr,
		pixels,
		WINDOW_WIDTH * 4
	);

	SDL_RenderCopyEx(
	    renderer,
		texture,
		nullptr,
		nullptr,
		0.0,
		nullptr,
		SDL_FLIP_NONE
	);

	SDL_RenderPresent(renderer);
}
