#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	CVector<int>  vecInt;

	vecInt.reserve(100);
	for (int i = 0; i < 100; i++) {
		vecInt.push_back(1 + i);
	}

	for (int i = 0; i < vecInt.size(); i++) {
		cout << vecInt[i] << endl;
	}
	return 0;
}

