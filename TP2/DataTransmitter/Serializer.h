#include <vector>

class Serializer {

private:
	std::vector<char> buffer;
	int position;
public:
	Serializer();
	Serializer(int size);
	void ResizeBuffer();

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
			std::vector<char>::iterator it;
			it = buffer.begin();
			buffer.insert(it + position, data);
		}
	}
	std::vector<char> GetBuffer() { return buffer; }
};