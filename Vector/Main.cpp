#include <iostream>
#include "Vector.h"
#include "Stack.h"
#include "Que.h"
using namespace std;

int main() {
	//CVector<int>  vecInt;

	//vecInt.reserve(100);
	//for (int i = 0; i < 100; i++) {
	//	vecInt.push_back(1 + i);
	//}

	//for (int i = 0; i < vecInt.size(); i++) {
	//	cout << vecInt[i] << endl;
	//}
	

	CStack<int> stackInt;

	for (int i = 0; i < 50; i++) {
		stackInt.push(i + 1);
	}

	//while (!stackInt.empty()) {
	//	cout << stackInt.pop() << endl;
	//}

	CQue<int> queInt;
	for (int i = 0; i < 30; i++) {
		queInt.push(i + 1);
	}

	//while (!queInt.empty()) {
	//	cout << queInt.pull() << endl;
	//}

	CCircleQueue<int, 10> CqueInt;

	for (int i = 0; i < 10; i++) {
		CqueInt.push(i + 1);
	}

	cout << "3개 pop" << endl;
	for (int i = 0; i < 3; i++) {
		cout << CqueInt.pop() << endl;
	}

	cout << "2개 push" << endl;
	for (int i = 0; i < 2; i++) {
		CqueInt.push(i + 1);
	}

	cout << "모두 pop" << endl;
	while (!CqueInt.empty()) {
		cout << CqueInt.pop() << endl;
	}

	return 0;
}
