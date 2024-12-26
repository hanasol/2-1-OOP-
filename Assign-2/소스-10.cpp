#include <iostream>
#include <fstream>
using namespace std;
void separate(char* temp, char*& name, char*& id, int& score);
void strcpy_(char* str1, const char* str2);
int strcmp_(const char* str1, const char* str2);
int strlen_(const char* str);
#define size 30
class School {
private:
	char* name;//학생의 이름
	char* id;//학생의 id
	int score;//점수
public:
	School() :score(0) {//이니셜라이저를 이용하여 점수 초기화
		name = nullptr;//이름 초기화
		id = nullptr;//id 초기화
	}
	School(const School& other) : score(other.score) {//복사생성자
		name = new char[strlen_(other.name) + 1];
		id = new char[strlen_(other.id) + 1];
		strcpy_(name, other.name);
		strcpy_(id, other.id);
	}//동적할당을 통해서 깊은 복사가 진행되도록 함

	~School() {//소멸자에서 메모리 해제
		delete[] name;
		delete[] id;
	}
	int Getscore() {//점수를 반환하는 함수
		return score;
	}
	void load(char* name_, char* id_, int score_) {
		delete[] name;
		delete[] id;//원래 있던 메모리 해제
		name = new char[strlen_(name_) + 1];
		id = new char[strlen_(id_) + 1];//새롭게 메모리 할당
		strcpy_(name, name_);
		strcpy_(id, id_);//값 복사
		score = score_;
	}
	void print() {
		cout << "Name : " << name << "\n";
		cout << "Student ID : " << id << "\n";
		cout << "Score : " << score << "\n";
		cout << "-------------------\n";
	}
};
int main() {
	ifstream fin;//파일로부터 읽어오기 위해서 ifstrema객체 생성
	School* stu[size];//객체 포인터 배열 사용
	char menu[30];
	int cnt = 0;//학생의 수
	char* name = new char[101];
	char* id = new char[101];
	int score;
	char temp[300];
	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "load_student")) {
			fin.open("student.txt");//해당 이름의 파일 오픈
			while (fin.getline(temp, 300)) {//한 문장씩 받아서 temp에 저장
				separate(temp, name, id, score);//이름, id, 점수로 문자열을 파싱
				stu[cnt] = new School();//각 객체에 메모리 할당
				stu[cnt]->load(name, id, score);
				cnt++;
			}
		}
		else if (0 == strcmp_(menu, "print_all")) {
			cout << "=====Print=====\n";
			for (int i = 0; i < cnt; i++)
				stu[i]->print();
		}
		else if (0 == strcmp_(menu, "sort_by_score")) {//버블소트를 사용하여 내림차순으로 정렬
			for (int i = 0; i < cnt - 1; i++) {
				for (int j = 0; j < cnt - i - 1; j++) {
					if (stu[j]->Getscore() < stu[j + 1]->Getscore()) {//이전 객체의 점수가 더 작다면 교환
						School* temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;//객체를 스왑
					}
				}
			}
		}
		else if (0 == strcmp_(menu, "Exit")) {
			delete[] name;
			delete[] id;
			for (int i = 0; i < cnt; i++)
				delete stu[i];//stu는 School객체의 포인터 배열이므로 stu[i]는 하나의 객체임. 
			//따라서 delete[]가 아닌 delete사용
			fin.close();//파일을 닫음
			cout << "Exit the program";
			return 0;
		}
		else {
			cout << "Invalid input\n";
		}
	}
}
void separate(char* temp, char*& name, char*& id, int& score) {//가져온 문자열에서 이름, id, 점수를 구분하는 함수
	int j = 0;
	int ind = 0;
	char arr[3][101] = { 0, };//단어, id, 점수가 저장될 char형 2차원 배열
	for (int i = 0; i < strlen_(temp); i++) {//0부터 문장의 끝까지 반복
		if (temp[i] == ',') {//,로 구분되어 있으므로 ,를 만나면
			arr[j][ind] = '\0';//널문자를 저장하여 한 문자열 생성
			j++;//j증가
			ind = 0;//다음 행에서 0 인덱스부터 저장하기 위해서 0으로 초기화
			continue;//다음 반복 실행
		}
		else if (temp[i] == ' ') {
			continue;//공백 무시
		}
		arr[j][ind] = temp[i];//한 문자씩 arr의 한 행에 저장
		ind++;//다음 인덱스로 이동
	}
	arr[j][ind] = '\0';//마지막 문자열을 완성
	strcpy_(name, arr[0]);//이름에 복사, name은 참조자이므로 인자로 전달된 name도 바뀜
	strcpy_(id, arr[1]);//id에 복사, id도 마찬가지
	score = 0;
	for (int i = 0; i < strlen_(arr[2]); i++)//arr[2]에는 점수가 문자열로 저장되어 있음
		score = score * 10 + (arr[2][i] - '0');//점수가 10이상의 값일 수 있으므로 문자를 int로 변환하여 원래의 숫자로 만들어줌 
}
void strcpy_(char* str1, const char* str2) {//str2의 문자열을 str1에 복사하는 함수
	int i = 0;
	while (str2[i] != NULL) {//str2가 NULL이 아니라면 반복
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