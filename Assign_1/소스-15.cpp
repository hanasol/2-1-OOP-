#include <iostream>
#include <ctime>
using namespace std;
bool Check(int* arr1, int* arr2);//Hit�� blow�� üũ���ִ� Check�Լ� ����
int main() {
	srand(time(NULL));//���ึ�� ������ ���� �ޱ����ؼ� srand�Լ��� �õ�� time(NULL)�� �־���
	int arr[4] = { 0, };//��������
	int arr2[4] = { 0, };//�Է¼���
	for (int i = 0; i < 4; i++)
	{
		arr[i] = rand() % 4;//�迭�� 0~9�� �� �Ҵ�
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) { //arr[i]�� arr[j]�� ������
				i--;//i�� �ϳ� �ٿ��� �ٽ� �� �Ҵ� ��, �ߺ��˻� ����
				continue;//�ߺ��� ã���� �ٸ� �ߺ��� �˻��� �ʿ� �����Ƿ� continue�� ���ؼ� �� ���Ҵ�
			}
		}
	}
	for (int i = 0; i < 5; i++) {//5�� �ݺ�
		if (Check(arr, arr2)) {//hit�� 4�� ���߸� true�� ��ȯ
			cout << "Win" << endl;//win���
			return 0;
		}
		cout << endl;
	}//for���� �����ٸ� ���� ������ ���� ���̹Ƿ�
	cout << "Lose" << endl << endl;//lose���
	cout << "the correct answer: ";
	for (int j = 0; j < 4; j++)
		cout << arr[j];//�������� ���
}
bool Check(int* arr1, int* arr2) {//Check�Լ� ����, true�� false�� ��ȯ�ϹǷ� bool������ ������
	int cnt1 = 0, cnt2 = 0;//Hit, Blow
	int num;
	cout << "Guess: ";
	cin >> num;
	for (int i = 1; i <= 4; i++) {//�Է¹��� ���ڸ� �ϳ��� �迭�� ����
		arr2[4 - i] = num % 10;//3 2 1 0�� �ε����� 1�� �ڸ��� �����ϹǷ� ���� �Է°� ���� ������ �����
		num /= 10;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr2[i] == arr1[j]) {
				cnt2 += 1;//���� ���� ������ blow+=1;
				if (i == j)
					cnt1 += 1;//�ڸ����� ���ٸ� hit+=1;
			}
		}
	}
	cnt2 -= cnt1;//blow�� hit���� �ߺ����� �� ���� �����Ƿ� hit���� ����
	cout << endl << "Hit: " << cnt1 << ", " << "Blow: " << cnt2;
	cout << endl << endl << "------------------" << endl;
	if (cnt1 == 4)//Hit�� 4���� win
		return true;
}
