// main.cpp

#include <iostream>

#include "engine/IOEngine.hpp"
#define PORT 4444
#define IP "127.0.0.1"

int main()
{

	IOEngine ioEngine;;

	std::cout << "Options:\n";
	std::cout << "\t1. Send message\n";
	std::cout << "\t2 Listen for message\n";
	std::cout << "Choice: ";

	int userInputChoice;
	std::cin >> userInputChoice;
	std::string userInputMessage;

	switch (userInputChoice) {
	case 1:
		while (true) {
			ioEngine.connect(IP, PORT);
			std::cout << "\nType message: ";
			std::cin >> userInputMessage;
			ioEngine.sendMessage(userInputMessage);
		}
	case 2:
		while (true) {
			std::cout << "\nWaiting for message...\n";
			ioEngine.listenForMessages(targetPort);
		}
	}

	return 0;
}


