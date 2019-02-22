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
	포인터 : 가리키다. 일반 변수는 일반적은 값을 저장하게 되지만 포인터 변수는 메모리 주소를 저장하게 된다.
	모든 변수 타입은 포인터 타입을 선언할 수 있다. int변수의 주소는 int포인터 변수에 저장을 해야한다.
	포인터는 메모리 주소를 담아놓는 변수이기 때문에 x86으로 개발할 때는 무조건 4바이트가 나온다.
	x64일때는 8바이트가 나온다.

	포인터는 자기 스스로 아무런 일도 할 수 없다. 반드시 다른 변수의 메모리
	주소를 가지고 있어야 일을 할 수 잇는데 가지고 있는 그 메모리 주소에 접근해서 값을 제어할 수 있다.

	형태 : 변수타입 *변수명; 의 형태로 구성한다.
	*/

	int iNumber = 100;
	// 변수 선언시 *을 붙여주면 해당 타이의 포인터 변수가 된다.
	// 변수 앞에 &를 붙여주면 해당 변수의 주소가 된다.
	int *pNum = &iNumber;

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;

	// 역참조는 포이너 변수 앞에 *을 붙이게 되면 역참조가 된다.
	// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.

	*pNum = 1234;

	cout << "iNumber value : " << iNumber << endl;
	cout << "iNumber Adress : " << &iNumber << endl;
	cout << "pNum value : " << pNum << endl;
	cout << "pNum Adress : " << *pNum << endl;

	/*
	포인터와 배열의 관계 : 배열명은 포인터이다. 배열명 자체가 해당 배열의 메모리에서의
	시작점 주소를 의미한다.
	*/

	int iArray[10] = { 1,2,3,4,5,6,7,8,9,0 };
	cout << "Array Adress " << iArray << endl;
	cout << "iArray[0] Adress " << &iArray[0] << endl;

	int *pArray = iArray;
	cout << pArray << endl;
	cout << pArray+2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl; //연산자 우선순위로 인해 1+100이 된다.

	/*
	포인터 연산 : +,- 연산을 제공한다. ++,__도 가능한데 1을 증가하게 되면
	단순히 메모리주소 값이 1 증가하는 것이 아니라 int*의 경우 int 타입의 메모리 주소를
	갖게 되는데 1을 증가시켜주면 sizeof(int) (해당 포인터타입의 변수타입 크기)만큼 증가하게 된다.
	int 포인터이므로 int의 크기인 4만큼 증가하게 된다.
	*/

	char *pText = "테스트 문자열"; //내부적으로 const(상수)로 설정되어있다.
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
	//연산자 우선순위 때문에 .을 먼저 인식하게 된다. 메모리주소.은 잘못된 문법이다.
	(*pStudent).iEng = 60;

	cout << tStudent.iEng << "  " << tStudent.iKor << endl;

	// 메모리주소 -> 을 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
	pStudent->iKor = 80;
	cout << tStudent.iKor << endl;

	// void : 타입이 없다. void의 포인터 타입을 활용할 수 있다.
	// 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장이 가능하다.
	// 단, 역참조가 불가능하고 메모리 주소만 저장 가능하다. (메모리 주소를 저장하기 위한 버퍼로 활용가능)

	void* pVoid = &iNumber;
	cout << "iNumber Adress : " << pVoid << endl;
	//*pVoid = 10 -> 불가능
	int* pConvert = (int*)pVoid; // 형변환을 하고 역참조하여야 한다.
	*pConvert = 100;
	*((int*)pVoid) = 9999;
	cout << "iNumber Value : " << iNumber << endl;

	pVoid = &tStudent;
	cout << "tStudent Adress : " << pVoid << endl;

	int iNumber1 = 1111;
	iNumber = 2222;
	pNum = &iNumber;

	// 이중포인터 : *을 2개 붙인다. 일반 포인터 변수가 일반 변수의 메모리
	// 주소를 저장하는 변수라면 이중포인터는 포인터의 포인터이다.
	// 즉, 이중포인터는 포인터 변수의 메모리 주소를 저장하는 포인터이다.
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