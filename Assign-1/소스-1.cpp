#include <iostream>
using namespace std;
int round_(double num);//반올림 함수 선언
int main() {
	int arr[5];//입력받은 정수를 저장하는 배열
	double a = 0;//입력받은 정수의 평균
	cout << "Enter the five numbers: ";
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];//정수를 입력
		a += arr[i];//입력받은 정수를 더해줌
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[j] > arr[j + 1]) {//j번째 정수가 j+1번째 정수보다 크다면 값을 바꿈, 따라서 오름차순으로 정렬
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	a /= 5;//입력받은 정수들의 합을 5로 나눔
	cout << "MIN: " << arr[0] << endl;//오름차순이므로 0번째는 가장 작은 값
	cout << "MAX: " << arr[4] << endl;//오름차순이므로 4번째는 가장 큰 값
	cout << "AVG: " << round_(a);//a를 전달하여 반올림 된 값을 출력함
	return 0;
}
int round_(double num) {//반올림 함수 정의
	int a;
	if (num >= 0)
		a = num + 0.5;//num이 양수라면 0.5를 더해주고 int형으로 저장하여 반올림 구현
	else
		a = num - 0.5;//num이 음수라면 0.5를 빼주고 int형으로 저장하여 반올림 구현
	return a;//반올림 된 값 반환
}