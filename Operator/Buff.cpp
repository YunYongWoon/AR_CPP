#include <iostream>
#include <time.h>
using namespace std;

int main() {
	const int iAttack = 0x00000001; //00001
	const int iArmor = 0x00000002; //00010
	const int iHP = 0x00000004; //00100
	const int iMP = 0x00000008; //01000
	const int iCritical = 0x00000010; //10000

	//00001 | 00100 = 00101 
	//00101 | 10000 = 10101

	int iBuf = iAttack | iHP | iCritical;
	// 게임 내에서 버프를 줄땐 or연산자 사용

	cout << "Attack : " << (iBuf&iAttack) << endl;
	cout << "Armor : " << (iBuf&iArmor) << endl;
	cout << "HP: " << (iBuf&iHP) << endl;
	cout << "MP : " << (iBuf&iMP) << endl;
	cout << "Critical : " << (iBuf&iCritical) << endl;
	// 버프 확인 시에는 and연산자 사용

	//쉬프트연산자
	cout << (20 << 2) << endl;
	cout << (20 << 3) << endl;
	cout << (20 << 4) << endl;
	cout << (20 >> 2) << endl;
	cout << (20 >> 3) << endl;
	cout << (20 >> 4) << endl;

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;
	
	
	iNumber <<= 16;
	iNumber |= iLow;
	cout << "High = " << (iNumber >> 16) << endl;
	cout << "Low = " << (iNumber & 0x0000ffff) << endl;
	
	//증감연산자
	int iNumber2 = 10;
	cout << ++iNumber2 << endl;
	cout << iNumber2++ << endl;
	cout << iNumber2 << endl;

	//if 조건문
	if ((iBuf & iArmor) != 0)
		cout << "Armor 버프가 있습니다." << endl;
	if ((iBuf & iHP) != 0)
		cout << "HP 버프가 있습니다." << endl;
	if ((iBuf & iMP) != 0)
		cout << "MP 버프가 있습니다." << endl;
	if ((iBuf & iAttack) != 0)
		cout << "Attack 버프가 있습니다." << endl;
	if ((iBuf & iCritical) != 0)
		cout << "Critical 버프가 있습니다." << endl;

	//if, else, else if
	if (false)
		cout << "if문 조건 true" << endl;
	else
		cout << "if문 조건 false" << endl;

	//cin >> iNumber;
	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20 사이의 숫자이다" << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21~30 사이의 숫자이다" << endl;
	else
		cout << "그 외의 숫자이다." << endl;

	//난수 발생
	srand((unsigned int)time(0));
	cout << rand() << endl;
	cout << rand() << endl;
	//값이 랜덤이다
	cout << (rand() % 100) << endl;
	// 0~99까지의 숫자를 가져온다.
	cout << (rand() % 100 + 100) << endl;
	// 100~199까지의 숫자를 가져온다.

	int iUpgrade;
	cout << "업그레이드 기본 수치를 입력하세요: ";
	cin >> iUpgrade;
	

	//강화 확률을 구한다.
	float fPercent = rand() % 10000 / 100.f;
	cout << "업그레이드 : " << iUpgrade << endl;
	cout << "확률 : " << fPercent << endl;

	// 강화 시도
	if (iUpgrade <= 3)
		cout << "강화성공" << endl;
	if (4 <= iUpgrade&&iUpgrade <= 6) {
		if (fPercent < 40.f)
			cout << "강화성공" << endl;
		else
			cout << "강화실패" << endl;
	}
	if (7 <= iUpgrade&&iUpgrade <= 10) {
		if (fPercent < 20.f)
			cout << "강화성공" << endl;
		else
			cout << "강화실패" << endl;
	}
	if (11 <= iUpgrade&&iUpgrade <= 15) {
		if (fPercent < 10.f)
			cout << "강화성공" << endl;
		else
			cout << "강화실패" << endl;
	}
	if (16 <= iUpgrade&&iUpgrade <= 20) {
		if (fPercent < 1.f)
			cout << "강화성공" << endl;
		else
			cout << "강화실패" << endl;
	}


	return 0;
}