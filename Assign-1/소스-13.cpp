#include <iostream>
using namespace std;
void convert(char* str);//��ҹ��ڸ� �ٲپ��ִ� convert�Լ� ����
int main() {
	char a[100] = "";//100ũ���� char�� �迭 ����
	cout << "Enter the string: ";
	cin.getline(a, 100);//������� �Է��� �ޱ����ؼ� getline���
	convert(a);//��ҹ��� ��ȯ
	cout << "Result: ";
	cout << a;//����� ���
	return 0;
}
void convert(char* str) {//��ҹ��ڸ� �ٲپ��ִ� convert�Լ� ����
	for (int i = 0; i < strlen(str); i++) {//str�� ���̸�ŭ �ݺ�
		if ('A' <= str[i] && str[i] <= 'Z') {//�ƽ�Ű �ڵ忡�� ���ĺ� ��ҹ����� ���̴� 32, �빮���϶�
			str[i] += 32;//�빮�ڰ� �ҹ��ں��� 32��ŭ �����Ƿ� 32�� ���������ν� �ҹ��ڷ� ��ȯ
		}
		else if ('a' <= str[i] && str[i] <= 'z')//�ҹ����϶�
			str[i] -= 32;//�ҹ��ڰ� �빮�ں��� 32��ŭ ũ�Ƿ� 32�� �������ν� �빮�ڷ� ��ȯ
	}
}
