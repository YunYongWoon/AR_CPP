#include <iostream>
#include <functional>
using namespace std;

/* 
�Լ������� : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ �� �ִ�.
�����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴�.
�Լ������� ������ : ��ȯŸ�� (*�����ͺ�����)(����Ÿ��);�� ���·� ����
*/

int Sum(int a, int b) {
	return a + b;
}

int OutSum(int a, int b) {
	cout << "a - b" << endl;
	return a - b;
}

void Output() {
	cout << "Output Function" << endl;
}

float TestFunc(float a) {
	cout << a << endl;
	return a;
}

class CHanzo {
public:
	CHanzo() {

	}
	~CHanzo() {

	}
public:
	int m_iTest;
	void Output() {
		// this->�� ���� �����ϴ�.
		cout << this->m_iTest << endl;
	}
};


int main() {
	int (*pFunc)(int, int) = Sum;
	cout << pFunc(10, 20) << endl;

	pFunc = OutSum;
	OutSum(10, 20);

	//pFunc = Output (X)
	void (*pFunc1)() = Output;
	pFunc1();

	CHanzo hanzo1, hanzo2;
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	// this ������ : Ŭ���� �ȿ��� this�� ����� ��� �ش� ��ü��
	// �޸� �ּҰ� �ȴ�. �� �ڱ��ڽ��� �������̴�.
	// ����Լ��� ȣ���� �� this�� ȣ���ڷ� �����Ѵ�.
	hanzo1.Output();
	hanzo2.Output();

	// ����Լ������� ����� �����ͺ��� �̸� �տ� Ŭ������::�� �ٿ��ش�.
	void(CHanzo::*pFunc2)() = &CHanzo::Output;

	(hanzo1.*pFunc2)();

	function<void()> func1;
	function<void()> func2;

	/*
	function ����� C++11���� ������ ���ִ� ����̴�. �� ����� �Լ������͸�
	����, ��� ������ �ʰ� ���� �ּҸ� �����ؼ� ȣ������ �� �ֵ��� ������ִ�
	����̴�.
	������ : function<��ȯŸ��(����Ÿ��)> ������; �� ���·� �����Ѵ�.
	*/

	cout << "===============Funtional===================" << endl;
	// bind �Լ��� �Լ��� �����ش�.
	func1 = bind(Output);
	func2 = bind(&CHanzo::Output, &hanzo2);
	
	func1();
	func2();

	function<int(int, int)> func3;
	function<float(float)> func4;

	// �Լ��� ���ڰ� ���� ��� placeholders�� �̿��ؼ� ������ ������ ������ �� �ִ�.
	// �Ʒ�ó�� 2,1�� �־��ָ� ���ڰ� ���� �ٲ�� �ȴ�.
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);

	// ������ 2,1�� �ٲ���� ������ b=10,a=20�̴�.
	func3(20, 10);

	func4 = bind(TestFunc, placeholders::_1);
	func4(3.14f);

	return 0;
}