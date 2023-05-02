#include "include/game_state.h"
#include <cmath>
#include <cstdint>

GameState::~GameState() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

int32_t GameState::init() {
	window = SDL_CreateWindow(
	    "Ende der Straße",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH * 2,
		WINDOW_HEIGHT * 2,
		SDL_WINDOW_SHOWN
	);

	if (window == nullptr) {
		log_error(std::cout, "SDL_CreateWindow");
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

	player.x = 70;
	player.y = -110;
	player.z = 40;
	player.angle = 0;
	player.look = 0;
	
	return 0;
}

void GameState::clear() {
	memset(pixels, 20, sizeof(pixels));
}

void GameState::update(float_t delta_time) {
	kbd_state = SDL_GetKeyboardState(nullptr);

	int32_t dx = math._sin[player.angle] * 800 * delta_time;
	int32_t dy = math._cos[player.angle] * 800 * delta_time;

	if (kbd_state[SDL_SCANCODE_W]) {
		// forward
		player.x += dx; player.y += dy;
	}
	if (kbd_state[SDL_SCANCODE_A]) {
		// strafe left
		player.x -= dy; player.y += dx;
	}
	if (kbd_state[SDL_SCANCODE_S]) {
		// backwards
		player.x -= dx; player.y -= dy;
	}
	if (kbd_state[SDL_SCANCODE_D]) {
		// strafe right 
		player.x += dy; player.y -= dx;
	}
	if (kbd_state[SDL_SCANCODE_LEFT]) {
		// turn left
		player.angle -= 1;
		if (player.angle < 0) player.angle += 360;
	}
	if (kbd_state[SDL_SCANCODE_RIGHT]) {
		// turn left
		player.angle += 1;
		if (player.angle > 359) player.angle -= 360;
	}
	if (kbd_state[SDL_SCANCODE_UP]) {
		// go up
		player.z += 10;
	}
	if (kbd_state[SDL_SCANCODE_DOWN]) {
		// go down
		player.z -= 10;
	}

	if (kbd_state[SDL_SCANCODE_RETURN]) {
		std::cout << "x: " << player.x << " y: " << player.y << " z: " << player.z << std::endl;
		std::cout << "angle: " << player.angle << " look: " << player.look << std::endl;
	}

	// basic rendering
	int32_t world_x[4], world_y[4], world_z[4];
	float_t cosine = math._cos[player.angle], sine = math._sin[player.angle];

	// offset to player
	int32_t x1 = 40 - player.x, y1 = 10 - player.y;
	int32_t x2 = 40 - player.x, y2 = 290 - player.y;

	// world x
	world_x[0] = x1 * cosine - y1 * sine;
	world_x[1] = x2 * cosine - y2 * sine;
	world_x[2] = world_x[0];
	world_x[3] = world_x[1];

	// world y
	world_y[0] = y1 * cosine + x1 * sine;
	world_y[1] = y2 * cosine + x2 * sine;
	world_y[2] = world_y[0];
	world_y[3] = world_y[1];

	// world z
	world_z[0] = 0 - player.z;
	world_z[1] = 0 - player.z;
	world_z[2] = world_z[0] + 40;
	world_z[3] = world_z[1] + 40;

	// screen x and y
	world_x[0] = world_x[0] * 200 / world_y[0] + (WINDOW_WIDTH / 2);
	world_y[0] = world_z[0] * 200 / world_y[0] + (WINDOW_WIDTH / 2);

	world_x[1] = world_x[1] * 200 / world_y[1] + (WINDOW_WIDTH / 2);
	world_y[1] = world_z[1] * 200 / world_y[1] + (WINDOW_WIDTH / 2);

	world_x[2] = world_x[2] * 200 / world_y[2] + (WINDOW_WIDTH / 2);
	world_y[2] = world_z[2] * 200 / world_y[2] + (WINDOW_WIDTH / 2);

	world_x[3] = world_x[3] * 200 / world_y[3] + (WINDOW_WIDTH / 2);
	world_y[3] = world_z[3] * 200 / world_y[3] + (WINDOW_WIDTH / 2);

	int32_t delta_yb = world_y[1] - world_y[0];
	int32_t delta_yt = world_y[3] - world_y[2];
	int32_t delta_x = world_x[1] - world_x[0];
	if (delta_x == 0) delta_x = 1;

	int32_t init_x = world_x[0];
	for (int32_t x = init_x; x < world_x[1]; x++) {
		int32_t y1 = delta_yb * (x - init_x + 0.5) / delta_x + world_y[0];
		int32_t y2 = delta_yt * (x - init_x + 0.5) / delta_x + world_y[2];
		for (int32_t y = y1; y < y2; y++)
			set_pixel(x, y, 0xFFFFFFFF);
	}
}

void GameState::display() {
	SDL_RenderClear(renderer);
	SDL_UpdateTexture(texture, nullptr, pixels, WINDOW_WIDTH * 4);
	SDL_RenderCopyEx(renderer, texture, nullptr, nullptr, 0.0, nullptr, SDL_FLIP_NONE);
	SDL_RenderPresent(renderer);
}

void GameState::set_pixel(uint32_t x, uint32_t y, int32_t color) {
	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
		pixels[(y * WINDOW_WIDTH) + x] = color;
}
