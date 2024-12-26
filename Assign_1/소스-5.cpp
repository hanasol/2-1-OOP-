#include <iostream>
using namespace std;
int main() {
	int num;//입력받을 정수
	int arr[5] = { 0, };//배열의 값을 0으로 초기화하여 선언
	cout << "Enter the number: ";
	cin >> num;
	for (int i = 4; i >= 0; i--) {
		arr[i] = num % 10;//num의 1의 자리수를 arr 배열의 뒷자리부터 저장함
		num /= 10;//num의 1의 자리수를 없앰
	}
	for (int i = 0; i < 5; i++) {//행
		for (int j = i; j < 5; j++) {//열, j가 i부터 시작하여 하나씩 왼쪽으로 밀려서 출력되도록 함,
			//arr은 뒷자리부터 num의 1의 자리수를 저장하였으므로 num의 같은 순서로 정수가 저장되어있음
			cout << arr[j] << " ";
		}
		if (i != 4)//마지막행이 아니라면 개행
			cout << endl;
	}
	return 0;
}