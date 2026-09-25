#include <cctype>
#include <iostream>
int main()
{
	int num1, num2;
	std::cout << "What is the first number in the range?" << std::endl;
	std::cin >> num1;
	if (std::cin.fail() || !(std::isspace(std::cin.peek()) || std::cin.eof())) {
		std::cerr << "The first number could not be read as an integer." << std::endl;
		return 1;
	}
	std::cout << "What is the last number in the range?" << std::endl;
	std::cin >> num2;
	if (std::cin.fail() || !(std::isspace(std::cin.peek()) || std::cin.eof())) {
		std::cerr << "The last number could not be read as an integer." << std::endl;
		return 1;
	}
	while (num1 < num2) {
		std::cout << num1 << std::endl;
		++num1;
	}
	while (num1 > num2) {
		std::cout << num1 << std::endl;
		--num1;
	}
	std::cout << num1 << std::endl;
}