#include <iostream>
#include <ctime>
using namespace std;
struct node {
	int data;
	int idx;
	node* next;
};
class List {
private:
	node* head;
	node* tail;
	int cnt;//리스트의 노드의 갯수
public:
	List() : cnt(0) {
		head = nullptr;
		tail = nullptr;
	}
	void addValue(int data) {
		node* temp = new node;//추가할 노드
		temp->data = data;//추가할 노드의 데이터 저장
		temp->next = nullptr;
		if (head == nullptr) {//리스트가 비어있을 때
			head = temp;
			tail = temp;//head와 tail을 temp로 지정
			tail->next = nullptr;//tail의 다음 노드는 nullptr
			head->idx = tail->idx = 0;//head와 tail의 index는 0
			cnt++;//리스트의 노드 갯수 증가
		}
		else {//리스트에 1개 이상의 노드가 있을 때
			tail->next = temp;//tail의 다음 노드로 temp를 연결
			tail = temp;//tail을 temp로 옮김
			tail->idx = cnt;//tail의 index는 현재 노드의 갯수
			cnt++;//노드의 갯수 증가
		}
		if (cnt == 10) {//리스트에 10개가 다 찼다면
			tail->next = head;//tail의 다음 노드를 head로 이어줌
		}
	}
	node* Gethead() {//head를 반환
		return head;
	}
	void print() {
		node* temp = head;//temp는 head 노드부터 시작
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != nullptr && temp != head);//해당 노드가 nullptr이 아니고 head가 아니면 반복
		cout << endl;
	}
	void transfer(int a, int b) {//b 인덱스의 값을 a 인덱스의 값으로 저장하는 함수
		node* temp = head;//head부터 순회
		if (a != b) {
			while (temp->idx != a)
				temp = temp->next;//a 인덱스까지 이동
			int data = temp->data;//a 인덱스의 값을 저장
			while (temp->idx != b) {//b 인덱스까지 이동하는 과정
				srand(time(NULL));
				int flag = rand() % 10;//0~9의 random number generation
				if (flag == 0) {//0~9 중에서 0이 나오면 연결이 끊김: 1/10->10%확률
					cout << "Detected a disconnection between " << temp->idx << " and " << temp->next->idx << endl;
					temp->next = nullptr;//해당 노드의 다음 노드를 nullptr로 저장하여 연결을 끊음
					return;//함수 종료
				}
				temp = temp->next;//10%의 확률로 연결이 끊기지 않으면 다음 노드로 이동
			}
			temp->data = data;//temp가 b 인덱스까지 이동했으므로 해당 노드의 데이터를 a 인덱스의 데이터로 바꿔줌
		}
		else
			return;
	}
};
int main() {
	int arr[10] = { 0, };//초기화 할 값을 저장할 배열
	char menu[20];
	List list;//연결리스트 객체 생성
	while (1) {
		cin >> menu;
		if (0== strcmp(menu,"initialize")) {//initialize command
			for (int i = 0; i < 10; i++) {
				cin >> arr[i];//10개의 리스트 원소 입력
				list.addValue(arr[i]);//리스트에 추가
			}
		}
		else if (0 == strcmp(menu, "transfer")) {//transfer command
			int a, b;//옮길 인덱스
			char temp[20];
			cin >> a >> temp >>b;//to는 입력받기만 하고 사용X
			list.transfer(a, b);
		}
		else if (0 == strcmp(menu, "print")) {//print command
			list.print();
		}
		else if (0 == strcmp(menu, "exit")) {
			cout << "Exit the program\n";
			return 0;
		}
		else {
			cout << "Invalid input\n";
		}
	}
}