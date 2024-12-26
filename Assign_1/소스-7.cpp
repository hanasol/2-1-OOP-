#include <iostream>
using namespace std;
int pow(int num1, int num2);//pow함수 선언
int main() {
	int a, b;
	cout << "Enter the exponent: ";
	cin >> a;//exponent 입력
	cout << "Enter the power: ";
	cin >> b;//power 입력
	cout << "power(" << a << "," << b << "): " << pow(a, b);
	return 0;
}
int pow(int num1, int num2) {
	if (num2 != 0) {
		return num1 * pow(num1, num2 - 1);//x^n=x*x^(n-1)이므로 num2-1을 파라미터로 전달하여 다시 pow함수 호출
	}
	else//n^0=1이므로 num2가 0이면 1반환
		return 1;
}