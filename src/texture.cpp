#define STB_IMAGE_IMPLEMENTATION
#include "include/texture.h"

Texture::Texture(std::string path) {
	uint8_t* image_data = stbi_load(path.c_str(), &width, &height, &channels, 0);
	data = (uint32_t*) malloc(width * height * sizeof(uint32_t));

	uint32_t pixel_start = 0;
	for (int32_t p = 0; p < width * height; p++) {
		data[p] = (image_data[pixel_start+3]* 16 * 16 * 16 * 16 * 16 * 16)
			+ (image_data[pixel_start+2] * 16 * 16 * 16 * 16)
			+ (image_data[pixel_start+1] * 16 * 16)
			+ image_data[pixel_start];
		pixel_start += channels;
	}
	stbi_image_free(image_data);
}
