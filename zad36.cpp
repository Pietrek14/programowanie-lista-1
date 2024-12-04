#include <iostream>
#include <random>

int main() {
	constexpr int n = 10;

	int tab[n][n];

	std::srand(time(0));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			tab[i][j] = std::rand() % 10;
		}
	}

	int count[10];

	for(int i = 0; i < 10; i++) {
		count[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << tab[i][j] << " ";

			count[tab[i][j]]++;
		}

		std::cout << '\n';
	}

	std::cout << '\n';

	for(int i = 0; i < 10; i++) {
		std::cout << i << ": " << count[i] << '\n';
	}

	return 0;
}
