#include <iostream>
#include <iomanip>

int main() {
	unsigned int n;

	std::cout << "Podaj n: ";
	std::cin >> n;

	if(n == 0) {
		std::cout << "Uwaga! Dla liczby 0 struktura jest pusta.\n";
	}

	if(n >= 10) {
		std::cerr << "Wartosci powyzej 10 sa niedopuszczalne!\n";
		return 1;
	}

	for(int i = 1; i <= n; i++) {
		std::cout << std::setw(i) << std::setfill((char)(i + '0')) << "" << '\n';
	}

	for(int i = n - 1; i >  0; i--) {
		std::cout 
			<< std::setw(n - i) << std::setfill(' ') << ""
			<< std::setw(i) << std::setfill((char)(i + '0')) << "" << '\n';
	}

	return 0;
}