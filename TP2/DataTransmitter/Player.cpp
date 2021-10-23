#include "Player.h"

void Player::Write(Serializer& serializer)
{
	//serializer.Write(classId);
	serializer.Write(life, MIN_LIFE, MAX_LIFE);
	serializer.Write(money, MIN_MONEY,MAX_MONEY,ACCURACY_MONEY);
}

void Player::Read(Deserializer& deserializer, std::vector<char> buffer)
{
	life = deserializer.ReadInt(buffer, MIN_LIFE, MAX_LIFE);
	money = deserializer.ReadFloat(buffer, MIN_MONEY, MAX_MONEY, ACCURACY_MONEY);
}

int Player::GetDataSize()
{
	return 100;
}
