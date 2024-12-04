#include <iostream>
#include <iomanip>

constexpr int M = 3, N = 5;

uint32_t ackermann_values[M][N];

uint32_t ackermann(uint32_t m, uint32_t n) {
	uint32_t result;

	// if(ackermann_values[m][n] != 0) {
	// 	return ackermann_values[m][n];
	// }

	if(m == 0) {
		result = n + 1;
	} else if(n == 0) {
		result = ackermann(m - 1, 1);
	} else {
		result = ackermann(m - 1, ackermann(m, n - 1));
	}

	// if(m < M && n < N) {
	// 	ackermann_values[m][n] = result;
	// }
	return result;
}

int main() {
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			ackermann_values[i][j] = 0;
		}
	}

	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			ackermann_values[i][j] = ackermann(i, j);
		}
	}

	std::cout << "Tablica liczb Ackermanna:\n";

	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			std::cout << std::setw(4) << std::setfill(' ') << ackermann_values[i][j];
		}

		std::cout << '\n';
	}

	return 0;
}