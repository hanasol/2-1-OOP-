#include <iostream>
using namespace std;
int main() {
	int num;//�Է¹��� ����
	int arr[5] = { 0, };//�迭�� ���� 0���� �ʱ�ȭ�Ͽ� ����
	cout << "Enter the number: ";
	cin >> num;
	for (int i = 4; i >= 0; i--) {
		arr[i] = num % 10;//num�� 1�� �ڸ����� arr �迭�� ���ڸ����� ������
		num /= 10;//num�� 1�� �ڸ����� ����
	}
	for (int i = 0; i < 5; i++) {//��
		for (int j = i; j < 5; j++) {//��, j�� i���� �����Ͽ� �ϳ��� �������� �з��� ��µǵ��� ��,
			//arr�� ���ڸ����� num�� 1�� �ڸ����� �����Ͽ����Ƿ� num�� ���� ������ ������ ����Ǿ�����
			cout << arr[j] << " ";
		}
		if (i != 4)//���������� �ƴ϶�� ����
			cout << endl;
	}
	return 0;
}