#include "Deserializer.h"
#include "framework.h"


Deserializer::Deserializer()
{
	position = 0;
}

Deserializer::~Deserializer()
{
}

int Deserializer::ReadInt(std::vector<int> buffer)
{
	position++;
	return Decompressor((int)*(buffer.begin() + position));
}

float Deserializer::ReadFloat(std::vector<int> buffer)
{
	position++;
	return Decompressor((float)*(buffer.begin() +position));
}