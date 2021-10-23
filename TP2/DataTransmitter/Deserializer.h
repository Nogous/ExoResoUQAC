#pragma once
#include <vector>

class Deserializer
{
private:
	int position;

public:
	Deserializer();
	~Deserializer();

	int ReadInt(std::vector<int> buffer);
	float ReadFloat(std::vector<int> buffer);

};