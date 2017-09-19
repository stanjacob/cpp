#include <iostream>

auto mult = [](int a, int b) -> int {
	return a*b;
};

auto divide = [](int a, int b) -> int {
	return a/b;
};

int main() {
	decltype(mult) g = divide;
	int i = g(2, 4);
	std::cout << i << std::endl;
	return 0;
}