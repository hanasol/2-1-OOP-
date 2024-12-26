#include <iostream>
using namespace std;
void perfect(int num);//완전수인지 판별하는 perfect함수 선언
int main() {
	cout << "Perfect numbers between 1 and 1000:" << endl;
	for (int i = 2; i < 1001; i++) {
		perfect(i);//1은 완전수가 아니므로 2부터 1000까지 반복하며 완전수를 출력
	}
	return 0;
}
void perfect(int num) {
	if (num % 2 == 1) {//1000까지의 완전수 중 홀수는 없음
		return;
	}
	else {
		int arr[1001] = { 0, };
		int sum = 0;//num을 제외한 약수의 합
		int cnt1 = 0, cnt2 = 0;//num을 제외한 약수의 갯수
		for (int i = 1; i < num; i++) {//1부터 num-1까지 반복
			if (num % i == 0) {//num을 i로 나눈 나머지가 0이라면 i는 num의 약수
				arr[i] += i;//약수가 i라면 arr[i]==[i]
				cnt1 += 1;//약수의 갯수 1개 증가
				sum += i;//num을 제외한 모든 약수의 합
			}
		}
		if (sum == num) {//num과 num을 제외한 모든 약수의 합이 같다면 완전수
			cout << num << " = ";
			for (int i = 1; i < num; i++) {//1부터 num-1까지 반복
				if (arr[i] != 0) {//arr[i]가 0이 아니라면 num의 약수
					cout << i;//약수를 출력
					cnt2 += 1;//cnt2값 증가
					if (cnt2 < cnt1)//cnt2의 값이 약수의 갯수보다 작을때만 +기호 출력
						cout << " + ";
				}
			}
			cout << "\n";
		}
		else
			return;
	}
}
