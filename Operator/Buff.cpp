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
	// ���� ������ ������ �ٶ� or������ ���

	cout << "Attack : " << (iBuf&iAttack) << endl;
	cout << "Armor : " << (iBuf&iArmor) << endl;
	cout << "HP: " << (iBuf&iHP) << endl;
	cout << "MP : " << (iBuf&iMP) << endl;
	cout << "Critical : " << (iBuf&iCritical) << endl;
	// ���� Ȯ�� �ÿ��� and������ ���

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

	int iNumber2 = 10;
	cout << ++iNumber2 << endl;
	cout << iNumber2++ << endl;
	cout << iNumber2 << endl;
	return 0;
}