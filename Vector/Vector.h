#pragma once
template <typename T>
class CVectorNode
{
private:
	CVectorNode() {

	}
	~CVectorNode() {

	}
private:
	template <typename T>
	friend class CVector;

private:
	T m_Data;
	int m_iIndex;
};


template <typename T>
class CVector
{
public:
	CVector() {
		m_iSize = 0;
		m_iCapasity = 2;

		m_pArray = new NODE[m_iCapasity + 2];//End, Begin 노드 포함.
	}

	CVector(int iSize) {
		m_pArray = new NODE[iSize + 2];//End, Begin 노드 포함.		
		m_iCapasity = iSize;
		m_iSize = 0;		
	}
	~CVector() {
		delete[] m_pArray;
	}

private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize;
	unsigned int m_iCapasity;

public:
	void push_back(const T& data) {
		if (full())
			resize(m_iSize * 2);

		m_pArray[m_iSize + 1].m_Data = data;
		// 0번 인덱스는 Begin. 실제 1번인덱스부터 노드가 추가되는데
		// 처음 추가된 노든는 0번부터 인덱스를 주도록 한다.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
	}

	void resize(int iSize) {
		PNODE pArray = new NODE[iSize + 2];//End, Begin 노드 포함.

		// 위에서 2배만큼 공간을 새로 할당하고 기존 노드의
		// 데이터를 새로 할당한 공간에 복사
		// 메모리 주소에 +1을 해준 이유는 1번 인덱스부터 시작하기 때문에
		// 여기서부터 복사를 해주기 위함이다.
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE)*m_iSize);

		//기존 노드를 삭제한다.
		delete[] m_pArray;

		m_pArray = pArray;

		m_iCapasity = iSize;
	}
	
	bool full() {
		return m_iSize == m_iCapasity;
	}

	void clear() {
		
		delete[] m_pArray;
		m_iSize = 0;
		m_iCapasity = 2;
		m_pArray = new NODE[m_iCapasity + 2];
	}
	unsigned int size() const{
		return m_iSize;
	}

	unsigned int capasity() const {
		return m_iCapasity;
	}

	T operator [](int idx) {
		return m_pArray[idx + 1].m_Data;
	}

	void reserve(int iSize) {
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];

		m_iCapasity = iSize;
		m_iSize = 0;
	}
		
};

