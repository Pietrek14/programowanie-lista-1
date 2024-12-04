#include <iostream>

bool increment(char text[], int index = 0) {
	if(text[index] == '\0') {
		return false;
	}

	if(text[index] == 'c') {
		text[index] = 'a';
		return increment(text, index + 1);
	}

	text[index]++;

	return true;
}

int main() {
	char text[5] = "aaaa";

	do {
		std::cout << text << '\n';
	} while(increment(text));
}