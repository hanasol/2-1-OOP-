#include <iostream>
using namespace std;
int fibo_rec(int num);//����Լ��� ������ �Ǻ���ġ ���� ����
int fibo_iter(int num);//����Լ��� ������� ���� �Ǻ���ġ ���� ����
int main() {
	int a;
	cout << "Enter the number:";
	cin >> a;//���� �Է�
	cout << "Fibonacci_iter(" << a << "): " << fibo_rec(a) << endl;//�Է¹��� ������ �Ǻ���ġ ���� �� ���
	cout << "Fibonacci_iter(" << a << "): " << fibo_iter(a);//�Է¹��� ������ �Ǻ���ġ ���� �� ���
}
int fibo_rec(int num) {//����Լ��� ������ �Ǻ���ġ ���� ����
	if (num == 1)//�Ǻ���ġ ������ ù��° ���� 0
		return 0;
	else if (num == 2)//�Ǻ���ġ ������ �ι�° ���� 1
		return 1;
	else
		return fibo_rec(num - 1) + fibo_rec(num - 2);//3��° �̻��� ������ �ռ� �� ���� ���̹Ƿ� 
	//num-1, num-2�� �Ķ���ͷ� �����Ͽ� ���� ���� �� ��ȯ�ϰ� �� �������� �ڱ� �ڽŰ�
	//���� �Լ��� ȣ���ϹǷ� ����Լ���
}
int fibo_iter(int num) {//����Լ��� ������� ���� �Ǻ���ġ ���� ����
	int* arr = new int[num];//arr�� int�� ����� num��ŭ �������� ũ�� �Ҵ�
	arr[1] = 0;//�Ǻ���ġ ������ ù��° ���� 0
	arr[2] = 1;//�Ǻ���ġ ������ �ι�° ���� 1
	for (int i = 3; i <= num; i++)
		arr[i] = arr[i - 1] + arr[i - 2];//3���� num���� �ռ� �� �迭�� ���� ���Ͽ� ����
	return arr[num];//�Է¹��� ���� �Ǻ���ġ ���� ���� ��ȯ
	delete arr;//�޸� ����
}