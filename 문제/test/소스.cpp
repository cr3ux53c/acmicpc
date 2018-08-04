#include <iostream>

void main() {
	try {
		throw 4;
	}
	catch (int a) {
		std::cout << a;
	}

	return;
}