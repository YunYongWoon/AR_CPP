#include <iostream>
using namespace std;

/*
��� : Ŭ������ ���ΰ��� �θ�� �ڽİ��� ���踦 ������ �� �ִ�.
�ڽ�Ŭ������ �θ�Ŭ������ ������� ����� �� �ִ�.

�θ�Ŭ�������� public�̳� protect�� �Ǿ��ִ� ������� ����� ����������
private�� �Ǿ������� �ڽĿ��� ����� �Ұ����ϴ�.

����� ���� : public, private ����� �ִ�.

������ : ��Ӱ��迡 �ִ� Ŭ�������� ���� ����ȯ�� ������ ������ ���Ѵ�.

�����Լ� : �Լ� �������̵��̶�� �Ѵ�. �Լ��� �������ϴ� ����̴�.
����Լ� �տ� virtual Ű���带 ���̸� �ش� �Լ��� �����Լ��� �ȴ�.
���� CParent Ŭ������ virtual void Output()�Լ��� ������ �ڽ�Ŭ����������
�� �����Լ��� �������Ҽ� �ִ�. �����Ǵ� �Լ��̸��� ���ڰ� ������ �Ȱ��ƾ�
�Ѵ�.

�����Լ��� ������ �ִ� Ŭ������ ���������� �����Լ� ���̺��̶�� ���� �����Ѵ�.
�����Լ����̺��� �����Լ����� �޸� �ּҸ� �����ϴ� ���̺��̴�.

���� CParent�� Output�� �����Լ��̰� CChild Ŭ������ Output�� �������Ѵٸ�
�׷� �� CChild ��ü�� �����ϸ� �����Լ� ���̺��� CChild Ŭ������ Output�ּҰ� 
�ö󰡰� �ȴ�.

���� CParent��ü�� �����Ѵٸ� CParent�� Output �ּҰ� �ö󰡰� �ȴ�.

�׷��� Output�Լ�, �� �����Լ��� ȣ���ϰ� �Ǹ� ���� �����Լ� ���̺��� �����ؼ� 
�޸� �ּҸ� Ȯ���Ѵ�. �����Լ����̺� CChild�� Output�ּҰ� �� �ִٸ�
�� �ּ��� �Լ��� ȣ�����ִ� �����̴�.

�Ҹ��ڵ� �����Լ��� ���� �� �ִ�. �θ��� �Ҹ��ڴ� �����Լ��� ��������.
*/

class CParent {
public:
	CParent() {
		cout << "CParent ������" << endl;
	}
	virtual ~CParent() {
		cout << "CParent �Ҹ���" << endl;
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

	// ���������Լ� : �����Լ� �ڿ� = 0�� �ٿ��ָ� �ش� �����Լ��� 
	// ���������Լ��� �ȴ�. ���������Լ��� �����κ��� �������� �ʴ´�.
	// ���������Լ��� ������ �ִ� Ŭ������ �߻�Ŭ������� �θ���.
	// �߻�Ŭ������ �ν��Ͻ�(��ü) ������ �Ұ����ϴ�.
	// ���������Լ��� �ڽĿ��� �ݵ�� �������ؾ� �Ѵ�. �ڽĿ��� �������ؼ�
	// ����� �������� ������־��� �����̴�.

	virtual void OutputPure() = 0;
};
class CChild : public CParent {
public: 
	CChild() {
		m_iB = 200;
		// m_iC�� private�̱� ������ �ڽ� ���ο����� ������ �Ұ����ϴ�.
		cout << "CChild ������" << endl;
	}
	virtual ~CChild() {
		cout << "CChild �Ҹ���" << endl;
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
		cout << "���������Լ� CChild" << endl;
	}
};

class CChild1 : private CParent {
public:
	CChild1() {
		m_iA = 100;
		m_iB = 200;
		cout << "CChild1 ������" << endl;
	}
	virtual ~CChild1() {
		cout << "CChild1 �Ҹ���" << endl;
	}
private:
	int m_iD;
};

class CChildChild : public CChild {
public:
	CChildChild() {
		m_iD = 500;
		cout << "CChildChild ������" << endl;

	}
	~CChildChild() {
		cout << "CChildChild �Ҹ���" << endl;
	}
private:
	int m_iE;
public:
	virtual void OutputPure() {
		cout << "���������Լ� CChild1" << endl;
	}
};

int main() {
	/*
	��Ӱ��迡���� ������ ȣ�� ���� : �θ� -> �ڽ� ������ ȣ��ȴ�.
	��Ӱ��迡���� �Ҹ��� ȣ�� ���� : �ڽ� -> �θ� ������ ȣ��ȴ�.
	*/
	
	//parent parent;
	//child child;
	//child1 child1;
	//childChild childchild;

	//parent.m_iA = 100;
	//child.m_iA = 200;
	
	// CChild1 Ŭ������ CParent�� private����� �ϰ� �����Ƿ� CParent�� 
	// public���� �����Ǿ��ִ� ����鵵 �ܺο����� ������ �Ұ����ϴ�.

	//child1.m_iA = 300; -> �ȵȴ�
	//child1.Output(); -> �ȵȴ�

	// CCHild Ŭ������ CParent Ŭ������ ��ӹް� �ִ�.
	// new CChild�� �ϰ� �Ǹ� CChild ��ü �ϳ��� �������ְ� �� �޸� �ּҸ�
	// ��ȯ�Ѵ�.
	// �׷��� �Ʒ������� CParent* Ÿ�� ������ �� ��ȯ�� �ּҸ� �������ְ�
	// �ִ�. �θ�������Ÿ�Կ� CChild ��ü�� �޸� �ּҸ� ���� �� �ִ�
	// ������ ��Ӱ��迡 �ֱ� �����̴�. �ڽ� �޸� �ּҸ� �θ�������Ÿ������
	// ����ȯ �� ���̱� �����̴�. �̷� ����ȯ�� ��ĳ�����̶�� �Ѵ�.

	// �ڽ� -> �θ� Ÿ�� ����ȯ : ��ĳ����
	// �θ� -> �ڽ� Ÿ�� ����ȯ : �ٿ�ĳ����

	CParent* pParent = new CChild;
	//CParent* pParent1 = new CChild1;
	CParent* pParent2 = new CChildChild;

	CParent* pParentArr[2] = {};

	pParentArr[0] = new CChild;
	pParentArr[1] = new CChild;

	// �Ʒ� �� Ŭ������ ��� CParent Ŭ������ ��ӹް� �ִ�.
	// �׷��Ƿ� pParent�� �� Ÿ�� ��� �ٿ�ĳ���� �����ϴ�.
	// �׷��� pParent�� CChild�� �Ҵ��� ��ü�̴�.
	// �� ��ü�� CChild1 Ÿ������ �ٿ�ĳ���� �Ͽ� �־��ְ� �Ǹ�
	// �� ��ü�� ����� �� ������ �߻��� �� �ִ�. �ֳ��ϸ� ���ʿ� ������ ��ü
	// �� �ƴ� �ٸ�Ÿ������ ��ȯ�� ���̱� �����̴�.

	CChild* pChild = (CChild*)pParent;
	CChild1* pChild1 = (CChild1*)pParent;

	// CChild Ŭ������ �ִ� ChildOutput �Լ��� ������ �Ұ����ϴ�.
	// �ֳ��ϸ� pParent�� CParent ������ Ÿ���̱� ������ �ڽ� �����
	// ������ �Ұ����ϱ� �����̴�. ���� �����ϰ� �ʹٸ� ����ȯ�� �ؾ��Ѵ�.
	//((CChild*)pParent)->ChildOutput();
	pParent->Output();

	pParent->OutputPure();
	pParent2->OutputPure();

	// ���� delete�� �ϰ� �Ǹ� CChild �Ҹ��� -> CParent �Ҹ��ڰ� ȣ��Ǿ�� 
	// �ϴµ� ���� CParent �Ҹ��ڸ� ȣ��ȴ�.
	// �ٺ������� pParent�� CParent ������ Ÿ���̴�. CParent ������
	// Ÿ���̱� ������ CChild �Ҹ��ڰ� ȣ��� �� ����.
	delete pParent;
	delete pParent2;

	for (int i = 0; i < 2; i++) {
		//delete pParentArr[i];
	}

	return 0;
}