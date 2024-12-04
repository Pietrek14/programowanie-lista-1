#include <iostream>

int main() {
	double nums[10];

	for(int i = 0; i < 10; i++) {
		std::cin >> nums[i];
	}

	std::cout << "Podano liczby:\n";

	double min = nums[0];
	double max = nums[0];

	for(int i = 0; i < 10; i++) {
		std::cout << nums[i];

		if(nums[i] > max) {
			max = nums[i];
		}

		if(nums[i] < min) {
			min = nums[i];
		}

		if(i < 9) {
			std::cout << ", ";
		}
	}

	std::cout << "\nNajwieksza z nich to: " << max << '\n';
	std::cout << "Najmniejsza z nich to: " << min << '\n';

	return 0;
}