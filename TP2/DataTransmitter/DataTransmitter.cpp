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

	std::cout << player.life << std::endl;
	std::cout << player.money << std::endl;
	std::cout << player2.life << std::endl;
	std::cout << player2.money << std::endl;
	std::cout << "---------------------------" << std::endl;

	Serializer ser = Serializer(1);
	player.Write(ser);
	Deserializer deser = Deserializer();
	player2.Read(deser, ser.GetBuffer());

	std::cout << player.life << std::endl;
	std::cout << player.money << std::endl;
	std::cout << player2.life << std::endl;
	std::cout << player2.money << std::endl;

	//float myFloat = 1.23456f;
	//int myInt = 4000;
	//std::cout << "Compressed float : " << Compressor(myFloat) << std::endl;
	//std::cout << "Decompressed float : " << Decompressor(Compressor(myFloat)) << std::endl;
	//std::cout << Compressor(myInt) << std::endl;
	return 0;
}
