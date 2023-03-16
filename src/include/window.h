#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdint>
#include "util.h"

class Window {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	static const uint32_t WINDOW_WIDTH = 1000;
	static const uint32_t WINDOW_HEIGHT = 1000;
	static const uint32_t RENDER_WIDTH = 600;
	static const uint32_t RENDER_HEIGHT = 600;
public:
	Window() {}
	~Window();

	int32_t init();
	void clear();
	void display();
	void set_pixel(uint32_t x, uint32_t y, int32_t color);

	int32_t pixels[RENDER_WIDTH * RENDER_HEIGHT];
};
