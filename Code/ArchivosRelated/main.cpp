#include <bits/stdc++.h>

class User {
	private:
		std::string username, password;

	public:
		int selectedOption;
		std::string getUsername() { return this -> username; }
		std::string getPassword() { return this -> password; }

		bool validateOption() {
			bool isValid = false;
			std::array <int, 2> validOptions = {1, 2};

			for (int i : validOptions) {
				if (this -> selectedOption == i)
					isValid = true;
			}

			return isValid;
		}

		void setupUsername (std::string value) { this -> username = value; }
		void setupPassword (std::string value) { this -> password = value; }
};	



void mainMenu(User* user) {
	int opcion;
	std::cout << "Login Menu" << std::endl;
	std::array <std::string, 2> displayValues = {"1. Sign Up", "2. Login"};
	for (std::string i : displayValues)
		std::cout << i << std::endl;

	
	do {
		std::cout << "-> ";
		std::cin >> user -> selectedOption;
	} while (!user -> validateOption());
}

void signUp (User* user) {
	std::string value;
	
	std::cout << "Ingrese el nombre de usuario: ";
	getline(std::cin, value);
	user -> setupUsername(value);

	std::cout << "Ingrese su contraseña: ":
	getline(std::cin, value);
	user -> setupPassword(value);
}

void logIn(User* user) {
	
}


int main() {
	std::ofstream logFile ("logFile.txt", std::ios::app);

	User* user = new User();

	switch (user -> selectedOption) {
		case 1: {
			signUp(user); break;
		}

		case 2: {
			logIn(user); break;
		}
	}
	
	
	return EXIT_SUCCESS;
}