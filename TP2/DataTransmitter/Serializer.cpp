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
	size_t sizeMax = sizeof(max - min);
	char c = (char)Compressor(data, min, max);
	if (position + sizeMax > buffer.size())
	{
		ResizeBuffer(sizeMax);
	}
	std::memcpy(buffer.data() + position, &c, sizeMax);

	position += sizeMax;
}

void Serializer::Write(float data, float min, float max, int accuracy)
{
	size_t sizeMax = sizeof((max * accuracy) - (min * accuracy));
	char c = (char)Compressor(data, min, max);
	if (position + sizeMax > buffer.size())
	{
		ResizeBuffer(sizeMax);
	}
	std::memcpy(buffer.data() + position, &c, sizeMax);

	position += sizeMax;
}