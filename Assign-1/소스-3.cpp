#include <iostream>
using namespace std;
int main() {
	char arr[10] = {};//char�� ������ �Է¹��� ���� ����
	cout << "Enter ten characters: ";
	for (int i = 0; i < 10; i++)
		cin >> arr[i];//char�� ���� �Է�
	cout << "Input characters are: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " " << arr[9 - i];//i�� 0���� 4���� �ݺ��ϸ鼭 i�� 9-i��°�� char������ ���,
		//(1, 10), (2, 9), (3, 8)..��°�� ������ ��µ�
		if (i != 4)//������ ���� �ƴϸ� ����
			cout << endl;
	}
	return 0;
}