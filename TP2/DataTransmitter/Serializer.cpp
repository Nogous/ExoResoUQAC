#include "Serializer.h"
#include <iostream>

Serializer::Serializer()
{
	position = 0;
	buffer = std::vector<char>();
	buffer.reserve(128);
}

Serializer::Serializer(int size)
{
	position = 0;
	buffer = std::vector<char>();
	buffer.reserve(size);
}

void Serializer::ResizeBuffer()
{
	std::cout << "Resizing Buffer" << std::endl;
	buffer.resize(buffer.size() * 2);
	std::cout << "Buffer Size is now : " << buffer.capacity() << std::endl;
}