#include <iostream>

int sumowanie_cyfr(int n) {
	if(n == 0) {
		return 0;
	}

	return sumowanie_cyfr(n / 10) + n % 10;
}

int main() {
	int n;
	std::cin >> n;

	std::cout << sumowanie_cyfr(n) << '\n';

	return 0;
}