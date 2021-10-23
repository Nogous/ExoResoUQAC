#pragma once

const int MIN_INT = -10;
const int MAX_INT = 300;

static int Compressor(int i) {
	//int maxRange = 300;

	if (i < MIN_INT)
		i = MIN_INT;
	else if (i > MAX_INT)
		i = MAX_INT;

	return i - MIN_INT;
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

static int Decompressor(int i)
{
	i += MIN_INT;
	return i;
}

static float Decompressor(float f)
{
	f += MIN_FLOAT;
	f /= FLOAT_ACCURACY;
	return f;
}