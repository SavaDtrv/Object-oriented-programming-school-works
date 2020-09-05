#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "animal.h"

using namespace std;

int main() {

	Animal animal("Chicken", 5, 30, 1.5, 2.5);

	animal.description();


	system("pause");
	return 0;
}