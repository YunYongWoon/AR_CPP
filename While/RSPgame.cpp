#include <iostream>
#include <time.h>
using namespace std;


enum RSP {
	RSP_R = 1,
	RSP_S,
	RSP_P,
	RSP_END
};


int main() {
	int iNumber = 0;

	while (iNumber < 10){ 
		cout << iNumber << endl; 
		++iNumber;
		
		if (iNumber == 4) {
			break;
		}
	}
	
	//ȭ���� �����.
	system("cls");

	srand((unsigned int)time(0));

	int iPlayer,iAi;

	while (true)
	{
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl;

		cout << "�޴��� �Է��Ͻÿ� : ";
		cin >> iPlayer;

		if (iPlayer < RSP_R || iPlayer>RSP_END) {
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			system("pause");
			continue;
		}
		else if (iPlayer == RSP_END)
			break;
		
		//���� ������ �Ѵ�.
		iAi = (rand() % 3 + 1);
		
		switch (iAi) {
		case RSP_R:
			cout << "AI = ����" << endl;
			break;
		case RSP_S:
			cout << "AI = ����" << endl;
			break;
		case RSP_P:
			cout << "AI = ��" << endl;
			break;
		}
		
		int iWin = iPlayer - iAi;
		if (iWin == -1 || iWin == 2)
			cout << "�÷��̾� �¸�!" << endl;
		else if (iWin == 0)
			cout << "�����ϴ�" << endl;
		else
			cout << "AI �¸�!!" << endl;
	}

	return 0;
}