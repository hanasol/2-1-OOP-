#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "Enter the number of rows: ";
	cin >> num;//1���� 19������ �� �Է�
	while (num % 2 == 0) {//num�� ¦���� �� ����ó��
		cout << "Please enter odd number" << endl;
		cout << "Enter the number of rows: ";
		cin >> num;
	}
	int temp = (num + 1) / 2;//�Է¹��� Ȧ���� �߰� ���� temp�� ����
	for (int i = 0; i < temp; i++) {//1~temp��
		for (int j = 1; j <= num; j++) {//��
			if (j == temp - i || j == temp + i) //temp�� �������� �� �� i�� ���� ��µǾ����
				cout << "*";
			else//�������� ������ ��µǾ����
				cout << ' ';
		}
		cout << endl;
	}
	for (int i = temp; i < num; i++) {//temp+1~num��
		for (int j = 1; j <= num; j++) {//��
			if (j == temp - (num - i - 1) || j == temp + (num - i - 1))//temp�� �������� �� �� (num-i-1)�� ���� ��µǾ����
				cout << "*";
			else//�������� ������ ��µǾ����
				cout << ' ';
		}
		if (i != num - 1)//������ ���� �ƴ϶�� ����
			cout << endl;
	}
	return 0;
}