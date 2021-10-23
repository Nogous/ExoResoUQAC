#include "Serializer.h"
#include "Deserializer.h"

class Player {

private:
	const int MIN_LIFE = 0;
	const int MAX_LIFE = 300;

	const float MIN_MONEY = -99999.99f;
	const float MAX_MONEY =  99999.99f;
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