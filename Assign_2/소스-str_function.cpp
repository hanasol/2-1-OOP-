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
        cout << "문자열이 동일합니다\n";
    else if (0 < strcmp_(str1, str2))
        cout << "str1이 str2보다 사전순으로 뒤입니다.\n";
    else
        cout << "str1이 str2보다 사전순으로 앞입니다.\n";
    cout << strlen_(str1);
}
int strcmp_(const char* str1, const char* str2) {//문자열이 같은지 비교해주는 함수
    int i = 0;
    while (str1[i]!=NULL && (str1[i] == str2[i])) {//두 문자열의 문자가 같고 str1이 NULL이 아니라면 반복
        i++;
    }
    if (str1[i] - str2[i] == 0)//두 아스키 값의 차이가 0이라면 두 문자열이 같음
        return 0;
    else if (str1[i] > str2[i])
        return 1;//str1이 str2보다 사전순으로 뒤면 1반환
    else
        return -1;//str1이 str2보다 사전순으로 앞이면 -1반환
}
void strcpy_(char* str1, const char* str2) {//str2의 문자열을 str1에 복사하는 함수
    int i = 0;
    while (str2[i]!=NULL) {//str2가 NULL이 아니라면 반복
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0'; // 문자열의 끝에 널 문자를 추가
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