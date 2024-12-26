#include <iostream>
using namespace std;
int main() {
	srand(time(NULL));
	int arr[4] = { 0, };//랜덤숫자
	int arr2[4] = { 0, };//입력숫자
	arr[0] = rand() % 10;
	for (int i = 1; i < 4; i++) {
		arr[i] = rand() % 10;//숫자를 할당
		for (int j = i - 1; j >= 0; j--) {//i-1부터 0까지 반복하면서
			while (arr[i] == arr[j])//중복이 있다면
				arr[i] = rand() % 10;//다시 할당
		}
	}
	for (int i = 0; i < 4; i++)
		cout << arr[i] << " ";
}