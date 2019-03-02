#include <iostream>
using namespace std;

/*
템플릿 : 컴파일 단게에서 타입을 결정짓는 기능이다.
타입이 다양하게 바뀔 수 있다.

template <typename 원하는이름>의 형태로 사용 가능하다.
template <class 원하는 이름>의 형태로도 사용 가능하다.

예) template <typename T>
void Output(){
	cout << typeid(T).name << endl;
}
위처럼 함수를 만들고 호출시
Output<int>();
Output<float>();

이렇게 해주면 int,float으로 타입이 정해진다. 상황에 따라 넣어주는 타입으로
타입이 가변적으로 바뀌는 것이다.

가변타입은 여러개를 지정해줄 수 있다.
template <typename T, typename T1>
void Output(){
}

위처럼 여러개 지정도 가능한 것이다. 
*/

template <typename T>
void OutputType(){
	cout << "========= OutputData =========" << endl;
	cout << typeid(T).name() << endl;	
}

template <typename T>
void OutputType(T data) {
	cout << "========= OutputData =========" << endl;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}

typedef struct _tagStudent {

}STUDENT, *PSTUDENT;

class CCar {
public:
	CCar() {

	}
	~CCar() {

	}
};

enum TEST {

};

class CTemplate {
public:
	CTemplate() {

	}
	~CTemplate() {

	}
public:
	template<class T,class T1>
	void Output(T a, T1 b) {
		cout << a << endl;
		cout << b << endl;
	}
};

template <typename T>
class CTemplate1 {
public:
	CTemplate1() {
		cout << typeid(T).name() << endl;
	}
	~CTemplate1() {

	}
private:
	T m_Data;
public:
	void Output(){
		cout << typeid(T).name() << endl;
		cout << m_Data << endl;
	}
};

int main() {
	OutputType<int>();
	OutputType<float>();
	OutputType<STUDENT>();
	OutputType<CCar>();
	OutputType<TEST>();

	OutputType<int>(10);
	OutputType<float>(3.1);
	OutputType(382.383f);
	OutputType('a');
	OutputType("ㅋㅋㅋㅋ");

	CTemplate tem;
	tem.Output(10, 'a');

	CTemplate1<int> tem1;
	tem1.Output();
	
	CTemplate1<CTemplate> tem2;
}