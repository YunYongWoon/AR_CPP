#include <iostream>
using namespace std;

#define  NAME_SIZE   64

// 구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능이다
//          사용자정의 변수 타입니다
//  형식  : struct 구조체명{};의 현태로 구성된다
// 배열과 구조체의 공통점
// 1. 데이터 집합이다
// 2. 연속된 메모리 블럭에 할당된다. 구조체 멤버들은 연속된 메모리 블럭으로 잡히게 된다.
struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main() {
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// 구조체 멤버에 접근할 때는 .을 이용해서 접근하게 된다.
	tStudent.iKor = 100;

	// 문자열을 배열에다가 넣을 때에는 단순 대입으로는 불가하다.
	// strcpy_s른 함수를 이용해서 문자열을 복사해 주어야 한다.
	// 오른쪽에 있는 문자열을 왼쪽으로 복사해 주는 역할이다.

	strcpy_s(tStudent.strName, "가나다라 asdf");
	strcat_s(tStudent.strName, " 문자열 붙이기");
	cout << "이름길이 : " << strlen(tStudent.strName) << endl;
	//strlen : 문자열의 크기를 확인해주는 함수
	//strcat_s : 문자열을 붙여주는 기능의 함수
	//strcmp : 두 문자열을 비교하여 같을 경우 0을 반환, 다를경우 0이 아닌 값을 반환한다.

	char strName[NAME_SIZE] = {};
	strcpy_s(tStudent.strName, "홍길동");
	cout << "비료할 이름은 : ";
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
		cout << "학생을 찾앗습니다" << endl;
	else
		cout << "학생을 찾지 못하였습니다." << endl;
	
	

	// 문자열의 끝은 항상 NULL로 끝나야 한다.
	// 하지만 쓰레기값이 들어가있는 상태에서 각 배열요소에 값을 넣어주게 되면 그 값이 출력되고 
	// 나머지 부분은 쓰레기값으로 출력된다. 왜냐하면 출력할때 문자열의 끝을 인식할 수 없기 때문이다. 
	// NULL이 들어가야 되는데 쓰레기값이 들어가 있기 때문이다.
	
	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "총점 : " << tStudent.iMath << endl;
	cout << "평균 : " << tStudent.fAvg << endl;

	return 0;
}