#include <iostream>
using namespace std;
int gcd(int num1, int num2);//gcd함수 선언
int lcm(int num1, int num2);//lcm함수 선언
int main() {
	int a, b;
	cout << "Enter the 1st number: ";
	cin >> a;//첫번째 숫자 입력
	cout << "Enter the 2nd number: ";
	cin >> b;//두번째 숫자 입력
	cout << "lcm(" << a << "," << b << "): " << lcm(a, b);
	return 0;
}
int gcd(int num1, int num2) {//최대공약수 함수
	if (num2== 0) 
		return num1;
	return gcd(num2, num1 % num2);//유클리드 호제법
}
int lcm(int num1, int num2) {//최소공배수 함수
	return (num1 * num2) / gcd(num1, num2);//a*b=gcd(a,b)*lcm(a,b)이므로 lcm함수는 두 수를 곱한값에 gcd를 나누면 됨
}