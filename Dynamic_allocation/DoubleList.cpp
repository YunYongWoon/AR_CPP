#include "DoubleList.h"

void InitList(PLIST pList) {
	// 포인터는 가급적이면 초기화를 할 때 NULL(0)으로 초기화해두고 쓰는게 좋다.
	// 왜냐면 0은 false 0 이 아닌 모든 수는 true이기 때문이다.
	pList->iSize = 0;

	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	// 시작노드의 다음노드는 마지막 노드이다.
	pList->pBegin->pNext = pList->pEnd;
	// 마지막노드의 이전 노드는 시작노드이다.
	pList->pEnd->pPrev = pList->pBegin;

	pList->pEnd->pNext = NULL;
	pList->pBegin->pPrev = NULL;
}


void DestroyList(PLIST pList) {
	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

void Push_Back(PLIST pList) {
	system("cls");
	cout << "======================= 학생추가 ========================" << endl;
	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);
	cout << "학번 : ";
	tStudent.iNumber = InputInt();
	cout << "국어 : ";
	tStudent.iKor = InputInt();
	cout << "영어 : ";
	tStudent.iEng = InputInt();
	cout << "수학 : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;


	PNODE pNode = new NODE;
	pNode->tStudent = tStudent;

	// 새로 추가되는 노드는 END노드의 이전노드와 End노드 사이에 추가해야 한다.
	// 그래서 pEnd의 pPrev노드를 구해놓는다
	PNODE pPrev = pList->pEnd->pPrev;
	// pEnd노드 이전 노드의 다음으로 추가할 노드를 지정한다.
	pPrev->pNext = pNode;
	// 추가할 노드의 이전 노드로 End의 이전 노드를 지정한다.
	pNode->pPrev = pPrev;

	//새로 추가할 노드의 다음 노드를 pEnd에 연결
	pNode->pNext = pList->pEnd;
	// pEnd노드의 이전 노드로 새로 추가할 노드를 지정.
	pList->pEnd->pPrev = pNode;

	++pList->iSize;
}

void Sort(PLIST pList) {
	system("cls");
	cout << "=========================== 학생정렬 ==========================" << endl;
	cout << "1. 학번기준" << endl;
	cout << "2. 평균기준" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput <= SORT_NONE || iInput > SORT_AVG) {
		cout << "잘못 선택하였습니다." << endl;
		system("pause");
		return;
	}

	PNODE pFirst = pList->pBegin->pNext;
	PNODE pSecond = pFirst->pNext;

	while (pFirst != pList->pEnd->pPrev) {
		// Second는 무조건 First 노드 다음 노드부터 검사를 시작한다
		pSecond = pFirst->pNext;
		//Second는 End이전까지 반복해야 하므로 End가 아닐동안만 반복한다.
		while (pSecond != pList->pEnd) {
			bool bSwap = false;
			switch (iInput) {
			case SORT_NUM:
				if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber)
					bSwap = true;
				break;
			case SORT_AVG:
				if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg)
					bSwap = true;
				break;
			}

			if (bSwap) {
				// First노드의 이전과 다음 노드를 저장한다.
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;
				// Second노드의 이전과 다음 노드를 저장한다.
				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;

				pFirstPrev->pNext = pSecond;
				pSecond->pPrev = pFirstPrev;

				//바꾸려는 두 노드가 붙어잇는 경우
				if (pSecond != pFirstNext) {
					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;
				}
				//떨어져 있는 경우
				else {
					pSecond->pNext = pFirst;
					pFirst->pPrev = pSecond;
				}
						 
				pSecondNext->pPrev = pFirst;
				pFirst->pNext = pSecondNext;

				PNODE pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;
			}
			pSecond = pSecond->pNext;
		}
		pFirst = pFirst->pNext;
	}

	cout << "정렬이 완료되었습니다." << endl;
	system("pause");
}

void Pust_Front(PLIST pList) {

}

void OutputStudent(const PSTUDENT pStudent) {
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl << endl;
}

void Output(PLIST pList) {
	int iMenu;
	while (true) {
		system("cls");
		cout << "===========================학생출력==========================" << endl;
		cout << "1. 정방향 출력" << endl;
		cout << "2. 역방향 출력" << endl;
		cout << "메뉴를 선택하세요 : ";
		iMenu = InputInt();

		if (iMenu > OP_NONE&&iMenu <= OP_REVERSE)
			break;
	}
	PNODE pNode = NULL;

	switch (iMenu) {
	case OP_OUTPUT:
		// 추가되는 노드들은 begin과 end 사이에 배치된다. 그러므로 begin의 다음 
		// 노드를 얻어온다.
		pNode = pList->pBegin->pNext;

		while (pNode != pList->pEnd) {
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pNext;
		}
		break;
	case OP_REVERSE:
		pNode = pList->pEnd->pPrev;

		while (pNode != pList->pBegin) {
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pPrev;
		}
		break;
	}

	system("pause");
}

void Search(PLIST pList){
	system("cls");
	cout << "===========================학생탐색==========================" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}

	cout << "학생을 찾지 못하였습니다." << endl;
	system("pause");
}
void Delete(PLIST pList){
	system("cls");
	cout << "===========================학생삭제==========================" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			// 현재 지울 노드의 이전노드의 다음은 현재 지울 노드로 되어잇다.
			// 지울 노드는 지워져야 하기 때문에 이전노드의 다음노드를
			// 지울 노드의 다음 노드로 한다.
			// 다음 노드의 이전은 현재 노드인데 이전노드로 준다.

			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << "학생을 삭제하였습니다" << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "해당 학생을 찾지 못하였습니다" << endl;
	system("pause");
}
