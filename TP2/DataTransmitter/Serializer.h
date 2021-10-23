#pragma once
#include <vector>

class Serializer {

private:
	std::vector<char> buffer;
	size_t position;
public:
	Serializer();
	Serializer(int size);
	void ResizeBuffer(size_t size);

	template <class T>
	void SerializeData(const T data) 
	{
		int dataSize = sizeof(data);
		if (buffer.size() + dataSize > buffer.capacity())
		{
			ResizeBuffer();
			SerializeData(data);
		}
		else
		{
			data.Write(buffer);
		}
	}

	void Write(int data, int min, int max);
	void Write(float data, float min, float max, int accuracy);
	
	std::vector<char> GetBuffer() { return buffer; }
};