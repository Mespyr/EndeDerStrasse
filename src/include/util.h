#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdint>
#include <string>

int32_t init_lib();
void log_error(std::ostream& os, const std::string &msg);
