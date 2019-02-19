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
	
	//화면을 지운다.
	system("cls");

	srand((unsigned int)time(0));

	int iPlayer,iAi;

	while (true)
	{
		cout << "1. 바위" << endl;
		cout << "2. 가위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;

		cout << "메뉴를 입력하시오 : ";
		cin >> iPlayer;

		if (iPlayer < RSP_R || iPlayer>RSP_END) {
			cout << "잘못된 값을 입력하였습니다." << endl;
			system("pause");
			continue;
		}
		else if (iPlayer == RSP_END)
			break;
		
		//봇이 생성을 한다.
		iAi = (rand() % 3 + 1);
		
		switch (iAi) {
		case RSP_R:
			cout << "AI = 바위" << endl;
			break;
		case RSP_S:
			cout << "AI = 가위" << endl;
			break;
		case RSP_P:
			cout << "AI = 보" << endl;
			break;
		}
		
		int iWin = iPlayer - iAi;
		if (iWin == -1 || iWin == 2)
			cout << "플레이어 승리!" << endl;
		else if (iWin == 0)
			cout << "비겼습니다" << endl;
		else
			cout << "AI 승리!!" << endl;
	}

	return 0;
}