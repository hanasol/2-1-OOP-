#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class TaggerState {
public:
	virtual void toward() = 0;//toward�Լ��� pure virtual�� ���� 
	bool flag_BtoF = false;//Back���� Front�� ���°� �ٲ���� üũ�� ����
	bool flag_FtoB = false;//Front���� back���� ���°� �ٲ���� üũ�� ����
};
class Back :public TaggerState {//�ڸ� �ٶ󺸰�����: �̵� ����
public:
	string phrase = "Green Light!";
	int phrase_cursor = 0;
	int temp = -1;
	int randNum;
	void toward() override {//TaggerState Ŭ������ �����Լ��� toward�Լ� ������
		flag_BtoF = false;
		while (phrase_cursor <= phrase.size()) {//Ŀ���� phrase�� ������� �۰ų� ���� ������ �ݺ�
			time_t now = time(0);
			srand(now);
			//�� �ݺ����� ���ο� �õ�� ���� �� ����
			char* dt = ctime(&now);
			string timeStr(dt);//Thu May 9 15:55:03 2024\n�� ���·� ���ڿ��� �����
			string sec = timeStr.substr(17, 2);//timeStr���� �ʸ� ���� ����
			if (temp != stoi(sec)) {//1�ʸ��� ����
				temp = stoi(sec);//�ʸ� int������ �ٲ㼭 temp�� ����
				randNum = rand() % 5 + 2;//2~6�� ���� ��
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(phrase_cursor),0 });//0��, phrase_cursor���� ó������ Ŀ�� �̵�
				for (int i = phrase_cursor; i < phrase_cursor + randNum; i++) {//���� �� ��ŭ ���
					cout << phrase[i];
					if (i >= phrase.size())//phrase�� ���̺��� Ŀ���� ����
						break;
				}
				phrase_cursor += randNum;//Ŀ���� ���� �� ��ŭ ����
			}
		}
		flag_BtoF = true;//!�� �����ϸ� true�� ���¸� ����
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });//0,0���� �̵�
		cout << "            ";//��ĭ�� ����ؼ� �������� ó���ϴ� ȿ��
	}
};
class Front :public TaggerState {//���� �ٶ󺸰� ����: �̵� �Ұ���
public:
	string phrase = "Red Light!";
	int phrase_cursor = 0;
	void toward() override {//TaggerState Ŭ������ �����Լ��� toward�Լ� ������
		flag_BtoF = false;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });//0,0���� �̵�
		time_t now = time(0);
		srand(now);
		int randTime = rand() % 9 + 2;//2~10�� ���� �� �Ҵ�
		cout << phrase;
		Sleep(1000 * randTime);//���� �� ��ŭ ���
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });//0,0���� �̵�
		cout << "          ";//��ĭ�� ����Ͽ� �������� ó��
		flag_FtoB = true;//���� �ð��� ������ true�� ���¸� ����
	}
};
class Player {
private:
	TaggerState* state;//������ ����
	int progress;
	bool State_back;//back ���¸� true, front ���¸� false
public:
	Player() {
		progress = 0;
		state = new Back();//�ʱ� ���´� back
		State_back = true;//�ʱ⿡�� back�̹Ƿ� true
	}
	~Player() {
		delete state;
	}
	void SetState(TaggerState* newState) {//���ο� ���·� ����
		delete state;//���� ���� ����
		state = newState;//���ο� ���·� �ʱ�ȭ
	}
	void toward() {
		state->toward();//���� ���¿� �´� �Լ� ȣ��
		progress++;
	}
	int GetProgress() {//progress��ȯ
		return progress;
	}
	bool GetState() {//���� ���� ��ȯ
		return State_back;
	}
	void SetState_back(bool flag) {//���� ���¸� �����ϴ� �Լ�
		State_back = flag;
	}
};
int main() {
	int Statecursor = 0;//���� ������¸� �����ִ� Ŀ��
	short cursor = 0;
	int temp = -1;

	cout << "=============================\n";
	cout << "    Red Light! Green Light!    \n\n";
	cout << "        (Press any key)        \n";
	cout << "=============================\n";
	_getch(); //�ƹ�Ű�� �Է� ����
	system("cls");//ȭ���� ����

	Player player;//player ��ü ����
	while (Statecursor <= 20) {//20 ���ϱ����� �ݺ�
		time_t now = time(0);
		srand(now);
		char* dt = ctime(&now);//Thu May 9 15:55:03 2024\n�� ���·� ���ڿ��� �����
		string timeStr(dt);//timeStr���� �ʸ� ���� ����
		string sec = timeStr.substr(17, 2);//�ʸ� ���� ����
		//1�ʸ��� ����
		if (temp != stoi(sec)) {
			temp = stoi(sec);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,5 });//0,5�� �̵�
			cout << "start | ";
			for (int i = 0; i < Statecursor; i++) {//���� Ŀ����ŭ @@���
				cout << "@@";
			}
			for (int i = 0; i < 20 - Statecursor; i++)//20-Ŀ�� ��ŭ --���
				cout << "--";
			cout << " | end ";
			cout << " ( " << Statecursor << "/20 )\n";//������ ���� ���
		}
		if (Statecursor == 20)//���� Ŀ���� 20�� �����ϸ� �ݺ��� Ż��, ���� �¸�
			break;
		player.toward();//���� ���¿� �ش��ϴ� �Լ� ȣ��
		if (player.GetState()) {//back���¿��� Ű �Է�
			while (_kbhit()) {//������ �Է��ϸ� ������ �̵���
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,4 });//0,4�� �̵�
				int input = _getch();//int������ �ƽ�Ű�ڵ带 �Է¹���
				if (input == 224) {//����Ű�� �ԷµǾ��ٸ�
					input = _getch();//���� ���Ҵ�
					if (input == 77) {//������ ����Ű:77
						cout << "Forword.";//Froword. ���
						Statecursor++;//Statecursor �̵�
						Sleep(300);//0.5�� ���
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,4 });//�ٽ� 0,4�� �̵�
						cout << "        ";//������ ����Ͽ� Forword�� ����� ȿ��
					}
				}
			}
		}
		else {//front ���¿��� Ű �Է�
			if (_kbhit()) {//Ű �Է��� Ȯ��
				int input = _getch();
				if (input == 224) {//����Ű �Է� Ȯ��
					input = _getch();
					if (input == 77) {//������ ����Ű
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,4 });//4�� 0���� �̵�
						cout << "Tagger found out.";
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,8 });//8�� 0���� �̵�
						cout << "Lose..\n\nexit the program\n";
						return 0;//���� �й�, ���α׷� ����
					}
				}
			}
		}
		if (player.GetState()) {//back����
			player.SetState(new Front());//Front���·� ��ȯ
			player.SetState_back(false);
		}
		else {//Front ����
			player.SetState(new Back());//Back���·� ��ȯ
			player.SetState_back(true);
		}
	}
	//���ӿ��� �¸� ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,5 });//5�� 0���� �̵�
	cout << "start | ";
	for (int i = 0; i < 20; i++) {
		cout << "@@";//20ĭ ���� ���
	}
	cout << " | end ";
	cout << " ( " << 20 << "/20 )\n";//�¸� ���� ���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,8 });//8�� 0���� �̵�
	cout << "Win!!\n\nexit the program\n";
	return 0;//���� �¸�, ���α׷� ����
}