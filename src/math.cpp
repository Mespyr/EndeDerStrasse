#include "include/math.h"

Math::Math() {
	for (int x = 0; x < 360; x++) {
		_cos[x] = cos(x * PI / 180.0);
		_sin[x] = sin(x * PI / 180.0);
	}
}
