#include <iostream>
using namespace std;
int floor_(double num);
int strcmp_(const char* str1, const char* str2);
void strcpy_(char* dest, const char* src);
class Student {
private:
	char* name;//학생의 이름
	char* studentID;//학생의 id
	double Score;//점수
public:
	Student() {//기본 생성자에서 각 멤버를 초기화
		name = nullptr;
		studentID = nullptr;
		Score = 0;
	}
	Student(char* _name, char* id, double score) {//할당받은 인자로 멤버를 초기화
		name = new char[strlen(_name) + 1];
		strcpy_(name, _name);
		studentID = new char[strlen(id) + 1];
		strcpy_(studentID, id);
		Score = score;
	}
	~Student() { }//임시 객체를 생성하고 없어지는 과정에서 메모리르 해제하면 이름과 id의 메모리가 누수됨
	char* return_name() {
		return name;//이름을 반환
	}
	char* return_ID() {
		return studentID;//id를 반환
	}
	double return_score() {
		return Score;//점수를 반환
	}
	void print_all() {
		cout << "Name : " << name << "\n";
		cout << "Student ID : " << studentID << "\n";
		cout << "Score : " << Score << "\n";
		cout << "------------------------\n";
	}
};
class School {
private:
	Student* student_list;
	int size;
public:
	School(int stu_num) {
		student_list = new Student[stu_num];//메모리 할당
		size = 0;
	}
	~School() {
		for (int i = 0; i < size; i++) {
			delete[] student_list[i].return_name();//student의 멤버에 할당한 메모리 해제
			delete[] student_list[i].return_ID();//studednt의 멤버에 할당한 메모리 해제
		}
		delete[] student_list;//School의 멤버에 할당한 메모리
	}
	void addStudent(char* name, char* id, double score) {
		student_list[size] = Student(name, id, score);//객체 생성
		size++;
	}
	void sortStudents() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (student_list[j].return_score() < student_list[j + 1].return_score()) {//점수에 따라서 내림차순 정렬
					Student temp = student_list[j];
					student_list[j] = student_list[j + 1];
					student_list[j + 1] = temp;//객체를 서로 스왑
				}
			}
		}
	}
	void printStudents() {
		for (int i = 0; i < size; i++) {
			student_list[i].print_all();//각 객체의 정보 출력
		}
	}
	void print_A_grade() {
		sortStudents();
		int cnt = floor_(size * 0.3);//내림으로 cnt에 값 저장
		for (int i = 0; i < cnt; i++)
			student_list[i].print_all();//상위 30%에 해당하는 학생의 정보 저장
	}
	void print_B_grade() {
		sortStudents();
		int start = floor_(size * 0.3);
		int end = floor_(size * 0.5);
		for (int i = start; i < end; i++)//상위 30%~50%에 해당하는 학생의 정보 저장
			student_list[i].print_all();
	}
};
int main() {
	char* name = new char[101];
	char* id = new char[101];
	double score;
	char* menu = new char[100];
	int num = 0;//학생의 수
	School stu(20);//School객체 생성

	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "new_student")) {
			cin >> name >> id >> score;
			stu.addStudent(name, id, score);////정보를 입력받아서 추가
			num++;//학생의 수 증가
		}
		else if (0 == strcmp_(menu, "sort_by_score")) {
			stu.sortStudents();//점수를 기준으로 내림차순 정렬
		}
		else if (0 == strcmp_(menu, "print_all")) {
			cout << "=====print====\n";
			stu.printStudents();//모든 객체의 정보 출력
		}
		else if (0 == strcmp_(menu, "print_A_grade")) {
			cout << "=====A grade=====\n";
			stu.print_A_grade();//A등급 출력
		}
		else if (0 == strcmp_(menu, "print_B_grade")) {
			cout << "=====B grade=====\n";
			stu.print_B_grade();//B등급 출력
		}
		else if (0 == strcmp_(menu, "exit")) {
			delete[] name;
			delete[] id;
			delete[] menu;
			cout << "Exit the program";//main에서 할당한 메모리 해제 후 프로그램 종료
			return 0;
		}
		else {
			cout << "Invalid input\n";
		}
	}
}
int floor_(double num) {//double형 변수를 올림하는 함수
	return (int)num;//int형으로 형변환하여 반환
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
