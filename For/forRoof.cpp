#include <iostream>
using namespace std;

int main() {
	// �� �׸���
	/* ex)
	*
	**
	***
	****
	*****
	*/
	int i,j,line;
	cout << "�� �� �׸��� ���Ͻÿ� : ";
	cin >> line;

	for (i = 0; i < line; i++) {
		for (j = 0; j < (i + 1); j++) {
			cout << "*";
		}
		cout << endl;
	}

	// �� �׸���
	/* ex)
	*****
	****
	***
	**
	*
	*/
	cout << "�� �� �׸��� ���Ͻÿ� : ";
	cin >> line;

	for (i = 0; i < line; i++) {
		for (j = line; j > i; j--) {
			cout << "*";
		}
		cout << endl;
	}

	// �� �׸���
	/* ex)
	  *
	 ***
	*****
   *******
	*/
	cout << "�� �� �׸��� ���Ͻÿ� : ";
	cin >> line;

	for (i = 0; i < line; i++) {
		for (j = line-1; j > i; j--) {
			cout << " ";
		}
		for (j = 0; j < 2 * i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	//������

	for (i = 2; i < 10; i+=3) {
		for (j = 1; j < 11; j++) {
			cout << i << " * " << j << " = " << i*j << "\t";
			cout << i + 1 << " * " << j << " = " << (i+1)*j << "\t";
			cout << i + 2 << " * " << j << " = " << (i+2)*j <<"\t"<< endl;
		}
		cout << endl;
	}

	//���̾Ƹ��
	cout << "�� �� ¥�� : ";
	cin >> line;

	if (line % 2 == 0){ 
		cout << "�׸� �� �����ϴ�" << endl; 
	}		
	else {

		for(i=0;i<line;i++){
			//����
			int Count = i;
			if (i > line / 2)
				Count = line - 1 - i;
			for (j = 0; j < line / 2 - Count; j++)
				cout << " ";
			//�� 
			Count = i;
			if (i > line / 2)
				Count = line - 1 - i;
			for (j = 0; j < Count * 2 + 1; j++)
				cout << "*";

			cout << endl;
		}

		
		
	}
	return 0;
}

