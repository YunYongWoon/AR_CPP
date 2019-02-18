#include <iostream>
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

	cin >> iNumber;
	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20 사이의 숫자이다" << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21~30 사이의 숫자이다" << endl;
	else
		cout << "그 외의 숫자이다." << endl;


	return 0;
}