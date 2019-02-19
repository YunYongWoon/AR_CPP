#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 25; i++) {
		iNumber[i] = i + 1;
	}
	// ������ ������ �迭
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iBingo = 0;

	while (true) {
		system("cls");

		//���� 5X5�� ����ϱ�
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

		//�� ���� 5 �̻��̸� ���� ����
		if (iBingo >= 5) {
			break;
		}

		cout << "���� �Է��Ͻÿ�(0�� ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25) {
			continue;
		}
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

		//���� �� �� üũ�ϴ°��� �Ź� ���ڸ� �Է��� ������ ó������
		//���� ī��Ʈ�Ѵ�. �׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ ��
		//���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;

		//���� ���� �� �� ���ϱ�
		int iStar1;
		int iStar2;

		for (int i = 0; i < 5; i++) {
			//�� ���� üũ�ϱ� ���� ���� 0���� �� ���� �ʱ�ȭ
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; j++) {
				//���� �� �� ���ϱ�
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				//���� �� �� ���ϱ�
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
			}
			//j for���� ���������� ���� ���� ���� �� ������ ����� iStar1
			//������ ���� �ȴ�. iStar1,iStar2 ���� 5�̸� ������ ���
			//*�̶�� �ǹ̹Ƿ� ���� �� ī��Ʈ�� �߰��� �ش�.
			if (iStar1 == 5)
				++iBingo;
			if (iStar2 == 5)
				++iBingo;


		}
		// ����->���ϴ� �밢��
		iStar1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		// �»��->���ϴ� �밢��
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;


	}

	return 0;
}