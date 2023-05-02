#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>
#include <cstdint>
#include "util.h"
#include "math.h"
#include "player.h"

class GameState {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	static const uint32_t WINDOW_WIDTH = 600;
	static const uint32_t WINDOW_HEIGHT = 400;
	int32_t pixels[WINDOW_WIDTH * WINDOW_HEIGHT];

	Math math;
	Player player;

	const uint8_t *kbd_state;
public:
	GameState() {}
	~GameState();

	int32_t init();
	void clear();
	void update(float_t delta_time);
	void display();
	void set_pixel(uint32_t x, uint32_t y, int32_t color);
};
