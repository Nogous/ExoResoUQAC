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
	size_t sizeMax = std::abs(max * accuracy - min * accuracy);

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
	else if (sizeMax <= UINT64_MAX) {
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
	Write((float)data.x, min.x, max.x, accuracy);
	Write((float)data.y, min.y, max.y, accuracy);
	Write((float)data.z, min.z, max.z, accuracy);
}

void Serializer::Write(Quaternion data)
{
	int maxIndex;
	float maxValue = -2;

	for (int i = 0; i < 4; i++)
	{
		float element = data.x;
		switch (i)
		{
		case 1:
			element = data.y;
			break;
		case 2:
			element = data.z;
			break;
		case 3:
			element = data.w;
			break;
		}
		float abs = std::abs(element);
		if (abs > maxValue)
		{
			switch (i)
			{
			case 0:
				maxIndex = 0;
				break;
			case 1:
				maxIndex = 1;
				break;
			case 2:
				maxIndex = 2;
				break;
			case 3:
				maxIndex = 3;
				break;
			}
			maxValue = abs;
		}
	}

	Write(maxIndex, 0, 3);

	switch (maxIndex)
	{
	case 0:
		Write(data.y, -0.707, 0.707, 1000);
		Write(data.z, -0.707, 0.707, 1000);
		Write(data.w, -0.707, 0.707, 1000);
		break;
	case 1:
		Write(data.x, -0.707, 0.707, 1000);
		Write(data.z, -0.707, 0.707, 1000);
		Write(data.w, -0.707, 0.707, 1000);
		break;
	case 2:
		Write(data.x, -0.707, 0.707, 1000);
		Write(data.y, -0.707, 0.707, 1000);
		Write(data.w, -0.707, 0.707, 1000);
		break;
	case 3:
		Write(data.x, -0.707, 0.707, 1000);
		Write(data.y, -0.707, 0.707, 1000);
		Write(data.z, -0.707, 0.707, 1000);
		break;
	}
}