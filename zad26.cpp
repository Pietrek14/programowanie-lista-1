#include <iostream>

int main() {
	std::cout << "int[20]: " << sizeof(int[20]) << '\n';
	std::cout << "float[20]: " << sizeof(float[20]) << '\n';
	std::cout << "double[20]: " << sizeof(double[20]) << '\n';
	std::cout << "int[5][2]: " << sizeof(int[5][2]) << '\n';

	return 0;
}
