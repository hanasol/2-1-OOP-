#include <iostream>
using namespace std;
#define size 100
int priority(char op);
int operate(int a, int b, char op);
bool digit(char n);
int calculate(char* arr);
int strlen_(const char* str);
int flag = 0;
class Stack {
	int ptr;//������ ����Ű�� ����
	int arr[size];//���� �迭
public:
	Stack() {
		ptr = -1;//��ü�� �����Ǹ� ������ ��������Ƿ� ptr=-1
	}
	void push(int a) {//���ÿ� ���� �־���
		ptr++;//ptr�� ����
		arr[ptr] = a;//ptr�� �� �Ҵ�
	}
	int pop() {//���ÿ� �� ��ȯ, ����
		if (ptr < 0) {//ptr�� 0���� ������ ������ �������
			return 0;
		}
		else {
			int a = arr[ptr];//ptr�� ����Ű�� ������ ���� ����
			ptr--;//ptr�ϳ� ����
			return a;//�� ���� �� ��ȯ
		}
	}
	int peek() {//���������ʰ� �� ��ȯ
		if (ptr < 0) {//ptr�� 0���� ������ ������ �������
			return 0;
		}
		else {
			return arr[ptr];//���� ptr�� ����Ű�� �� ��ȯ
		}
	}
	bool empty() {//������ ����ִ��� �Ǵ��ϴ� �Լ�
		if (ptr < 0)
			return false;//����ִٸ� false��ȯ
		return true;//ä�����ִٸ� true��ȯ
	}
};
int main() {
	char str[size];
	cout<<"Enter the formular : ";
	cin.getline(str,size);//size��ŭ�� ������ ������ ���ڿ��� �Է¹���
	cout << "Result : " << calculate(str);
}
int priority(char op) {//�������� �켱����
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;//���ϱ�� ������ �����ڰ� �켱������ ����
	return 0;
}
int operate(int a, int b, char op) {//�������ִ� �Լ�
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if(b!=0)
			return a / b;
		else {
			cout << "�и�� 0�� �� �� �����ϴ�.\n";
			exit(1);//�и� 0�� �Ǵ� ������ �߻������Ƿ� 1�� ��ȯ�ϰ� ����
		}
	default:
		cout << "��ȿ���� ���� ��Ģ�����Դϴ�.\n";
		exit(1);//��ȿ���� ���� ��Ģ�����̹Ƿ� 1�� ��ȯ�ϰ� ����
	}
	return 0;
}
bool digit(char n) {//���������� �Ǻ����ִ� �Լ�
	if ('0' <= n && n <= '9')
		return true;//���ڶ�� true
	return false;//�ƴ϶�� false
}
int calculate(char* arr) {
	Stack number;//����(�ǿ�����)�� �����ϴ� ����
	Stack op;//�����ڸ� �����ϴ� ����

	for (int i = 0; i < strlen_(arr); i++) {
		if (arr[i] == ' ')//��ĭ ����
			continue;

		else if (arr[i] == '(')//���� ��ȣ
			op.push(arr[i]);//���� ��ȣ�� ������ ���ÿ� ����

		else if (digit(arr[i])) {//����
			int temp = 0;
			int len = strlen_(arr);
			while (i < len && digit(arr[i])) {//arr�� ���̺��� �۰� ���ڶ��
				temp = (10 * temp) + (arr[i] - '0');//10�� �Ѿ�� ���� ���� �� ����
				i++;//�ڸ���+1 ��ŭ i ����
			}
			number.push(temp);//temp���� ���� ���ÿ� �־���
			i--;//������ i�� �ϳ� ���ҽ�Ŵ
		}

		else if (arr[i] == ')') {//�ݴ� ��ȣ
			while (op.empty() && op.peek() != '(') {//������ ������ ������� �ʰ� ������ ������ �� �� �����ڰ� ���� ��ȣ�� �ƴ϶��
				//�ǿ����ڿ� �������� ����� ���� --> ��ȣ�� ������ ���� �����ϴ� ȿ��
				int num2 = number.pop();
				int num1 = number.pop();//���� ���ÿ��� �ΰ��� ���� ����
				char op1 = op.pop();//������ ���ÿ��� �ϳ��� �����ڸ� �̾Ƽ� ����
				number.push(operate(num1, num2, op1));//���� ����� ����
			}
			if (op.empty())
				op.pop();//�ݺ��Ͽ� �����ڵ��� ��� �������� ���� ���� ��ȣ�� ����
		}

		else {//������
			while (op.empty() && priority(op.peek()) >= priority(arr[i])) {//���� ���ÿ� ����� �������� �켱������ ������ ������ ���� ���ų� ���ٸ� �ݺ�
				int num2 = number.pop();
				int num1 = number.pop();//���� ���ÿ��� �ΰ��� ���� ����
				char op1 = op.pop();//������ ���ÿ��� �ϳ��� �����ڸ� ����
				number.push(operate(num1, num2, op1));//���� ����� ����
			}
			op.push(arr[i]);//������ �����ڸ� ������ ���ÿ� ����
		}
	}
	while (op.empty()) {//�����ڰ� ���� ������ �ݺ�
		int num2 = number.pop();
		int num1 = number.pop();//���� ���ÿ��� �ΰ��� ���� ����
		char op1 = op.pop();//������ ���ÿ��� �ϳ��� �����ڸ� ����
		number.push(operate(num1, num2, op1));//���� ����� ����
	}
	return number.pop();//���� �� ��ȯ
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
