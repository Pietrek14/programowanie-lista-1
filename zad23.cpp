#include <iostream>

bool is_o(char character) {
	return character == 'o' || character == 'O';
}

int main() {
	char text[1024];

	std::cin.getline(text, 1024);

	if(text[0] == '\0') {
		std::cout << 0 << '\n';
		return 0;
	}

	int count = 0;

	for(int i = 0; text[i + 1] != '\0'; i++) {
		if(is_o(text[i]) && is_o(text[i + 1])) {
			count++;
		}
	}

	std::cout << count << '\n';

	return 0;
}