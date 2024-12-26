#include <iostream>
using namespace std;
int main() {
	char arr[10] = {};//char형 변수를 입력받을 변수 선언
	cout << "Enter ten characters: ";
	for (int i = 0; i < 10; i++)
		cin >> arr[i];//char형 변수 입력
	cout << "Input characters are: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " " << arr[9 - i];//i가 0부터 4까지 반복하면서 i와 9-i번째의 char변수를 출력,
		//(1, 10), (2, 9), (3, 8)..번째의 순서로 출력됨
		if (i != 4)//마지막 줄이 아니면 개행
			cout << endl;
	}
	return 0;
}