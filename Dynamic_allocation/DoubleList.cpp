#include "DoubleList.h"

void InitList(PLIST pList) {
	// �����ʹ� �������̸� �ʱ�ȭ�� �� �� NULL(0)���� �ʱ�ȭ�صΰ� ���°� ����.
	// �ֳĸ� 0�� false 0 �� �ƴ� ��� ���� true�̱� �����̴�.
	pList->iSize = 0;

	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	// ���۳���� �������� ������ ����̴�.
	pList->pBegin->pNext = pList->pEnd;
	// ����������� ���� ���� ���۳���̴�.
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
	cout << "======================= �л��߰� ========================" << endl;
	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);
	cout << "�й� : ";
	tStudent.iNumber = InputInt();
	cout << "���� : ";
	tStudent.iKor = InputInt();
	cout << "���� : ";
	tStudent.iEng = InputInt();
	cout << "���� : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;


	PNODE pNode = new NODE;
	pNode->tStudent = tStudent;

	// ���� �߰��Ǵ� ���� END����� �������� End��� ���̿� �߰��ؾ� �Ѵ�.
	// �׷��� pEnd�� pPrev��带 ���س��´�
	PNODE pPrev = pList->pEnd->pPrev;
	// pEnd��� ���� ����� �������� �߰��� ��带 �����Ѵ�.
	pPrev->pNext = pNode;
	// �߰��� ����� ���� ���� End�� ���� ��带 �����Ѵ�.
	pNode->pPrev = pPrev;

	//���� �߰��� ����� ���� ��带 pEnd�� ����
	pNode->pNext = pList->pEnd;
	// pEnd����� ���� ���� ���� �߰��� ��带 ����.
	pList->pEnd->pPrev = pNode;

	++pList->iSize;
}

void Sort(PLIST pList) {
	system("cls");
	cout << "=========================== �л����� ==========================" << endl;
	cout << "1. �й�����" << endl;
	cout << "2. ��ձ���" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iInput = InputInt();

	if (iInput <= SORT_NONE || iInput > SORT_AVG) {
		cout << "�߸� �����Ͽ����ϴ�." << endl;
		system("pause");
		return;
	}

	PNODE pFirst = pList->pBegin->pNext;
	PNODE pSecond = pFirst->pNext;

	while (pFirst != pList->pEnd->pPrev) {
		// Second�� ������ First ��� ���� ������ �˻縦 �����Ѵ�
		pSecond = pFirst->pNext;
		//Second�� End�������� �ݺ��ؾ� �ϹǷ� End�� �ƴҵ��ȸ� �ݺ��Ѵ�.
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
				// First����� ������ ���� ��带 �����Ѵ�.
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;
				// Second����� ������ ���� ��带 �����Ѵ�.
				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;

				pFirstPrev->pNext = pSecond;
				pSecond->pPrev = pFirstPrev;

				//�ٲٷ��� �� ��尡 �پ��մ� ���
				if (pSecond != pFirstNext) {
					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;
				}
				//������ �ִ� ���
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

	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	system("pause");
}

void Pust_Front(PLIST pList) {

}

void OutputStudent(const PSTUDENT pStudent) {
	cout << "�̸� : " << pStudent->strName << "\t�й� : " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t���� : " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << endl;
	cout << "���� : " << pStudent->iTotal << "\t��� : " << pStudent->fAvg << endl << endl;
}

void Output(PLIST pList) {
	int iMenu;
	while (true) {
		system("cls");
		cout << "===========================�л����==========================" << endl;
		cout << "1. ������ ���" << endl;
		cout << "2. ������ ���" << endl;
		cout << "�޴��� �����ϼ��� : ";
		iMenu = InputInt();

		if (iMenu > OP_NONE&&iMenu <= OP_REVERSE)
			break;
	}
	PNODE pNode = NULL;

	switch (iMenu) {
	case OP_OUTPUT:
		// �߰��Ǵ� ������ begin�� end ���̿� ��ġ�ȴ�. �׷��Ƿ� begin�� ���� 
		// ��带 ���´�.
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
	cout << "===========================�л�Ž��==========================" << endl;

	cout << "Ž���� �̸��� �Է��ϼ��� : ";
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

	cout << "�л��� ã�� ���Ͽ����ϴ�." << endl;
	system("pause");
}
void Delete(PLIST pList){
	system("cls");
	cout << "===========================�л�����==========================" << endl;

	cout << "Ž���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			// ���� ���� ����� ��������� ������ ���� ���� ���� �Ǿ��մ�.
			// ���� ���� �������� �ϱ� ������ ��������� ������带
			// ���� ����� ���� ���� �Ѵ�.
			// ���� ����� ������ ���� ����ε� �������� �ش�.

			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << "�л��� �����Ͽ����ϴ�" << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "�ش� �л��� ã�� ���Ͽ����ϴ�" << endl;
	system("pause");
}
