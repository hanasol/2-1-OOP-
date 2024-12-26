#include <iostream>
#include <ctime>
using namespace std;
void sort_des(int arr[]);
int sum_(int* row, int size);
int main() {
	srand(time(NULL));
	int** arr = new int*[10];//2���� �迭�� �޸� �Ҵ�
	for (int i = 0; i < 10; i++)
		arr[i] = new int[10];//�� ���� �޸� �Ҵ�
	int sum[10] = { 0, };//�� ���� �����ϴ� �迭
	int* ptr[10];//�� ���� ������ ������ �迭
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % 101;//�� ���� ������ 0~100�� ���� �� �ο�
			sum[i] += arr[i][j];//���� ���� ���ؼ� �� ���� �հ� ����
		}
	}
	cout << "Original Matrix\n";
	for (int i = 0; i < 10; i++) {//��
		for (int j = 0; j < 10; j++) {//��
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nSort by Row (Descending Order):\n";
	for (int i = 0; i < 10; i++) {//��
		sort_des(arr[i]);//�ึ�� ������������ ����
		for (int j = 0; j < 10; j++) {//��
			cout << arr[i][j] << "\t";
		}
		cout << "| Sum: " << sum[i] << "\n";//�� �࿡���� �����̹Ƿ� �� ���� ����
	}
	for (int i = 0; i < 10; i++) {
		ptr[i] = arr[i];//������ �迭�� ���� arr�� ���� mapping
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9-i; j++) {//0~9�� ����� �� ������ �����ϹǷ� ������ �ε������� ���� ū �� ���� ����
			//���� ���� �ɰ���. ���� 0���� 9-i������ �ݺ�
			if (sum_(ptr[j], 10) > sum_(ptr[j + 1], 10)) {//j�� j+1���� �պ��� ũ�ٸ�
				int* temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;//������ �迭�� j�� j+1�� ��ȯ->������ �迭���� Matrix�� ���� Mapping�Ǿ� �����Ƿ�
				//���� �տ� ���� ������������ ���� �ٲ�� �Ͱ� ����
			}
		}
	}
	cout << "\nSort by Sum (Ascending order):\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << ptr[i][j] << "\t";//ptr���� ���Ӱ� ���ĵ� Matrix�� ����Ǿ�����
		cout << "| Sum: " << sum_(ptr[i], 10) << "\n";
	}
	for (int i = 0; i < 10; i++)
		delete[] arr[i];//�� ���� �޸� ����
	delete[] arr;//��ü �޸� ����->�޸� �Ҵ�� �ݴ� ����
}

void sort_des(int arr[]) {//������������ �迭�� �������ִ� �Լ�(���� ����)
	int temp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9-i; j++) {//�ݺ��ϸ鼭 ������ �κ��� ���� ���� ���� ������ �ǹǷ� 0~9-i������ �ݺ���
			if (arr[j] < arr[j + 1]) {//ū ���� �ڿ� �ִٸ� �� �ε����� ��ȯ
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int sum_(int* row, int size) {//�� ���� ���� ��ȯ�ϴ� �Լ�
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += row[i];
	return sum;
}