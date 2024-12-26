#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool pass_condition(char* pass);
struct Member {
	char id[20];
	char password[20];
};
class membership {
private:
	Member* inform;
	int cnt_num;//������ ����� ��
public:
	membership(){ }
	membership(int num) :cnt_num(0){
		inform = new Member[num];//num��ŭ �޸� �Ҵ�
	}
	~membership() {
		delete[] inform;//�޸� ����
	}
	void set_Inform(char* id, char* password) {//���Ϸκ��� �Է¹��� id, password�� ��ü�� ����
		strcpy(inform[cnt_num].id, id);
		strcpy(inform[cnt_num].password, password);
		cnt_num++;//������ ��� �� ����
	}
	void set_encInform(char* id, char* password) {//�Է¹��� id, password, ��й�ȣ�� ���ĺ��� id�� ���̸�ŭ ���������� �з��� ��ȣȭ�Ǿ ����
		strcpy(inform[cnt_num].id, id);//�Է¹��� id�� ����
		int len = strlen(id);
		for (int i = 0; i < strlen(password); i++) {
			if ('a' <= password[i] && password[i] <= 'z') {//���ĺ� �ҹ��ڶ��
				password[i] += len - 26;//id�� ���̿��� ���ĺ��� ������ 26�� ��
				if (password[i] < 'a')//�ƽ�Ű �ڵ�� a���� �۴ٸ�
					password[i] += 26;//26�� ������
			}
			else if ('A' <= password[i] && password[i] <= 'Z') {//�빮�ڶ��
				password[i] += len - 26;///id�� ���̿��� ���ĺ��� ������ 26�� ��
				if (password[i] < 'A')//�ƽ�Ű �ڵ�� A���� �۴ٸ�
					password[i] += 26;//26�� ������
			}
		}
		strcpy(inform[cnt_num].password, password);//��ȣȭ�� password ����
		cnt_num++;//������ ��� �� ����
	}
	bool Check_id(char* id) {//���̵� ������ Ȯ��
		for (int i = 0; i < cnt_num; i++) {
			if (0 == strcmp(inform[i].id, id))
				return true;//���� id�� ������ true
		}
		return false;//������ flase
	}
	bool Check_pass(char* id, char* password) {//��й�ȣ�� ������ Ȯ��
		int len = strlen(id);
		for (int i = 0; i < strlen(password); i++) {
			if ('a' <= password[i] && password[i] <= 'z') {//���ĺ� �ҹ��ڶ��
				password[i] += len - 26;
				if (password[i] < 'a')
					password[i] += 26;
			}
			else if ('A' <= password[i] && password[i] <= 'Z') {//�빮�ڶ��
				password[i] += len - 26;
				if (password[i] < 'A')
					password[i] += 26;
			}
		}//��й�ȣ ��ȣȭ
		for (int i = 0; i < cnt_num; i++) {
			if (0 == strcmp(inform[i].password,password))
				return true;//���� ��й�ȣ���� ������ true
		}
		return false;//��й�ȣ�� �ٸ��� flase
	}
	void Withdraw(char* id) {//Ż��
		for (int i = 0; i < cnt_num; i++) {//��� ��ü�� ���鼭 �´� id�� Ž��
			if (0 != strcmp(inform[i].id, id)) {//id�� �ٸ��ٸ�
				continue;//�ݺ��� �ǳʶ�
			}
			else {//id�� ���ٸ� id�� password�� �� ���ڿ��� �ٲپ Ż��
				strcpy(inform[i].id, "");
				strcpy(inform[i].password, "");
			}
		}
	}
	void saveInfo() {//������ ���Ͽ� �����ϴ� �Լ�
		ofstream fout;//ofstream��ü ����
		fout.open("membership.txt");//�Է��� �޾ƿ��� ���ϰ� ���� ������ ��
		for (int i = 0; i < cnt_num; i++) {//���Ե� ����� ����ŭ �ݺ��ϸ� id password�� ���·� ���Ͽ� ����
			fout << inform[i].id << " " << inform[i].password << endl;
		}
		fout.close();//���� �ݱ�
	}
};
void Login_state(membership& mem, char* id_log, char* pass_log);//�α��� ���¸� ��Ÿ���� �Լ�
int main() {
	ifstream fin;//���Ϸκ��� ���Ե� ����� ������ �о���� ���ؼ� ifstream��ü ����
	membership mem(100);//�ִ� 100���� ���� ���尡��
	int menu;
	char id_log[30];
	char pass_log[30];
	string temp;
	fin.open("membership.txt");//member.txt������ ��
	while (!fin.eof()) {
		char id[30];
		char pass[30];
		fin >> id >> pass;
		if (0 == strcmp(id, "") || 0 == strcmp(pass, ""))//id�� ��й�ȣ�� �����̸� Ż��ó��
			continue;//���� �ݺ�
		mem.set_Inform(id, pass);//���Ե� ����� ������ ��ü�� ����
	}
	while (1) {
		cout << "=======================================\n";
		cout << "Menu.\n";
		cout << "1. Login\n";
		cout << "2. Register\n";
		cout << "3. Withdraw\n";
		cout << "4. Exit\n  :  ";
		cin >> menu;
		cout << "--------------------------------------\n";
		if (menu == 1) {//Login, ID�� ��й�ȣ�� �¾ƾ� �α��� ����
			cout << "User id: ";
			cin >> id_log;
			cout << "password: ";
			cin >> pass_log;
			cout << "--------------------------------------\n";
			if (mem.Check_id(id_log)) {//���̵� ���ٸ� 
				if (mem.Check_pass(id_log, pass_log)) {//��й�ȣ���� ���ٸ�
					cout << "Login successful.\n";//�α��� ����
					Login_state(mem, id_log, pass_log);//�α��� ���·� �Ѿ
					mem.saveInfo();//���Ե� ����� ������ ���Ͽ� ����
					return 0;
				}
				else {//��й�ȣ�� �ٸ��ٸ�
					cout << "Login failed. Invalid User id or password\n";
				}
			}
			else {//���̵� �ٸ��ٸ�
				cout << "Login failed. Invalid User id or password\n";
			}
		}
		else if (menu == 2) {//Register, ������ �ߺ��Ǵ� ID�� �������, ��й�ȣ�� �ҹ���, ����, Ư������ 1���̻�, 10���� �̻�, 20���� ������ ������ �����ؾ���
			char id[30];
			char pass[30];
			cout << "User id: ";
			cin >> id;
			cout << "password: ";
			cin >> pass;
			cout << "--------------------------------------\n";
			if (!mem.Check_id(id)) {//���̵� �ߺ� X
				if (!pass_condition(pass)) {//��ȣ ���� ����
					cout << "Registration successful.\n";
					mem.set_encInform(id, pass);//���Կ� ���������Ƿ� ��й�ȣ�� ��ȣȭ�Ͽ� ��ü�� ����
				}
				else {//��ȣ ���� ������
					cout << "Unsatisfied with password conditions\n";
				}
			}
			else {//id �ߺ�
				cout << "overlapping ID\n";
			}
		}
		else if (menu == 3) {//Withdraw, Login���°� �ƴϹǷ� Ż�� �Ұ�
			cout << "Invalid.\n";
			cout << "--------------------------------------\n";
		}
		else if (menu == 4) {
			cout << "Exit the program\n";
			mem.saveInfo();//��ü�� ������ ���Ͽ� �����ϰ� ����
			return 0;
		}
		else {
			cout << "Invalid menu\n";
			cout << "--------------------------------------\n";
		}
	}
}
bool pass_condition(char* pass) {//��й�ȣ�� ������ �����ϴ��� �Ǵ��ϴ� �Լ�
	int alpha = 0;//���ĺ� �ҹ����� ����
	int digit = 0;//������ ����
	int special = 0;//Ư�������� ����
	int len = strlen(pass);//��й�ȣ�� ����
	if (len < 10 || len > 20)//���̰� 10���� �۰ų� 20���� ũ�ٸ�
		return true;//���� ����X, true ��ȯ
	for (int i = 0; i < len; i++) {
		if ('a' <= pass[i]&& pass[i] <= 'z') {//�ҹ���
			alpha++;
		}
		else if ('1' <= pass[i]&& pass[i] <= '9')//����
			digit++;
		else {
			if ('A' <= pass[i]&& pass[i] <= 'Z')//�빮�ڴ� ����
				continue;
			else//Ư������
				special++;
		}
	}
	if (alpha == 0 || digit == 0 || special == 0) {//���ǿ� �ϳ��� �������� ���Ѵٸ�
		return true;//true ��ȯ
	}
	return false;//������ ��� �����ϸ� flase ��ȯ
}
void Login_state(membership& mem, char* id_log, char* pass_log) {//�α��� ���¸� ��Ÿ���� �Լ�
	while (1) {
		int menu;
		cout << "=======================================\n";
		cout << "Logged in user : (" << id_log << ")\n";
		cout << "Menu.\n";
		cout << "1. Login\n";
		cout << "2. Register\n";
		cout << "3. Withdraw\n";
		cout << "4. Exit\n  :  ";
		cin >> menu;
		if (menu == 1) {//�̹� �α����� �Ǿ������Ƿ� �α���X
			cout << "You are already logged in.\n";
			cout << "--------------------------------------\n";
		}
		else if (menu == 2) {//�̹� �α����� �Ǿ������Ƿ� ����X
			cout << "You are already logged in.\n";
			cout << "--------------------------------------\n";
		}
		else if (menu == 3) {//�α��� ���¿��� Ż�� ����
			mem.Withdraw(id_log);//�ش� id�� password�� �´� ������ Ż��
			cout << "Successful withdraw.\n";
			return;
		}
		else if (menu == 4) {
			cout << "Exit the program\n";
			mem.saveInfo();//��ü�� ������ ���Ͽ� �����ϰ� ����
			return;
		}
		else {
			cout << "Invalid menu\n";
		}
	}
}
