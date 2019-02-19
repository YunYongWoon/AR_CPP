#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 25; i++) {
		iNumber[i] = i + 1;
	}
	// 빙고판 무작위 배열
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

		//숫자 5X5로 출력하기
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

		//줄 수가 5 이상이면 게임 종료
		if (iBingo >= 5) {
			break;
		}

		cout << "값을 입력하시오(0은 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25) {
			continue;
		}
		//중복체크를 위한 변수.
		bool bAcc = true;

		//모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 
		//숫자가 있는지를 찾아낸다.
		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {
				//숫자를 찾았을 경우 중복된 숫자가 아니므로 bAcc변수를
				//false로 만들어준다.
				bAcc = false;
				// 숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
				iNumber[i] = INT_MAX;
				// 다른 숫자를 찾을 필요가 없으므로 break
				break;
			}

		}
		//bAcc변수가 true일 경우, 중복된 숫자를 입력한 것이므로 숫자를 *로 
		//바꾸지 못햇으므로 다시 입력받게 continue 해준다.
		if (bAcc)
			continue;

		//빙고 줄 수 체크하는것은 매번 숫자를 입력할 때마다 처음부터
		//새로 카운트한다. 그러므로 iBingo 변수를 0으로 매번 초기화 후
		//새롭게 줄 수를 구해주도록 한다.
		iBingo = 0;

		//가로 세로 줄 수 구하기
		int iStar1;
		int iStar2;

		for (int i = 0; i < 5; i++) {
			//한 줄을 체크하기 전에 먼저 0으로 별 갯수 초기화
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; j++) {
				//가로 별 수 구하기
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				//세로 별 수 구하기
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
			}
			//j for문을 빠져나오면 현재 줄의 가로 별 개수가 몇개인지 iStar1
			//변수에 들어가게 된다. iStar1,iStar2 값이 5이면 한줄이 모드
			//*이라는 의미므로 빙고 줄 카운트를 추가해 준다.
			if (iStar1 == 5)
				++iBingo;
			if (iStar2 == 5)
				++iBingo;


		}
		// 우상단->좌하단 대각선
		iStar1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		// 좌상단->우하단 대각선
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