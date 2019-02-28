#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	CLinkedList<int> listInt;
	CLinkedList<float> listFloat;

	for(int i=0;i<100;i++){
		listInt.push_back(i + 1);
	}

	CLinkedList<int>::iterator iter;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter) {
		cout << *iter << endl;
	}

	CLinkedList<int>::Riterator Riter;

	for (Riter = listInt.Rbegin(); Riter != listInt.Rend(); ++Riter) {
		cout << *Riter << endl;
	}

	return 0;
}