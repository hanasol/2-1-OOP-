#include <iostream>
using namespace std;
int round_(double num);//�ݿø� �Լ� ����
int main() {
	int arr[5];//�Է¹��� ������ �����ϴ� �迭
	double a = 0;//�Է¹��� ������ ���
	cout << "Enter the five numbers: ";
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];//������ �Է�
		a += arr[i];//�Է¹��� ������ ������
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[j] > arr[j + 1]) {//j��° ������ j+1��° �������� ũ�ٸ� ���� �ٲ�, ���� ������������ ����
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	a /= 5;//�Է¹��� �������� ���� 5�� ����
	cout << "MIN: " << arr[0] << endl;//���������̹Ƿ� 0��°�� ���� ���� ��
	cout << "MAX: " << arr[4] << endl;//���������̹Ƿ� 4��°�� ���� ū ��
	cout << "AVG: " << round_(a);//a�� �����Ͽ� �ݿø� �� ���� �����
	return 0;
}
int round_(double num) {//�ݿø� �Լ� ����
	int a;
	if (num >= 0)
		a = num + 0.5;//num�� ������ 0.5�� �����ְ� int������ �����Ͽ� �ݿø� ����
	else
		a = num - 0.5;//num�� ������� 0.5�� ���ְ� int������ �����Ͽ� �ݿø� ����
	return a;//�ݿø� �� �� ��ȯ
}