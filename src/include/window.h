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

	static const int WINDOW_WIDTH = 1000;
	static const int WINDOW_HEIGHT = 800;
	int32_t pixels[WINDOW_WIDTH * WINDOW_HEIGHT];
};
