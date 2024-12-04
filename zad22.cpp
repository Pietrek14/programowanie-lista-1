#include <iostream>

int main() {
	char text[1024];

	std::cin.getline(text, 1024);

	for(int i = 0; text[i] != '\0'; i++) {
		char curr = text[i];

		if(curr == ' ') {
			continue;
		}

		if(curr >= 'a' && curr <= 'z') {
			std::cout << (char)(curr - 'a' + 'A');
			continue;
		}

		std::cout << curr;
	}

	return 0;
}
