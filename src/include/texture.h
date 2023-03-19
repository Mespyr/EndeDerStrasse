#pragma once

#include <cstdint>
#include <string>
#include "stb_image.h"

class Texture {
public:
	Texture(std::string path);

	int32_t width, height, channels;
	uint32_t* data;
};
