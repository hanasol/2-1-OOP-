#include <iostream>
using namespace std;
int power(int n);
void Hadamard(int** arr, int n, int i = 0, int j = 0);//i, j�� ����Ʈ�� 0���� ����
int main() {
	int n;
	cout << "Enter the value of n for Hadamard matrix (2^n x 2^n): ";
	cin >> n;
	int size = power(n);
	int** arr = new int* [size];//2^n x 2^n�� Matrix �޸� �Ҵ�
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];//�� ���� �޸� �Ҵ�
	Hadamard(arr, size);//2^n x 2^n ũ���� Hadamard ��� ����
	for (int i = 0; i < size; i++) {//���
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	for (int i = 0; i < size; i++)
		delete[] arr[i];//Matrix�� �� �޸� ����
	delete[] arr;//��ü Matrix �޸� ����
}
int power(int n) {//2^n�� ��ȯ�ϴ� �Լ�
	if (n == 0)
		return 1;//n�� 0�̶�� 1��ȯ
	else
		return 2 * power(n - 1);//n�� 0�� �ƴ϶�� 2�� ���ϰ� n-1�� ���ڷ� �����Ͽ� power�� �ٽ� ȣ��
}
void Hadamard(int** arr, int n, int i, int j) {//Hadamard ����� �����ϴ� �Լ�
	if (n==1) {//n�� 1�� ��, [i][j]�� 1�� ����
		arr[i][j] = 1;
		return;
	}
	int temp = n / 2;//���� ũ�⸦ ����
	Hadamard(arr, temp, i, j);//1���� (���� ��)����
	Hadamard(arr, temp, i, j + temp);//2���� (������ ��)����
	Hadamard(arr, temp, i + temp, j);//3���� (���� �Ʒ�)����
	for (int k = 0; k < temp; k++) {
		for (int l = 0; l < temp; l++) {
			arr[i + temp + k][j + temp + l] = -arr[i + k + temp][j + l];//4����(������ �Ʒ�)�� 3������ �ݴ� ��ȣ�� �����ؾ��� 
		}
	}
}