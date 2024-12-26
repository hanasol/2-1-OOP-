#include <iostream>
#include <ctime>
using namespace std;
int main() {
	int size;
	srand(time(NULL));
	size = rand() % 16 + 5;//5부터 20의 랜덤값 할당-->배열의 크기
	int max_point = size - 1;//배열의 마지막 부분 저장
	cout << "Size of array: " << size << endl;
	int* arr = new int[size];//size크기의 int사이즈를 동적할당
	cout << "Randon numbers: ";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 101;//각 배열에 0부터 100의 랜덤 정수를 할당
		cout << arr[i] << " ";//랜덤 값 출력
	}
	cout << endl << endl;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {//j인덱스의 값이 j+1인덱스의 값보다 크다면 바꿈
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}//버블 정렬을 사용하여 오름차순으로 배열 정렬
		}
	}
	for (int i = size - 1; i >= 1; i--) {//배열의 맨 뒤부터 맨 앞까지 반복
		if (arr[i] == arr[i - 1])//최댓값이 같다면
			max_point -= 1;//앞쪽 인덱스를 max_point에 저장
		else
			break;//값이 다르다면 최댓값이 아니므로 배열 중단
	}
	cout << "Maximum value: " << arr[max_point] << "     " << ",Address: " << &arr[max_point] << endl;
	cout << "Minimum value: " << arr[0] << "     " << ",Address: " << &arr[0];
	delete arr;
	return 0;
}