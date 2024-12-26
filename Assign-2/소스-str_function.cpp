#include <iostream>
using namespace std;
int strcmp_(const char* str1, const char* str2);
void strcpy_(char* dest, const char* src);
int strlen_(const char* str);
int main() {
    char* str1 = new char[100];
    char* str2 = new char[100];
    cin >> str1;
    cin >> str2;
    if (0 == strcmp_(str1, str2))
        cout << "���ڿ��� �����մϴ�\n";
    else if (0 < strcmp_(str1, str2))
        cout << "str1�� str2���� ���������� ���Դϴ�.\n";
    else
        cout << "str1�� str2���� ���������� ���Դϴ�.\n";
    cout << strlen_(str1);
}
int strcmp_(const char* str1, const char* str2) {//���ڿ��� ������ �����ִ� �Լ�
    int i = 0;
    while (str1[i]!=NULL && (str1[i] == str2[i])) {//�� ���ڿ��� ���ڰ� ���� str1�� NULL�� �ƴ϶�� �ݺ�
        i++;
    }
    if (str1[i] - str2[i] == 0)//�� �ƽ�Ű ���� ���̰� 0�̶�� �� ���ڿ��� ����
        return 0;
    else if (str1[i] > str2[i])
        return 1;//str1�� str2���� ���������� �ڸ� 1��ȯ
    else
        return -1;//str1�� str2���� ���������� ���̸� -1��ȯ
}
void strcpy_(char* str1, const char* str2) {//str2�� ���ڿ��� str1�� �����ϴ� �Լ�
    int i = 0;
    while (str2[i]!=NULL) {//str2�� NULL�� �ƴ϶�� �ݺ�
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0'; // ���ڿ��� ���� �� ���ڸ� �߰�
}
int strlen_(const char* str) {//NULL�� ������ ���ڿ��� ���� ��ȯ
    int len = 0;
    int i = 0;
    while (str[i] != NULL) {//str�� NULL�� �ƴ϶�� �ݺ�
        len++;//�ݺ����� ���̰� 1�� ����
        i++;
    }
    return len;//���ڿ��� ���� ��ȯ
}