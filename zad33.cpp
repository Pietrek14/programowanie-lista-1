#include <iostream>
#include <list>

std::list<std::list<int>> permutations(int n) {
	if(n == 1) {
		return {{ 1 }};
	}

	auto prev = permutations(n - 1);

	std::list<std::list<int>> result = {};

	for(auto& perm : prev) {
		for(int i = 0; i < n; i++) {
			auto copy = perm;
			auto it = copy.begin();
			
			for(int j = 0; j < i; j++) {
				it++;
			}

			copy.insert(it, n);
			result.push_back(copy);
		}
	}

	return result;
}

int main() {
	int n;
	std::cin >> n;

	auto perms = permutations(n);

	for(const auto& perm : perms) {
		for(int val : perm) {
			std::cout << val << " ";
		}

		std::cout << '\n';
	}

	return 0;
}