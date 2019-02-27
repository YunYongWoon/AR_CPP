#include <iostream>
using namespace std;
/*
- 객체(object) : 모든 사물을 의미한다. C++에서 객체를 의미하는 것은
각 변수들도 객체로 취급 할 수도 있따. 하지만 객체지향은 프로그래밍을 지원하기 위해
제공하는 수단은 class이다. class는 객체가 아니라 객체를 만들기 위한 틀이다.

- 객체지향 프로그래밍(OOP) : 객체들의 관계를 설정해주어서 부품을 조립하듯이 
객체들을 조립하여 완성된 프로그램을 만들어나가는 방식이다.

- 선언 방법 : class 클래스명{};의 형태로 선언한다.
코드블럭 안에 멤버변수를 넣어줄 수 있다. 함수도 멤버로 만들 수 있다.

클래스의 4가지 속성
1. 캡슐화 : 클래스 안에 속하는 여러 변수 혹은 함수를 하나의 클래스로
묶어주는 기능

2. 은닉화 : 클래스 안에 속하는 변수 혹은 함수를 내가 원하는 부분만 외부에 
공개하고 외부에 공개하지 않을 수 있다.
	- public	: 클래스 내부와 외부 모두에서 접근이 가능하다.
	- protected : 클래스 외부에서는 접근이 불가능하고 자신 내부나 자식 클래스
				내부에서는 접근이 가능한 키워드
	- private	: 자신 내부에서만 접근이 가능하고 외부나 자식 내부에서는 접근
				이 불가능한 방법이다.

3. 상속성 : 클래스간에 부모, 자식 관계를 형성할 수 있다.
자식 클래스는 부모클래스의 멤버를 물려받아 자신의 것처럼 사용할 수 있다.
단, private으로 되어있는 멤버에는 접근이 불가능하다.

4. 다형성 : 부모 자식관계로 상속관계가 형성되어 있는 클래스간에 서로 형변환이
가능한 성질을 말한다.

- 생성자와 소멸자
생성자 : 어떤 클래스를 이용해서 객체를 생성할 때 자동으로 호출되는
함수이다. 객체 생성시 호출되는 함수이기 때문에 객체의 멤버변수를 
초기화할때 유용하게 사용할 수 있다.
생성자를 만들어주지 않을 경우 내부적으로 기본 생성자가 제공이 되어서
기본 생성자(디폴트 생성자)를 자동으로 호출해주게 된다.
클래스명(){}의 형태로 선언한다.

소멸자 : 어떤 클래스를 이용해서 생성한 객체가 메모리에서 해제될때 자동으로
호출되는 함수이다. 객체를 사용하고 난 뒤 마무리 작업을 해줄 때 유용하게 사용할
수 있다.
~클래스명(){}의 형태로 선언한다.
*/

class CTracer {
public:
	CTracer() {
		// 생성자 : 오버로딩이 가능하다.
		cout << "생성자" << endl;
		strcpy_s(m_strName, "트레이서");
	}

	CTracer(char* pName) {
		strcpy_s(m_strName, pName);
	}

	CTracer(char* pName, int iFlash, int iBack)
		: m_iBack(iBack), m_iFlash(iFlash) {
		cout << "flash back생성자 호출" << endl;
		strcpy_s(m_strName, pName);
	}

	~CTracer() {
		// 소멸자
		cout << "소멸자" << endl;
	}
	char m_strName[32];
public:
	int m_iAttack;
	int m_iHP;
	void Output() {
		cout << "Name : " << m_strName << endl;
		
	}
private:
	int m_iFlash;
	int m_iBack;
};

int main() {
	/*
	레퍼런스 : 다른 대상을 참조하게 만들어주는 기능
	참조를 하게되면 그 대상에 접근하여 값을 변경할 수 있다.
	단, 레퍼런스는 처음 레퍼런스 변수 생성시 참조하는 대상을 지정해
	주어야 한다.
	변수타입 &레퍼런스명 = 참조할변수명; 으로 한다.
	
	int iNumber = 100;
	int iNumber1 = 9999;
	// iRefNum 레퍼런스 변수는 iNumber를 참조한다.
	int &iRefNum = iNumber;
	

	iRefNum = 1234;

	iRefNum = iNumber1;
	cout << iNumber << endl;  -> 1234
	cout << sizeof(int&) << endl;  -> 4
	*/
	CTracer tr1;
	CTracer tr2("한조", 3, 1);
	// main함수 안은 클래스 외부이기 때문에 public으로 설정되어있는 ㅈ
	tr1.Output();
	tr2.Output();
	return 0;
}