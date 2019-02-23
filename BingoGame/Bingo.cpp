#include <iostream>
#include <time.h>
using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER { // 각 빙고 줄
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
	// 빙고판 무작위 배열
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		// 플레이어 숫자를 섞어준다.
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// Ai 숫자도 섞어준다.

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAiNumber[idx1];
		iAiNumber[idx1] = iAiNumber[idx2];
		iAiNumber[idx2] = iTemp;
	}

	int iBingo = 0, iAiBingo = 0;
	int iAimode;

	// AI 난이도 선택
	while (true) {
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선택하시오 : ";
		cin >> iAimode;

		if (iAimode >= AM_EASY && iAimode <= AM_HARD) {
			break;
		}
	}

	// Ai Easy모드는 현재 Ai의 숫자목록중 *로 바뀌지 않은 숫자 목록을 만들어서
	// 그 목록 중 하나를 선택하게 한다. (랜덤하게)

	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	


	while (true) {
		system("cls");

		// 플레이어 숫자 5X5로 출력하기
		cout << "++++++++++ 플레이어 ++++++++++" << endl;
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

		//줄 수가 5 이상이면 게임 종료
		if (iBingo >= 5) {
			cout << "플레이어 승리!!" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "Ai 승리!!" << endl;
			break;
		}

		cout << "값을 입력하시오(0은 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25) 
			continue;
		
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

		//중복이 아니라면 Ai의 숫자도 찾아서 *로 바꾸어준다.
		for (int i = 0; i < 25; i++) {
			if (iAiNumber[i] == iInput) {
				iAiNumber[i] = INT_MAX;
				break;
			}
		}

		//Ai가 선택을 한다. 
		switch (iAimode) {
		case AM_EASY:
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; i++) {
				// 현재 숫자가 *이 아닐경우
				if (iAiNumber[i] != INT_MAX) {
					// *이 아닌 숫자일 경우 iNoneSelectCount를 인덱스로 활용
					// 한다. 선택 안된 목록에 추가할때마다 개수를 1씩 증가
					// 시켜서 총 선택안된 개수를 구해준다.
					// 그런데 0부터 카운트가 시작이므로 0에 넣고 ++해서 1개 추가되었다고
					// 한다.
					iNoneSelect[iNoneSelectCount] = iAiNumber[i];
					++iNoneSelectCount;
				}
			}
			// for문을 빠져나오게 되면 선택안된 목록이 만들어지고
			// 선택안된 목록의 개수가 만들어지게 된다.
			// 선택안된 목록의 숫자중 랜덤한 하나의 숫자를 얻어오기 위해
			// 인덱스를 랜덤하게 구해준다.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			// 가능성이 가장 큰 줄을 선택하게 한다.(5개인 줄은 제외)
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// 가로세로 라인 중 가장 *이 많은 라인 찾기
			for (int i = 0; i < 5; i++) {
				iStarCount = 0;
				for (int j = 0; j < 5; j++) {
					if (iAiNumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}	
				// 별이 5개 미만이어야 빙고줄이 아니다.
				// 라인의 별보다는 커야 가장 별이 많은 라인이므로
				// 라인을 교체해주고 별의 갯수를 센다.
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// 가로 라인중 가장 별이 많은 라인 체크
					// 가로 라인은 0~4 부여
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// 가로라인은 위에서 구함. 다음은 세로라인.
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

			// 왼쪽 -> 오른쪽 대각선 체크
			
			iStarCount = 0;
			for (int i = 0; i < 25; i+=6) {
				if (iAiNumber[i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_LT;
				iSaveCount = iStarCount;
				
			}

			// 오른쪽 -> 왼쪽 대각선 체크

			iStarCount = 0;
			for (int i = 0; i <= 20; i += 4) {
				if (iAiNumber[i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_RT;
				iSaveCount = iStarCount;

			}

			// 라인 저장 완료. iLine에 가장 가능성이 높은 줄 번호가 저장됨.
			// 그 줄에 있는 *이 아닌 숫자중 하나 저장.
			if (iLine <= LN_H5) {
				// 가로줄일 경우
				for (int i = 0; i < 5; i++) {
					if (iAiNumber[iLine * 5 + i] != INT_MAX) {
						iInput = iAiNumber[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5) {
				// 세로줄일 경우
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

		// Ai가 숫자를 선택했으므로 플레이어와 Ai의 숫자를 *로 바꾸어준다.
		for (int i = 0; i < 25; i++) {
			if (iNumber[i] == iInput) {
				iNumber[i] = INT_MAX;
				break;
			}

		}

		// Ai 숫자도 바꾸어준다.
		for (int i = 0; i < 25; i++) {
			if (iAiNumber[i] == iInput) {
				iAiNumber[i] = INT_MAX;
				break;
			}
		}

		//빙고 줄 수 체크하는것은 매번 숫자를 입력할 때마다 처음부터
		//새로 카운트한다. 그러므로 iBingo 변수를 0으로 매번 초기화 후
		//새롭게 줄 수를 구해주도록 한다.
		iBingo = 0, iAiBingo = 0;

		//가로 세로 줄 수 구하기
		int iStar1=0;
		int iStar2=0;
		int iAiStar1 = 0;
		int iAiStar2=0;

		for (int i = 0; i < 5; i++) {
			//한 줄을 체크하기 전에 먼저 0으로 별 갯수 초기화
			iStar1 = iStar2 = 0;
			iAiStar1 = iAiStar2 = 0;
			for (int j = 0; j < 5; j++) {
				//가로 별 수 구하기
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				//세로 별 수 구하기
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
				//Ai가로 별 수 구하기
				if (iAiNumber[i * 5 + j] == INT_MAX)
					++iAiStar1;
				//Ai세로 별 수 구하기
				if (iAiNumber[j * 5 + i] == INT_MAX)
					++iAiStar2;
			}
			//j for문을 빠져나오면 현재 줄의 가로 별 개수가 몇개인지 iStar1
			//변수에 들어가게 된다. iStar1,iStar2 값이 5이면 한줄이 모드
			//*이라는 의미므로 빙고 줄 카운트를 추가해 준다.
			if (iStar1 == 5)
				++iBingo;
			if (iStar2 == 5)
				++iBingo;
			if (iAiStar1 == 5)
				++iAiBingo;
			if (iAiStar2 == 5)
				++iAiBingo;


		}
		// 우상단->좌하단 대각선
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
		// 좌상단->우하단 대각선
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