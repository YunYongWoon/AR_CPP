#include <iostream>
using namespace std;

#define  NAME_SIZE   64

// ����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�
//          ��������� ���� Ÿ�Դϴ�
//  ����  : struct ����ü��{};�� ���·� �����ȴ�
// �迭�� ����ü�� ������
// 1. ������ �����̴�
// 2. ���ӵ� �޸� ���� �Ҵ�ȴ�. ����ü ������� ���ӵ� �޸� ������ ������ �ȴ�.
struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main() {
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// ����ü ����� ������ ���� .�� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;

	// ���ڿ��� �迭���ٰ� ���� ������ �ܼ� �������δ� �Ұ��ϴ�.
	// strcpy_s�� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
	// �����ʿ� �ִ� ���ڿ��� �������� ������ �ִ� �����̴�.

	strcpy_s(tStudent.strName, "�����ٶ� asdf");
	strcat_s(tStudent.strName, " ���ڿ� ���̱�");
	cout << "�̸����� : " << strlen(tStudent.strName) << endl;
	//strlen : ���ڿ��� ũ�⸦ Ȯ�����ִ� �Լ�
	//strcat_s : ���ڿ��� �ٿ��ִ� ����� �Լ�
	//strcmp : �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ, �ٸ���� 0�� �ƴ� ���� ��ȯ�Ѵ�.

	char strName[NAME_SIZE] = {};
	strcpy_s(tStudent.strName, "ȫ�浿");
	cout << "����� �̸��� : ";
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
		cout << "�л��� ã�ѽ��ϴ�" << endl;
	else
		cout << "�л��� ã�� ���Ͽ����ϴ�." << endl;
	
	

	// ���ڿ��� ���� �׻� NULL�� ������ �Ѵ�.
	// ������ �����Ⱚ�� ���ִ� ���¿��� �� �迭��ҿ� ���� �־��ְ� �Ǹ� �� ���� ��µǰ� 
	// ������ �κ��� �����Ⱚ���� ��µȴ�. �ֳ��ϸ� ����Ҷ� ���ڿ��� ���� �ν��� �� ���� �����̴�. 
	// NULL�� ���� �Ǵµ� �����Ⱚ�� �� �ֱ� �����̴�.
	
	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "��� : " << tStudent.fAvg << endl;

	return 0;
}