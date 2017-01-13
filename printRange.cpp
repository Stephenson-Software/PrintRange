#include <iostream>
int main()
{
	int num1, num2;
	std::cout << "What is the first number in the range?" << std::endl;
	std::cin >> num1;
	std::cout << "What is the last number in the range?" << std::endl;
	std::cin >> num2;
	if (num1 < num2) {
		while (num1 <= num2) {
			std::cout << num1 << std::endl;
			++num1;
		}
	}
	else if (num1 > num2) {
		while (num1 >= num2) {
			std::cout << num1 << std::endl;
			--num1;
		}
	}
	else {
		std::cout << num1 << std::endl;
	}
}