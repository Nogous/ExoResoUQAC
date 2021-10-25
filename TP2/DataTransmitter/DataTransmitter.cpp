// DataTransmitter.cpp : définit le point d'entrée de l'application.
//

#include "DataTransmitter.h"
#include "Serializer.h"
#include "framework.h"
#include "Player.h"
using namespace std;

int main()
{/*
	Serializer s = Serializer(10);
	
	char mystring[] = "sltlazonecommentcava";
	s.SerializeData(mystring);
	std::cout << "Buffer contains : " << s.GetBuffer().data() << std::endl;
	
	int myInt = 123456789;
	s.SerializeData(myInt);
	std::cout << "Buffer contains : " << s.GetBuffer().data() << std::endl;

	s.SerializeData(myFloat);
	std::cout << "Buffer contains : " << s.GetBuffer().data() << std::endl;*/

	Player player = Player(200, -9876.5f, Vector3(1.1f, 1.1f, 1.1f), Quaternion());


	Player player2 = Player();
	player2.rotation.w = 2;

	player.armor = 2;
	player.size = Vector3(1.12f, -10.2f, .13f);

	Serializer ser = Serializer();
	player.Write(ser);
	Deserializer deser = Deserializer();
	player2.Read(deser, ser.GetBuffer());

	std::cout << "-------Update-Player1--------" << std::endl;

	player.PrintPlayerData();
	std::cout << "-------Update-Player2--------" << std::endl;

	player2.PrintPlayerData();

	return 0;
}
