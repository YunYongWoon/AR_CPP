#pragma once

template <typename T>
class CListNode {
// 생성자와 소멸자를 private하게 되면 외부에서 객체를 생성하고 해제할 수 없다.
// 생성자는 객체를 생성할 때 자동으로 호출이 되는 함수인데 private으로
// 되면 객체를 생성하면서 호출시 접근이 불가능하다.
private:	
	CListNode():m_pNext(NULL),m_pPrev(NULL) {

	}
	~CListNode() {

	}
private:
	// friend : 친구로 만들어준다. friend로 지정해준 클래스에서 
	// 이 클래스의 private이나 protected에 접근이 가능해진다.
	// 일반 클래스는 friend 라인만 적으면 되지만 template클래스의 경우
	// 아래처럼 template를 지정해주어야 한다.
	template<typename T>
	friend class CLinkedList;
	template<typename T>
	friend class CListIterator;
	template<typename T>
	friend class CListReverseIterator;

private:
	T m_Data;
	CListNode<T>* m_pNext;
	CListNode<T>* m_pPrev;
};

// 반복자 클래스 : 리스트의 노드를 반복해서 순회할 수 있는 기능을 제공하는 
// 클래스

template <typename T>
class CListIterator {
public:
	CListIterator() {

	}
	~CListIterator() {

	}

private:
	template <typename T>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE m_pNode;
public:
	bool operator == (const CListIterator<T>& iter) {
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListIterator<T>& iter) {
		return m_pNode != iter.m_pNode;
	}

	void operator ++() {
		m_pNode = m_pNode->m_pNext;
	}

	void operator --() {
		m_pNode = m_pNode->m_pPrev;
	}

	T operator *() {
		return m_pNode->m_Data;
	}

};

template <typename T>
class CListReverseIterator {
public:
	CListReverseIterator() {

	}
	~CListReverseIterator() {

	}

private:
	template <typename T>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE m_pNode;
public:
	bool operator == (const CListReverseIterator<T>& Riter) {
		return m_pNode == Riter.m_pNode;
	}

	bool operator != (const CListReverseIterator<T>& Riter) {
		return m_pNode != Riter.m_pNode;
	}

	void operator ++() {
		m_pNode = m_pNode->m_pPrev;
	}

	void operator --() {
		m_pNode = m_pNode->m_pNext;
	}

	T operator *() {
		return m_pNode->m_Data;
	}

};

template <typename T>
class CLinkedList {
public:
	CLinkedList() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}
	~CLinkedList() {
		clear();
		delete m_pBegin;
		delete m_pEnd;
		m_iSize = 0;
	}

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

public:
	typedef CListIterator<T> iterator;
	typedef CListReverseIterator<T> Riterator;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	// 레퍼런스는 참조하는 대상의 값을 변경할 수 있다. 그런데 const를 붙여주면
	// 참조하는 대상의 값을 변경할 수 없다.
	void push_back(const T& data) {

		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//End의 이전 노드가 가장 마지막 노드이다.
		PNODE pPrev = m_pEnd->m_pPrev;

		//연결해준다.
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data) {
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// Begin의 다음 노드는 가장 첫번째 노드이다.
		PNODE pFirst = m_pBegin->m_pNext;

		pFirst->m_pPrev = pNode;
		pNode->m_pNext = pFirst;

		pNode->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNode;

		++m_iSize;
	}

	// 멤버함수 뒤에 const를 붙여주면 이 함수 내에서 멤버변수의 값을 
	// 변경할 수 없다.
	unsigned int size() const {
		return m_iSize;
	}

	bool empty() const {
		return m_iSize == 0;
	}

	void clear() {
		PNODE pNode = m_pBegin->m_pNext;

		//pNode가 End가 되면 반복을 종료.
		while (pNode != m_pEnd) {
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;
	}

	iterator begin() {
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}

	iterator end() {
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}
	
	// 오버로딩이 안되므로 함수 이름을 변경
	Riterator Rbegin() {
		Riterator Riter;
		Riter.m_pNode = m_pEnd;
		return Riter;
	}

	Riterator Rend() {
		Riterator Riter;
		Riter.m_pNode = m_pBegin;
		return Riter;
	}
};