#include <iostream>
using namespace std;
double ceil_(double num);//ceil_�Լ� ����
double floor_(double num);//floor_�Լ� ����
double round_(double num);//round_�Լ� ����
int main() {
	double num;
	cout << "Enter the floating-point number: ";
	cin >> num;//float�� ������ �Է¹���
	cout << fixed;//�Ҽ��� �Ʒ� �ڸ��� ������ ���ؼ� fixed ���
	cout.precision(2);//�Ҽ��� �Ʒ� 2�ڸ������� ���
	cout << "Ceiling: " << ceil_(num) / 100.0 << endl;//�ø�
	cout << "Floor: " << floor_(num) / 100.0 << endl;//����
	cout << "Rounding: " << round_(num) / 100.0;//�ݿø� 
}

double ceil_(double num) {//�ø�
	num *= 100;
	if (num >= 0) {//num�� ����� ��
		num += 1;//1�� �����ְ�
		int a = (int)num;//int������ ����ȯ
		return a;
	}
	else {//num�� ������ ��
		int a = (int)num;//int������ ����ȯ�Ͽ� �Ҽ��� ���� (������ �ø�)
		return a;
	}
}
double floor_(double num) {//����
	num *= 100;
	int a = (int)num;
	if (num >= 0)//������ ����ȯ�� ���ؼ� �Ҽ��� ����
		return a;
	else//������� 1�� �� ���� ����ȯ�Ͽ� �Ҽ��� ����
		return a - 1;//(������ ����)
}
double round_(double num) {//�ݿø�
	num *= 100;
	if (num >= 0)
		return num + 0.49;//������ 0.499�� ���ϰ� ��ȯ�Ͽ� �ݿø�
	else
		return num - 0.49;//������� 0.499�� ���� ��ȯ�Ͽ� �ݿø�
}