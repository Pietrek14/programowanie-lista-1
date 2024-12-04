#include <iostream>

int sumaLiczbNaturalnych(int n) {
	if(n == 0) {
		return 0;
	}

	return sumaLiczbNaturalnych(n - 1) + n;
}

int main() {
	int n;
	std::cin >> n;

	std::cout << sumaLiczbNaturalnych(n) << '\n';

	return 0;
}
