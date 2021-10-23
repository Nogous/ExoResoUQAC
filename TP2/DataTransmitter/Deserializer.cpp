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
	return Decompressor((int)*(buffer.begin() + position), min);
	position += sizeof(max-min);
}

float Deserializer::ReadFloat(std::vector<char> buffer, float min, float max, int accuracy)
{
	return Decompressor((float)*(buffer.begin() +position), min, accuracy);
	position += sizeof(max*accuracy - min*accuracy);
}