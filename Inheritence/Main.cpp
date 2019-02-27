#include <iostream>
using namespace std;

/*
상속 : 클래스는 서로간에 부모와 자식간의 관계를 형성할 수 있다.
자식클래스는 부모클래스의 멤버들을 사용할 수 있다.

부모클래스에서 public이나 protect로 되어있는 멤버들은 사용이 가능하지만
private로 되어있으면 자식에서 사용이 불가능하다.

상속의 형태 : public, private 상속이 있다.

다형성 : 상속관계에 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.

가상함수 : 함수 오버라이딩이라고도 한다. 함수를 재정의하는 기능이다.
멤버함수 앞에 virtual 키워드를 붙이면 해당 함수는 가상함수가 된다.
만약 CParent 클래스에 virtual void Output()함수가 있으면 자식클래스에서는
이 가상함수를 재정의할수 있다. 재정의는 함수이름과 인자가 완전히 똑같아야
한다.

가상함수를 가지고 있는 클래스는 내부적으로 가상함수 테이블이라는 것을 생성한다.
가상함수테이블은 가상함수들의 메모리 주소를 저장하는 테이블이다.

만약 CParent의 Output이 가상함수이고 CChild 클래스에 Output을 재정의한다면
그런 뒤 CChild 객체를 생성하면 가상함수 테이블에는 CChild 클래스의 Output주소가 
올라가게 된다.

만약 CParent객체를 생성한다면 CParent의 Output 주소가 올라가게 된다.

그래서 Output함수, 즉 가상함수를 호출하게 되면 먼저 가상함수 테이블을 참조해서 
메모리 주소를 확인한다. 가상함수테이블에 CChild의 Output주소가 들어가 있다면
그 주소의 함수를 호출해주는 개념이다.

소멸자도 가상함수로 만들 수 있다. 부모의 소멸자는 가상함수로 만들어두자.
*/

class CParent {
public:
	CParent() {
		cout << "CParent 생성자" << endl;
	}
	virtual ~CParent() {
		cout << "CParent 소멸자" << endl;
	}
public:
	int m_iA;
protected:
	int m_iB;
private:
	int m_iC;

public:
	virtual void Output() {
		cout << "Parent Output Function" << endl;
	}

	// 순수가상함수 : 가상함수 뒤에 = 0을 붙여주면 해당 가상함수는 
	// 순수가상함수가 된다. 순수가상함수는 구현부분이 존재하지 않는다.
	// 순수가상함수를 가지고 있는 클래스를 추상클래스라고 부른다.
	// 추상클래스는 인스턴스(객체) 생성이 불가능하다.
	// 순수가상함수는 자식에서 반드시 재정의해야 한다. 자식에서 재정의해서
	// 사용할 목적으로 만들어주었기 때문이다.

	virtual void OutputPure() = 0;
};
class CChild : public CParent {
public: 
	CChild() {
		m_iB = 200;
		// m_iC는 private이기 때문에 자식 내부에서도 접근이 불가능하다.
		cout << "CChild 생성자" << endl;
	}
	virtual ~CChild() {
		cout << "CChild 소멸자" << endl;
	}

protected:
	int m_iD;
public:
	void ChildOutput() {
		cout << "ChildOutput Function" << endl;
	}
	virtual void Output() {
		CParent::Output();
		cout << "Child Output Function" << endl;
	}
	virtual void OutputPure() {
		cout << "순수가상함수 CChild" << endl;
	}
};

class CChild1 : private CParent {
public:
	CChild1() {
		m_iA = 100;
		m_iB = 200;
		cout << "CChild1 생성자" << endl;
	}
	virtual ~CChild1() {
		cout << "CChild1 소멸자" << endl;
	}
private:
	int m_iD;
};

class CChildChild : public CChild {
public:
	CChildChild() {
		m_iD = 500;
		cout << "CChildChild 생성자" << endl;

	}
	~CChildChild() {
		cout << "CChildChild 소멸자" << endl;
	}
private:
	int m_iE;
public:
	virtual void OutputPure() {
		cout << "순수가상함수 CChild1" << endl;
	}
};

int main() {
	/*
	상속관계에서의 생성자 호출 순서 : 부모 -> 자식 순으로 호출된다.
	상속관계에서의 소멸자 호출 순서 : 자식 -> 부모 순으로 호출된다.
	*/
	
	//parent parent;
	//child child;
	//child1 child1;
	//childChild childchild;

	//parent.m_iA = 100;
	//child.m_iA = 200;
	
	// CChild1 클래스는 CParent를 private상속을 하고 있으므로 CParent에 
	// public으로 설정되어있는 멤버들도 외부에서는 접근이 불가능하다.

	//child1.m_iA = 300; -> 안된다
	//child1.Output(); -> 안된다

	// CCHild 클래스는 CParent 클래스를 상속받고 있다.
	// new CChild를 하게 되면 CChild 객체 하나를 생성해주고 그 메모리 주소를
	// 반환한다.
	// 그런데 아래에서는 CParent* 타입 변수에 이 반환된 주소를 대입해주고
	// 있다. 부모포인터타입에 CChild 객체의 메모리 주소를 넣을 수 있는
	// 이유는 상속관계에 있기 때문이다. 자식 메모리 주소를 부모포인터타입으로
	// 형변환 된 것이기 때문이다. 이런 형변환을 업캐스팅이라고 한다.

	// 자식 -> 부모 타입 형변환 : 업캐스팅
	// 부모 -> 자식 타입 형변환 : 다운캐스팅

	CParent* pParent = new CChild;
	//CParent* pParent1 = new CChild1;
	CParent* pParent2 = new CChildChild;

	CParent* pParentArr[2] = {};

	pParentArr[0] = new CChild;
	pParentArr[1] = new CChild;

	// 아래 두 클래스는 모두 CParent 클래스를 상속받고 있다.
	// 그러므로 pParent를 두 타입 모두 다운캐스팅 가능하다.
	// 그런데 pParent는 CChild로 할당한 객체이다.
	// 이 객체를 CChild1 타입으로 다운캐스팅 하여 넣어주게 되면
	// 이 객체를 사용할 때 문제가 발생할 수 있다. 왜냐하면 애초에 생성한 객체
	// 가 아닌 다른타입으로 변환한 것이기 때문이다.

	CChild* pChild = (CChild*)pParent;
	CChild1* pChild1 = (CChild1*)pParent;

	// CChild 클래스에 있는 ChildOutput 함수에 접근이 불가능하다.
	// 왜냐하면 pParent는 CParent 포인터 타입이기 때문에 자식 멤버에
	// 접근이 불가능하기 때문이다. 만약 접근하고 싶다면 형변환을 해야한다.
	//((CChild*)pParent)->ChildOutput();
	pParent->Output();

	pParent->OutputPure();
	pParent2->OutputPure();

	// 현재 delete를 하게 되면 CChild 소멸자 -> CParent 소멸자가 호출되어야 
	// 하는데 지금 CParent 소멸자만 호출된다.
	// 근본적으로 pParent는 CParent 포인터 타입이다. CParent 포인터
	// 타입이기 때문에 CChild 소멸자가 호출될 수 없다.
	delete pParent;
	delete pParent2;

	for (int i = 0; i < 2; i++) {
		//delete pParentArr[i];
	}

	return 0;
}