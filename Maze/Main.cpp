#include <iostream>
#include <conio.h>
using namespace std;

struct _tagPoint {
	int x;
	int y;
};

// Ÿ���� �������ϴ� �Լ�
typedef _tagPoint  POINT;
typedef _tagPoint*  PPOINT;

void SetMaze(char Maze[21][21],PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pFinishPos) {
	pStartPos->x = 0;
	pStartPos->y = 0;

	pFinishPos->x = 19;
	pFinishPos->y = 19;

	*pPlayerPos = *pStartPos;
	/*
	0 : ��
	1 : ��
	2 : ������
	3 : ������
	4 : ��ź
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

void Output(char Maze[21][21],PPOINT pPlayerPos) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (Maze[i][j] == '4')
				cout << "��";
			else if (pPlayerPos->x == j&&pPlayerPos->y == i)
				cout << "��";			
			else if (Maze[i][j] == '0')
				cout << "��";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "��";
			else if (Maze[i][j] == '3')
				cout << "��";
		}
		cout << endl;
	}
}
// ������ ������ const�� �����ϸ� ����Ű�� ����� ���� ������ �� ����.
void CreateBomb(char Maze[21][21], const PPOINT pPlayer,
	PPOINT pBombArr, int *pBombCount) {
	if (*pBombCount == 5)
		return;
	for (int i = 0; i < *pBombCount; i++) {
		if (pPlayer->x == pBombArr[i].x&&pPlayer->y == pBombArr[i].y)
			return;
	}
	pBombArr[*pBombCount] = *pPlayer;
	++(*pBombCount);

	Maze[pPlayer->y][pPlayer->x] = '4';
}

void FireBomb(char Maze[21][21], PPOINT pPlayer, PPOINT pBombArr, int* pBombCount) {
	for (int i = 0; i < *pBombCount; i++) {
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		if (pPlayer->x == pBombArr[i].x&&pPlayer->y == pBombArr[i].y) {
			pPlayer->x = 0;
			pPlayer->y = 0;
		}
		if (pBombArr[i].y - 1 >= 0) {
			if (Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';
			// �÷��̾ ��ź �ݰ濡 ���� ��
			if (pPlayer->x == pBombArr[i].x&&pPlayer->y == pBombArr[i].y - 1) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].y + 1 < 20) {
			if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';
			// �÷��̾ ��ź �ݰ濡 ���� ��
			if (pPlayer->x == pBombArr[i].x&&pPlayer->y  == pBombArr[i].y + 1) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].x - 1 >= 0) {
			if (Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';
			// �÷��̾ ��ź �ݰ濡 ���� ��
			if (pPlayer->x == pBombArr[i].x - 1&&pPlayer->y == pBombArr[i].y) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
		if (pBombArr[i].x + 1 < 20) {
			if (Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';
			// �÷��̾ ��ź �ݰ濡 ���� ��
			if (pPlayer->x == pBombArr[i].x + 1&&pPlayer->y== pBombArr[i].y) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
	}

	*pBombCount = 0;
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y - 1 >= 0) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0'&&
			Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
			--pPlayerPos->y;
	}
}
void MoveDown(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y + 1 < 20) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
			++pPlayerPos->y;
	}
}
void MoveLeft(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x - 1 >= 0) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
			--pPlayerPos->x;
	}
}
void MoveRight(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x + 1 <20) {
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0'&&
			Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
			++pPlayerPos->x;
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cinput) {
	switch (cinput) {
	case'w':
	case'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case's':
	case'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;

	}
}



int main() {
	// 20X20 �̷θ� ����� �ش�.
	char strMaze[21][21];

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tFinishPos;

	int iBombCount = 0;
	POINT tBombPos[5];

	// �̷θ� �����Ѵ�.
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tFinishPos);


	while (true) {
		system("cls");
		// �̷θ� ����Ѵ�.
		Output(strMaze, &tPlayerPos);
		if (tPlayerPos.x == tFinishPos.x&&tPlayerPos.y == tFinishPos.y) {
			cout << "�����Ͽ����ϴ�" << endl;
			break;
		}

		cout << "t : ��ź��ġ, u : ��ź ��Ʈ����" << endl;
		cout << "w : ��, a : ����, s : �Ʒ�, d : ������, q : ����" << endl;
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;
		else if (cInput == 't' || cInput == 'T')
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		else if (cInput == 'u' || cInput == 'U')
			FireBomb(strMaze,&tPlayerPos,tBombPos, &iBombCount);
		else
			MovePlayer(strMaze, &tPlayerPos, cInput);

	}
}