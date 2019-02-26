// #pragma once : 이 헤더파일을 딱 1번만 포함시키겠다.
#pragma once
#include <iostream>

using namespace std;

//헤더파일에는 보통 함수의 선언부분을 만들어 준다.
enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_SORT,
	MM_EXIT
};

enum OUTPUT_TYPE {
	OP_NONE,
	OP_OUTPUT,
	OP_REVERSE
};

enum SORT_TYPE {
	SORT_NONE,
	SORT_NUM,
	SORT_AVG
};

#define NAME_SIZE   32

typedef struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, *PSTUDENT;

//리스트 노드를 만든다.
typedef struct _tagNode {
	STUDENT tStudent;
	_tagNode * pNext;
	_tagNode * pPrev;
}NODE, *PNODE;

//리스트 구조체를 만들어준다.
typedef struct _tagList {
	// pBegin과 pEnd는 명시적으로 처음과 끝을 의미하도록 만든다.
	// 실제 데이터를 저장하는 노드는 아니다. 실제 데이터를 저장하는 노드는
	// pBegin과 pEnd사이에 존재하게만들어준다.
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, *PLIST;

static int InputInt() {
	int input;
	cin >> input;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return input;
}

static int OutputMenu() {
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 학생정렬" << endl;
	cout << "6. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";

	int iInput = InputInt();
	if (iInput <= MM_NONE || iInput>MM_EXIT) {
		return MM_NONE;
	}
}

static void InputString(char *pString, int iSize) {
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}


void InitList(PLIST pList);
void DestroyList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);
void Search(PLIST pList);
void Delete(PLIST pList);
void Sort(PLIST pList);