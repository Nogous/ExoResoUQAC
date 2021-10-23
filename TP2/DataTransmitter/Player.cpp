#include "Player.h"

void Player::Write(Serializer& serializer)
{
	serializer.Write(classId);
	serializer.Write(life);
	serializer.Write(weight);
}

void Player::Read(Deserializer& deserializer, std::vector<int> buffer)
{
	life = deserializer.ReadInt(buffer);
	weight = deserializer.ReadFloat(buffer);
}

int Player::GetDataSize()
{
	return 100;
}
