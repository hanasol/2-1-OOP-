#include <iostream>
using namespace std;
int pow(int num1, int num2);//pow�Լ� ����
int main() {
	int a, b;
	cout << "Enter the exponent: ";
	cin >> a;//exponent �Է�
	cout << "Enter the power: ";
	cin >> b;//power �Է�
	cout << "power(" << a << "," << b << "): " << pow(a, b);
	return 0;
}
int pow(int num1, int num2) {
	if (num2 != 0) {
		return num1 * pow(num1, num2 - 1);//x^n=x*x^(n-1)�̹Ƿ� num2-1�� �Ķ���ͷ� �����Ͽ� �ٽ� pow�Լ� ȣ��
	}
	else//n^0=1�̹Ƿ� num2�� 0�̸� 1��ȯ
		return 1;
}