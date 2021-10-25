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

float Deserializer::ReadFloat(std::vector<char> buffer, float min, float max, int accuracy)
{
	size_t sizeMax = std::abs(max - min);

	if (sizeMax <= UINT8_MAX) {
		sizeMax = sizeof(uint8_t);
		unsigned char c[sizeof(uint8_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint8_t*)c), min, accuracy);
	}
	else if (sizeMax <= UINT16_MAX) {
		sizeMax = sizeof(uint16_t);
		unsigned char c[sizeof(uint16_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint16_t*)c), min, accuracy);
	}
	else if (sizeMax <= UINT32_MAX) {
		sizeMax = sizeof(uint32_t);
		unsigned char c[sizeof(uint32_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint32_t*)c), min, accuracy);
	}
	return -1;
}

Vector3 Deserializer::ReadVector3(std::vector<char> buffer, Vector3 min, Vector3 max, int accuracy)
{
	float x = ReadFloat(buffer, min.x, max.x, accuracy);
	float y = ReadFloat(buffer, min.y, max.y, accuracy);
	float z = ReadFloat(buffer, min.z, max.z, accuracy);
	return Vector3(x,y,z);
}
