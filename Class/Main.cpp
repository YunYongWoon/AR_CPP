#include <iostream>
using namespace std;
/*
- ��ü(object) : ��� �繰�� �ǹ��Ѵ�. C++���� ��ü�� �ǹ��ϴ� ����
�� �����鵵 ��ü�� ��� �� ���� �ֵ�. ������ ��ü������ ���α׷����� �����ϱ� ����
�����ϴ� ������ class�̴�. class�� ��ü�� �ƴ϶� ��ü�� ����� ���� Ʋ�̴�.

- ��ü���� ���α׷���(OOP) : ��ü���� ���踦 �������־ ��ǰ�� �����ϵ��� 
��ü���� �����Ͽ� �ϼ��� ���α׷��� �������� ����̴�.

- ���� ��� : class Ŭ������{};�� ���·� �����Ѵ�.
�ڵ���� �ȿ� ��������� �־��� �� �ִ�. �Լ��� ����� ���� �� �ִ�.

Ŭ������ 4���� �Ӽ�
1. ĸ��ȭ : Ŭ���� �ȿ� ���ϴ� ���� ���� Ȥ�� �Լ��� �ϳ��� Ŭ������
�����ִ� ���

2. ����ȭ : Ŭ���� �ȿ� ���ϴ� ���� Ȥ�� �Լ��� ���� ���ϴ� �κи� �ܺο� 
�����ϰ� �ܺο� �������� ���� �� �ִ�.
	- public	: Ŭ���� ���ο� �ܺ� ��ο��� ������ �����ϴ�.
	- protected : Ŭ���� �ܺο����� ������ �Ұ����ϰ� �ڽ� ���γ� �ڽ� Ŭ����
				���ο����� ������ ������ Ű����
	- private	: �ڽ� ���ο����� ������ �����ϰ� �ܺγ� �ڽ� ���ο����� ����
				�� �Ұ����� ����̴�.

3. ��Ӽ� : Ŭ�������� �θ�, �ڽ� ���踦 ������ �� �ִ�.
�ڽ� Ŭ������ �θ�Ŭ������ ����� �����޾� �ڽ��� ��ó�� ����� �� �ִ�.
��, private���� �Ǿ��ִ� ������� ������ �Ұ����ϴ�.

4. ������ : �θ� �ڽİ���� ��Ӱ��谡 �����Ǿ� �ִ� Ŭ�������� ���� ����ȯ��
������ ������ ���Ѵ�.

- �����ڿ� �Ҹ���
������ : � Ŭ������ �̿��ؼ� ��ü�� ������ �� �ڵ����� ȣ��Ǵ�
�Լ��̴�. ��ü ������ ȣ��Ǵ� �Լ��̱� ������ ��ü�� ��������� 
�ʱ�ȭ�Ҷ� �����ϰ� ����� �� �ִ�.
�����ڸ� ��������� ���� ��� ���������� �⺻ �����ڰ� ������ �Ǿ
�⺻ ������(����Ʈ ������)�� �ڵ����� ȣ�����ְ� �ȴ�.
Ŭ������(){}�� ���·� �����Ѵ�.

�Ҹ��� : � Ŭ������ �̿��ؼ� ������ ��ü�� �޸𸮿��� �����ɶ� �ڵ�����
ȣ��Ǵ� �Լ��̴�. ��ü�� ����ϰ� �� �� ������ �۾��� ���� �� �����ϰ� �����
�� �ִ�.
~Ŭ������(){}�� ���·� �����Ѵ�.
*/

class CTracer {
public:
	CTracer() {
		// ������ : �����ε��� �����ϴ�.
		cout << "������" << endl;
		strcpy_s(m_strName, "Ʈ���̼�");
	}

	CTracer(char* pName) {
		strcpy_s(m_strName, pName);
	}

	CTracer(char* pName, int iFlash, int iBack)
		: m_iBack(iBack), m_iFlash(iFlash) {
		cout << "flash back������ ȣ��" << endl;
		strcpy_s(m_strName, pName);
	}

	~CTracer() {
		// �Ҹ���
		cout << "�Ҹ���" << endl;
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
	���۷��� : �ٸ� ����� �����ϰ� ������ִ� ���
	������ �ϰԵǸ� �� ��� �����Ͽ� ���� ������ �� �ִ�.
	��, ���۷����� ó�� ���۷��� ���� ������ �����ϴ� ����� ������
	�־�� �Ѵ�.
	����Ÿ�� &���۷����� = �����Һ�����; ���� �Ѵ�.
	
	int iNumber = 100;
	int iNumber1 = 9999;
	// iRefNum ���۷��� ������ iNumber�� �����Ѵ�.
	int &iRefNum = iNumber;
	

	iRefNum = 1234;

	iRefNum = iNumber1;
	cout << iNumber << endl;  -> 1234
	cout << sizeof(int&) << endl;  -> 4
	*/
	CTracer tr1;
	CTracer tr2("����", 3, 1);
	// main�Լ� ���� Ŭ���� �ܺ��̱� ������ public���� �����Ǿ��ִ� ��
	tr1.Output();
	tr2.Output();
	return 0;
}