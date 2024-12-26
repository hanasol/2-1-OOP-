#include <iostream>
using namespace std;
int strcmp_(const char* str1, const char* str2);
void strcpy_(char* dest, const char* src);
int strlen_(const char* str);
class Student{
private:
	char* name;
	char* studentID;
	double assignmentScore;
	double examScore;
	double attendance;
	double finalScore;
public:
	Student(char* name, char* id, double aScore, double eScore, double att) {//생성자
		this->name = new char[100];//학생 이름 메모리 할당
		strcpy_(this->name, name);//이름 저장
		studentID = new char[100];//id 메모리 할당
		strcpy_(studentID,id);//id 저장
		assignmentScore = aScore;//과제 점수 저장
		examScore = eScore;//시험 점수 저장
		attendance = att;//출석 점수 저장
		finalScore = (0.1 * att) + (0.4 * aScore) + (0.5 * eScore);//최종 점수 저장
	}
	~Student() {//소멸자
		delete[] this->name;//생성자에서 할당한 메모리 해제
		delete[] studentID;//생성자에서 할당한 메모리 해제
	}
	bool isNameCorrect(char* name) {//클래스의 멤버 중 이름과 같은지 판단해주는 함수
		for (int i = 0; i < strlen_(this->name); i++) {
			if ('A' <= this->name[i] && this->name[i] <= 'Z')
				this->name[i] += 32;//클래스의 멤버 변수인 name을 소문자로 변환
		}
		for (int i = 0; i < strlen_(name); i++) {
			if ('A' <= name[i] && name[i] <= 'Z')
				name[i] += 32;//입력받는 이름인 name을 소문자로 변환
		}
		if (0==strcmp_(this->name, name))
			return false;//찾는 이름이 있다면 false
		return true;//없다면 true
	}
	void changeScores(double aScore, double eScore, double att) {//점수를 바꾸어주는 함수
		assignmentScore = aScore;
		examScore = eScore;
		attendance = att;
		finalScore = (0.1 * att) + (0.4 * aScore) + (0.5 * eScore);//새로운 점수들로 최종 점수 저장
	}
	void print() {//정보를 출력해주는 함수
		cout << "Name : " << this->name<<"\n";
		cout << "Student ID : " << studentID << "\n";
		cout << "Final Score : " << finalScore << "\n";
		cout << "---------------------\n";
	}
};
int main() {
	Student* stu[10];
	char* menu = new char[10];
	char* name = new char[100];
	char* id = new char[100];
	double ascore, escore, att, fscore;
	int num = 0;//객체가 생성된 학생의 수
	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "insert")) {//insert커맨드
			cin >> name >> id >> ascore >> escore >> att;
			if (num == 0) {//아무 학생도 없을 때
				stu[num] = new Student(name, id, ascore, escore, att);//학생 객체 생성
				num++;//학생 수 증가
			}
			else {//학생이 1명 이상 있을 때
				for (int i = 0; i < num; i++) {
					if (stu[i]->isNameCorrect(name)) {//찾는 이름이 없을 때
						stu[num] = new Student(name, id, ascore, escore, att);
						num++;
						break;
					}
					else {//찾는 이름이 있을 때
						cout << "이미 해당 인원이 존재합니다\n";
						break;
					}
				}
			}
		}
		else if (0 == strcmp_(menu, "find")) {
			int flag = 0;//이름을 찾았는지 확인해주는 변수
			cin >> name;
			cout << "=====find=====\n";
			for (int i = 0; i < num; i++) {
				if (!stu[i]->isNameCorrect(name)) {//맞는 이름을 찾으면 정보 출력
					stu[i]->print();
					flag = 1;//학생을 찾으면 flag를 1로 저장
					break;//반복 끝
				}
			}
			if (flag == 0)//flag가 0이라면 이름이 맞는 학생이 없음
				cout << "not found\n";
		}
		else if (0 == strcmp_(menu, "change")) {
			cin >> name >> ascore >> escore >> att;
			for (int i = 0; i < num; i++) {
				if (!stu[i]->isNameCorrect(name)) {//맞는 이름의 점수를 바꿈
					stu[i]->changeScores(ascore, escore, att);
					break;//반복 끝
				}
			}
		}
		else if (0 == strcmp_(menu, "print")) {
			cout << "=====print=====\n";
			for (int i = 0; i < num; i++) {
				stu[i]->print();//저장된 모든 객체의 정보 출력
			}
		}
		else if (0 == strcmp_(menu, "exit")) {
			for (int i = 0; i < num; i++)
				delete stu[i];//생성된 객체의 메모리 해제
			delete[] name;
			delete[] id;
			cout << "Exit the program";
			return 0;
		}
	}
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