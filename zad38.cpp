#include <iostream>

void trojkat(int dlugosc) {
	if(dlugosc == 0) {
		return;
	}

	trojkat(dlugosc - 1);

	for(int i = 0; i < dlugosc; i++) {
		std::cout << "[]";
	}

	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;

	trojkat(n);

	return 0;
}
