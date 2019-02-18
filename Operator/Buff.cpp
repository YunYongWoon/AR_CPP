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

	//cin >> iNumber;
	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20 ������ �����̴�" << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21~30 ������ �����̴�" << endl;
	else
		cout << "�� ���� �����̴�." << endl;

	//���� �߻�
	srand((unsigned int)time(0));
	cout << rand() << endl;
	cout << rand() << endl;
	//���� �����̴�
	cout << (rand() % 100) << endl;
	// 0~99������ ���ڸ� �����´�.
	cout << (rand() % 100 + 100) << endl;
	// 100~199������ ���ڸ� �����´�.

	int iUpgrade;
	cout << "���׷��̵� �⺻ ��ġ�� �Է��ϼ���: ";
	cin >> iUpgrade;
	

	//��ȭ Ȯ���� ���Ѵ�.
	float fPercent = rand() % 10000 / 100.f;
	cout << "���׷��̵� : " << iUpgrade << endl;
	cout << "Ȯ�� : " << fPercent << endl;

	// ��ȭ �õ�
	if (iUpgrade <= 3)
		cout << "��ȭ����" << endl;
	if (4 <= iUpgrade&&iUpgrade <= 6) {
		if (fPercent < 40.f)
			cout << "��ȭ����" << endl;
		else
			cout << "��ȭ����" << endl;
	}
	if (7 <= iUpgrade&&iUpgrade <= 10) {
		if (fPercent < 20.f)
			cout << "��ȭ����" << endl;
		else
			cout << "��ȭ����" << endl;
	}
	if (11 <= iUpgrade&&iUpgrade <= 15) {
		if (fPercent < 10.f)
			cout << "��ȭ����" << endl;
		else
			cout << "��ȭ����" << endl;
	}
	if (16 <= iUpgrade&&iUpgrade <= 20) {
		if (fPercent < 1.f)
			cout << "��ȭ����" << endl;
		else
			cout << "��ȭ����" << endl;
	}


	return 0;
}