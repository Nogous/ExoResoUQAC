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

	Player player = Player(5400, 3.5f);


	Player player2 = Player();

	player.PrintPlayerData();
	player.position = Vector3(1, 3.456f, .5437234f);
	player.size = Vector3(1, 3.456f, .5437234f);
	player2.PrintPlayerData();
	std::cout << "---------------------------" << std::endl;

	Serializer ser = Serializer(1);
	player.Write(ser);
	Deserializer deser = Deserializer();
	player2.Read(deser, ser.GetBuffer());


	player.PrintPlayerData();
	player2.PrintPlayerData();

	return 0;
}
