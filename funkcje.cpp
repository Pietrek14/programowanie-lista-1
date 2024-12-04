#include "funkcje.h"

#include <iostream>
#include <iomanip>
#include <random>
#include <vector>

double sine(double angle, unsigned int precision) {
	double result = 0;
	double current_term = angle;

	for(int i = 0; i < precision; i++) {
		result += current_term;

		current_term *= -angle * angle / ((2 * i + 2) * (2 * i + 3));
	}

	return result;
}

double tax(TaxVariant tax_variant, double income_pln) {
	double first_percentage, second_percentage, second_limit;

	switch(tax_variant) {
		case TaxVariant::UNDER_25:
			first_percentage = 0.15;
			second_percentage = 0.28;
			second_limit = 50000;
			break;

		case TaxVariant::OVER_25:
			first_percentage = 0.17;
			second_percentage = 0.32;
			second_limit = 85000;
			break;

		case TaxVariant::MARRIED:
			first_percentage = 0.17;
			second_percentage = 0.32;
			second_limit = 170000;
			break;
	}

	if(income_pln <= second_limit) {
		return first_percentage * income_pln;
	} else {
		return first_percentage * second_limit + second_percentage * (income_pln - second_limit);
	}
}

void generate_password(int length) {
	if(length < 4)  {
		std::cerr << "The password must be at least 4 characters long!\n";
		return;
	}

	std::srand(time(0));

	int special_char_index, digit_index, small_char_index, cap_index;

	special_char_index = rand() % length;

	digit_index = rand() % length;
	if(digit_index == special_char_index) {
		digit_index = (digit_index + 1) % length;
	}

	small_char_index = rand() % length;
	while(small_char_index == special_char_index || small_char_index == digit_index) {
		small_char_index = (small_char_index + 1) % length;
	}

	cap_index = rand() % length;
	while(cap_index == special_char_index || cap_index == digit_index || cap_index == small_char_index) {
		cap_index = (cap_index + 1) % length;
	}

	std::cout << special_char_index << " " << digit_index << " " << small_char_index << " " << cap_index << '\n';

	std::string result = "";

	constexpr char special_chars[] = { '!', '?', '_', '#', '$', '%', '@', '^', '&', '*' };

	for(int i = 0; i < length; i++) {
		if(i == special_char_index) {
			result += special_chars[rand() % (sizeof(special_chars) / sizeof(char))];
			continue;
		}

		if(i == digit_index) {
			result += (char)('0' + rand() % 10);
			continue;
		}

		if(i == small_char_index) {
			result += (char)('a' + rand() % ('z' - 'a'));
			continue;
		}

		if(i == cap_index) {
			result += (char)('A' + rand() % ('Z' - 'A'));
			continue;
		}

		result += '!' + rand() % ('}' - '!');
	}

	std::cout << "Wygenerowane haslo: " << result << '\n';
}

int divisors_sum(int n) {
	int sum = 1;

	for(int i = 2; i < std::sqrt(n) + 0.1; i++) {
		if(n % i == 0) {
			sum += i;

			if(n / i != i) {
				sum += n / i;
			}
		}
	}

	return sum;
}

void print_divisors_sum(int n) {
	std::cout << n << " = 1";

	for(int i = 2; i <= n / 2; i++) {
		if(n % i == 0) {
			std::cout << " + " << i;
		}
	}

	std::cout << '\n';
}

bool czy_doskonala(int n) {
	return divisors_sum(n) == n;
}

void liczby_zaprzyjaznione(int a, int b) {
	std::cout << "Rozwazany przedzial: [ " << a << ", " << b << " ]\n";

	std::vector<int> skip = {};

	for(int i = a; i <= b; i++) {
		int div_sum = divisors_sum(i);

		if(div_sum < a || div_sum > b) {
			continue;
		}

		if(div_sum == i) {
			continue;
		}

		int div_sum2 = divisors_sum(div_sum);

		if(div_sum2 != i) {
			continue;
		}

		bool skip_this = false;

		for(int j = 0; j < skip.size(); j++) {
			if(i == skip[j]) {
				skip_this = true;
				break;
			}
		}

		if(skip_this) {
			continue;
		}

		std::cout << "\nLiczby zaprzyjaznione: " << i << " i " << div_sum << '\n';
		print_divisors_sum(i);
		print_divisors_sum(div_sum);
		std::cout << '\n';

		skip.push_back(div_sum);
	}
}

void box_string(std::string napis) {
	std::cout << std::setw(napis.length() + 2) << std::setfill('*') << "" << '\n';
	std::cout << '!' << napis << "!\n";
	std::cout << std::setw(napis.length() + 2) << std::setfill('*') << "" << '\n';
}

std::string liczba_slownie(int n) {
	std::string result = "";

	switch(n / 100) {
		case 1:
			result = "sto";
			break;
		case 2:
			result = "dwiescie";
			break;
		case 3:
			result = "trzysta";
			break;
		case 4:
			result = "czterysta";
			break;
		case 5:
			result = "piecset";
			break;
		case 6:
			result = "szescset";
			break;
		case 7:
			result = "siedemset";
			break;
		case 8:
			result = "osiemset";
			break;
		case 9:
			result = "dziewiecset";
			break;
	}

	n %= 100;

	if(n == 0) {
		return result;
	}

	if(n >= 10) {
		result += " ";

		if(n < 20) {
			switch(n) {
				case 10:
					return result + "dziesiec";
				case 11:
					return result + "jedenascie";
				case 12:
					return result + "dwanascie";
				case 13:
					return result + "trzynascie";
				case 14:
					return result + "czternascie";
				case 15:
					return result + "pietnascie";
				case 16:
					return result + "szesnascie";
				case 17:
					return result + "siedemnascie";
				case 18:
					return result + "osiemnascie";
				case 19:
					return result + "dziewietnascie";
			}
		}
	}

	switch(n / 10) {
		case 2:
			result += "dwadziescia";
			break;
		case 3:
			result += "trzydziesci";
			break;
		case 4:
			result += "czterdziesci";
			break;
		case 5:
			result += "piecdziesiat";
			break;
		case 6:
			result += "szescdziesiat";
			break;
		case 7:
			result += "siedemdziesiat";
			break;
		case 8:
			result += "osiemdziesiat";
			break;
		case 9:
			result += "dziewiecdziestat";
			break;
	}

	n %= 10;

	if(n == 0) {
		return result;
	}

	result += " ";

	switch(n) {
		case 1:
			result += "jeden";
			break;
		case 2:
			result += "dwa";
			break;
		case 3:
			result += "trzy";
			break;
		case 4:
			result += "cztery";
			break;
		case 5:
			result += "piec";
			break;
		case 6:
			result += "szesc";
			break;
		case 7:
			result += "siedem";
			break;
		case 8:
			result += "osiem";
			break;
		case 9:
			result += "dziewiec";
			break;
	}

	return result;
}

void totolotek(int n, int a, int b) {
	if(b <= a) {
		std::cerr << "b musi byc wieksze od a!\n";
		return;
	}

	if(n <= 0) {
		std::cout << "n musi byc liczba dodatnia!\n";
		return;
	}

	auto rand = std::mt19937();

	rand.seed(time(0));

	for(int i = 0; i < n; i++) {
		int random_number = (double)rand() / rand.max() * (b + 1 - a) + a;

		std::cout << random_number << '\n';
	}
}

int sekwencje(int n) {
	char curr_streak_digit = 10;
	int curr_streak = 1, max_streak = 1;

	for(; n > 0; n /= 10) {
		char curr_digit = n % 10;

		if(curr_digit == curr_streak_digit) {
			curr_streak++;

			if(curr_streak > max_streak) {
				max_streak = curr_streak;
			}

			continue;
		}

		curr_streak = 1;
		curr_streak_digit = curr_digit;
	}

	return max_streak;
}
