#include <string>

double sine(double angle, unsigned int precision = 20);

enum class TaxVariant {
	UNDER_25,
	OVER_25,
	MARRIED
};

double tax(TaxVariant tax_variant, double income_pln);

void generate_password(int length);

bool czy_doskonala(int n);

void liczby_zaprzyjaznione(int a, int b);

void box_string(std::string napis);

std::string liczba_slownie(int n);

void totolotek(int n, int a, int b);

int sekwencje(int n);