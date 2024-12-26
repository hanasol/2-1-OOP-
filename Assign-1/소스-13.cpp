#include <iostream>
using namespace std;
void convert(char* str);//대소문자를 바꾸어주는 convert함수 선언
int main() {
	char a[100] = "";//100크기의 char형 배열 선언
	cout << "Enter the string: ";
	cin.getline(a, 100);//공백까지 입력을 받기위해서 getline사용
	convert(a);//대소문자 변환
	cout << "Result: ";
	cout << a;//결과값 출력
	return 0;
}
void convert(char* str) {//대소문자를 바꾸어주는 convert함수 정의
	for (int i = 0; i < strlen(str); i++) {//str의 길이만큼 반복
		if ('A' <= str[i] && str[i] <= 'Z') {//아스키 코드에서 알파벳 대소문자의 차이는 32, 대문자일때
			str[i] += 32;//대문자가 소문자보다 32만큼 작으므로 32를 더해줌으로써 소문자로 변환
		}
		else if ('a' <= str[i] && str[i] <= 'z')//소문자일때
			str[i] -= 32;//소문자가 대문자보다 32만큼 크므로 32를 빼줌으로써 대문자로 변환
	}
}
