#include <iostream>
#include <ctime>
using namespace std;
void quick(int* data, int start, int end);
void merge(int* arr, int start, int end);
void divide(int* arr, int start, int end);
bool bin_search(int* arr, int len, int target, int& index);
int main() {
	srand(time(NULL));
	int arr[11] = { 0, };//찾는 값이 없는 경우, 오름차순으로 업데이트된 배열을 만들기 위해서 11로 크기 설정
	int sel, target, key;//정렬을 선택하는 변수, 찾을 값, 찾을 값의 index
	cout << "Random values : ";
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 101;//0부터 100까지의 랜덤 숫자 할당
		cout << arr[i] << " ";
	}
	cout << endl<< "Select sorting method (1: Quick Sort, 2: Merge Sort) :";
	cin >> sel;
	switch (sel) {
	case 1://1이라면 퀵 정렬 사용
		quick(arr, 0, 9);
		cout << "Sorted numbers (Quick Sort): ";
		break;
	case 2://2라면 병합 정렬 사용
		divide(arr, 0, 9);
		cout << "Sorted numbers (Merge Sort): ";
		break;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl << "Enter a value to search : ";
	cin >> target;
	if (bin_search(arr, 10, target, key))//key를 파라미터에 전달하여 bin_search함수에서 key에 직접 접근이 가능하게 함
		cout << "Searched number index : " << key;//찾는 값이 배열에 있다면 인덱스 출력
	else {//찾는 값이 배열에 없을 때
		if (arr[0] > target) {//찾는 값이 첫 인덱스의 값보다 작다면
			for (int i = 9; i >= 0; i--)
				arr[i + 1] = arr[i];//처음부터 한칸씩 뒤로 미루고
			arr[0] = target;//첫 배열값에 할당
		}
		else if (arr[9] < target)//찾는 값이 마지막 인덱스의 값보다 크다면
			arr[10] = target;//마지막 배열값에 할당
		else if (arr[0] < target && target < arr[9]) {//배열의 사이에 찾는 값이 있다면
			for (int i = 9; i >= key; i--)//key부터 마지막까지 
				arr[i + 1] = arr[i];//뒤로 한칸씩 미룸
			arr[key] = target;//key인덱스에 찾는 값을 할당
			//key에는 bin_search함수에 start값이 저장되어 있으므로 arr[key]에 저장하면 오름차순으로 정렬됨
		}
		cout << "Updated numbers: ";
		for (int i = 0; i < 11; i++)
			cout << arr[i] << " ";//찾는 값이 추가된 배열 출력
	}
}
void quick(int* data, int start, int end) {
	int key = start;
	int i = key + 1;//왼쪽 출발
	int j = end;//오른쪽 출발
	int temp;
	if (start >= end)
		return;//정렬할 원소가 1개인 경우
	while (i <= j) {//i와 j가 엇갈릴 때 까지 반복
		while (i <= end && data[i] <= data[key])//end에 닿을 때 까지, key값보다 큰 i값을 찾을 때 까지
			i++;//i 증가
		while (j > start && data[j] >= data[key])//start 앞 까지, key보다 작은 작은 i값을 찾을 때 까지
			j--;//j 감소
		if (i > j) {//i와 j가 엇갈리면
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;//j와 key값을 스왑-->j는 새로운 key값으로 바뀜
		}
		else {//i와 j번째 인덱스를 스왑
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	//재귀함수를 이용해서 start부터 j-1, j+1과 end까지로 분할하여 계산
	quick(data, start, j - 1);
	quick(data, j + 1, end);
}
void merge(int* arr, int start, int end) {
	int* temp = new int[10];
	int mid = (start + end) / 2;
	int i = start;//앞 배열을 탐색(arr을 분할했을 때)
	int j = mid + 1;//뒷 배열을 탐색(arr을 분할했을 때)
	int k = start;//임시 배열(temp)
	while (i <= mid && j <= end) {//각 배열에 끝을 도달하기 전까지 반복
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	if (i > mid) {//앞 배열의 인덱스가 분할한 배열을 넘어간다면 (임시 배열이 앞 배열로 모두 채워졌다면)
		while (j <= end)
			temp[k++] = arr[j++];
	}
	else//임시 배열이 뒷 배열로 모두 채워졌다면
		while (i <= mid)
			temp[k++] = arr[i++];
	for (int i = start; i <= end; i++)
		arr[i] = temp[i];
	delete[] temp;
}
void divide(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;//중간값 설정
		divide(arr, start, mid);//처음부터 중간까지 범위 나누기
		divide(arr, mid + 1, end);//중간부터 끝까지 범위 나누기
		merge(arr, start, end);////나눈 부분을 다시 병합
	}
}
bool bin_search(int* arr, int len, int target, int& index) {//int형 참조자를 사용하여 직접 메모리에 접근
	int start = 0;
	int end = len - 1;
	int mid;
	while (end >= start) {
		mid = (start + end) / 2;//중간 인덱스
		if (arr[mid] == target) {//중간 인덱스의 값이 찾는 값과 같으면
			index = mid;//index에 mid값 저장
			return true;//true 반환
		}
		else if (arr[mid] > target)//찾는 값이 중간보다 왼쪽에 있다면
			end = mid - 1;//end를 mid-1로 초기화
		else//찾는 값이 중간보다 오른쪽에 있다면
			start = mid + 1;//start를 mid+1로 초기화
	}
	index = start;//i와 i+1인덱스 사이에 찾는 값이 있다면 start에는 i가 저장되므로 
	//start값을 반환하여 start의 인덱스에 찾는 값이 들어갈 수 있도록 함
	return false;
}

