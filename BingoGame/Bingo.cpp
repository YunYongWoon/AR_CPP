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

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAiNumber[25] = {};


	for (int i = 0; i < 25; i++) {
		iNumber[i] = i + 1;
		iAiNumber[i] = i + 1;
	}
	// ������ ������ �迭
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		// �÷��̾� ���ڸ� �����ش�.
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// Ai ���ڵ� �����ش�.

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAiNumber[idx1];
		iAiNumber[idx1] = iAiNumber[idx2];
		iAiNumber[idx2] = iTemp;
	}

	int iBingo = 0, iAiBingo = 0;
	int iAimode;

	// AI ���̵� ����
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

	// Ai Easy���� ���� Ai�� ���ڸ���� *�� �ٲ��� ���� ���� ����� ����
	// �� ��� �� �ϳ��� �����ϰ� �Ѵ�. (�����ϰ�)

	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	


	while (true) {
		system("cls");

		// �÷��̾� ���� 5X5�� ����ϱ�
		cout << "++++++++++ �÷��̾� ++++++++++" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << "Bingo : " << iBingo << endl;

		cout << "++++++++++++++ AI +++++++++++++" << endl;

		switch (iAimode) {
		case AM_EASY:
			cout << "AiMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AiMode : Hard" << endl;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iAiNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAiNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << "AIBingo : " << iAiBingo << endl;

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
		bool bAcc = true;


		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� 
		//���ڰ� �ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {
				//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ� bAcc������
				//false�� ������ش�.
				bAcc = false;
				// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;
				// �ٸ� ���ڸ� ã�� �ʿ䰡 �����Ƿ� break
				break;
			}

		}
		//bAcc������ true�� ���, �ߺ��� ���ڸ� �Է��� ���̹Ƿ� ���ڸ� *�� 
		//�ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�.
		if (bAcc)
			continue;

		//�ߺ��� �ƴ϶�� Ai�� ���ڵ� ã�Ƽ� *�� �ٲپ��ش�.
		for (int i = 0; i < 25; i++) {
			if (iAiNumber[i] == iInput) {
				iAiNumber[i] = INT_MAX;
				break;
			}
		}

		//Ai�� ������ �Ѵ�. 
		switch (iAimode) {
		case AM_EASY:
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; i++) {
				// ���� ���ڰ� *�� �ƴҰ��
				if (iAiNumber[i] != INT_MAX) {
					// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ��
					// �Ѵ�. ���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� ����
					// ���Ѽ� �� ���þȵ� ������ �����ش�.
					// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0�� �ְ� ++�ؼ� 1�� �߰��Ǿ��ٰ�
					// �Ѵ�.
					iNoneSelect[iNoneSelectCount] = iAiNumber[i];
					++iNoneSelectCount;
				}
			}
			// for���� ���������� �Ǹ� ���þȵ� ����� ���������
			// ���þȵ� ����� ������ ��������� �ȴ�.
			// ���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ����
			// �ε����� �����ϰ� �����ش�.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			// ���ɼ��� ���� ū ���� �����ϰ� �Ѵ�.(5���� ���� ����)
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���μ��� ���� �� ���� *�� ���� ���� ã��
			for (int i = 0; i < 5; i++) {
				iStarCount = 0;
				for (int j = 0; j < 5; j++) {
					if (iAiNumber[i * 5 + j] == INT_MAX)
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
					if (iAiNumber[j * 5 + i] == INT_MAX)
						++iStarCount;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount) {
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// ���� -> ������ �밢�� üũ
			
			iStarCount = 0;
			for (int i = 0; i < 25; i+=6) {
				if (iAiNumber[i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_LT;
				iSaveCount = iStarCount;
				
			}

			// ������ -> ���� �밢�� üũ

			iStarCount = 0;
			for (int i = 0; i <= 20; i += 4) {
				if (iAiNumber[i] == INT_MAX)
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
					if (iAiNumber[iLine * 5 + i] != INT_MAX) {
						iInput = iAiNumber[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5) {
				// �������� ���
				for (int i = 0; i < 5; i++) {
					if (iAiNumber[iLine * 5 + (iLine - 5)] != INT_MAX) {
						iInput = iAiNumber[iLine * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT) {
				for (int i = 0; i < 25; i+=6) {
					if (iAiNumber[i] != INT_MAX) {
						iInput = iAiNumber[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT) {
				for (int i = 0; i < 24; i += 4) {
					if (iAiNumber[i] != INT_MAX) {
						iInput = iAiNumber[i];
						break;
					}
				}
			}
			break;
		}

		// Ai�� ���ڸ� ���������Ƿ� �÷��̾�� Ai�� ���ڸ� *�� �ٲپ��ش�.
		for (int i = 0; i < 25; i++) {
			if (iNumber[i] == iInput) {
				iNumber[i] = INT_MAX;
				break;
			}

		}

		// Ai ���ڵ� �ٲپ��ش�.
		for (int i = 0; i < 25; i++) {
			if (iAiNumber[i] == iInput) {
				iAiNumber[i] = INT_MAX;
				break;
			}
		}

		//���� �� �� üũ�ϴ°��� �Ź� ���ڸ� �Է��� ������ ó������
		//���� ī��Ʈ�Ѵ�. �׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ ��
		//���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0, iAiBingo = 0;

		//���� ���� �� �� ���ϱ�
		int iStar1=0;
		int iStar2=0;
		int iAiStar1 = 0;
		int iAiStar2=0;

		for (int i = 0; i < 5; i++) {
			//�� ���� üũ�ϱ� ���� ���� 0���� �� ���� �ʱ�ȭ
			iStar1 = iStar2 = 0;
			iAiStar1 = iAiStar2 = 0;
			for (int j = 0; j < 5; j++) {
				//���� �� �� ���ϱ�
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				//���� �� �� ���ϱ�
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
				//Ai���� �� �� ���ϱ�
				if (iAiNumber[i * 5 + j] == INT_MAX)
					++iAiStar1;
				//Ai���� �� �� ���ϱ�
				if (iAiNumber[j * 5 + i] == INT_MAX)
					++iAiStar2;
			}
			//j for���� ���������� ���� ���� ���� �� ������ ����� iStar1
			//������ ���� �ȴ�. iStar1,iStar2 ���� 5�̸� ������ ���
			//*�̶�� �ǹ̹Ƿ� ���� �� ī��Ʈ�� �߰��� �ش�.
			if (iStar1 == 5)
				++iBingo;
			if (iStar2 == 5)
				++iBingo;
			if (iAiStar1 == 5)
				++iAiBingo;
			if (iAiStar2 == 5)
				++iAiBingo;


		}
		// ����->���ϴ� �밢��
		iStar1 = 0;
		iAiStar1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		for (int i = 4; i <= 20; i += 4) {
			if (iAiNumber[i] == INT_MAX)
				++iAiStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		if (iAiStar1 == 5)
			++iAiBingo;
		// �»��->���ϴ� �밢��
		iStar1 = 0;
		iAiStar1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		for (int i = 0; i < 25; i += 6) {
			if (iAiNumber[i] == INT_MAX)
				++iAiStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		if (iAiStar1 == 5)
			++iAiBingo;


	}

	return 0;
}