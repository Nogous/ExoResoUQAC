#pragma once

static int Compressor(int i) {
	int min = 0;
	int max = 300;
	int maxRange = 300;

	if (i < min)
		i = min;
	else if (i > max)
		i = max;

	return i;
}

const int MIN_FLOAT = -9999;
const int MAX_FLOAT = 9999;
const int FLOAT_ACCURACY = 100;

static int Compressor(float f) {
	
	f *= FLOAT_ACCURACY;
	if (f < MIN_FLOAT)
		f = MIN_FLOAT;
	else if (f > MAX_FLOAT)
		f = MAX_FLOAT;

	f -= MIN_FLOAT;
	
	return (int)f;
}

static float Decompressor(float f)
{
	f += MIN_FLOAT;
	f /= FLOAT_ACCURACY;
	return f;
}