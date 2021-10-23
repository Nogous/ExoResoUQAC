#include "Player.h"

void Player::Write(Serializer& serializer)
{
	serializer.Write(classId);
	serializer.Write(life);
	serializer.Write(weight);
}

void Player::Read(Serializer& serializer)
{
}

int Player::GetDataSize()
{
	return 100;
}
