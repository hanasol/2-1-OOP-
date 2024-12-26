#include <iostream>
using namespace std;
int power(int n);
void Hadamard(int** arr, int n, int i = 0, int j = 0);//i, j는 디폴트값 0으로 선언
int main() {
	int n;
	cout << "Enter the value of n for Hadamard matrix (2^n x 2^n): ";
	cin >> n;
	int size = power(n);
	int** arr = new int* [size];//2^n x 2^n의 Matrix 메모리 할당
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];//각 행의 메모리 할당
	Hadamard(arr, size);//2^n x 2^n 크기의 Hadamard 행렬 세팅
	for (int i = 0; i < size; i++) {//출력
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	for (int i = 0; i < size; i++)
		delete[] arr[i];//Matrix의 행 메모리 해제
	delete[] arr;//전체 Matrix 메모리 해제
}
int power(int n) {//2^n을 반환하는 함수
	if (n == 0)
		return 1;//n이 0이라면 1반환
	else
		return 2 * power(n - 1);//n이 0이 아니라면 2를 곱하고 n-1을 인자로 전달하여 power을 다시 호출
}
void Hadamard(int** arr, int n, int i, int j) {//Hadamard 행렬을 구성하는 함수
	if (n==1) {//n이 1일 때, [i][j]에 1을 저장
		arr[i][j] = 1;
		return;
	}
	int temp = n / 2;//절반 크기를 저장
	Hadamard(arr, temp, i, j);//1구역 (왼쪽 위)저장
	Hadamard(arr, temp, i, j + temp);//2구역 (오른쪽 위)저장
	Hadamard(arr, temp, i + temp, j);//3구역 (왼쪽 아래)저장
	for (int k = 0; k < temp; k++) {
		for (int l = 0; l < temp; l++) {
			arr[i + temp + k][j + temp + l] = -arr[i + k + temp][j + l];//4구역(오른쪽 아래)은 3구역과 반대 부호로 저장해야함 
		}
	}
}