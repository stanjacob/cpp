#include <stdio.h>
#include <string.h>

class MockClass {
public:
	template <class Comp>
	int doSomething(int a, int b, Comp lambdaFunc) {
		return lambdaFunc(a, b);
	}

	int addSetStuff(int a, int b) {
		auto lambdaFuncAdd = [this](int a, int b) {
			return a + b + this->addedValue;
		};
		int result = doSomething(a, b, lambdaFuncAdd);
		return result;
	}

	const int addedValue = 10;
};

int main() {
	const char* a = "hiasdf";
	int size = strlen(a) + 1
	;
	printf("%d\n", size);
	char b[size];

	strcpy(b, a);
	for (int i = 0; i < (size + 1); ++i) {
		printf("%c\n", b[i]);
	}
	
	MockClass temp;
	printf("%d\n", temp.addSetStuff(4, 5));

	return 0;
}