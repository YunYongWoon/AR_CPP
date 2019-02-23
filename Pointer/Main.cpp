#include <iostream>
using namespace std;

struct _tagStudent {
	int iKor;
	int iEng;
	int iMat;
	int iMax;
	int iAge;

};

int main() {
	/*
	������ : ����Ű��. �Ϲ� ������ �Ϲ����� ���� �����ϰ� ������ ������ ������ �޸� �ּҸ� �����ϰ� �ȴ�.
	��� ���� Ÿ���� ������ Ÿ���� ������ �� �ִ�. int������ �ּҴ� int������ ������ ������ �ؾ��Ѵ�.
	�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ x86���� ������ ���� ������ 4����Ʈ�� ���´�.
	x64�϶��� 8����Ʈ�� ���´�.

	�����ʹ� �ڱ� ������ �ƹ��� �ϵ� �� �� ����. �ݵ�� �ٸ� ������ �޸�
	�ּҸ� ������ �־�� ���� �� �� �մµ� ������ �ִ� �� �޸� �ּҿ� �����ؼ� ���� ������ �� �ִ�.

	���� : ����Ÿ�� *������; �� ���·� �����Ѵ�.
	*/

	int iNumber = 100;
	// ���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ �ȴ�.
	// ���� �տ� &�� �ٿ��ָ� �ش� ������ �ּҰ� �ȴ�.
	int *pNum = &iNumber;

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;

	// �������� ���̳� ���� �տ� *�� ���̰� �Ǹ� �������� �ȴ�.
	// �������� �̿��ؼ� ���� �����ų� ������ �� �ִ�.

	*pNum = 1234;

	cout << "iNumber value : " << iNumber << endl;
	cout << "iNumber Adress : " << &iNumber << endl;
	cout << "pNum value : " << pNum << endl;
	cout << "pNum Adress : " << *pNum << endl;

	/*
	�����Ϳ� �迭�� ���� : �迭���� �������̴�. �迭�� ��ü�� �ش� �迭�� �޸𸮿�����
	������ �ּҸ� �ǹ��Ѵ�.
	*/

	int iArray[10] = { 1,2,3,4,5,6,7,8,9,0 };
	cout << "Array Adress " << iArray << endl;
	cout << "iArray[0] Adress " << &iArray[0] << endl;

	int *pArray = iArray;
	cout << pArray << endl;
	cout << pArray+2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl; //������ �켱������ ���� 1+100�� �ȴ�.

	/*
	������ ���� : +,- ������ �����Ѵ�. ++,__�� �����ѵ� 1�� �����ϰ� �Ǹ�
	�ܼ��� �޸��ּ� ���� 1 �����ϴ� ���� �ƴ϶� int*�� ��� int Ÿ���� �޸� �ּҸ�
	���� �Ǵµ� 1�� ���������ָ� sizeof(int) (�ش� ������Ÿ���� ����Ÿ�� ũ��)��ŭ �����ϰ� �ȴ�.
	int �������̹Ƿ� int�� ũ���� 4��ŭ �����ϰ� �ȴ�.
	*/

	char *pText = "�׽�Ʈ ���ڿ�"; //���������� const(���)�� �����Ǿ��ִ�.
	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "abcd";
	cout << pText << endl;
	cout << (int*)pText << endl;

	char str[8] = "abcdefg";
	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent *pStudent = &tStudent;
	//������ �켱���� ������ .�� ���� �ν��ϰ� �ȴ�. �޸��ּ�.�� �߸��� �����̴�.
	(*pStudent).iEng = 60;

	cout << tStudent.iEng << "  " << tStudent.iKor << endl;

	// �޸��ּ� -> �� �̿��ؼ� ����Ű�� ����� ����� ������ �� �ִ�.
	pStudent->iKor = 80;
	cout << tStudent.iKor << endl;

	// void : Ÿ���� ����. void�� ������ Ÿ���� Ȱ���� �� �ִ�.
	// ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ��� ������ �����ϴ�.
	// ��, �������� �Ұ����ϰ� �޸� �ּҸ� ���� �����ϴ�. (�޸� �ּҸ� �����ϱ� ���� ���۷� Ȱ�밡��)

	void* pVoid = &iNumber;
	cout << "iNumber Adress : " << pVoid << endl;
	//*pVoid = 10 -> �Ұ���
	int* pConvert = (int*)pVoid; // ����ȯ�� �ϰ� �������Ͽ��� �Ѵ�.
	*pConvert = 100;
	*((int*)pVoid) = 9999;
	cout << "iNumber Value : " << iNumber << endl;

	pVoid = &tStudent;
	cout << "tStudent Adress : " << pVoid << endl;

	int iNumber1 = 1111;
	iNumber = 2222;
	pNum = &iNumber;

	// ���������� : *�� 2�� ���δ�. �Ϲ� ������ ������ �Ϲ� ������ �޸�
	// �ּҸ� �����ϴ� ������� ���������ʹ� �������� �������̴�.
	// ��, ���������ʹ� ������ ������ �޸� �ּҸ� �����ϴ� �������̴�.
	int **ppNum = &pNum;

	*ppNum = &iNumber1;
	*pNum = 3333;


	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Addr : " << &iNumber << endl;
	cout << "*pNum : " << *pNum << endl;
	cout << "pNum value : " << pNum << endl;
	cout << "pNum Addr : " << &pNum << endl;
	cout << "*ppNum : " << *ppNum << endl;
	cout << "**ppNum : " << **ppNum << endl; 
	cout << "ppNum Addr : " << &ppNum << endl;
	cout << "ppNum Value : " << ppNum << endl;


	return 0;
}