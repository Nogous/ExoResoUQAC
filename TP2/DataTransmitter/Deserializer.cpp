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
	size_t sizeMax = std::abs(max - min);
	if (sizeMax <= UINT8_MAX) {
		sizeMax = sizeof(uint8_t);
		unsigned char c[sizeof(uint8_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint8_t*)c), min);
	}
	else if (sizeMax <= UINT16_MAX) {
		sizeMax = sizeof(uint16_t);
		unsigned char c[sizeof(uint16_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint16_t*)c), min);
	}
	else if (sizeMax <= UINT32_MAX) {
		sizeMax = sizeof(uint32_t);
		unsigned char c[sizeof(uint32_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint32_t*)c), min);
	}

	return-1;
}

//template <class T>
//int Deserializer::ReadInt(std::vector<char> buffer, const T dataType, int min, int max)
//{
//	const size_t sizeMax = sizeof(T);
//	unsigned char c[sizeMax];
//	std::memcpy(c, buffer.data() + position, sizeMax);
//
//	position += sizeof(T);
//	return Decompressor(*(int*)c, min);
//}

float Deserializer::ReadFloat(std::vector<char> buffer, float min, float max, int accuracy)
{
	const size_t sizeMax = 4;
	int activePos = position;
	position += sizeof(max - min);
	unsigned char c[sizeMax];
	std::memcpy(c, buffer.data() + activePos, sizeMax);

	return Decompressor(*(int*)c, min, accuracy);
}