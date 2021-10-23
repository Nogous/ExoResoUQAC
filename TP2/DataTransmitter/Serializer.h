#include <vector>

class Serializer {

private:
	std::vector<int> buffer;
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
			data.Write(buffer);
		}
	}

	void Write(int data);
	void Write(float data);
	
	std::vector<int> GetBuffer() { return buffer; }
};