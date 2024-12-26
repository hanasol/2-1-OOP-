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
	Student(char* name, char* id, double aScore, double eScore, double att) {//������
		this->name = new char[100];//�л� �̸� �޸� �Ҵ�
		strcpy_(this->name, name);//�̸� ����
		studentID = new char[100];//id �޸� �Ҵ�
		strcpy_(studentID,id);//id ����
		assignmentScore = aScore;//���� ���� ����
		examScore = eScore;//���� ���� ����
		attendance = att;//�⼮ ���� ����
		finalScore = (0.1 * att) + (0.4 * aScore) + (0.5 * eScore);//���� ���� ����
	}
	~Student() {//�Ҹ���
		delete[] this->name;//�����ڿ��� �Ҵ��� �޸� ����
		delete[] studentID;//�����ڿ��� �Ҵ��� �޸� ����
	}
	bool isNameCorrect(char* name) {//Ŭ������ ��� �� �̸��� ������ �Ǵ����ִ� �Լ�
		for (int i = 0; i < strlen_(this->name); i++) {
			if ('A' <= this->name[i] && this->name[i] <= 'Z')
				this->name[i] += 32;//Ŭ������ ��� ������ name�� �ҹ��ڷ� ��ȯ
		}
		for (int i = 0; i < strlen_(name); i++) {
			if ('A' <= name[i] && name[i] <= 'Z')
				name[i] += 32;//�Է¹޴� �̸��� name�� �ҹ��ڷ� ��ȯ
		}
		if (0==strcmp_(this->name, name))
			return false;//ã�� �̸��� �ִٸ� false
		return true;//���ٸ� true
	}
	void changeScores(double aScore, double eScore, double att) {//������ �ٲپ��ִ� �Լ�
		assignmentScore = aScore;
		examScore = eScore;
		attendance = att;
		finalScore = (0.1 * att) + (0.4 * aScore) + (0.5 * eScore);//���ο� ������� ���� ���� ����
	}
	void print() {//������ ������ִ� �Լ�
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
	int num = 0;//��ü�� ������ �л��� ��
	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "insert")) {//insertĿ�ǵ�
			cin >> name >> id >> ascore >> escore >> att;
			if (num == 0) {//�ƹ� �л��� ���� ��
				stu[num] = new Student(name, id, ascore, escore, att);//�л� ��ü ����
				num++;//�л� �� ����
			}
			else {//�л��� 1�� �̻� ���� ��
				for (int i = 0; i < num; i++) {
					if (stu[i]->isNameCorrect(name)) {//ã�� �̸��� ���� ��
						stu[num] = new Student(name, id, ascore, escore, att);
						num++;
						break;
					}
					else {//ã�� �̸��� ���� ��
						cout << "�̹� �ش� �ο��� �����մϴ�\n";
						break;
					}
				}
			}
		}
		else if (0 == strcmp_(menu, "find")) {
			int flag = 0;//�̸��� ã�Ҵ��� Ȯ�����ִ� ����
			cin >> name;
			cout << "=====find=====\n";
			for (int i = 0; i < num; i++) {
				if (!stu[i]->isNameCorrect(name)) {//�´� �̸��� ã���� ���� ���
					stu[i]->print();
					flag = 1;//�л��� ã���� flag�� 1�� ����
					break;//�ݺ� ��
				}
			}
			if (flag == 0)//flag�� 0�̶�� �̸��� �´� �л��� ����
				cout << "not found\n";
		}
		else if (0 == strcmp_(menu, "change")) {
			cin >> name >> ascore >> escore >> att;
			for (int i = 0; i < num; i++) {
				if (!stu[i]->isNameCorrect(name)) {//�´� �̸��� ������ �ٲ�
					stu[i]->changeScores(ascore, escore, att);
					break;//�ݺ� ��
				}
			}
		}
		else if (0 == strcmp_(menu, "print")) {
			cout << "=====print=====\n";
			for (int i = 0; i < num; i++) {
				stu[i]->print();//����� ��� ��ü�� ���� ���
			}
		}
		else if (0 == strcmp_(menu, "exit")) {
			for (int i = 0; i < num; i++)
				delete stu[i];//������ ��ü�� �޸� ����
			delete[] name;
			delete[] id;
			cout << "Exit the program";
			return 0;
		}
	}
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
int strlen_(const char* str) {//NULL�� ������ ���ڿ��� ���� ��ȯ
	int len = 0;
	int i = 0;
	while (str[i] != NULL) {//str�� NULL�� �ƴ϶�� �ݺ�
		len++;//�ݺ����� ���̰� 1�� ����
		i++;
	}
	return len;//���ڿ��� ���� ��ȯ
}