#include "Serializer.h"

class Player {

public :
	Player(int life, float weight) : life(life), weight(weight) {}
	Player() = default;
	~Player() = default;

	int classId = 11;
	int life;
	float weight;

	void Write(Serializer& serializer);
	void Read(Serializer& serializer);
	int GetDataSize();
};