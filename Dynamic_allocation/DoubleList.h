// #pragma once : �� ��������� �� 1���� ���Խ�Ű�ڴ�.
#pragma once
#include <iostream>

using namespace std;

//������Ͽ��� ���� �Լ��� ����κ��� ����� �ش�.
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

//����Ʈ ��带 �����.
typedef struct _tagNode {
	STUDENT tStudent;
	_tagNode * pNext;
	_tagNode * pPrev;
}NODE, *PNODE;

//����Ʈ ����ü�� ������ش�.
typedef struct _tagList {
	// pBegin�� pEnd�� ��������� ó���� ���� �ǹ��ϵ��� �����.
	// ���� �����͸� �����ϴ� ���� �ƴϴ�. ���� �����͸� �����ϴ� ����
	// pBegin�� pEnd���̿� �����ϰԸ�����ش�.
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
	cout << "1. �л��߰�" << endl;
	cout << "2. �л�����" << endl;
	cout << "3. �л�Ž��" << endl;
	cout << "4. �л����" << endl;
	cout << "5. �л�����" << endl;
	cout << "6. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";

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