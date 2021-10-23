#include "Serializer.h"
#include "Deserializer.h"

class Player {

private:
	const int MIN_LIFE = -10;
	const int MAX_LIFE = 30000;

	const float MIN_MONEY = -100.10f;
	const float MAX_MONEY =  200.20f;
	const int ACCURACY_MONEY = 100;

public :
	Player(int life, float money) : life(life), money(money) {}
	Player() = default;
	~Player() = default;

	int classId = 11;
	int life;
	float money;

	void Write(Serializer& serializer);
	void Read(Deserializer& deserializer, std::vector<char> buffer);
	int GetDataSize();
};