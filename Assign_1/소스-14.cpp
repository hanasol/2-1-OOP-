#include <iostream>
using namespace std;
void perfect(int num);//���������� �Ǻ��ϴ� perfect�Լ� ����
int main() {
	cout << "Perfect numbers between 1 and 1000:" << endl;
	for (int i = 2; i < 1001; i++) {
		perfect(i);//1�� �������� �ƴϹǷ� 2���� 1000���� �ݺ��ϸ� �������� ���
	}
	return 0;
}
void perfect(int num) {
	if (num % 2 == 1) {//1000������ ������ �� Ȧ���� ����
		return;
	}
	else {
		int arr[1001] = { 0, };
		int sum = 0;//num�� ������ ����� ��
		int cnt1 = 0, cnt2 = 0;//num�� ������ ����� ����
		for (int i = 1; i < num; i++) {//1���� num-1���� �ݺ�
			if (num % i == 0) {//num�� i�� ���� �������� 0�̶�� i�� num�� ���
				arr[i] += i;//����� i��� arr[i]==[i]
				cnt1 += 1;//����� ���� 1�� ����
				sum += i;//num�� ������ ��� ����� ��
			}
		}
		if (sum == num) {//num�� num�� ������ ��� ����� ���� ���ٸ� ������
			cout << num << " = ";
			for (int i = 1; i < num; i++) {//1���� num-1���� �ݺ�
				if (arr[i] != 0) {//arr[i]�� 0�� �ƴ϶�� num�� ���
					cout << i;//����� ���
					cnt2 += 1;//cnt2�� ����
					if (cnt2 < cnt1)//cnt2�� ���� ����� �������� �������� +��ȣ ���
						cout << " + ";
				}
			}
			cout << "\n";
		}
		else
			return;
	}
}
