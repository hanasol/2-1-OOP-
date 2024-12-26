#include <iostream>
#include <ctime>
using namespace std;
bool Check(int* arr1, int* arr2);//Hit와 blow를 체크해주는 Check함수 선언
int main() {
	srand(time(NULL));//실행마다 랜덤한 값을 받기위해서 srand함수에 시드로 time(NULL)을 넣어줌
	int arr[4] = { 0, };//랜덤숫자
	int arr2[4] = { 0, };//입력숫자
	for (int i = 0; i < 4; i++)
	{
		arr[i] = rand() % 4;//배열에 0~9의 값 할당
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) { //arr[i]와 arr[j]가 같으면
				i--;//i를 하나 줄여서 다시 값 할당 후, 중복검사 진행
				continue;//중복을 찾으면 다른 중복은 검사할 필요 없으므로 continue를 통해서 값 재할당
			}
		}
	}
	for (int i = 0; i < 5; i++) {//5번 반복
		if (Check(arr, arr2)) {//hit를 4개 맞추면 true를 반환
			cout << "Win" << endl;//win출력
			return 0;
		}
		cout << endl;
	}//for문이 끝났다면 수를 맞추지 못한 것이므로
	cout << "Lose" << endl << endl;//lose출력
	cout << "the correct answer: ";
	for (int j = 0; j < 4; j++)
		cout << arr[j];//랜덤숫자 출력
}
bool Check(int* arr1, int* arr2) {//Check함수 정의, true나 false를 반환하므로 bool형으로 정의함
	int cnt1 = 0, cnt2 = 0;//Hit, Blow
	int num;
	cout << "Guess: ";
	cin >> num;
	for (int i = 1; i <= 4; i++) {//입력받은 숫자를 하나씩 배열에 저장
		arr2[4 - i] = num % 10;//3 2 1 0의 인덱스로 1의 자리를 저장하므로 랜덤 입력과 같은 순서로 저장됨
		num /= 10;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr2[i] == arr1[j]) {
				cnt2 += 1;//같은 수가 있으면 blow+=1;
				if (i == j)
					cnt1 += 1;//자리까지 같다면 hit+=1;
			}
		}
	}
	cnt2 -= cnt1;//blow에 hit까지 중복으로 센 값이 있으므로 hit값을 빼줌
	cout << endl << "Hit: " << cnt1 << ", " << "Blow: " << cnt2;
	cout << endl << endl << "------------------" << endl;
	if (cnt1 == 4)//Hit가 4개면 win
		return true;
}
