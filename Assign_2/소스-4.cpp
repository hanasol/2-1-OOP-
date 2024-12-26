#include <iostream>
using namespace std;
void Separate(char* str, char* del);
bool Check(char* str, char* del);
int strlen_(const char* str);
int main() {
	char str[100];
	char del[10];
	cout << "Enter the string : ";
	cin.getline(str,100);//공백을 포함한 문자열을 입력
	cout << "Enter the delimeter : ";
	cin.getline(del, 10);//공백을 포함한 문자열을 입력
	Separate(str, del);
}
void Separate(char* str, char* del) {//구분자로 문자열을 나누는 함수
	char temp[100][100];//구분자로 자른 string을 저장하는 배열
	int i = 0;//str의 index
	int j = 0;//del의 index, temp의 index
	int k = 0;//temp의 행
	while (str[i] != '\0') {//str이 널문자가 아닐 때까지 반복->str의 끝까지 반복
		if (Check(&str[i], del)) {//구분자와 다른 문자열, str[i]의 주소를 전달하여 구분자가 단어나 공백이라도 
			//한글자씩 비교하여 구분할 수 있도록 함
			temp[k][j] = str[i];//k행에 str과 같은 문자 저장
			j++;//j증가
		}//반복문을 돌면서 구분자와 같은 문자를 만나기 전까지 문자가 저장되어, 구분자로 문자열이 나누어짐
		else {//구분자와 같은 문자열
			temp[k][j] = '\0';//k행의 끝에 널문자를 저장
			k++;//다음행으로 넘어감
			j = 0;//j를 0으로 초기화
			i += strlen_(del) - 1;//i에 del의 길이-1을 더하여 구분자를 제외한 다음 문자열 앞 인덱스로 넘어감
		}
		i++;//str의 다음 문자로 구분자와 비교하기위해 i증가
	}
	temp[k][j] = '\0';//마지막 행의 끝을 널문자로 저장
	cout << "Separated tokens :\n";
	for (int i = 0; i <= k; i++)
		cout << temp[i] << "\n";//구분자로 구분된 문자열을 출력
}
bool Check(char* str, char* del) {//문자가 구분자와 같은지 판단하는 함수
	for (int i = 0; del[i] != '\0'; i++) {
		if (str[i] != del[i])//문자가 구분자와 같지 않으면
			return true;//true반환
	}
	return false;//같다면 false 반환
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