#include "Deserializer.h"
#include "framework.h"


Deserializer::Deserializer()
{
	position = 0;
}

Deserializer::~Deserializer()
{
}

int Deserializer::ReadInt(std::vector<char> buffer, int min, int max)
{
	const size_t sizeMax = 4;
	int activePos = position;
	position += sizeof(max - min);
	unsigned char c[sizeMax];
	std::memcpy(c, buffer.data() + activePos, sizeMax);

	return Decompressor(*(int*)c, min);
}

float Deserializer::ReadFloat(std::vector<char> buffer, float min, float max, int accuracy)
{
	int activePos = position;
	position += sizeof(max * accuracy - min * accuracy);
	return Decompressor((float)*(buffer.begin() +activePos), min, accuracy);
}