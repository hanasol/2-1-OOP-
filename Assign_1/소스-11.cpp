#include <iostream>
using namespace std;
void mul(int num1, int num2);//mul함수 선언
int main() {
	int a, b;
	cout << "Enter the 1st number: ";
	cin >> a;//첫번째 숫자 입력
	cout << "Enter the 2nd number: ";
	cin >> b;//두번째 숫자 입력
	cout << "multiple(" << a << "," << b << "): ";
	mul(a, b);//mul함수 호출
	return 0;
}
void mul(int num1, int num2) {//mul함수 정의
	if (num2 % num1 == 0)//num2을 num1으로 나눈 나머지가 0이면 num2가 num1의 배수이므로 true출력
		cout << "true";
	else//배수가 아니라면 false출력
		cout << "false";
}