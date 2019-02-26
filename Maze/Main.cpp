#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

struct _tagPoint {
	int x;
	int y;
};

typedef struct _tagPlayer {
	_tagPoint tPos;
	bool bWallPush;
	bool bTransparency;
	int iBombPower;
}PLAYER, *PPLAYER;

// 타입을 재정의하는 함수
typedef _tagPoint  POINT;
typedef _tagPoint*  PPOINT;

void SetMaze(char Maze[21][21],PPLAYER pPlayer, PPOINT pStartPos, PPOINT pFinishPos) {
	pStartPos->x = 0;
	pStartPos->y = 0;

	pFinishPos->x = 19;
	pFinishPos->y = 19;

	pPlayer->tPos = *pStartPos;
	/*
	0 : 벽
	1 : 길
	2 : 시작점 
	3 : 도착점
	4 : 폭탄
	*/
	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111110000011110");
	strcpy_s(Maze[2],  "00100000011111110010");
	strcpy_s(Maze[3],  "00100000000000010010");
	strcpy_s(Maze[4],  "01111111100000010010");
	strcpy_s(Maze[5],  "01000000001111110010");
	strcpy_s(Maze[6],  "01000000000000000010");
	strcpy_s(Maze[7],  "01111111100000111010");
	strcpy_s(Maze[8],  "00000000100000100010");
	strcpy_s(Maze[9],  "00000000111111100010");
	strcpy_s(Maze[10], "00000000000000000010");
	strcpy_s(Maze[11], "11111111100000000010");
	strcpy_s(Maze[12], "00000000111111111110");
	strcpy_s(Maze[13], "00010000100000000000");
	strcpy_s(Maze[14], "00010000111111110000");
	strcpy_s(Maze[15], "00011111100000010010");
	strcpy_s(Maze[16], "00000000100000010010");
	strcpy_s(Maze[17], "00000000100000100010");
	strcpy_s(Maze[18], "00111111111111111110");
	strcpy_s(Maze[19], "00000000000000000013");
}

void Output(char Maze[21][21],PPLAYER pPlayer) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (Maze[i][j] == '4')
				cout << "♨";
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "☆";			
			else if (Maze[i][j] == '0')
				cout << "■";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "★";
			else if (Maze[i][j] == '3')
				cout << "◎";
			else if (Maze[i][j] == '5')
				cout << "㈜";
			else if (Maze[i][j] == '6')
				cout << "※";
			else if (Maze[i][j] == '7')
				cout << "○";
		}
		cout << endl;
	}

	cout << "폭탄파워 : " << pPlayer->iBombPower << endl;
	cout << "벽통과 : ";
	if (pPlayer->bTransparency)
		cout << "ON\t";
	else
		cout << "OFF\t";

	cout << "벽밀기 : ";
	if (pPlayer->bWallPush)
		cout << "ON" << endl;
	else
		cout << "OFF" << endl;
}
// 포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 없다.
void CreateBomb(char Maze[21][21], const PPLAYER pPlayer,
	PPOINT pBombArr, int *pBombCount) {
	if (*pBombCount == 5)
		return;

	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	for (int i = 0; i < *pBombCount; i++) {
		if (pPlayer->tPos.x == pBombArr[i].x &&
			pPlayer->tPos.y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void FireBomb(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount) {
	for (int i = 0; i < *pBombCount; i++) {
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		if (pPlayer->tPos.x == pBombArr[i].x&&pPlayer->tPos.y == pBombArr[i].y) {
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}
		for (int j = 1; j < pPlayer->iBombPower; ++j) {
			if (pBombArr[i].y - j >= 0) {
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
					}
					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
					// 플레이어가 폭탄 반경에 있을 때
					if (pPlayer->tPos.x == pBombArr[i].x&&pPlayer->tPos.y == pBombArr[i].y - j) {
						pPlayer->tPos.x = 0;
						pPlayer->tPos.y = 0;
					}
				}
			}
			if (pBombArr[i].y + j < 20) {
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}
					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
					// 플레이어가 폭탄 반경에 있을 때
					if (pPlayer->tPos.x == pBombArr[i].x&&pPlayer->tPos.y == pBombArr[i].y + j) {
						pPlayer->tPos.x = 0;
						pPlayer->tPos.y = 0;
					}
				}
			}
			if (pBombArr[i].x - j >= 0) {
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';
						else
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
					// 플레이어가 폭탄 반경에 있을 때
					if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y) {
						pPlayer->tPos.x = 0;
						pPlayer->tPos.y = 0;
					}
				}
			}
			if (pBombArr[i].x + j < 20) {
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0') {
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';
						else
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
					// 플레이어가 폭탄 반경에 있을 때
					if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y) {
						pPlayer->tPos.x = 0;
						pPlayer->tPos.y = 0;
					}
				}
			}
		}
	}
	*pBombCount = 0;
}
	
		
		
			
				
			
			
			
			


bool AddItem(char cItemType, PPLAYER pPlayer) {
	if (cItemType == '5') {
		if (pPlayer->iBombPower<5)
			++pPlayer->iBombPower;

		return true;
	}
		
	else if (cItemType == '6') {
		pPlayer->bWallPush = true;
		return true;
	}
	
	else if (cItemType == '7') {
		pPlayer->bTransparency = true;
		return true;
	}	
	return false;
}

void MoveUp(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y - 1 >= 0) {
		if (pPlayer->bTransparency)
			--pPlayer->tPos.y;

		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0'&&
			Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
			--pPlayer->tPos.y;

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x],pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';		
	}
}
void MoveDown(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y + 1 < 20) {
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
			++pPlayer->tPos.y;

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}
void MoveLeft(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x - 1 >= 0) {
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
			--pPlayer->tPos.x;

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}
void MoveRight(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x + 1 <20) {
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0'&&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
			++pPlayer->tPos.x;

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cinput) {
	switch (cinput) {
	case'w':
	case'W':
		MoveUp(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case's':
	case'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;

	}
}

int main() {
	srand((unsigned int)time(0));

	// 20X20 미로를 만들어 준다.
	char strMaze[21][21];

	PLAYER tPlayer = {};

	POINT tStartPos;
	POINT tFinishPos;

	tPlayer.iBombPower = 1;

	int iBombCount;
	POINT tBombPos[5];

	// 미로를 설정한다.
	SetMaze(strMaze, &tPlayer, &tStartPos, &tFinishPos);


	while (true) {
		system("cls");
		// 미로를 출력한다.
		Output(strMaze, &tPlayer);
		if (tPlayer.tPos.x == tFinishPos.x&&tPlayer.tPos.y == tFinishPos.y) {
			cout << "도착하였습니다" << endl;
			break;
		}

		cout << "t : 폭탄설치, u : 폭탄 터트리기, i : 벽 밀기" << endl;
		cout << "w : 위, a : 왼쪽, s : 아래, d : 오른쪽, q : 종료" << endl;
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;
		else if (cInput == 't' || cInput == 'T')
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		else if (cInput == 'u' || cInput == 'U')
			FireBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		else
			MovePlayer(strMaze, &tPlayer, cInput);

	}

	return 0;
}

