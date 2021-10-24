#pragma once

static int Compressor(int i, int min, int max) {

	if (i < min)
		i = min;
	else if (i > max)
		i = max;

	return i - min;
}

static int Compressor(float f, float min, float max, int accuracy) {
	
	if (f < min)
		f = min;
	else if (f > max)
		f = max;

	f -= min;
	f *= accuracy;

	return (int)f;
}

static int Decompressor(int i, int min)
{
	i += min;
	return i;
}

static float Decompressor(int i, float min, int accuracy)
{
	float f = (float)i/accuracy;
	f += min;
	return f;
}