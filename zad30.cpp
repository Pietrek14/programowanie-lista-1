#include <iostream>

int strlen(char text[]) {
	int result = 0;

	for(; text[result] != '\0'; result++);

	return result;
}

void odwroc(char *s, char *t) {
	char* output = s;
	char* input = t;

	int len = strlen(input);

	for(int i = 0; i < len; i++) {
		output[i] = input[len - i - 1];
	}

	output[len] = '\0';
}

int main() {
	char text[1024];

	std::cin.getline(text, 1024);

	char out[1024];

	odwroc(out, text);

	std::cout << out << '\n';

	return 0;
}