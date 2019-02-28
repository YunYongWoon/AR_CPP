#pragma once

template <typename T>
class CQueNode {
private:
	CQueNode() :m_pNext(NULL) {

	}
	~CQueNode() {

	}

private:
	template<typename T>
	friend class CQue;

private:
	T m_Data;
	CQueNode<T>* m_pNext;
	CQueNode<T>* m_pPrev;
};

template <typename T>
class CQue
{
public:
	CQue() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}
	~CQue() {
		PNODE pNode = m_pBegin;
		while (pNode) {
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}
	}

private:
	typedef CQueNode<T> NODE;
	typedef CQueNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	void push(const T& data) {
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	T pull() {
		if (empty())
			return 0;

		// 가져올 노드는 begin의 다음 노드이다.
		PNODE pNode = m_pBegin->m_pNext;

		// 가져올 노드를 지워주려면 begin과 가져올 노드의 다음 노드를 
		// 연결해 주어야 한다.
		PNODE pNext = pNode->m_pNext;

		T data = pNode->m_Data;

		delete pNode;

		m_pBegin->m_pNext = pNext;
		--m_iSize;

		return data;
	}

	T top() {
		if (empty())
			return 0;
		return m_pEnd->m_pPrev->m_Data;
	}

	bool empty() {
		return m_iSize == 0;
	}
};

// 비타입 템플릿 인자 : #define과 비슷한 논리.
template <typename T, int SIZE = 20>
class CCircleQueue {
public:
	CCircleQueue() {
		m_iSize = 0;
		m_iHead = 0;
		m_iTail = 0;
	}
	~CCircleQueue() {

	}

private:
	T m_data[SIZE + 1];
	unsigned int m_iSize;
	unsigned int m_iHead;
	unsigned int m_iTail;

public:
	void push(const T& data) {
		if (full())
			return;

		int idx = (m_iTail + 1) % (SIZE + 1);

		m_data[idx] = data;
		m_iTail = idx;
		++m_iSize;		
	}

	T pop() {
		if (empty())
			return 0;

		int idx = (m_iHead + 1) % (SIZE + 1);

		T data = m_data[idx];

		m_iHead = idx;
		--m_iSize;

		return data;
	}

	bool full() {
		return m_iSize == SIZE;
	}

	bool empty() {
		return m_iSize == 0;
	}

};

