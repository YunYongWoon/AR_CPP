#include <iostream>
using namespace std;

#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14
#define STUDENT_MAX 15

struct _tagStudent {
	char strName[NAME_SIZE];
	char strAdress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};
int main() {
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	// �迭�� �߰��� ������ ������ ������ ������ش�.
	int iStudentCount = 0;
	int istdNumber = 1;

	char  strName[NAME_SIZE] = {};
	while (true) {
		system("cls");

		//�޴� ���
		cout << "1. �л� ���" << endl;
		cout << "2. �л� ����" << endl;
		cout << "3. �л� Ž��" << endl;
		cout << "4. �л� ���" << endl;
		cout << "5. �� ��" << endl;

		int iMenu;
		cin >> iMenu;

		// cin�� �����ʿ� int������ ���� ������ �Է��ؾ� �Ѵ�. �����ʿ� ���� ���� Ÿ�Կ�
		// ���缭 ���� �Է��ؾ� �ϴµ� �Ǽ��� ������ �ƴ� ���ڸ� �Է��� ��� ������ �߻��Ѵ�.
		// �̶����� ����ó���� ������ �߻��ߴ����� ���⿡�� üũ�Ͽ� ������ �߻��ϸ� cin������ �������۸� ����ְ�
		// cin ���ο� �Է¹��۰� �ִµ� �Է¹��۴� �Է��� ���� �����س��� �� ���¤� ������ �־��ִ� ������ �Ѵ�. �� �Է�
		// ���ۿ� \n�� ���������Ƿ� ���۸� ��ȸ�Ͽ� \n�� �����ش�.

		// ���� : �ӽ�����ﰣ�̴�.
		
		// ������ üũ�Ѵ�. cin.fail()�� ���� �� �Է� ������ �߻��� ��� true�� ��ȯ�Ѵ�.
		if (cin.fail()) {
			// �������۸� ����ش�.
			cin.clear();

			// �Է¹��ۿ� \n�� ���������Ƿ� �Է¹��۸� �˻��Ͽ� \n�� �����ش�.
			// ù��°���� �˻��ϰ��� �ϴ� ���� ũ�⸦ �����Ѵ�. �˳��ϰ� 1024����Ʈ�� �������־���. 
			// �ι�°���� ã���� �ϴ� ���ڸ� �־��ش�. �׷��� �Է¹��ۿ��� \n�� �ִ� ������ ã�Ƽ� �� �κ��� ���
			// �����༭ �ٽ� �Է¹��� �� �ֵ��� ���ش�.
			cin.ignore(1024, '\n');
			continue;
		}
		

		if (iMenu == MENU_EXIT)
			break;
		switch (iMenu) {
		// �л������� �߰��Ѵ�.(�й�, �̸�, ������ ����(����, ���), �ּ�, �ڵ��� ��ȣ)
		// ������ ������ �Է�, �й�, ����, ����� ������ ���� ������ش�.

		//��� �� �л��� ����� �� �ִ� �ִ�ġ�� ��� ���̻� ����� �ȵǰ� ���´�.

		case MENU_INSERT:  
			system("cls");
			cout << "=====================�л��߰�========================" << endl;
			if (iStudentCount == STUDENT_MAX){
				cout << "����� ������ �����մϴ�." << endl;
				break; 
			}
				
			cout << "�̸� : ";
			cin>> tStudentArr[iStudentCount].strName;
			cin.ignore(1024, '\n');

			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAdress, ADDRESS_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "����: ";
			cin >> tStudentArr[iStudentCount].iKor;
			cout << "����: ";
			cin >> tStudentArr[iStudentCount].iEng;
			cout << "����: ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal = 
				tStudentArr[iStudentCount].iKor+ 
				tStudentArr[iStudentCount].iEng+
				tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.f;

			tStudentArr[iStudentCount].iNumber = istdNumber;

			++istdNumber;
			++iStudentCount;
			cout << "�л� �߰� �Ϸ�" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			cout << "=====================�л�����======================" << endl;

			cin.ignore(1024, '\n');
			cout << "���� �� �̸��� �Է��Ͻÿ� : ";
			cin.getline(strName, NAME_SIZE);

			// ��ϵǾ��ִ� �л� ����ŭ �ݺ��ϸ� �л��� ã�´�.
			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					for (int j = i; j < iStudentCount - 1; j++)
						tStudentArr[i] = tStudentArr[i + 1];
				}
				--iStudentCount;

				cout << "�ش� �л��� �����Ͽ����ϴ�.";
				break;
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "=====================�л�Ž��======================" << endl;

			cin.ignore(1024,'\n');
			cout << "�˻� �� �̸��� �Է��Ͻÿ� : ";
			cin.getline(strName, NAME_SIZE);

			// ��ϵǾ��ִ� �л� ����ŭ �ݺ��ϸ� �л��� ã�´�.
			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "�̸� : " << tStudentArr[i].strName << endl;
					cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "�ּ� : " << tStudentArr[i].strAdress << endl;
					cout << "�й� : " << tStudentArr[i].iNumber << endl;
					cout << "���� : " << tStudentArr[i].iKor << endl;
					cout << "���� : " << tStudentArr[i].iEng << endl;
					cout << "���� : " << tStudentArr[i].iMath << endl;
					cout << "���� : " << tStudentArr[i].iTotal << endl;
					cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
				}
			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "====================�л����======================" << endl;
			// ��ϵ� �л� ����ŭ �ݺ��ϸ� �л����� ���
			for (int i = 0; i < iStudentCount; i++) {
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "�ּ� : " << tStudentArr[i].strAdress << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "���� : " << tStudentArr[i].iKor << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl<<endl;
			}
			break;
		default:
			cout << "�޴��� �߸� �����Ͽ����ϴ�." << endl;
			break;
		}
		system("pause");
	}
}