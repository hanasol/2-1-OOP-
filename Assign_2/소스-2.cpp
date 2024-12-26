#include <iostream>
#include <ctime>
using namespace std;
void quick(int* data, int start, int end);
void merge(int* arr, int start, int end);
void divide(int* arr, int start, int end);
bool bin_search(int* arr, int len, int target, int& index);
int main() {
	srand(time(NULL));
	int arr[11] = { 0, };//ã�� ���� ���� ���, ������������ ������Ʈ�� �迭�� ����� ���ؼ� 11�� ũ�� ����
	int sel, target, key;//������ �����ϴ� ����, ã�� ��, ã�� ���� index
	cout << "Random values : ";
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 101;//0���� 100������ ���� ���� �Ҵ�
		cout << arr[i] << " ";
	}
	cout << endl<< "Select sorting method (1: Quick Sort, 2: Merge Sort) :";
	cin >> sel;
	switch (sel) {
	case 1://1�̶�� �� ���� ���
		quick(arr, 0, 9);
		cout << "Sorted numbers (Quick Sort): ";
		break;
	case 2://2��� ���� ���� ���
		divide(arr, 0, 9);
		cout << "Sorted numbers (Merge Sort): ";
		break;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl << "Enter a value to search : ";
	cin >> target;
	if (bin_search(arr, 10, target, key))//key�� �Ķ���Ϳ� �����Ͽ� bin_search�Լ����� key�� ���� ������ �����ϰ� ��
		cout << "Searched number index : " << key;//ã�� ���� �迭�� �ִٸ� �ε��� ���
	else {//ã�� ���� �迭�� ���� ��
		if (arr[0] > target) {//ã�� ���� ù �ε����� ������ �۴ٸ�
			for (int i = 9; i >= 0; i--)
				arr[i + 1] = arr[i];//ó������ ��ĭ�� �ڷ� �̷��
			arr[0] = target;//ù �迭���� �Ҵ�
		}
		else if (arr[9] < target)//ã�� ���� ������ �ε����� ������ ũ�ٸ�
			arr[10] = target;//������ �迭���� �Ҵ�
		else if (arr[0] < target && target < arr[9]) {//�迭�� ���̿� ã�� ���� �ִٸ�
			for (int i = 9; i >= key; i--)//key���� ���������� 
				arr[i + 1] = arr[i];//�ڷ� ��ĭ�� �̷�
			arr[key] = target;//key�ε����� ã�� ���� �Ҵ�
			//key���� bin_search�Լ��� start���� ����Ǿ� �����Ƿ� arr[key]�� �����ϸ� ������������ ���ĵ�
		}
		cout << "Updated numbers: ";
		for (int i = 0; i < 11; i++)
			cout << arr[i] << " ";//ã�� ���� �߰��� �迭 ���
	}
}
void quick(int* data, int start, int end) {
	int key = start;
	int i = key + 1;//���� ���
	int j = end;//������ ���
	int temp;
	if (start >= end)
		return;//������ ���Ұ� 1���� ���
	while (i <= j) {//i�� j�� ������ �� ���� �ݺ�
		while (i <= end && data[i] <= data[key])//end�� ���� �� ����, key������ ū i���� ã�� �� ����
			i++;//i ����
		while (j > start && data[j] >= data[key])//start �� ����, key���� ���� ���� i���� ã�� �� ����
			j--;//j ����
		if (i > j) {//i�� j�� ��������
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;//j�� key���� ����-->j�� ���ο� key������ �ٲ�
		}
		else {//i�� j��° �ε����� ����
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	//����Լ��� �̿��ؼ� start���� j-1, j+1�� end������ �����Ͽ� ���
	quick(data, start, j - 1);
	quick(data, j + 1, end);
}
void merge(int* arr, int start, int end) {
	int* temp = new int[10];
	int mid = (start + end) / 2;
	int i = start;//�� �迭�� Ž��(arr�� �������� ��)
	int j = mid + 1;//�� �迭�� Ž��(arr�� �������� ��)
	int k = start;//�ӽ� �迭(temp)
	while (i <= mid && j <= end) {//�� �迭�� ���� �����ϱ� ������ �ݺ�
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	if (i > mid) {//�� �迭�� �ε����� ������ �迭�� �Ѿ�ٸ� (�ӽ� �迭�� �� �迭�� ��� ä�����ٸ�)
		while (j <= end)
			temp[k++] = arr[j++];
	}
	else//�ӽ� �迭�� �� �迭�� ��� ä�����ٸ�
		while (i <= mid)
			temp[k++] = arr[i++];
	for (int i = start; i <= end; i++)
		arr[i] = temp[i];
	delete[] temp;
}
void divide(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;//�߰��� ����
		divide(arr, start, mid);//ó������ �߰����� ���� ������
		divide(arr, mid + 1, end);//�߰����� ������ ���� ������
		merge(arr, start, end);////���� �κ��� �ٽ� ����
	}
}
bool bin_search(int* arr, int len, int target, int& index) {//int�� �����ڸ� ����Ͽ� ���� �޸𸮿� ����
	int start = 0;
	int end = len - 1;
	int mid;
	while (end >= start) {
		mid = (start + end) / 2;//�߰� �ε���
		if (arr[mid] == target) {//�߰� �ε����� ���� ã�� ���� ������
			index = mid;//index�� mid�� ����
			return true;//true ��ȯ
		}
		else if (arr[mid] > target)//ã�� ���� �߰����� ���ʿ� �ִٸ�
			end = mid - 1;//end�� mid-1�� �ʱ�ȭ
		else//ã�� ���� �߰����� �����ʿ� �ִٸ�
			start = mid + 1;//start�� mid+1�� �ʱ�ȭ
	}
	index = start;//i�� i+1�ε��� ���̿� ã�� ���� �ִٸ� start���� i�� ����ǹǷ� 
	//start���� ��ȯ�Ͽ� start�� �ε����� ã�� ���� �� �� �ֵ��� ��
	return false;
}

