#include <iostream>
using namespace std;

enum NUM {
	Num_0,	//�ƹ��͵� �ο����� ���� ��� 0���� ���ʴ�� ���� �ο��ȴ�.
	Num_1,	//
	Num_2,
	Num_3,
};

#define Num_4  4

int main() {
	int iNumber;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	switch (iNumber) {
	case Num_1 : 
		cout << "�Է��� ���ڴ� 1 �Դϴ�" << endl;
		break;
	case Num_2:
		cout << "�Է��� ���ڴ� 2 �Դϴ�" << endl;
		break;
	case Num_3:
		cout << "�Է��� ���ڴ� 3 �Դϴ�" << endl;
		break;
	case Num_4:
		cout << "�Է��� ���ڴ� 4 �Դϴ�" << endl;
		break;
	default:
		cout << "�Է��� ���ڴ� �����ϴ�." << endl;
		break;
	}

	cout << sizeof(Num_0) << endl;
	cout << typeid(NUM).name() << endl;

	return 0;
}