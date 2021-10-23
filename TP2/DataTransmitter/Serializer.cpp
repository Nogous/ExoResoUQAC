#include "Serializer.h"
#include "framework.h"
#include <iostream>

Serializer::Serializer()
{
	position = 0;
	buffer = std::vector<int>();
	buffer.reserve(128);
}

Serializer::Serializer(int size)
{
	position = 0;
	buffer = std::vector<int>();
	buffer.reserve(size);
}

void Serializer::ResizeBuffer()
{
	std::cout << "Resizing Buffer" << std::endl;
	buffer.resize(buffer.size() * 2);
	std::cout << "Buffer Size is now : " << buffer.capacity() << std::endl;
}

void Serializer::Write(int data)
{
	std::vector<int>::iterator it = buffer.begin();
	buffer.insert(it + position, Compressor(data));
	position ++;
}

void Serializer::Write(float data)
{
	std::vector<int>::iterator it = buffer.begin();
	buffer.insert(it + position, Compressor(data));
	position++;
}
