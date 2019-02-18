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

	//����Ʈ������
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
	
	//����������
	int iNumber2 = 10;
	cout << ++iNumber2 << endl;
	cout << iNumber2++ << endl;
	cout << iNumber2 << endl;

	//if ���ǹ�
	if ((iBuf & iArmor) != 0)
		cout << "Armor ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iHP) != 0)
		cout << "HP ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iMP) != 0)
		cout << "MP ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iAttack) != 0)
		cout << "Attack ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iCritical) != 0)
		cout << "Critical ������ �ֽ��ϴ�." << endl;

	//if, else, else if
	if (false)
		cout << "if�� ���� true" << endl;
	else
		cout << "if�� ���� false" << endl;

	cin >> iNumber;
	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20 ������ �����̴�" << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21~30 ������ �����̴�" << endl;
	else
		cout << "�� ���� �����̴�." << endl;


	return 0;
}