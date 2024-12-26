#include <iostream>
#include <ctime>
using namespace std;
void sort_des(int arr[]);
int sum_(int* row, int size);
int main() {
	srand(time(NULL));
	int** arr = new int*[10];//2차원 배열의 메모리 할당
	for (int i = 0; i < 10; i++)
		arr[i] = new int[10];//각 행의 메모리 할당
	int sum[10] = { 0, };//합 값을 저장하는 배열
	int* ptr[10];//각 행을 저장할 포인터 배열
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % 101;//한 행의 열마다 0~100의 랜덤 값 부여
			sum[i] += arr[i][j];//랜덤 값을 더해서 한 행의 합값 저장
		}
	}
	cout << "Original Matrix\n";
	for (int i = 0; i < 10; i++) {//행
		for (int j = 0; j < 10; j++) {//열
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nSort by Row (Descending Order):\n";
	for (int i = 0; i < 10; i++) {//행
		sort_des(arr[i]);//행마다 내림차순으로 정렬
		for (int j = 0; j < 10; j++) {//열
			cout << arr[i][j] << "\t";
		}
		cout << "| Sum: " << sum[i] << "\n";//한 행에서의 정렬이므로 합 값은 같음
	}
	for (int i = 0; i < 10; i++) {
		ptr[i] = arr[i];//포인터 배열의 값에 arr의 행을 mapping
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9-i; j++) {//0~9의 행들을 합 값으로 정렬하므로 마지막 인덱스에는 가장 큰 합 값을 가진
			//행이 저장 될것임. 따라서 0부터 9-i전까지 반복
			if (sum_(ptr[j], 10) > sum_(ptr[j + 1], 10)) {//j가 j+1행의 합보다 크다면
				int* temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;//포인터 배열의 j와 j+1을 교환->포인터 배열에는 Matrix의 행이 Mapping되어 있으므로
				//행의 합에 따라서 오름차순으로 행이 바뀌는 것과 같음
			}
		}
	}
	cout << "\nSort by Sum (Ascending order):\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << ptr[i][j] << "\t";//ptr에는 새롭게 정렬된 Matrix가 저장되어있음
		cout << "| Sum: " << sum_(ptr[i], 10) << "\n";
	}
	for (int i = 0; i < 10; i++)
		delete[] arr[i];//각 행의 메모리 해제
	delete[] arr;//전체 메모리 해제->메모리 할당과 반대 순서
}

void sort_des(int arr[]) {//내림차순으로 배열을 정렬해주는 함수(버블 정렬)
	int temp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9-i; j++) {//반복하면서 마지막 부분은 가장 작은 수로 정렬이 되므로 0~9-i전까지 반복함
			if (arr[j] < arr[j + 1]) {//큰 값이 뒤에 있다면 앞 인덱스와 교환
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int sum_(int* row, int size) {//각 행의 합을 반환하는 함수
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += row[i];
	return sum;
}