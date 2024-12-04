#include <iostream>

bool anagramy( char *s, char *t ) {
	char* text1 = s;
	char* text2 = t;

	int counts[255];

	for(int i = 0; i < 255; i++) {
		counts[i] = 0;
	}

	for(int i = 0; text1[i] != '\0' || text2[i] != '\0'; i++) {
		if(text1[i] == '\0' || text2[i] == '\0') {
			return false;
		}

		counts[text1[i]]++;
		counts[text2[i]]--;
	}

	for(int i = 0; i < 255; i++) {
		if(counts[i] != 0) {
			return false;
		}
	}

	return true;
}

int main() {
	char text1[1024];
	char text2[1024];

	std::cin >> text1 >> text2;

	std::cout << (anagramy(text1, text2) ? "anagramy" : "nie anagramy") << '\n';

	return 0;
}