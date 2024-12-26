#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
private:
	Node* m_next;
	T m_Data;
public:
	Node(){
		m_next = nullptr;
		m_Data = 0;
	}
	~Node(){ }
	void Setdata(T data) {//data는 private 멤버 변수이므로 Node 클래스내에서 접근하여 data를 저장할 함수가 필요함
		m_Data = data;
	}
	void Setnext(Node* next) {//m_next또한 private 멤버 변수이므로 Node 클래스내에서 접근하여 next 노드를 저장할 함수가 필요
		m_next = next;
	}
	T Getdata() {//해당 노드의 data를 반환하는 함수
		return m_Data;
	}
	Node* Getnext() {//다음 노드를 반환하는 함수
		return m_next;
	}
};
template <typename T>
class Queue {
private:
	Node<T>* m_Front;
	Node<T>* m_Back;
public:
	Queue() {
		m_Front = nullptr;
		m_Back = nullptr;
	}
	~Queue(){ }
	void enqueue(T data) {//큐에 값 삽입
		Node<T>* temp = new Node<T>;//내가 저장할 노드
		temp->Setdata(data);
		if (m_Front == nullptr) {//큐가 비어있다면
			m_Front = temp;
			m_Back = temp;//front, back 모두 temp로 초기화
			m_Back->Setnext(nullptr);//back의 다음 노드는 nullptr
		}
		else {//큐가 비어있지 않다면
			m_Back->Setnext(temp);//back노드의 다음 노드로 temp를 저장
			m_Back = temp;//back노드를 temp로 옮김
			m_Back->Setnext(nullptr);//back의 다음 노드는 nullptr
		}
	}
	T dequeue() {//큐에 가장 앞 값 반환, 삭제
		Node<T>* temp = new Node<T>;
		T data = m_Front->Getdata();//가장 앞 값을 data에 저장
		temp = m_Front;//temp에 m_front를 저장
		m_Front = m_Front->Getnext();//m_front를 다음 노드로 옮김
		delete temp;//temp 메모리 해제
		return data;//가장 앞 값 반환
	}
	bool isEmpty() {//큐가 비어있는지 판단하는 함수
		if (m_Front == nullptr)
			return false;//비어있으면 false
		return true;//아니라면 true
	}
	T Front() {//가장 앞 값 반환
		return m_Front->Getdata();
	}
	void print() {
		Node<T>* temp = m_Front;//m_Front노드부터 시작
		if (m_Front == nullptr)//m_Front노드가 nullptr이라면 큐가 비어있음
			cout << "Queue is empty\n";
		else {//아니라면
			while (temp != nullptr) {//nullptr이 아닐 때까지 반복
				cout << temp->Getdata() << endl;//temp의 데이터 출력
				temp = temp->Getnext();//temp를 다음 노드로 옮김
			}
		}
	}
};

int main() {
	Queue<int> que;//int형으로 큐 객체 생성
	string menu;
	while (1) {
		cin >> menu;
		if (menu == "enqueue") {//enqueue command
			int data;
			cin >> data;//데이터를 입력받음
			que.enqueue(data);//큐에 enqueue
		}
		else if (menu == "dequeue") {//dequeue command
			if (que.isEmpty()) {//큐가 비어있지 않다면 실행
				int data = que.dequeue();//가장 앞 데이터 반환, 삭제
				cout << "Value of front is " << data << endl;
			}
			else
				cout << "Queue is empty\n";
		}
		else if (menu == "front") {//front command
			if (que.isEmpty()) {//큐가 비어있지 않다면 실행
				int data = que.Front();//가장 앞 데이터 반환
				cout << "Value of front is " << data << endl;
			}
			else
				cout << "Queue is empty\n";
		}
		else if (menu == "isEmpty") {//isEmpty command
			if (!que.isEmpty())//큐가 비어있다면
				cout << "Queue is empty\n";
			else//큐가 비어있지 않다면
				cout << "Queue is not empty\n";
		}
		else if (menu == "print") {//print command
			que.print();
		}
		else if (menu == "exit") {//exit command
			cout << "Exit the program";
			return 0;
		}
		else {//유효하지 않은 command
			cout << "Invalid input\n";
		}
	}
}