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
	void setTime(int hour, int min, int sec) {//���� ��, ��, �ʷ� ������� �ʱ�ȭ
		this->hour = hour;
		this->minute = min;
		this->second = sec;
	}
	void addTime(int sec) {//�Է¹��� �ʸ� ���ϴ� �Լ�
		int hour = 0;
		int min = 0;
		while (sec >= 3600) {//�Է¹��� �ʰ� 3600�� �̻��̶��
			sec -= 3600;
			hour++;
		}//3600�̸��� �ɶ����� 3600�� ���� �ø� +1
		while (sec >= 60) {//60 �̻��̶��
			sec -= 60;
			min++;
		}//60�̸��� �ɶ����� 60�� ���� ���� +1
		//�Է¹��� �ʸ� ��, ��, �ʷ� ����
		this->hour += hour;//�ø� ����
		this->minute += min;//���� ����
		this->second += sec;//�ʸ� ����
		while (this->second >= 60) {//�ʸ� ��� ������ ��, 60�̻��̶��
			this->second -= 60;//�ʿ��� 60�� ����
			this->minute++;//�� ����
		}
		while (this->minute >= 60) {//���� ��� ������ ��, 60�̻��̶��
			this->minute -= 60;//�п��� 60�� ����
			this->hour++;//�� ����
		}
		this->hour %= 24;//�ô� 0~23������ ǥ���ϹǷ� 24�� ����
	}
	void  printTime() {
		cout << hour << ":" << minute << ":" << second << endl;
	}
};
class Korea : public Time {//Time Ŭ������ public���
private:
	int hour;
	int minute;
	int second;
public:
	Korea(int hour, int min, int sec):Time(hour, min, sec) {//TimeŬ������ �����ڸ� ȣ���Ͽ� ��� �ʱ�ȭ
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time Ŭ������ addTime�Լ� ������
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
	void  printTime() {//Time Ŭ������ printTime�Լ� ������
		cout << hour << ":" << minute << ":" << second << endl;
	}
	~Korea(){ }
};
class WashingtonDC : public Time {//Time Ŭ������ public ���
private:
	int hour;
	int minute;
	int second;
public:
	WashingtonDC(int hour, int min, int sec) :Time(hour, min, sec) {//Time Ŭ������ �����ڸ� ȣ���Ͽ� ��� �ʱ�ȭ
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time Ŭ������ addTime �Լ� ������
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
	void setTime() {//TimeŬ������ setTime�Լ� ������
		hour -= 13;//�ѱ��� WashingtonDC�� ������ -13 
		if (hour < 0)//hour�� 0 �̸��̸�
			hour += 24;//24�� ������
	}
	void  printTime() {//TimeŬ������ printTime�Լ� ������
		cout << hour << ":" << minute << ":" << second << endl;
	}
	~WashingtonDC() { }
};
class Paris : public Time {//Time Ŭ������ public ���
private:
	int hour;
	int minute;
	int second;
public:
	Paris(int hour, int min, int sec) :Time(hour, min, sec) {//Time Ŭ������ �����ڸ� ȣ���Ͽ� ��� �ʱ�ȭ
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time Ŭ������ addTime �Լ� ������
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
	void setTime() {//TimeŬ������ setTime�Լ� ������
		hour -= 7;//�ѱ��� Paris�� ������ -7
		if (hour < 0)
			hour += 24;
	}
	void  printTime() {//TimeŬ������ printTime�Լ� ������
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
	greenwichObservatory(int hour, int min, int sec) :Time(hour, min, sec) {//Time Ŭ������ �����ڸ� ȣ���Ͽ� ��� �ʱ�ȭ
		this->hour = hour;
		minute = min;
		second = sec;
	}
	void addTime(int sec) {//Time Ŭ������ addTime �Լ� ������
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
	void setTime() {//TimeŬ������ setTime�Լ� ������
		hour -= 8;//�ѱ��� greenwichObservatory�� ������ -8
		if (hour < 0)
			hour += 24;
	}
	void printTime() {//TimeŬ������ printTime�Լ� ������
		cout << hour << ":" << minute << ":" << second << endl;
	}
	~greenwichObservatory() { }
};
int main() {
	time_t timer;
	struct tm* t;
	timer = time(NULL);//time�Լ��� time_t Ÿ������ ������� ��ȯ, 1970�� 1�� 1�� 0�� 0�� 0�ʸ� �������� ������� �帥 �ð��� �� ������ ��ȯ
	t = localtime(&timer);
	string menu;
	Time time1;//Time ��ü ����
	time1.setTime(t->tm_hour, t->tm_min, t->tm_sec);//���� ��, ��, �ʷ� �ð�����
	Korea k(t->tm_hour, t->tm_min, t->tm_sec);
	WashingtonDC w(t->tm_hour, t->tm_min, t->tm_sec);
	Paris p(t->tm_hour, t->tm_min, t->tm_sec);
	greenwichObservatory g(t->tm_hour, t->tm_min, t->tm_sec);
	//��� Ŭ������ ���� ��, �� ,�ʷ� ��� �ʱ�ȭ
	while (1) {
		cout << "Command : ";
		cin >> menu;
		if (menu == "setting") {//setting command
			w.setTime();
			p.setTime();
			g.setTime();
		}//�ѱ��� ���� �ð��� ����X, �� Ŭ�������� �����ǵ� setTime�Լ� ȣ��
		else if (menu == "add") {//add command
			int second;
			cin >> second;
			k.addTime(second);
			w.addTime(second);
			p.addTime(second);
			g.addTime(second);
		}//�� Ŭ�������� �����ǵ� addTime�Լ� ȣ��
		else if (menu == "print") {
			cout << "Korea                = ";
			k.printTime();
			cout << "washingtonDC         = ";
			w.printTime();
			cout << "Paris                = ";
			p.printTime();
			cout << "GreenwichObservatory = ";
			g.printTime();
		}//�� Ŭ�������� �����ǵ� print�Լ� ȣ��
		else if (menu == "exit") {
			cout << "exit the program\n";
			return 0;
		}
		else {
			cout << "Invalid input\n";
		}
	}
}