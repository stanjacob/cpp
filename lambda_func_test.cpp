#include <iostream>

int main() {
	auto lambda_func = [](const char* a, const char* b) {
    	return (std::string(a) < std::string(b));
    };
    const char* str = "hi";
    const char* str2 = "hi";
    std::cout << lambda_func(str, str2) << std::endl;

    const char* str = "hi";
    const char* str2 = "bye";
    std::cout << lambda_func(str, str2) << std::endl;

    const char* str = "hi";
    const char* str2 = "yo";
    std::cout << lambda_func(str, str2) << std::endl;
    return 0;
}