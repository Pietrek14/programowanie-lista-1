#include <iostream>

int main() {
	char text[1024];

	std::cin.getline(text, 1024);

	int counts[255];

	for(int i = 0; i < 255; i++) {
		counts[i] = 0;
	}

	for(int i = 0; text[i] != '\0'; i++) {
		counts[text[i]]++;
	}

	for(int curr = 0; curr < 255; curr++) {
		if(counts[curr] == 0) {
			continue;
		}

		std::cout << (char)curr << ": " << counts[curr] << '\n';
	}

	return 0;
}