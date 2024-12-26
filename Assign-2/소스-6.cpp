#include <iostream>
#include <fstream>
using namespace std;
void strcpy_(char* str1, const char* str2);
int strcmp_(const char* str1, const char* str2);
int strlen_(const char* str);
void Search(int& flag, int& col, char* word, char* arr);
void Change(int flag, int col, char* word1, char* word2, char* arr);
void Insert(int col, char* word, char* arr);
void Delete(int flag, int col, char* word, char* arr);
#define max_row 1000
#define max_col 1000
int main() {
	ifstream fin;//파일에서 문자열을 읽어오기 위한 ifstream객체
	char arr[max_row][max_col] = { 0, };//행과 열을 저장하는 2차원 배열
	char temp[300];//파일에서 문자열을 저장할 char형 배열
	int row = 0;//문장의 총 행
	char menu[15];//메뉴를 입력받을 char형 배열

	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "open")) {//open 커맨드
			char file_name[30];
			cin >> file_name;//파일 이름 입력
			fin.open(file_name);//입력받은 파일을 엶
			while (fin.getline(temp, 300)) {//getline을 통해서 temp에 공백을 포함한 한 문장씩 저장
				strcpy_(arr[row], temp);//2차원 배열의 행에 문장을 저장
				row++;//행 증가
			}
		}
		else if (0 == strcmp(menu, "search")) {//search 커맨드
			char word[50] = { NULL };//찾을 단어를 입력받을 배열
			int num = 0;//찾는 단어가 몇개인지 저장할 변수
			cin >> word;//단어 입력
			for (int i = 0; i < row; i++) {
				int col = 0;//한 행의 열
				int flag = 0;//단어를 찾았는지 확인하는 변수
				Search(flag, col, word, arr[i]);//단어 서치
				if (flag == 1)//1이라면 단어를 찾았다는 뜻이므로
					num++;//num증가
			}
			cout << "===\'" << word << "\' search(" << num << ")===\n";
			for (int i = 0; i < row; i++) {
				int col = 0;
				int flag = 0;
				Search(flag, col, word, arr[i]);
				if (flag == 1) {//flag가 1이라면 문자열을 찾음
					cout << "(" << i << ", " << col << ") ";//찾은 단어의 행과 열 출력
				}
			}
			cout << "\n------------------------------\n";
		}
		else if (0 == strcmp_(menu, "change")) {//change 커맨드
			char word1[30];//바꿀 단어
			char word2[30];//바뀔 단어
			cin >> word1 >> word2;//두 단어를 입력받음
			for (int i = 0; i < row; i++) {
				int col = 0;//한 행의 열
				int flag = 0;//단어를 찾아서 바꾸어야 하므로 단어를 찾았는지 확인하는 변수
				Search(flag, col, word1, arr[i]);//단어 검색
				Change(flag, col, word1, word2, arr[i]);//단어 변경
			}
			cout << "===change===\n";
			cout << word1 << " -> " << word2<<"\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "insert")) {//insert 커맨드
			int row, col;//단어를 삽입할 행, 열
			char word[30];//삽입할 단어
			cin >> row >> col >> word;//행 열 단어 입력
			Insert(col, word, arr[row]);//해당 행과 열에 단어 삽입
			cout << "===insert===\n";
			cout << word << " Inserted into (" << row << ", " << col << ")\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "delete")) {//delete 커맨드
			char word[30];//삭제할 단어
			cin >> word;
			for (int i = 0; i < row; i++) {
				int col = 0;//한 행의 열
				int flag = 0;//단어를 찾아서 삭제해야 하므로 단어를 찾았는지 확인하는 변수
				Search(flag, col, word, arr[i]);//단어 검색
				Delete(flag, col, word, arr[i]);//단어 삭제
			}
			cout << "===delete===\n";
			cout << "Delete " << word << "\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "save")) {//save 커맨드
			ofstream fout;//새로 바뀐 문장을 파일에 저장하기 위해서 ofstream객체
			char file_name[20];//저장할 파일 이름
			cin >> file_name;
			fout.open(file_name);//파일을 엶
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < max_col && arr[i][j] != '\0'; j++)
					fout << arr[i][j];//매트릭스에 변경되어 저장된 함수를 파일에 저장
				fout << "\n";
			}
			fout.close();//파일을 닫음
			cout << "===save===\n";
			cout << "Save the file as \"" << file_name << "\"\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "exit")) {
			cout << "Exit the program\n";
			fin.close();//open 커맨드에서 열었던 파일을 닫음
			return 0;
		}
		else
			cout << "Invalid input\n";
	}

	fin.close();
}

void strcpy_(char* str1, const char* str2) {//str2의 문자열을 str1에 복사하는 함수
	int i = 0;
	while (str2[i] != NULL) {//str2가 NULL이 아니라면 반복
		str1[i] = str2[i];//str1에 i인덱스에 str2의 i인덱스의 값 저장
		i++;//i증가
	}
	str1[i] = '\0'; // 문자열의 끝에 널 문자를 추가
}
int strcmp_(const char* str1, const char* str2) {//문자열이 같은지 비교해주는 함수
	int i = 0;
	while (str1[i] != NULL && (str1[i] == str2[i])) {//두 문자열의 문자가 같고 str1이 NULL이 아니라면 반복
		i++;
	}
	if (str1[i] - str2[i] == 0)//두 아스키 값의 차이가 0이라면 두 문자열이 같음
		return 0;
	else if (str1[i] > str2[i])
		return 1;//str1이 str2보다 사전순으로 뒤면 1반환
	else
		return -1;//str1이 str2보다 사전순으로 앞이면 -1반환
}
int strlen_(const char* str) {//NULL을 제외한 문자열의 길이 반환
	int len = 0;//문자열의 길이
	int i = 0;
	while (str[i] != NULL) {//str이 NULL이 아니라면 반복
		len++;//반복마다 길이가 1씩 증가
		i++;//i증가
	}
	return len;//문자열의 길이 반환
}

void Search(int& flag, int& col, char* word, char* arr) {//내가 찾을 단어의 열을 저장하는 함수
	int column = 0;
	int j = 0;
	int wordlen = strlen_(word);//찾을 단어의 길이 저장
	for (int i = 0; i < max_col && arr[i] != '\0'; i++) {
		if (arr[i] == ' ') {//공백이라면 다음 문자로 넘어감
			column++;
			continue;
		}
		else {//공백이 아니라면 단어를 비교
			char temp[30] = { NULL };
			j = i;
			int k = 0;
			while (arr[j] != ' ' && arr[j] != '\0' && k < wordlen) {//다음 공백을 만나기 전까지, 널문자가 아닐 때 까지, 찾을 단어의 길이만큼 비교
				temp[k++] = arr[j++];//문장의 단어를 새로운 배열에 저장
			}
			temp[k] = '\0';//끝에 널문자를 붙혀서 문자열로 만듦
			if (0 == strcmp_(temp, word)) {//두 문자열을 비교하여 같다면
				col = column;//해당 단어의 첫 인덱스를 저장
				flag = 1;//flag를 1로 저장
			}
			column++;//열 증가
		}
	}
}
void Change(int flag, int col, char* word1, char* word2, char* arr) {//word1 -> word2로 바꾸는 함수
	if (flag == 0)//flag가 0이라면 바꿀 단어가 해당 행에 없으므로 종료
		return;
	else if(flag==1) {//flag가 1이라면 바꿀 단어가 해당행에 있으므로 실행
		int len1 = strlen_(word1);//바꿀 단어
		int len2 = strlen_(word2);//바뀔 단어
		int arrlen = strlen_(arr);//행의 길이
		char temp1[200] = { NULL };//단어를 제외한 앞문장
		char temp2[200] = { NULL };//단어를 제외한 뒷문장
		char newarr[300] = { NULL };//새문장
		int j = 0;
		int i;
		for (i = 0; i < col; i++) {//문장의 처음부터 내가 찾은 단어의 앞까지 저장
			temp1[j] = arr[i];
			j++;
		}
		temp1[i] = '\0';//널문자를 붙여서 문자열로 만듦
		j = 0;
		for (i = col + len1; arr[i] != '\0'; i++) {//문장에서 내가 찾은 단어의 뒤부터 끝까지 저장
			temp2[j] = arr[i];
			j++;
		}
		temp2[i] = '\0';//널문자를 붙여서 문자열로 만듦
		int templen1 = strlen_(temp1);//단어를 제외한 앞문장 길이
		int templen2 = strlen_(temp2);//단어를 제외한 뒷문장 길이
		int k = 0;
		for (int i = 0; i < templen1; i++) {//앞문장을 새로운 배열에 저장
			newarr[i] = temp1[k];
			k++;
		}
		k = 0;
		for (int i = templen1; i < templen1 + len2; i++) {//바뀔 단어 저장
			newarr[i] = word2[k];
			k++;
		}
		k = 0;
		for (int i = templen1 + len2; i < templen1 + len2 + templen2; i++) {//뒷문장 저장
			newarr[i] = temp2[k];
			k++;
		}
		newarr[templen1 + templen2 + len2] = '\0';//앞문장 길이+ 뒷문장 길이+ 바뀔 단어의 길이= newarr의 마지막 인덱스
		arr[arrlen] = ' ';//arr의 맨 뒤 널문자를 공백으로 대체
		for (int i = 0; i < templen1 + templen2 + len2; i++) {
			arr[i] = newarr[i];//다시 원래의 배열에 복사
		}
		arr[templen1 + templen2 + len2] = '\0';//마지막에 널문자를 붙여서 새로운 문장을 문자열로 완성
	}
}
void Insert(int col, char* word, char* arr) {//입력한 행, 열에 단어를 삽입하는 함수
	int len = strlen_(word);//삽입할 단어의 길이
	int lenarr = strlen_(arr);//문장의 길이
	int j = 0;
	int i;
	char temp1[50] = { NULL };//앞 문장을 저장할 배열
	char temp2[50] = { NULL };//뒷 문장을 저장할 배열
	char newarr[100] = { NULL };
	for (i = 0; i < col; i++){//내가 넣을 열 전까지의 문장을 저장
		temp1[j] = arr[i];
		j++;
	}
	temp1[i] = '\0';//마지막에 널문자를 입력하여 문자열로 만듦
	j = 0;
	for (i = col; arr[i] != NULL; i++) {//내가 넣을 열 다음부터 끝까지 저장
		temp2[j] = arr[i];
		j++;
	}
	temp2[i] = '\0';//마지막에 널문자를 입력하여 문자열로 만듦
	int len1 = strlen_(temp1);//temp1의 길이
	int len2 = strlen_(temp2);//temp2의 길이
	for (int i = 0; i < len1; i++)//새로운 배열에 앞문장 저장
		newarr[i] = temp1[i];
	int k = 0;
	for (int i = len1; i < len1 + len; i++) {//새로운 배열의 내가 저장할 행에 단어 저장
		newarr[i] = word[k];
		k++;
	}
	k = 0;
	for (int i = len1 + len; i < len1 + len + len2; i++) {//단어의 바로 뒤부터 뒷문장 저장
		newarr[i] = temp2[k];
		k++;
	}
	newarr[len1 + len2 + len] = '\0';//마지막에 널문자를 삽입하여 문자열로 만듦
	arr[lenarr] = ' ';//arr의 마지막 널문자를 공백으로 대체
	for (int i = 0; i < len1 + len2 + len; i++) {
		arr[i] = newarr[i];//원래의 문장에 새로 만든 문장을 복사
	}
	arr[len1 + len2 + len] = '\0';//마지막에 널문자를 삽입하여 새로운 문장을 문자열로 저장
}
void Delete(int flag, int col, char* word, char* arr) {//입력한 단어를 삭제하는 함수
	int len = strlen_(word);//삭제할 단어의 길이
	if (flag == 0) {//flag가 0이라면 바꿀 단어가 해당 행에 없으므로 종료
		return;
	}
	else if (flag == 1) {////flag가 1이라면 바꿀 단어가 해당 행있으므로 실행
		char temp[300] = { NULL };//바꿀 단어의 바로 뒷문장을 저장할 배열
		int j = 0;
		int i;
		for (i = col + len; arr[i] != '\0'; i++) {
			temp[j] = arr[i];//temp에 내가 없앨 단어 이후의 문장을 저장
			j++;
		}
		for (int i = col; i < col + len; i++) {
			arr[i] = ' ';
		}//내가 삭제할 단어를 공백으로 바꿈
		temp[i] = '\0';//마지막에 널문자 삽입하여 문자열로 반듦
		int templen = strlen_(temp);//temp의 길이 저장
		int k = 0;
		for (int i = col; i < col + templen; i++) {
			arr[i] = temp[k];//없앨 단어의 시작 인덱스부터 temp로 복사하여 단어를 없앤 새로운 문장을 만듦
			k++;
		}
		arr[col + templen] = '\0';//없앨 단어의 시작 열 + 나머지 문장의 길이= 단어를 없앤 문장의 끝
		//새로 저장한 문장의 끝 인덱스에 널문자 삽입
	}
}
