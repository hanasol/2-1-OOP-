#include <iostream>
using namespace std;
int strcmp_(const char* str1, const char* str2);
struct node { //노드 클래스
	int data;//노드의 데이터
	node* next;//다음 노드를 가리키는 포인터
};
class list {//리스트 클래스
private:
	node* head;//맨 앞 노드
	node* tail;//맨 뒤 노드
public:
	list() {
		head = nullptr;
		tail = nullptr;
	}//객체 생성 시 haed와 tail은 NULL로 초기화
	void add(int n) {//노드를 내림차순에 맞게 추가하는 함수
		node* temp = new node;//임시 노드 생성
		node* cur = new node;//추가할 노드
		if (head == nullptr) {//리스트가 비어있다면
			temp->data = n;//temp의 데이터를 n으로 초기화
			head = temp;//head는 temp가 됨
			tail = temp;//head와 tail은 같은 노드(temp)가 됨
			tail->next = nullptr;//tail의 다음 노드는 NULL로 저장
		}
		else {//노드가 한개 이상 존재
			cur->data = n;//추가할 노드의 값을 n으로 초기화
			temp = head;//임시 노드를 head로 지정(head부터 시작하여 추가)
			if (temp->data < n) {//넣을 숫자가 head의 데이터보다 클 때
				cur->next = head;//추가할 노드의 다음 노드를 head로 지정
				head = cur;//현재 노드를 head로 지정
			}
			else {//넣을 숫자가 head의 데이터보다 작을 때
				while (temp->next != nullptr && temp->next->data >= n) {//다음 노드가 nullptr이 아니고 다음 노드의 값이 내가 넣을 값보다 크다면
					//temp를 다음노드로 옮김
					temp = temp->next;
				}//temp가 내가 저장할 위치 바로 전의 노드가 됨
				cur->next = temp->next;//현재 노드의 다음 노드를 temp의 다음 노드로 저장(중간에 삽입하여 다음 노드와 리스트를 연결)
				temp->next = cur;//temp의 다음 노드를 추가할 노드로 저장(중간에 삽입하여 이전 노드와 리스트를 연결)
			}
		}
	}
	void deleteNode(int n) {//입력받은 값의 노드를 삭제하는 함수
		node* flag = new node;//삭제할 노드의 이전 노드를 생성
		flag = head;//head로 지정하여 맨 앞부터 반복
		while (flag != nullptr) {
			if (flag->next != nullptr && flag->data == n) {//2개 이상 and 맨 앞을 지울 때
				head = head->next;//head를 다음 노드로 이동하여 저장
				delete flag;//메모리해제
				return;
			}
			else if (flag->next != nullptr && flag->next->data == n) {//원소가 2개 이상일 때
				node* temp = flag->next;//flag는 삭제할 노드의 이전 노드이므로 flag->next는 내가 삭제할 노드, 삭제할 노드를 temp에 저장
				flag->next = temp->next;//이전 노드의 다음 노드에 삭제할 노드의 다음 노드로 저장
				delete temp;//삭제할 노드의 메모리를 해제
				return;
			}
			else if (flag->next == nullptr && flag->data == n) {//원소가 1개일 때 
				head = nullptr;
				tail = nullptr;//원소가 1개일 때 삭제하면 빈 리스트가 되므로 head와 tail을 모두 NULL로 초기화
				return;
			}
			flag = flag->next;//flag를 다음 노드로 옮김
		}
	}
	void ShowList(node* head) {//리스트 출력
		node* temp = new node;//임시 노드 생성
		if (head == nullptr)//head가 NULL이라면 빈 리스트
			cout << "리스트가 비어있습니다.";
		else {
			cout << "Linked list : ";
			temp = head;//temp를 head로 지정
			while (temp != nullptr) {//tail까지 반복
				cout << temp->data;//temp의 데이터 출력
				if (temp->next != nullptr)//temp의 다음노드가 NULL이라면 temp는 tail의 바로 이전 노드임
					cout << "->";//tail 바로 전까지만 화살표 출력
				temp = temp->next;//temp를 다음 노드로 이동
			}
		}
		cout << endl;
	}
	node* GetHead() {
		return head;//리스트의 맨 앞 노드를 반환
	}

};
int main() {
	char* menu = new char[30];
	list a;
	int n;
	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "insert")) {
			cin >> n;
			a.add(n);//n값을 연결리스트에 추가
			a.ShowList(a.GetHead());//head를 반환하여 head부터 값 출력
		}
		else if (0 == strcmp_(menu, "delete")) {
			cin >> n;
			a.deleteNode(n);//n값을 찾아서 삭제
			a.ShowList(a.GetHead());//head부터 값 출력
		}
		else if (0 == strcmp_(menu, "exit")) {//프로그램 종료
			cout << "Exit the program";
			delete menu;
			return 0;
		}
		else
			cout << "Invalid input\n";
	}
}
int strcmp_(const char* str1, const char* str2) {//문자열이 같은지 비교해주는 함수
	int i = 0;
	while (str1[i] != NULL && (str1[i] == str2[i])) {//두 문자열의 문자가 같고 str1이 NULL이 아니라면 반복
		i++;
	}
	if (str1[i] - str2[i] == 0)//두 아스키 값의 차이가 0이라면 두 문자열이 같음
		return 0;
	else if (str1[i] > str2[i])
		return 1;//str1이 str2보다 사전순으로 뒤면 1반환
	else
		return -1;//str1이 str2보다 사전순으로 앞이면 -1반환
}