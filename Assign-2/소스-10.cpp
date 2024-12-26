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
	char* name;//�л��� �̸�
	char* id;//�л��� id
	int score;//����
public:
	School() :score(0) {//�̴ϼȶ������� �̿��Ͽ� ���� �ʱ�ȭ
		name = nullptr;//�̸� �ʱ�ȭ
		id = nullptr;//id �ʱ�ȭ
	}
	School(const School& other) : score(other.score) {//���������
		name = new char[strlen_(other.name) + 1];
		id = new char[strlen_(other.id) + 1];
		strcpy_(name, other.name);
		strcpy_(id, other.id);
	}//�����Ҵ��� ���ؼ� ���� ���簡 ����ǵ��� ��

	~School() {//�Ҹ��ڿ��� �޸� ����
		delete[] name;
		delete[] id;
	}
	int Getscore() {//������ ��ȯ�ϴ� �Լ�
		return score;
	}
	void load(char* name_, char* id_, int score_) {
		delete[] name;
		delete[] id;//���� �ִ� �޸� ����
		name = new char[strlen_(name_) + 1];
		id = new char[strlen_(id_) + 1];//���Ӱ� �޸� �Ҵ�
		strcpy_(name, name_);
		strcpy_(id, id_);//�� ����
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
	ifstream fin;//���Ϸκ��� �о���� ���ؼ� ifstrema��ü ����
	School* stu[size];//��ü ������ �迭 ���
	char menu[30];
	int cnt = 0;//�л��� ��
	char* name = new char[101];
	char* id = new char[101];
	int score;
	char temp[300];
	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "load_student")) {
			fin.open("student.txt");//�ش� �̸��� ���� ����
			while (fin.getline(temp, 300)) {//�� ���徿 �޾Ƽ� temp�� ����
				separate(temp, name, id, score);//�̸�, id, ������ ���ڿ��� �Ľ�
				stu[cnt] = new School();//�� ��ü�� �޸� �Ҵ�
				stu[cnt]->load(name, id, score);
				cnt++;
			}
		}
		else if (0 == strcmp_(menu, "print_all")) {
			cout << "=====Print=====\n";
			for (int i = 0; i < cnt; i++)
				stu[i]->print();
		}
		else if (0 == strcmp_(menu, "sort_by_score")) {//�����Ʈ�� ����Ͽ� ������������ ����
			for (int i = 0; i < cnt - 1; i++) {
				for (int j = 0; j < cnt - i - 1; j++) {
					if (stu[j]->Getscore() < stu[j + 1]->Getscore()) {//���� ��ü�� ������ �� �۴ٸ� ��ȯ
						School* temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;//��ü�� ����
					}
				}
			}
		}
		else if (0 == strcmp_(menu, "Exit")) {
			delete[] name;
			delete[] id;
			for (int i = 0; i < cnt; i++)
				delete stu[i];//stu�� School��ü�� ������ �迭�̹Ƿ� stu[i]�� �ϳ��� ��ü��. 
			//���� delete[]�� �ƴ� delete���
			fin.close();//������ ����
			cout << "Exit the program";
			return 0;
		}
		else {
			cout << "Invalid input\n";
		}
	}
}
void separate(char* temp, char*& name, char*& id, int& score) {//������ ���ڿ����� �̸�, id, ������ �����ϴ� �Լ�
	int j = 0;
	int ind = 0;
	char arr[3][101] = { 0, };//�ܾ�, id, ������ ����� char�� 2���� �迭
	for (int i = 0; i < strlen_(temp); i++) {//0���� ������ ������ �ݺ�
		if (temp[i] == ',') {//,�� ���еǾ� �����Ƿ� ,�� ������
			arr[j][ind] = '\0';//�ι��ڸ� �����Ͽ� �� ���ڿ� ����
			j++;//j����
			ind = 0;//���� �࿡�� 0 �ε������� �����ϱ� ���ؼ� 0���� �ʱ�ȭ
			continue;//���� �ݺ� ����
		}
		else if (temp[i] == ' ') {
			continue;//���� ����
		}
		arr[j][ind] = temp[i];//�� ���ھ� arr�� �� �࿡ ����
		ind++;//���� �ε����� �̵�
	}
	arr[j][ind] = '\0';//������ ���ڿ��� �ϼ�
	strcpy_(name, arr[0]);//�̸��� ����, name�� �������̹Ƿ� ���ڷ� ���޵� name�� �ٲ�
	strcpy_(id, arr[1]);//id�� ����, id�� ��������
	score = 0;
	for (int i = 0; i < strlen_(arr[2]); i++)//arr[2]���� ������ ���ڿ��� ����Ǿ� ����
		score = score * 10 + (arr[2][i] - '0');//������ 10�̻��� ���� �� �����Ƿ� ���ڸ� int�� ��ȯ�Ͽ� ������ ���ڷ� ������� 
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