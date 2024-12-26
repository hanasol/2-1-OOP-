#include <iostream>
using namespace std;
int floor_(double num);
int strcmp_(const char* str1, const char* str2);
void strcpy_(char* dest, const char* src);
class Student {
private:
	char* name;//�л��� �̸�
	char* studentID;//�л��� id
	double Score;//����
public:
	Student() {//�⺻ �����ڿ��� �� ����� �ʱ�ȭ
		name = nullptr;
		studentID = nullptr;
		Score = 0;
	}
	Student(char* _name, char* id, double score) {//�Ҵ���� ���ڷ� ����� �ʱ�ȭ
		name = new char[strlen(_name) + 1];
		strcpy_(name, _name);
		studentID = new char[strlen(id) + 1];
		strcpy_(studentID, id);
		Score = score;
	}
	~Student() { }//�ӽ� ��ü�� �����ϰ� �������� �������� �޸𸮸� �����ϸ� �̸��� id�� �޸𸮰� ������
	char* return_name() {
		return name;//�̸��� ��ȯ
	}
	char* return_ID() {
		return studentID;//id�� ��ȯ
	}
	double return_score() {
		return Score;//������ ��ȯ
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
		student_list = new Student[stu_num];//�޸� �Ҵ�
		size = 0;
	}
	~School() {
		for (int i = 0; i < size; i++) {
			delete[] student_list[i].return_name();//student�� ����� �Ҵ��� �޸� ����
			delete[] student_list[i].return_ID();//studednt�� ����� �Ҵ��� �޸� ����
		}
		delete[] student_list;//School�� ����� �Ҵ��� �޸�
	}
	void addStudent(char* name, char* id, double score) {
		student_list[size] = Student(name, id, score);//��ü ����
		size++;
	}
	void sortStudents() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (student_list[j].return_score() < student_list[j + 1].return_score()) {//������ ���� �������� ����
					Student temp = student_list[j];
					student_list[j] = student_list[j + 1];
					student_list[j + 1] = temp;//��ü�� ���� ����
				}
			}
		}
	}
	void printStudents() {
		for (int i = 0; i < size; i++) {
			student_list[i].print_all();//�� ��ü�� ���� ���
		}
	}
	void print_A_grade() {
		sortStudents();
		int cnt = floor_(size * 0.3);//�������� cnt�� �� ����
		for (int i = 0; i < cnt; i++)
			student_list[i].print_all();//���� 30%�� �ش��ϴ� �л��� ���� ����
	}
	void print_B_grade() {
		sortStudents();
		int start = floor_(size * 0.3);
		int end = floor_(size * 0.5);
		for (int i = start; i < end; i++)//���� 30%~50%�� �ش��ϴ� �л��� ���� ����
			student_list[i].print_all();
	}
};
int main() {
	char* name = new char[101];
	char* id = new char[101];
	double score;
	char* menu = new char[100];
	int num = 0;//�л��� ��
	School stu(20);//School��ü ����

	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "new_student")) {
			cin >> name >> id >> score;
			stu.addStudent(name, id, score);////������ �Է¹޾Ƽ� �߰�
			num++;//�л��� �� ����
		}
		else if (0 == strcmp_(menu, "sort_by_score")) {
			stu.sortStudents();//������ �������� �������� ����
		}
		else if (0 == strcmp_(menu, "print_all")) {
			cout << "=====print====\n";
			stu.printStudents();//��� ��ü�� ���� ���
		}
		else if (0 == strcmp_(menu, "print_A_grade")) {
			cout << "=====A grade=====\n";
			stu.print_A_grade();//A��� ���
		}
		else if (0 == strcmp_(menu, "print_B_grade")) {
			cout << "=====B grade=====\n";
			stu.print_B_grade();//B��� ���
		}
		else if (0 == strcmp_(menu, "exit")) {
			delete[] name;
			delete[] id;
			delete[] menu;
			cout << "Exit the program";//main���� �Ҵ��� �޸� ���� �� ���α׷� ����
			return 0;
		}
		else {
			cout << "Invalid input\n";
		}
	}
}
int floor_(double num) {//double�� ������ �ø��ϴ� �Լ�
	return (int)num;//int������ ����ȯ�Ͽ� ��ȯ
}
int strcmp_(const char* str1, const char* str2) {//���ڿ��� ������ �����ִ� �Լ�
	int i = 0;
	while (str1[i] != NULL && (str1[i] == str2[i])) {//�� ���ڿ��� ���ڰ� ���� str1�� NULL�� �ƴ϶�� �ݺ�
		i++;
	}
	if (str1[i] - str2[i] == 0)//�� �ƽ�Ű ���� ���̰� 0�̶�� �� ���ڿ��� ����
		return 0;
	else if (str1[i] > str2[i])
		return 1;//str1�� str2���� ���������� �ڸ� 1��ȯ
	else
		return -1;//str1�� str2���� ���������� ���̸� -1��ȯ
}
void strcpy_(char* str1, const char* str2) {//str2�� ���ڿ��� str1�� �����ϴ� �Լ�
	int i = 0;
	while (str2[i] != NULL) {//str2�� NULL�� �ƴ϶�� �ݺ�
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0'; // ���ڿ��� ���� �� ���ڸ� �߰�
}
