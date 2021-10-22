#pragma once

static char* Compressor(int i) {
	int min = 0;
	int max = 300;
	int maxRange = 300;

	if (i < min)
		i = min;
	else if (i > max)
		i = max;
}