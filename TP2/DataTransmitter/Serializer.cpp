#include "Serializer.h"
#include "framework.h"
#include <iostream>

Serializer::Serializer()
{
	position = 0;
	buffer = std::vector<char>(4);
}

Serializer::Serializer(int size)
{
	buffer = std::vector<char>(size);
	position = 0;
}

void Serializer::ResizeBuffer(size_t size)
{
	std::cout << "Resizing Buffer" << std::endl;
	buffer.resize(buffer.size() + size);
	std::cout << "Buffer Size is now : " << buffer.capacity() << std::endl;
}

void Serializer::Write(int data, int min, int max)
{
	size_t sizeMax = std::abs(max - min);

	int compresedData = Compressor(data, min, max);

	char* c;

	if (sizeMax <= UINT8_MAX) {
		uint8_t shortData = compresedData;
		c = (char*)shortData;
		sizeMax = sizeof(shortData);
	}
	else if (sizeMax <= UINT16_MAX) {
		uint16_t shortData = compresedData;
		c = (char*)shortData;
		sizeMax = sizeof(shortData);
	}
	else if (sizeMax <= UINT32_MAX) {
		uint32_t shortData = compresedData;
		c = (char*)shortData;
		sizeMax = sizeof(shortData);
	}

	if (position + sizeMax > buffer.size())
	{
		ResizeBuffer(sizeMax);
	}
	std::memcpy(buffer.data() + position, &c, sizeMax);

	position += sizeMax;
}

void Serializer::Write(float data, float min, float max, int accuracy)
{
	size_t sizeMax = std::abs(max - min);

	int compresedData = Compressor(data, min, max, accuracy);

	char* c;

	if (sizeMax <= UINT8_MAX) {
		uint8_t shortData = compresedData;
		c = (char*)shortData;
		sizeMax = sizeof(shortData);
	}
	else if (sizeMax <= UINT16_MAX) {
		uint16_t shortData = compresedData;
		c = (char*)shortData;
		sizeMax = sizeof(shortData);
	}
	else if (sizeMax <= UINT32_MAX) {
		uint32_t shortData = compresedData;
		c = (char*)shortData;
		sizeMax = sizeof(shortData);
	}

	if (position + sizeMax > buffer.size())
	{
		ResizeBuffer(sizeMax);
	}
	std::memcpy(buffer.data() + position, &c, sizeMax);

	position += sizeMax;
}

void Serializer::Write(Vector3 data, Vector3 min, Vector3 max, int accuracy)
{
	Write(data.x, min.x, max.x, accuracy);
	Write(data.y, min.y, max.y, accuracy);
	Write(data.z, min.z, max.z, accuracy);
}