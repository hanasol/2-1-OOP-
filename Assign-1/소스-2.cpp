#include <iostream>
#include <ctime>
using namespace std;
double round_(double num);//반올림 함수 선언
int main() {
	srand(time(NULL));//time(NULL)을 srand의 시드로 넣어서 실행마다 랜덤 값이 바뀌도록 함
	int arr[5][10] = { 0, };//랜덤값을 저장하면 2중배열 선언
	double sum = 0;//각 열의 합
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = (rand() % 99) + 1;//1부터 99의 랜덤 값을 할당해야 하므로 rand()%99+1을 할당
		}
	}
	for (int i = 0; i < 5; i++) {//행
		for (int j = 0; j < 10; j++) {//열
			sum += arr[i][j];//각 행의 랜덤 값을 더함
			if (j == 9) {//각 행의 마지막 값
				if (arr[i][9] < 10)//i행의 마지막 값이 한자리 수 라면 공백을 먼저 출력 (오른쪽 정렬)
					cout << " ";
				cout << arr[i][9];//i행의 마지막 값이라면 공백없이 출력
				break;//다음 값을 출력할 필요가 없으므로 for문 탈출
			}
			if (arr[i][j] < 10)//한자리 수 라면 공백을 먼저 출력(오른쪽 정렬)
				cout << " ";
			cout << arr[i][j] << "  ";//i행 j열의 값 출력
		}
		if (10 <= sum && sum < 100) {//sum이 두자리 수 라면 공백을 하나 추가하여 오른쪽으로 정렬
			cout << " ㅣ  " << sum << " ㅣ  " << round_(sum / 10);//round_함수에 합의 평균을 전달하여 반올림된 값을 출력
		}
		else//아니라면 공백을 하나씩만 출력
			cout << " ㅣ " << sum << " ㅣ " << round_(sum/10);//round_함수에 합의 평균을 전달하여 반올림된 값을 출력
		if (i != 4)//마지막 행이 아니라면 개행
			cout << endl;
		sum = 0;
	}
}
double round_(double num) {//반올림 함수 정의
	int a = num + 0.5;//1부터 99의 합을 10으로 나눈 값이 변수로 전달되므로 num은 무조건 양의 정수,
	//따라서 0.5를 더한 값을 정수형으로 저장
	return a;//반올림된 값 반환
}