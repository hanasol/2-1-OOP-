#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(){ }
	Time(int hour, int min, int sec) {
		this->hour = hour;
		minute = min;
		second = sec;
	}
	~Time() { }
	void setTime(int hour, int min, int sec) {//현재 시, 분, 초로 멤버변수 초기화
		this->hour = hour;
		this->minute = min;
		this->second = sec;
	}
	void addTime(int sec) {//입력받은 초를 더하는 함수
		int hour = 0;
		int min = 0;
		while (sec >= 3600) {//입력받은 초가 3600초 이상이라면
			sec -= 3600;
			hour++;
		}//3600미만이 될때까지 3600을 빼고 시를 +1
		while (sec >= 60) {//60 이상이라면
			sec -= 60;
			min++;
		}//60미만이 될때까지 60을 빼고 분을 +1
		//입력받은 초를 시, 분, 초로 구분
		this->hour += hour;//시를 더함
		this->minute += min;//분을 더함
		this->second += sec;//초를 더함
		while (this->second >= 60) {//초를 모두 더했을 때, 60이상이라면
			this->second -= 60;//초에서 60을 빼고
			this->minute++;//분 증가
		}
		while (this->minute >= 60) {//분을 모두 더했을 때, 60이상이라면
			this->minute -= 60;//분에서 60을 빼고
			this->hour++;//시 증가
		}
		this->hour %= 24;//시는 0~23까지만 표현하므로 24로 나눔
	}
	void  printTime() {
		cout << hour << ":" << minute << ":" << second << endl;
	}
};
class Korea : public Time {//Time 클래스를 public상속
private:
	int hour;
	int minute;
	int second;
public:
	Korea(int hour, int min, int sec):Time(hour, min, sec) {//Time클래스의 생성자를 호출하여 멤버 초기화
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time 클래스의 addTime함수 재정의
		int hour = 0;
		int min = 0;
		while (sec >= 3600) {
			sec -= 3600;
			hour++;
		}
		while (sec >= 60) {
			sec -= 60;
			min++;
		}
		this->hour += hour;
		this->minute += min;
		this->second += sec;
		while (this->second >= 60) {
			this->second -= 60;
			this->minute++;
		}
		while (this->minute >= 60) {
			this->minute -= 60;
			this->hour++;
		}
		this->hour %= 24;
	}
	void  printTime() {//Time 클래스의 printTime함수 재정의
		cout << hour << ":" << minute << ":" << second << endl;
	}
	~Korea(){ }
};
class WashingtonDC : public Time {//Time 클래스를 public 상속
private:
	int hour;
	int minute;
	int second;
public:
	WashingtonDC(int hour, int min, int sec) :Time(hour, min, sec) {//Time 클래스의 생성자를 호출하여 멤버 초기화
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time 클래스의 addTime 함수 재정의
		int hour = 0;
		int min = 0;
		while (sec >= 3600) {
			sec -= 3600;
			hour++;
		}
		while (sec >= 60) {
			sec -= 60;
			min++;
		}
		this->hour += hour;
		this->minute += min;
		this->second += sec;
		while (this->second >= 60) {
			this->second -= 60;
			this->minute++;
		}
		while (this->minute >= 60) {
			this->minute -= 60;
			this->hour++;
		}
		this->hour %= 24;
	}
	void setTime() {//Time클래스의 setTime함수 재정의
		hour -= 13;//한국과 WashingtonDC의 시차는 -13 
		if (hour < 0)//hour이 0 미만이면
			hour += 24;//24를 더해줌
	}
	void  printTime() {//Time클래스의 printTime함수 재정의
		cout << hour << ":" << minute << ":" << second << endl;
	}
	~WashingtonDC() { }
};
class Paris : public Time {//Time 클래스를 public 상속
private:
	int hour;
	int minute;
	int second;
public:
	Paris(int hour, int min, int sec) :Time(hour, min, sec) {//Time 클래스의 생성자를 호출하여 멤버 초기화
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time 클래스의 addTime 함수 재정의
		int hour = 0;
		int min = 0;
		while (sec >= 3600) {
			sec -= 3600;
			hour++;
		}
		while (sec >= 60) {
			sec -= 60;
			min++;
		}
		this->hour += hour;
		this->minute += min;
		this->second += sec;
		while (this->second >= 60) {
			this->second -= 60;
			this->minute++;
		}
		while (this->minute >= 60) {
			this->minute -= 60;
			this->hour++;
		}
		this->hour %= 24;
	}
	void setTime() {//Time클래스의 setTime함수 재정의
		hour -= 7;//한국과 Paris의 시차는 -7
		if (hour < 0)
			hour += 24;
	}
	void  printTime() {//Time클래스의 printTime함수 재정의
		cout << hour << ":" << minute << ":" << second << endl;
	}
	~Paris() { }
};
class greenwichObservatory : public Time {
private:
	int hour;
	int minute;
	int second;
public:
	greenwichObservatory(int hour, int min, int sec) :Time(hour, min, sec) {//Time 클래스의 생성자를 호출하여 멤버 초기화
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time 클래스의 addTime 함수 재정의
		int hour = 0;
		int min = 0;
		while (sec >= 3600) {
			sec -= 3600;
			hour++;
		}
		while (sec >= 60) {
			sec -= 60;
			min++;
		}
		this->hour += hour;
		this->minute += min;
		this->second += sec;
		while (this->second >= 60) {
			this->second -= 60;
			this->minute++;
		}
		while (this->minute >= 60) {
			this->minute -= 60;
			this->hour++;
		}
		this->hour %= 24;
	}
	void setTime() {//Time클래스의 setTime함수 재정의
		hour -= 8;//한국과 greenwichObservatory의 시차는 -8
		if (hour < 0)
			hour += 24;
	}
	void printTime() {//Time클래스의 printTime함수 재정의
		cout << hour << ":" << minute << ":" << second << endl;
	}
	~greenwichObservatory() { }
};
int main() {
	time_t timer;
	struct tm* t;
	timer = time(NULL);//time함수는 time_t 타입으로 결과값을 반환, 1970년 1월 1일 0시 0분 0초를 기점으로 현재까지 흐른 시간을 초 단위로 반환
	t = localtime(&timer);
	string menu;
	Time time1;//Time 객체 생성
	time1.setTime(t->tm_hour, t->tm_min, t->tm_sec);//현재 시, 분, 초로 시간세팅
	Korea k(t->tm_hour, t->tm_min, t->tm_sec);
	WashingtonDC w(t->tm_hour, t->tm_min, t->tm_sec);
	Paris p(t->tm_hour, t->tm_min, t->tm_sec);
	greenwichObservatory g(t->tm_hour, t->tm_min, t->tm_sec);
	//모든 클래스를 현재 시, 분 ,초로 멤버 초기화
	while (1) {
		cout << "Command : ";
		cin >> menu;
		if (menu == "setting") {//setting command
			w.setTime();
			p.setTime();
			g.setTime();
		}//한국은 현재 시간과 시차X, 각 클래스에서 재정의된 setTime함수 호출
		else if (menu == "add") {//add command
			int second;
			cin >> second;
			k.addTime(second);
			w.addTime(second);
			p.addTime(second);
			g.addTime(second);
		}//각 클래스에서 재정의된 addTime함수 호출
		else if (menu == "print") {
			cout << "Korea                = ";
			k.printTime();
			cout << "washingtonDC         = ";
			w.printTime();
			cout << "Paris                = ";
			p.printTime();
			cout << "GreenwichObservatory = ";
			g.printTime();
		}//각 클래스에서 재정의된 print함수 호출
		else if (menu == "exit") {
			cout << "exit the program\n";
			return 0;
		}
		else {
			cout << "Invalid input\n";
		}
	}
}