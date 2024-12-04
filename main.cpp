#include <iostream>
#include <iomanip>
#include <cmath>
#include "funkcje.h"

void zad12() {
	std::cout << "  x  | std::sin(x) | my sin(x) \n";
	std::cout << std::setw(31) << std::setfill('-') << "" << '\n';

	for(double x = 0.; x < 3.14; x += 0.05) {
		std::cout << x << " | " << std::sin(x) << " | " << sine(x) << '\n';
	}
}

void zad13() {
	std::cout << tax(TaxVariant::UNDER_25, 55000) << '\n';
}

void zad14() {
	unsigned int length;

	std::cout << "Podaj dlugosc hasla: ";
	std::cin >> length;

	generate_password(length);
}

void zad15() {
	std::cout << "Liczby doskonale z przedzialu [1, 500]:\n";

	for(int i = 1; i <= 500; i++) {
		if(czy_doskonala(i)) {
			std::cout << i << '\n';
		}
	}
}

void zad16() {
	liczby_zaprzyjaznione(-5, 3000);
}

void zad17() {
	box_string("Witaj");
}

void zad18() {
	std::cout << liczba_slownie(123) << '\n';
}

void zad19() {
	totolotek(10, -6, 21);
}

void zad20() {
	std::cout << sekwencje(114445) << '\n';
}

int main() {
	zad20();

	return 0;
}