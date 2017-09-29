#include <stdio.h>
#include <string.h>

class MockClass {
public:
	template <class Comp>
	int doSomething(int a, int b, Comp lambdaFunc) {
		return lambdaFunc(a, b, addedValue);
	}

	int addSetStuff(int a, int b) {
		auto lambdaFuncAdd = [](int a, int b, int addedValue) {
			return a + b + addedValue;
		};
		int result = doSomething(a, b, lambdaFuncAdd);
		return result;
	}

	const int addedValue = 10;
};

int main() {
	const char* a = "hiasdf;lerkasdf;lks;dkfljkl;kkfkfksdlf";
	int size = strlen(a);
	char b[size];
	strcpy(b, a);
	printf("%s\n", b);

	MockClass temp;
	printf("%d\n", temp.addSetStuff(4, 5));

	return 0;
}