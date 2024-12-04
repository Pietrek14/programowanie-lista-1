#include <iostream>
#include <exception>
#include <random>
#include <string>

class RangeTooSmallException : public std::exception {
	std::string m_Message;

public:
	RangeTooSmallException(int a, int b) {
		m_Message = "Range [" + std::to_string(a) + ", "+ std::to_string(b)
			+ "] is invalid or doesn't contain enough natural numbers!";
	}

	char* what() {
		return const_cast<char*>(m_Message.c_str());
	}
};

class NonPositiveQuantityException : public std::exception {
	std::string m_Message;

public:
	NonPositiveQuantityException(int n) {
		m_Message = "The quantity must be positive (is " + std::to_string(n) + ")";
	}

	char* what() {
		return const_cast<char*>(m_Message.c_str());
	}
};

bool in_array(int num, int* arr, int arr_size) {
	for(int i = 0; i < arr_size; i++) {
		if(num == arr[i]) {
			return true;
		}
	}

	return false;
}

int* totolotek(int n, int a, int b) {
	if(n <= 0) {
		throw NonPositiveQuantityException(n);
	}

	if(b - a + 1 < n) {
		throw RangeTooSmallException(a, b);
	}

	auto rand = std::mt19937();

	rand.seed(time(0));

	int* result = new int[n];

	for(int i = 0; i < n; i++) {
		int num = rand() % (b - a + 1) + a;

		do {
			num++;

			if(num > b) {
				num = a;
			}
		} while(in_array(num, result, i));

		result[i] = num;
	}

	return result;
}

int main() {
	int n, a, b;

	std::cin >> n >> a >> b;

	int* nums;

	try {
		nums = totolotek(n, a, b);
	} catch(NonPositiveQuantityException e) {
		std::cout << e.what();

		return 1;
	} catch(RangeTooSmallException e) {
		std::cout << e.what();

		return 1;
	}

	for(int i = 0; i < n; i++) {
		std::cout << nums[i] << " ";
	}

	std::cout << '\n';

	delete[] nums;

	return 0;
}
