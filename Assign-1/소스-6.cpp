#include <iostream>
using namespace std;
double ceil_(double num);//ceil_함수 선언
double floor_(double num);//floor_함수 선언
double round_(double num);//round_함수 선언
int main() {
	double num;
	cout << "Enter the floating-point number: ";
	cin >> num;//float형 변수를 입력받음
	cout << fixed;//소수점 아래 자리수 고정을 위해서 fixed 사용
	cout.precision(2);//소수점 아래 2자리까지만 출력
	cout << "Ceiling: " << ceil_(num) / 100.0 << endl;//올림
	cout << "Floor: " << floor_(num) / 100.0 << endl;//내림
	cout << "Rounding: " << round_(num) / 100.0;//반올림 
}

double ceil_(double num) {//올림
	num *= 100;
	if (num >= 0) {//num이 양수일 때
		num += 1;//1을 더해주고
		int a = (int)num;//int형으로 형변환
		return a;
	}
	else {//num이 음수일 때
		int a = (int)num;//int형으로 형변환하여 소수를 버림 (음수의 올림)
		return a;
	}
}
double floor_(double num) {//내림
	num *= 100;
	int a = (int)num;
	if (num >= 0)//양수라면 형변환을 통해서 소수를 버림
		return a;
	else//음수라면 1을 뺀 값을 형변환하여 소수를 버림
		return a - 1;//(음수의 내림)
}
double round_(double num) {//반올림
	num *= 100;
	if (num >= 0)
		return num + 0.49;//양수라면 0.499를 더하고 반환하여 반올림
	else
		return num - 0.49;//음수라면 0.499를 빼고 반환하여 반올림
}