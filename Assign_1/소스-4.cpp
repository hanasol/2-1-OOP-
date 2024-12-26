#include <iostream>
using namespace std;
int main() {
	int a, cnt = 0, num = 0;//입력받는 정수, 자리수를 세주는 카운터, 거꾸로된 정수를 저장하는 정수 선언
	int arr[100] = { 0, };//정수를 거꾸로 저장할때 임시로 저장할 배열, int형이므로 100자리를 넘지않음
	cout << "Enter the number: ";
	cin >> a;
	while (a != 0) {//0이 아닐 때 까지 반복
		arr[cnt] = a % 10;//a의 1의 자리수를 0번째 자리부터 저장함
		a /= 10;//a를 10으로 나누어서 1의 자리수를 없앰
		cnt += 1;//카운터 1 증가
	}
	for (int j = 0; j < cnt; j++) {
		num += arr[j];//arr에는 a가 0부터 cnt-1까지 거꾸로 한 자리씩 저장되어있음, num에 한 자리씩 더해줌
		if (j != cnt - 1)//마지막 수는 더하기만 해주어야함
			num *= 10;//arr에 저장되어 있던 값이 더해지고, 10을 곱해주어 앞자리로 옮김
	}
	cout << "Reversed number: " << num;
	return 0;
}