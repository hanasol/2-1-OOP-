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
	int ptr;//스택을 가리키는 변수
	int arr[size];//스택 배열
public:
	Stack() {
		ptr = -1;//객체가 생성되면 스택이 비어있으므로 ptr=-1
	}
	void push(int a) {//스택에 값을 넣어줌
		ptr++;//ptr값 증가
		arr[ptr] = a;//ptr에 값 할당
	}
	int pop() {//스택에 값 반환, 삭제
		if (ptr < 0) {//ptr이 0보다 작으면 스택이 비어있음
			return 0;
		}
		else {
			int a = arr[ptr];//ptr이 가리키는 스택의 값을 저장
			ptr--;//ptr하나 감소
			return a;//맨 위의 값 반환
		}
	}
	int peek() {//삭제하지않고 값 반환
		if (ptr < 0) {//ptr이 0보다 작으면 스택이 비어있음
			return 0;
		}
		else {
			return arr[ptr];//현재 ptr이 가리키는 값 반환
		}
	}
	bool empty() {//스택이 비어있는지 판단하는 함수
		if (ptr < 0)
			return false;//비어있다면 false반환
		return true;//채워져있다면 true반환
	}
};
int main() {
	char str[size];
	cout<<"Enter the formular : ";
	cin.getline(str,size);//size만큼의 공백을 포함한 문자열을 입력받음
	cout << "Result : " << calculate(str);
}
int priority(char op) {//연산자의 우선순위
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;//곱하기와 나눗셈 연산자가 우선순위가 높음
	return 0;
}
int operate(int a, int b, char op) {//연산해주는 함수
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
			cout << "분모는 0이 될 수 없습니다.\n";
			exit(1);//분모가 0이 되는 에러가 발생했으므로 1을 반환하고 종료
		}
	default:
		cout << "유효하지 않은 사칙연산입니다.\n";
		exit(1);//유효하지 않은 사칙연산이므로 1을 반환하고 종료
	}
	return 0;
}
bool digit(char n) {//숫자인지를 판별해주는 함수
	if ('0' <= n && n <= '9')
		return true;//숫자라면 true
	return false;//아니라면 false
}
int calculate(char* arr) {
	Stack number;//숫자(피연산자)를 저장하는 스택
	Stack op;//연산자를 저장하는 스택

	for (int i = 0; i < strlen_(arr); i++) {
		if (arr[i] == ' ')//빈칸 무시
			continue;

		else if (arr[i] == '(')//여는 괄호
			op.push(arr[i]);//여는 괄호를 연산자 스택에 저장

		else if (digit(arr[i])) {//숫자
			int temp = 0;
			int len = strlen_(arr);
			while (i < len && digit(arr[i])) {//arr의 길이보다 작고 숫자라면
				temp = (10 * temp) + (arr[i] - '0');//10을 넘어가는 수가 계산될 수 있음
				i++;//자릿수+1 만큼 i 증가
			}
			number.push(temp);//temp값을 숫자 스택에 넣어줌
			i--;//증가된 i를 하나 감소시킴
		}

		else if (arr[i] == ')') {//닫는 괄호
			while (op.empty() && op.peek() != '(') {//연산자 스택이 비어있지 않고 연산자 스택의 맨 위 연산자가 여는 괄호가 아니라면
				//피연산자와 연산자의 계산을 진행 --> 괄호의 연산을 먼저 진행하는 효과
				int num2 = number.pop();
				int num1 = number.pop();//숫자 스택에서 두개의 값을 뽑음
				char op1 = op.pop();//연산자 스택에서 하나의 연산자를 뽑아서 없앰
				number.push(operate(num1, num2, op1));//연산 결과를 저장
			}
			if (op.empty())
				op.pop();//반복하여 연산자들은 모두 지워지고 남은 여는 괄호를 삭제
		}

		else {//연산자
			while (op.empty() && priority(op.peek()) >= priority(arr[i])) {//현재 스택에 저장된 연산자의 우선순위가 현재의 연산자 보다 높거나 같다면 반복
				int num2 = number.pop();
				int num1 = number.pop();//숫자 스택에서 두개의 값을 뽑음
				char op1 = op.pop();//연산자 스택에서 하나의 연산자를 뽑음
				number.push(operate(num1, num2, op1));//연산 결과를 저장
			}
			op.push(arr[i]);//현재의 연산자를 연산자 스택에 넣음
		}
	}
	while (op.empty()) {//연산자가 없을 때까지 반복
		int num2 = number.pop();
		int num1 = number.pop();//숫자 스택에서 두개의 값을 뽑음
		char op1 = op.pop();//연산자 스택에서 하나의 연산자를 뽑음
		number.push(operate(num1, num2, op1));//연산 결과를 저장
	}
	return number.pop();//최종 답 반환
}
int strlen_(const char* str) {//NULL을 제외한 문자열의 길이 반환
	int len = 0;
	int i = 0;
	while (str[i] != NULL) {//str이 NULL이 아니라면 반복
		len++;//반복마다 길이가 1씩 증가
		i++;
	}
	return len;//문자열의 길이 반환
}
