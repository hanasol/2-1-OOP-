#include <iostream>
using namespace std;
int main() {
	srand(time(NULL));
	int arr[4] = { 0, };//��������
	int arr2[4] = { 0, };//�Է¼���
	arr[0] = rand() % 10;
	for (int i = 1; i < 4; i++) {
		arr[i] = rand() % 10;//���ڸ� �Ҵ�
		for (int j = i - 1; j >= 0; j--) {//i-1���� 0���� �ݺ��ϸ鼭
			while (arr[i] == arr[j])//�ߺ��� �ִٸ�
				arr[i] = rand() % 10;//�ٽ� �Ҵ�
		}
	}
	for (int i = 0; i < 4; i++)
		cout << arr[i] << " ";
}