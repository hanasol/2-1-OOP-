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
	int cnt_num;//가입한 사람의 수
public:
	membership(){ }
	membership(int num) :cnt_num(0){
		inform = new Member[num];//num만큼 메모리 할당
	}
	~membership() {
		delete[] inform;//메모리 해제
	}
	void set_Inform(char* id, char* password) {//파일로부터 입력받은 id, password를 객체로 저장
		strcpy(inform[cnt_num].id, id);
		strcpy(inform[cnt_num].password, password);
		cnt_num++;//가입한 사람 수 증가
	}
	void set_encInform(char* id, char* password) {//입력받은 id, password, 비밀번호의 알파벳은 id의 길이만큼 오른쪽으로 밀려서 암호화되어서 저장
		strcpy(inform[cnt_num].id, id);//입력받은 id로 저장
		int len = strlen(id);
		for (int i = 0; i < strlen(password); i++) {
			if ('a' <= password[i] && password[i] <= 'z') {//알파벳 소문자라면
				password[i] += len - 26;//id의 길이에서 알파벳의 개수인 26을 뺌
				if (password[i] < 'a')//아스키 코드상 a보다 작다면
					password[i] += 26;//26을 더해줌
			}
			else if ('A' <= password[i] && password[i] <= 'Z') {//대문자라면
				password[i] += len - 26;///id의 길이에서 알파벳의 개수인 26을 뺌
				if (password[i] < 'A')//아스키 코드상 A보다 작다면
					password[i] += 26;//26을 더해줌
			}
		}
		strcpy(inform[cnt_num].password, password);//암호화된 password 저장
		cnt_num++;//가입한 사람 수 증가
	}
	bool Check_id(char* id) {//아이디가 같은지 확인
		for (int i = 0; i < cnt_num; i++) {
			if (0 == strcmp(inform[i].id, id))
				return true;//같은 id가 있으면 true
		}
		return false;//없으면 flase
	}
	bool Check_pass(char* id, char* password) {//비밀번호가 같은지 확인
		int len = strlen(id);
		for (int i = 0; i < strlen(password); i++) {
			if ('a' <= password[i] && password[i] <= 'z') {//알파벳 소문자라면
				password[i] += len - 26;
				if (password[i] < 'a')
					password[i] += 26;
			}
			else if ('A' <= password[i] && password[i] <= 'Z') {//대문자라면
				password[i] += len - 26;
				if (password[i] < 'A')
					password[i] += 26;
			}
		}//비밀번호 암호화
		for (int i = 0; i < cnt_num; i++) {
			if (0 == strcmp(inform[i].password,password))
				return true;//같은 비밀번호가가 있으면 true
		}
		return false;//비밀번호가 다르면 flase
	}
	void Withdraw(char* id) {//탈퇴
		for (int i = 0; i < cnt_num; i++) {//모든 객체를 돌면서 맞는 id를 탐색
			if (0 != strcmp(inform[i].id, id)) {//id가 다르다면
				continue;//반복을 건너뜀
			}
			else {//id가 같다면 id와 password를 빈 문자열로 바꾸어서 탈퇴
				strcpy(inform[i].id, "");
				strcpy(inform[i].password, "");
			}
		}
	}
	void saveInfo() {//정보를 파일에 저장하는 함수
		ofstream fout;//ofstream객체 생성
		fout.open("membership.txt");//입력을 받아오는 파일과 같은 파일을 엶
		for (int i = 0; i < cnt_num; i++) {//가입된 사람의 수만큼 반복하면 id password의 형태로 파일에 저장
			fout << inform[i].id << " " << inform[i].password << endl;
		}
		fout.close();//파일 닫기
	}
};
void Login_state(membership& mem, char* id_log, char* pass_log);//로그인 상태를 나타내는 함수
int main() {
	ifstream fin;//파일로부터 가입된 사람의 정보를 읽어오기 위해서 ifstream객체 생성
	membership mem(100);//최대 100명의 정보 저장가능
	int menu;
	char id_log[30];
	char pass_log[30];
	string temp;
	fin.open("membership.txt");//member.txt파일을 엶
	while (!fin.eof()) {
		char id[30];
		char pass[30];
		fin >> id >> pass;
		if (0 == strcmp(id, "") || 0 == strcmp(pass, ""))//id나 비밀번호가 공백이면 탈퇴처리
			continue;//다음 반복
		mem.set_Inform(id, pass);//가입된 사람의 정보를 객체로 저장
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
		if (menu == 1) {//Login, ID와 비밀번호가 맞아야 로그인 성공
			cout << "User id: ";
			cin >> id_log;
			cout << "password: ";
			cin >> pass_log;
			cout << "--------------------------------------\n";
			if (mem.Check_id(id_log)) {//아이디가 같다면 
				if (mem.Check_pass(id_log, pass_log)) {//비밀번호까지 같다면
					cout << "Login successful.\n";//로그인 성공
					Login_state(mem, id_log, pass_log);//로그인 상태로 넘어감
					mem.saveInfo();//가입된 사람의 정보를 파일에 저장
					return 0;
				}
				else {//비밀번호가 다르다면
					cout << "Login failed. Invalid User id or password\n";
				}
			}
			else {//아이디가 다르다면
				cout << "Login failed. Invalid User id or password\n";
			}
		}
		else if (menu == 2) {//Register, 이전에 중복되는 ID가 없어야함, 비밀번호는 소문자, 숫자, 특수문자 1개이상, 10글자 이상, 20글자 이하의 조건을 만족해야함
			char id[30];
			char pass[30];
			cout << "User id: ";
			cin >> id;
			cout << "password: ";
			cin >> pass;
			cout << "--------------------------------------\n";
			if (!mem.Check_id(id)) {//아이디 중복 X
				if (!pass_condition(pass)) {//암호 조건 충족
					cout << "Registration successful.\n";
					mem.set_encInform(id, pass);//가입에 성공했으므로 비밀번호를 암호화하여 객체에 저장
				}
				else {//암호 조건 불충족
					cout << "Unsatisfied with password conditions\n";
				}
			}
			else {//id 중복
				cout << "overlapping ID\n";
			}
		}
		else if (menu == 3) {//Withdraw, Login상태가 아니므로 탈퇴 불가
			cout << "Invalid.\n";
			cout << "--------------------------------------\n";
		}
		else if (menu == 4) {
			cout << "Exit the program\n";
			mem.saveInfo();//객체의 정보를 파일에 저장하고 종료
			return 0;
		}
		else {
			cout << "Invalid menu\n";
			cout << "--------------------------------------\n";
		}
	}
}
bool pass_condition(char* pass) {//비밀번호의 조건을 충족하는지 판단하는 함수
	int alpha = 0;//알파벳 소문자의 개수
	int digit = 0;//숫자의 개수
	int special = 0;//특수문자의 개수
	int len = strlen(pass);//비밀번호의 길이
	if (len < 10 || len > 20)//길이가 10보다 작거나 20보다 크다면
		return true;//조건 충족X, true 반환
	for (int i = 0; i < len; i++) {
		if ('a' <= pass[i]&& pass[i] <= 'z') {//소문자
			alpha++;
		}
		else if ('1' <= pass[i]&& pass[i] <= '9')//숫자
			digit++;
		else {
			if ('A' <= pass[i]&& pass[i] <= 'Z')//대문자는 생략
				continue;
			else//특수문자
				special++;
		}
	}
	if (alpha == 0 || digit == 0 || special == 0) {//조건에 하나라도 충족하지 못한다면
		return true;//true 반환
	}
	return false;//조건을 모두 만족하면 flase 반환
}
void Login_state(membership& mem, char* id_log, char* pass_log) {//로그인 상태를 나타내는 함수
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
		if (menu == 1) {//이미 로그인이 되어있으므로 로그인X
			cout << "You are already logged in.\n";
			cout << "--------------------------------------\n";
		}
		else if (menu == 2) {//이미 로그인이 되어있으므로 가입X
			cout << "You are already logged in.\n";
			cout << "--------------------------------------\n";
		}
		else if (menu == 3) {//로그인 상태에서 탈퇴 가능
			mem.Withdraw(id_log);//해당 id와 password에 맞는 정보를 탈퇴
			cout << "Successful withdraw.\n";
			return;
		}
		else if (menu == 4) {
			cout << "Exit the program\n";
			mem.saveInfo();//객체의 정보를 파일에 저장하고 종료
			return;
		}
		else {
			cout << "Invalid menu\n";
		}
	}
}
