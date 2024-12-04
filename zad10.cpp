#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

int main() {
	double start, end;
	int n;

	std::cout << "Start: ";
	std::cin >> start;

	std::cout << "Koniec: ";
	std::cin >> end;

	std::cout << "Punkty: ";
	std::cin >> n;

	std::cout << '\n';

	if(start > end) {
		double temp = start;
		start = end;
		end = temp;
	}

	double diff = 0.;

	if(n > 1) {
		diff = (end - start) / (n - 1);
	}

	double prev = 0.;

	for(int i = 0; i < n; i++) {
		double arg = start + i * diff;

		if(i == n - 1) {
			arg = end;
		}

		double result = (int)(std::sin(arg) * 100) / 100.;

		if((result < 0. && prev > 0.) || (result > 0. && prev < 0.)) {
			std::cout << '\n';
		}

		std::stringstream ss("");

		ss << "sin(" << std::setprecision(2) << std::fixed << arg << ") = "
			<< std::setprecision(2) << std::fixed << result;

		std::cout << std::setw(30) << std::setfill(' ') << ss.str();

		prev = result;
	}

	std::cout << '\n';

	return 0;
}
