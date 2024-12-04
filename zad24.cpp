#include <iostream>

bool is_digit(char character) {
	return character >= '0' && character <= '9';
}

int parse_int(char number_str[]) {
	int result = 0;
	bool negative = false;
	int index = 0;

	if(number_str[0] == '-') {
		negative = true;
		index++;
	}

	for(; is_digit(number_str[index]); index++) {
		result *= 10;
		result += number_str[index] - '0';
	}

	return negative ? -result : result;
}

int main() {
	char text[1024];

	std::cin.getline(text, 1024);

	std::cout << parse_int(text) << '\n';

	return 0;
}
