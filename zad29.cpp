#include <iostream>

void zamien_polowki(int tab[], int rozmiar) {
	for(int i = 0; i < rozmiar / 2; i++) {
		int temp = tab[i];
		tab[i] = tab[i + rozmiar / 2];
		tab[i + rozmiar / 2] = temp;
	}
}

int main() {
	int tab[] = { 2, 15, 9, 0, 74, 36, 1, 7 };
	constexpr int tab_size = sizeof(tab) / sizeof(int);

	zamien_polowki(tab, tab_size);

	for(int i = 0; i < tab_size; i++) {
		std::cout << tab[i] << ' ';
	}

	return 0;
}
