#include <iostream>

void litery(char *s, char *t) {
	char* output = s;
	char* input = t;

	constexpr int letter_count = 'z' - 'a' + 1;
	bool saved[letter_count];

	for(int i = 0; i < letter_count; i++) {
		saved[i] = false;
	}

	int out_index = 0;

	for(int i = 0; input[i] != '\0'; i++) {
		char curr = input[i];

		if(curr >= 'a' && curr <= 'z' && !saved[curr - 'a']) {
			output[out_index] = curr;
			out_index++;

			saved[curr - 'a'] = true;
		}

		if(curr >= 'A' && curr <= 'Z' && !saved[curr - 'A']) {
			output[out_index] = curr - 'A' + 'a';
			out_index++;

			saved[curr - 'A'] = true;
		}
	}

	output[out_index] = '\0';
}

int main() {
	char text[] = "Ala ma kota";
	char output[1024];

	litery(output, text);

	std::cout << output << '\n';

	return 0;
}
