#pragma once
#include <vector>

class Deserializer
{
private:
	size_t position;

public:
	Deserializer();
	~Deserializer();

	int ReadInt(std::vector<char> buffer, int min, int max);
	/*template <class T>
	int ReadInt(std::vector<char> buffer, const T dataType, int min, int max);*/

	float ReadFloat(std::vector<char> buffer, float min, float max, int accuracy);

};