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
public:
	Window() {}
	~Window();

	int32_t init();
	void display();
	void set_pixel(uint32_t x, uint32_t y, int32_t color);

	static const uint32_t WINDOW_WIDTH = 1000;
	static const uint32_t WINDOW_HEIGHT = 800;
	int32_t pixels[WINDOW_WIDTH * WINDOW_HEIGHT];
};
