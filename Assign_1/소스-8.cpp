#include <iostream>
using namespace std;
int gcd(int a, int b);//gcd함수 선언
int main() {
	int num1, num2;
	cout << "Enter the 1st number: ";
	cin >> num1;//첫번째 숫자 입력
	cout << "Enter the 2nd number: ";
	cin >> num2;//두번째 숫자 입력
	cout << "gcd(" << num1 << "," << num2 << "): " << gcd(num1, num2);
	return 0;
}
int gcd(int a, int b) {
	if (b == 0)//b가 0이라면 최대공약수는 a
		return a;
	return gcd(b, a % b);//유클리드 호제법에 의해서 gcd(a,b)=gcd(b,a%b)이므로
	//a가 b로 나누어지지 않으면 파라미터로 b,a%b를 전달하여 다시 gcd함수 호출
}