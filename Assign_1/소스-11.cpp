#include <iostream>
using namespace std;
void mul(int num1, int num2);//mul�Լ� ����
int main() {
	int a, b;
	cout << "Enter the 1st number: ";
	cin >> a;//ù��° ���� �Է�
	cout << "Enter the 2nd number: ";
	cin >> b;//�ι�° ���� �Է�
	cout << "multiple(" << a << "," << b << "): ";
	mul(a, b);//mul�Լ� ȣ��
	return 0;
}
void mul(int num1, int num2) {//mul�Լ� ����
	if (num2 % num1 == 0)//num2�� num1���� ���� �������� 0�̸� num2�� num1�� ����̹Ƿ� true���
		cout << "true";
	else//����� �ƴ϶�� false���
		cout << "false";
}