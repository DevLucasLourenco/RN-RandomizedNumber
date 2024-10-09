#include <string>;
#include <random>;
#include <iostream>
#include <vector>;

class CONFIG {
public:
	int minimalNumber = 1;
	int maximumNumber = 10;

	std::vector<int> getNumbers() {
		return { minimalNumber, maximumNumber };
	}

};

class User {
public:
	std::string name;
	int number = 0;

	User(std::string name) {
		this->name = name;
	};

	void showInfos() {
		std::cout << "Name:" << this->name;
	};

	int get() {
		return this->number;
	};

	void selectNumber() {
		CONFIG config;
		std::vector<int> numbersFromVector = config.getNumbers();
		std::cout << "Input a number between " << numbersFromVector[0] <<"-"<< numbersFromVector[1]<<"\n";

		int input;
		while (true) {
			std::cin >> input;

			if ((input >= numbersFromVector[0]) && (input <= numbersFromVector[1])) {
				this->number = input;
				break;
			}
			else {
				std::cout << "Invalid Value. Try to input an valid number between " << numbersFromVector[0] << "-" << numbersFromVector[1]<<"\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

		}
	};
};

int randomNumber() {
	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> distrib(1, 10);

	return distrib(gen);
};

int main(int argc, char** argv) {
	int numberRandomized = randomNumber();

	User person("Lucas");
	while (true) {
		person.selectNumber();
		int numberSelected = person.get();

		if (numberSelected == numberRandomized) {
			std::cout << "You'd Win! Its " << numberRandomized<<"\n";
			break;
		}
		else {
			std::cout << "Unfortunelly its incorrect.\n";
		}

		std::cout << "Would you like to guess one more time? (y/n)\n";
		
		std::string ans;
		std::cin >> ans;

		if (ans == "n") {
			break;
		}
	}
	
	return 0;
};
