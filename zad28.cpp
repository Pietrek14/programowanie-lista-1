#include <iostream>

int strlen(char text[]) {
	int result = 0;

	for(; text[result] != '\0'; result++);

	return result;
}

void reverse(char text[]) {
	int len = strlen(text);

	for(int i = 0; i < len / 2; i++) {
		char temp = text[i];
		text[i] = text[len - i - 1];
		text[len - i - 1] = temp;
	}
}

void add(char num1[], char num2[], char result[]) {
	int len1 = strlen(num1), len2 = strlen(num2);

	if(len2 > len1) {
		add(num2, num1, result);
		return;
	}

	int carry = 0;

	for(int i = 0; i < len1 || carry != 0; i++) {
		int digit1 = 0, digit2 = 0;

		if(i < len1) {
			digit1 = num1[i] - '0';
		}

		if(i < len2) {
			digit2 = num2[i] - '0';
		}

		int curr = digit1 + digit2 + carry;

		result[i] = (curr % 10) + '0';
		result[i + 1] = '\0';
		carry = curr / 10;
	}
}

int main() {
	char num1[201], num2[201];

	std::cin >> num1 >> num2;

	reverse(num1);
	reverse(num2);

	char result[202];

	add(num1, num2, result);

	reverse(result);

	std::cout << result << '\n';

	return 0;
}