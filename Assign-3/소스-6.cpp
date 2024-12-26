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
	virtual void toward() = 0;//toward함수를 pure virtual로 선언 
	bool flag_BtoF = false;//Back에서 Front로 상태가 바뀌는지 체크할 변수
	bool flag_FtoB = false;//Front에서 back으로 상태가 바뀌는지 체크할 변수
};
class Back :public TaggerState {//뒤를 바라보고있음: 이동 가능
public:
	string phrase = "Green Light!";
	int phrase_cursor = 0;
	int temp = -1;
	int randNum;
	void toward() override {//TaggerState 클래스의 가상함수인 toward함수 재정의
		flag_BtoF = false;
		while (phrase_cursor <= phrase.size()) {//커서가 phrase의 사이즈보다 작거나 같을 때까지 반복
			time_t now = time(0);
			srand(now);
			//매 반복마다 새로운 시드로 랜덤 값 생성
			char* dt = ctime(&now);
			string timeStr(dt);//Thu May 9 15:55:03 2024\n의 형태로 문자열이 저장됨
			string sec = timeStr.substr(17, 2);//timeStr에서 초만 따로 저장
			if (temp != stoi(sec)) {//1초마다 실행
				temp = stoi(sec);//초를 int형으로 바꿔서 temp에 저장
				randNum = rand() % 5 + 2;//2~6의 랜덤 값
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(phrase_cursor),0 });//0행, phrase_cursor열의 처음으로 커서 이동
				for (int i = phrase_cursor; i < phrase_cursor + randNum; i++) {//랜덤 값 만큼 출력
					cout << phrase[i];
					if (i >= phrase.size())//phrase의 길이보다 커지면 종료
						break;
				}
				phrase_cursor += randNum;//커서가 랜덤 값 만큼 증가
			}
		}
		flag_BtoF = true;//!에 도달하면 true로 상태를 변경
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });//0,0으로 이동
		cout << "            ";//빈칸을 출력해서 공백으로 처리하는 효과
	}
};
class Front :public TaggerState {//앞을 바라보고 있음: 이동 불가능
public:
	string phrase = "Red Light!";
	int phrase_cursor = 0;
	void toward() override {//TaggerState 클래스의 가상함수인 toward함수 재정의
		flag_BtoF = false;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });//0,0으로 이동
		time_t now = time(0);
		srand(now);
		int randTime = rand() % 9 + 2;//2~10의 랜덤 값 할당
		cout << phrase;
		Sleep(1000 * randTime);//랜덤 값 만큼 대기
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });//0,0으로 이동
		cout << "          ";//빈칸을 출력하여 공백으로 처리
		flag_FtoB = true;//랜덤 시간이 끝나면 true로 상태를 변경
	}
};
class Player {
private:
	TaggerState* state;//술래의 상태
	int progress;
	bool State_back;//back 상태면 true, front 상태면 false
public:
	Player() {
		progress = 0;
		state = new Back();//초기 상태는 back
		State_back = true;//초기에는 back이므로 true
	}
	~Player() {
		delete state;
	}
	void SetState(TaggerState* newState) {//새로운 상태로 설정
		delete state;//이전 상태 삭제
		state = newState;//새로운 상태로 초기화
	}
	void toward() {
		state->toward();//현재 상태에 맞는 함수 호출
		progress++;
	}
	int GetProgress() {//progress반환
		return progress;
	}
	bool GetState() {//현재 상태 반환
		return State_back;
	}
	void SetState_back(bool flag) {//현재 상태를 저장하는 함수
		State_back = flag;
	}
};
int main() {
	int Statecursor = 0;//현재 진행상태를 보여주는 커서
	short cursor = 0;
	int temp = -1;

	cout << "=============================\n";
	cout << "    Red Light! Green Light!    \n\n";
	cout << "        (Press any key)        \n";
	cout << "=============================\n";
	_getch(); //아무키나 입력 받음
	system("cls");//화면을 지움

	Player player;//player 객체 생성
	while (Statecursor <= 20) {//20 이하까지만 반복
		time_t now = time(0);
		srand(now);
		char* dt = ctime(&now);//Thu May 9 15:55:03 2024\n의 형태로 문자열이 저장됨
		string timeStr(dt);//timeStr에서 초만 따로 저장
		string sec = timeStr.substr(17, 2);//초만 따로 저장
		//1초마다 실행
		if (temp != stoi(sec)) {
			temp = stoi(sec);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,5 });//0,5로 이동
			cout << "start | ";
			for (int i = 0; i < Statecursor; i++) {//현재 커서만큼 @@출력
				cout << "@@";
			}
			for (int i = 0; i < 20 - Statecursor; i++)//20-커서 만큼 --출력
				cout << "--";
			cout << " | end ";
			cout << " ( " << Statecursor << "/20 )\n";//현재의 상태 출력
		}
		if (Statecursor == 20)//현재 커서가 20에 도달하면 반복문 탈출, 게임 승리
			break;
		player.toward();//현재 상태에 해당하는 함수 호출
		if (player.GetState()) {//back상태에서 키 입력
			while (_kbhit()) {//여러번 입력하면 여러번 이동됨
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,4 });//0,4로 이동
				int input = _getch();//int형으로 아스키코드를 입력받음
				if (input == 224) {//방향키가 입력되었다면
					input = _getch();//값을 재할당
					if (input == 77) {//오른쪽 방향키:77
						cout << "Forword.";//Froword. 출력
						Statecursor++;//Statecursor 이동
						Sleep(300);//0.5초 대기
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,4 });//다시 0,4로 이동
						cout << "        ";//공백을 출력하여 Forword를 지우는 효과
					}
				}
			}
		}
		else {//front 상태에서 키 입력
			if (_kbhit()) {//키 입력을 확인
				int input = _getch();
				if (input == 224) {//방향키 입력 확인
					input = _getch();
					if (input == 77) {//오른쪽 방향키
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,4 });//4행 0열로 이동
						cout << "Tagger found out.";
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,8 });//8행 0열로 이동
						cout << "Lose..\n\nexit the program\n";
						return 0;//게임 패배, 프로그램 종료
					}
				}
			}
		}
		if (player.GetState()) {//back상태
			player.SetState(new Front());//Front상태로 변환
			player.SetState_back(false);
		}
		else {//Front 상태
			player.SetState(new Back());//Back상태로 변환
			player.SetState_back(true);
		}
	}
	//게임에서 승리 시
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,5 });//5행 0열로 이동
	cout << "start | ";
	for (int i = 0; i < 20; i++) {
		cout << "@@";//20칸 진행 출력
	}
	cout << " | end ";
	cout << " ( " << 20 << "/20 )\n";//승리 상태 출력
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,8 });//8행 0열로 이동
	cout << "Win!!\n\nexit the program\n";
	return 0;//게임 승리, 프로그램 종료
}