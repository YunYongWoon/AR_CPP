#include <iostream>
using namespace std;

enum NUM {
	Num_0,	//아무것도 부여하지 않을 경우 0부터 차례대로 값이 부여된다.
	Num_1,	//
	Num_2,
	Num_3,
};

#define Num_4  4

int main() {
	int iNumber;
	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	switch (iNumber) {
	case Num_1 : 
		cout << "입력한 숫자는 1 입니다" << endl;
		break;
	case Num_2:
		cout << "입력한 숫자는 2 입니다" << endl;
		break;
	case Num_3:
		cout << "입력한 숫자는 3 입니다" << endl;
		break;
	case Num_4:
		cout << "입력한 숫자는 4 입니다" << endl;
		break;
	default:
		cout << "입력한 숫자는 없습니다." << endl;
		break;
	}

	cout << sizeof(Num_0) << endl;
	cout << typeid(NUM).name() << endl;

	return 0;
}