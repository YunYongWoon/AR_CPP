#include <iostream>
#include <time.h>
using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER { // �� ���� ��
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

// �Լ��� ����� ���� �κ����� ���� �� �ִ�.
void SetNumber(int *pArray);
void Shuffle(int *pArray);
AI_MODE SelectAiMode();
void OutputNumber(int *pArray, int iBingo);
bool ChangeNumber(int *pArray, int iInput);
int SelectAiNumber(int *pArray,AI_MODE eMode); 
int BingoCounting(int *pArray);
int BingoCountingH(int *pArray);
int BingoCountingV(int *pArray);
int BingoCountingLTD(int *pArray);
int BingoCountingRTD(int *pArray);

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAiNumber[25] = {};


	SetNumber(iNumber);
	SetNumber(iAiNumber);
	// ������ ������ �迭
	Shuffle(iNumber);
	Shuffle(iAiNumber);



	int iBingo = 0, iAiBingo = 0;
	// AI ���̵� ����
	AI_MODE eAimode = SelectAiMode();

	while (true) {
		system("cls");

		// �÷��̾� ���� 5X5�� ����ϱ�
		cout << "++++++++++ �÷��̾� ++++++++++" << endl;
		OutputNumber(iNumber, iBingo);
		cout << "++++++++++++++ AI +++++++++++++" << endl;
		switch (eAimode) {
		case AM_EASY:
			cout << "AiMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AiMode : Hard" << endl;
		}
		OutputNumber(iAiNumber, iAiBingo);

		//�� ���� 5 �̻��̸� ���� ����
		if (iBingo >= 5) {
			cout << "�÷��̾� �¸�!!" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "Ai �¸�!!" << endl;
			break;
		}

		cout << "���� �Է��Ͻÿ�(0�� ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25)
			continue;

		//�ߺ�üũ�� ���� ����.
		bool bAcc = ChangeNumber(iNumber, iInput);


		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� 
		//���ڰ� �ִ����� ã�Ƴ���.
		//bAcc������ true�� ���, �ߺ��� ���ڸ� �Է��� ���̹Ƿ� ���ڸ� *�� 
		//�ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�.
		if (bAcc)
			continue;


		//�ߺ��� �ƴ϶�� Ai�� ���ڵ� ã�Ƽ� *�� �ٲپ��ش�.
		ChangeNumber(iAiNumber, iInput);

		
		iInput = SelectAiNumber(iAiNumber, eAimode);
		// Ai�� ���ڸ� ���������Ƿ� �÷��̾�� Ai�� ���ڸ� *�� �ٲپ��ش�.	
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		//���� �� �� üũ�ϴ°��� �Ź� ���ڸ� �Է��� ������ ó������
		//���� ī��Ʈ�Ѵ�. �׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ ��
		//���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = BingoCounting(iNumber);
		iAiBingo = BingoCounting(iAiNumber);
	}

	return 0;
}

void SetNumber(int *pArray) {
	for (int i = 0; i < 25; i++)
		pArray[i] = i+1;
};

void Shuffle(int *pArray) {
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		// �÷��̾� ���ڸ� �����ش�.
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;

	}
}

AI_MODE SelectAiMode() {
	int iAimode;
	while (true) {
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��带 �����Ͻÿ� : ";
		cin >> iAimode;

		if (iAimode >= AM_EASY && iAimode <= AM_HARD) {
			break;
		}		
	}
	return (AI_MODE)iAimode;
}

void OutputNumber(int *pArray, int iBingo) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pArray[i * 5 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << pArray[i * 5 + j] << "\t";
		}
		cout << endl;
	}

	cout << "Bingo : " << iBingo << endl;
}

bool ChangeNumber(int *pArray, int iInput) {
	//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� 
	//���ڰ� �ִ����� ã�Ƴ���.
	for (int i = 0; i < 25; ++i) {
		if (iInput == pArray[i]) {
			//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ� bAcc������
			//false�� ������ش�.

			// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
			pArray[i] = INT_MAX;
			// �ٸ� ���ڸ� ã�� �ʿ䰡 �����Ƿ� break
			return false;
		}
	}
	return true;
}

int SelectAiNumber(int *pArray, AI_MODE eMode) {
	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	//Ai�� ������ �Ѵ�. 
	switch (eMode) {
	case AM_EASY:
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; i++) {
			// ���� ���ڰ� *�� �ƴҰ��
			if (pArray[i] != INT_MAX) {
				// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ��
				// �Ѵ�. ���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� ����
				// ���Ѽ� �� ���þȵ� ������ �����ش�.
				// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0�� �ְ� ++�ؼ� 1�� �߰��Ǿ��ٰ�
				// �Ѵ�.
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}
		// for���� ���������� �Ǹ� ���þȵ� ����� ���������
		// ���þȵ� ����� ������ ��������� �ȴ�.
		// ���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ����
		// �ε����� �����ϰ� �����ش�.
		return iNoneSelect[rand() % iNoneSelectCount];

	case AM_HARD:
		// ���ɼ��� ���� ū ���� �����ϰ� �Ѵ�.(5���� ���� ����)
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		// ���μ��� ���� �� ���� *�� ���� ���� ã��
		for (int i = 0; i < 5; i++) {
			iStarCount = 0;
			for (int j = 0; j < 5; j++) {
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}
			// ���� 5�� �̸��̾�� �������� �ƴϴ�.
			// ������ �����ٴ� Ŀ�� ���� ���� ���� �����̹Ƿ�
			// ������ ��ü���ְ� ���� ������ ����.
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				// ���� ������ ���� ���� ���� ���� üũ
				// ���� ������ 0~4 �ο�
				iLine = i;
				iSaveCount = iStarCount;
			}
		}

		// ���ζ����� ������ ����. ������ ���ζ���.
		for (int i = 0; i < 5; i++) {
			iStarCount = 0;
			for (int j = 0; j < 5; j++) {
				if (pArray[j * 5 + i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		// ���� -> ������ �밢�� üũ

		iStarCount = 0;
		for (int i = 0; i < 25; i += 6) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_LT;
			iSaveCount = iStarCount;

		}

		// ������ -> ���� �밢�� üũ

		iStarCount = 0;
		for (int i = 0; i <= 20; i += 4) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_RT;
			iSaveCount = iStarCount;

		}

		// ���� ���� �Ϸ�. iLine�� ���� ���ɼ��� ���� �� ��ȣ�� �����.
		// �� �ٿ� �ִ� *�� �ƴ� ������ �ϳ� ����.
		if (iLine <= LN_H5) {
			// �������� ���
			for (int i = 0; i < 5; i++) {
				if (pArray[iLine * 5 + i] != INT_MAX) {
					return pArray[iLine * 5 + i];
				}
			}
		}

		else if (iLine <= LN_V5) {
			// �������� ���
			for (int i = 0; i < 5; i++) {
				if (pArray[iLine * 5 + (iLine - 5)] != INT_MAX) {
					return pArray[iLine * 5 + (iLine - 5)];
				}
			}
		}

		else if (iLine == LN_LT) {
			for (int i = 0; i < 25; i += 6) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}

		else if (iLine == LN_RT) {
			for (int i = 0; i < 24; i += 4) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}
		break;
	}
	return -1;
}

int BingoCounting(int *pArray) {
	int iBingo = 0;
	iBingo += BingoCountingH(pArray);
	iBingo += BingoCountingV(pArray);
	iBingo += BingoCountingRTD(pArray);
	iBingo += BingoCountingLTD(pArray);

	return iBingo;
}

int BingoCountingH(int *pArray) {
	//���� �� �� ���ϱ�
	int iStar1 = 0, iBingo = 0;


	for (int i = 0; i < 5; i++) {
		//�� ���� üũ�ϱ� ���� ���� 0���� �� ���� �ʱ�ȭ
		iStar1 = 0;
		for (int j = 0; j < 5; j++) {
			//���� �� �� ���ϱ�
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}


int BingoCountingV(int *pArray) {
	//���� �� �� ���ϱ�
	int iStar1 = 0, iBingo = 0;


	for (int i = 0; i < 5; i++) {
		//�� ���� üũ�ϱ� ���� ���� 0���� �� ���� �ʱ�ȭ
		iStar1 = 0;
		for (int j = 0; j < 5; j++) {
			//���� �� �� ���ϱ�
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}

int BingoCountingLTD(int *pArray) {
	// �»��->���ϴ� �밢��
	int iStar = 0,iBingo = 0;
	for (int i = 0; i < 25; i += 6) {
		if (pArray[i] == INT_MAX)
			++iStar;
	}
	if (iStar == 5)
		++iBingo;

	return iBingo;
}

int BingoCountingRTD(int *pArray) {
	// ����->���ϴ� �밢��
	int iStar = 0, iBingo = 0;
	for (int i = 0; i < 24; i += 4) {
		if (pArray[i] == INT_MAX)
			++iStar;
	}
	if (iStar == 5)
		++iBingo;

	return iBingo;
}