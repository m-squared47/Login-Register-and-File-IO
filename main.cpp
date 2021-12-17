#include <iostream>
#include <fstream>
#include <string>

bool loggedIn() {
	std::string username, password, un, pw;

	//prompt user
	std::cout << "Enter Username: ";
	std::cin >> username;
	std::cout << "Enter Password: ";
	std::cin >> password;

	//read file
	std::ifstream read("Login-Register\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	//check login attempt
	if (un == username && pw == password) {
		return true;
	}

	return false;
}

int main() {
	int choice;

	//prompt user
	std::cout << "1. Register \n2. Login \n3. Quit \nYour Choice: ";
	std::cin >> choice;

	//if register is chosen
	if (choice == 1) {
		std::string username, password;

		//prompt user
		std::cout << "Select a Username: ";
		std::cin >> username;
		std::cout << "Select a Password: ";
		std::cin >> password;

		//create and append to file
		ofstream file;
		file.open("Login-Register\\" + username + ".txt");
		file << username << std::endl << password;
		file.close;

		main();
	}

	//if login is chosen
	if (choice == 2) {
		bool status = loggedIn();

		if (status) {
			std::cout << "Log In Successful" << std::endl;
			system("PAUSE");
			return 1;
		}
		else {
			std::cout << "Failed to Log In" << std::endl;
			return 0;
		}
	}

	//quit program
	if (choice == 3) {
		std::cout << "Exiting Program" << std::endl;
		return 0;
	}

	//error handling
	else {
		std::cout << "Invalid Option" << std::endl;
		main();
	}

	system("PAUSE");
	return 0;
}