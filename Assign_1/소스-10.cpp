#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "Enter the number of rows: ";
	cin >> num;//1부터 19까지의 행 입력
	while (num % 2 == 0) {//num이 짝수일 때 예외처리
		cout << "Please enter odd number" << endl;
		cout << "Enter the number of rows: ";
		cin >> num;
	}
	int temp = (num + 1) / 2;//입력받은 홀수의 중간 값을 temp의 저장
	for (int i = 0; i < temp; i++) {//1~temp행
		for (int j = 1; j <= num; j++) {//열
			if (j == temp - i || j == temp + i) //temp를 기준으로 앞 뒤 i는 별이 출력되어야함
				cout << "*";
			else//나머지는 공백이 출력되어야함
				cout << ' ';
		}
		cout << endl;
	}
	for (int i = temp; i < num; i++) {//temp+1~num행
		for (int j = 1; j <= num; j++) {//열
			if (j == temp - (num - i - 1) || j == temp + (num - i - 1))//temp를 기준으로 앞 뒤 (num-i-1)은 별이 출력되어야함
				cout << "*";
			else//나머지는 공백이 출력되어야함
				cout << ' ';
		}
		if (i != num - 1)//마지막 행이 아니라면 개행
			cout << endl;
	}
	return 0;
}