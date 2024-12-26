#include <iostream>
using namespace std;
void Separate(char* str, char* del);
bool Check(char* str, char* del);
int strlen_(const char* str);
int main() {
	char str[100];
	char del[10];
	cout << "Enter the string : ";
	cin.getline(str,100);//������ ������ ���ڿ��� �Է�
	cout << "Enter the delimeter : ";
	cin.getline(del, 10);//������ ������ ���ڿ��� �Է�
	Separate(str, del);
}
void Separate(char* str, char* del) {//�����ڷ� ���ڿ��� ������ �Լ�
	char temp[100][100];//�����ڷ� �ڸ� string�� �����ϴ� �迭
	int i = 0;//str�� index
	int j = 0;//del�� index, temp�� index
	int k = 0;//temp�� ��
	while (str[i] != '\0') {//str�� �ι��ڰ� �ƴ� ������ �ݺ�->str�� ������ �ݺ�
		if (Check(&str[i], del)) {//�����ڿ� �ٸ� ���ڿ�, str[i]�� �ּҸ� �����Ͽ� �����ڰ� �ܾ �����̶� 
			//�ѱ��ھ� ���Ͽ� ������ �� �ֵ��� ��
			temp[k][j] = str[i];//k�࿡ str�� ���� ���� ����
			j++;//j����
		}//�ݺ����� ���鼭 �����ڿ� ���� ���ڸ� ������ ������ ���ڰ� ����Ǿ�, �����ڷ� ���ڿ��� ��������
		else {//�����ڿ� ���� ���ڿ�
			temp[k][j] = '\0';//k���� ���� �ι��ڸ� ����
			k++;//���������� �Ѿ
			j = 0;//j�� 0���� �ʱ�ȭ
			i += strlen_(del) - 1;//i�� del�� ����-1�� ���Ͽ� �����ڸ� ������ ���� ���ڿ� �� �ε����� �Ѿ
		}
		i++;//str�� ���� ���ڷ� �����ڿ� ���ϱ����� i����
	}
	temp[k][j] = '\0';//������ ���� ���� �ι��ڷ� ����
	cout << "Separated tokens :\n";
	for (int i = 0; i <= k; i++)
		cout << temp[i] << "\n";//�����ڷ� ���е� ���ڿ��� ���
}
bool Check(char* str, char* del) {//���ڰ� �����ڿ� ������ �Ǵ��ϴ� �Լ�
	for (int i = 0; del[i] != '\0'; i++) {
		if (str[i] != del[i])//���ڰ� �����ڿ� ���� ������
			return true;//true��ȯ
	}
	return false;//���ٸ� false ��ȯ
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