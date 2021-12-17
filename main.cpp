#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool loggedIn() {
	string username, password, un, pw;

	//prompt user
	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	//read file
	ifstream read("Login-Register\\" + username + ".txt");
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
	cout << "1. Register \n2. Login \n3. Quit \nYour Choice: ";
	cin >> choice;

	//if register is chosen
	if (choice == 1) {
		string username, password;

		//prompt user
		cout << "Select a Username: ";
		cin >> username;
		cout << "Select a Password: ";
		cin >> password;

		//create and append to file
		ofstream file;
		file.open("Login-Register\\" + username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}

	//if login is chosen
	if (choice == 2) {
		bool status = loggedIn();

		if (status) {
			cout << "Log In Successful" << endl;
			system("PAUSE");
			return 1;
		}
		else {
			cout << "Failed to Log In" << endl;
			return 0;
		}
	}

	//quit program
	if (choice == 3) {
		cout << "Exiting Program" << endl;
		return 0;
	}

	//error handling
	else {
		cout << "Invalid Option" << endl;
		main();
	}

	system("PAUSE");
	return 0;
}