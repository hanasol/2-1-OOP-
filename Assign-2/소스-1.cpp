#include <iostream>
#include <ctime>
using namespace std;
int main() {
	int size;
	srand(time(NULL));
	size = rand() % 16 + 5;//5���� 20�� ������ �Ҵ�-->�迭�� ũ��
	int max_point = size - 1;//�迭�� ������ �κ� ����
	cout << "Size of array: " << size << endl;
	int* arr = new int[size];//sizeũ���� int����� �����Ҵ�
	cout << "Randon numbers: ";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 101;//�� �迭�� 0���� 100�� ���� ������ �Ҵ�
		cout << arr[i] << " ";//���� �� ���
	}
	cout << endl << endl;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {//j�ε����� ���� j+1�ε����� ������ ũ�ٸ� �ٲ�
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}//���� ������ ����Ͽ� ������������ �迭 ����
		}
	}
	for (int i = size - 1; i >= 1; i--) {//�迭�� �� �ں��� �� �ձ��� �ݺ�
		if (arr[i] == arr[i - 1])//�ִ��� ���ٸ�
			max_point -= 1;//���� �ε����� max_point�� ����
		else
			break;//���� �ٸ��ٸ� �ִ��� �ƴϹǷ� �迭 �ߴ�
	}
	cout << "Maximum value: " << arr[max_point] << "     " << ",Address: " << &arr[max_point] << endl;
	cout << "Minimum value: " << arr[0] << "     " << ",Address: " << &arr[0];
	delete arr;
	return 0;
}