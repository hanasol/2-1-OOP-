#include <iostream>
using namespace std;
int gcd(int a, int b);//gcd�Լ� ����
int main() {
	int num1, num2;
	cout << "Enter the 1st number: ";
	cin >> num1;//ù��° ���� �Է�
	cout << "Enter the 2nd number: ";
	cin >> num2;//�ι�° ���� �Է�
	cout << "gcd(" << num1 << "," << num2 << "): " << gcd(num1, num2);
	return 0;
}
int gcd(int a, int b) {
	if (b == 0)//b�� 0�̶�� �ִ������� a
		return a;
	return gcd(b, a % b);//��Ŭ���� ȣ������ ���ؼ� gcd(a,b)=gcd(b,a%b)�̹Ƿ�
	//a�� b�� ���������� ������ �Ķ���ͷ� b,a%b�� �����Ͽ� �ٽ� gcd�Լ� ȣ��
}