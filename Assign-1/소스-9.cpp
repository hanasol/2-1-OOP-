#include <iostream>
using namespace std;
int gcd(int num1, int num2);//gcd�Լ� ����
int lcm(int num1, int num2);//lcm�Լ� ����
int main() {
	int a, b;
	cout << "Enter the 1st number: ";
	cin >> a;//ù��° ���� �Է�
	cout << "Enter the 2nd number: ";
	cin >> b;//�ι�° ���� �Է�
	cout << "lcm(" << a << "," << b << "): " << lcm(a, b);
	return 0;
}
int gcd(int num1, int num2) {//�ִ����� �Լ�
	if (num2== 0) 
		return num1;
	return gcd(num2, num1 % num2);//��Ŭ���� ȣ����
}
int lcm(int num1, int num2) {//�ּҰ���� �Լ�
	return (num1 * num2) / gcd(num1, num2);//a*b=gcd(a,b)*lcm(a,b)�̹Ƿ� lcm�Լ��� �� ���� ���Ѱ��� gcd�� ������ ��
}