#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
private:
	Node* m_next;
	T m_Data;
public:
	Node() { 
		m_next = nullptr;
		m_Data = 0;
	}
	void Setnext(Node<T>* nextValue) {//멤버 변수인 next가 private으로 선언되어있으므로 Node클래스 내에서 접근해야함
		m_next = nextValue;//인자로 받은 노드를 next노드로 저장
	}
	void Setdata(T data) {//data또한 private으로 선언되어 있으므로 Node 클래스 내에서 접근해야함
		m_Data = data;
	}
	Node* Getnext() {//다음 노드를 반환하는 함수
		return m_next;
	}
	T Getdata() {//해당 노드의 data를 반환하는 함수
		return m_Data;
	}
	~Node() { }
};
template <typename T>
class Stack {
private:
	Node<T>* m_Top;
	Node<T>* m_Bot;
public:
	Stack() {
		m_Top = nullptr;
	}
	~Stack(){ }
	void push(T data){//스택에 값을 push
		Node<T>* temp = new Node<T>;//추가할 노드
		temp->Setnext(nullptr);
		temp->Setdata(data);
		if (m_Top == nullptr) {//스택이 비어있으면
			m_Top = temp;
		}
		else {//하나 이상 원소가 있다면
			temp->Setnext(m_Top);//temp의 다음 노드는 Top
			m_Top = temp;//Top노드를 temp로 옮김
		}
	}
	T pop() {//스택에서 값을 pop
		Node<T>* temp = new Node<T>;//삭제할 노드
		T data_top = m_Top->Getdata();//Top노드의 data를 저장
		temp = m_Top;//temp에 Top노드 저장
		m_Top = m_Top->Getnext();//Top노드를 다음으로 옮김
		delete temp;//temp 메모리 해제
		return data_top;//이전 Top노드의 data반환
	}
	bool isEmpty() {
		if (m_Top == nullptr)//Top노드가 nullptr이라면 스택이 비어있음
			return false;//비어있으면 flase
		return true;//아니면 true
	}
	T top() {//가장 위 값 반환
		return m_Top->Getdata();
	}
	Node<T>* GetHead() {//Head 반환
		return m_Top;
	}
	void print() {
		Node<T>* temp = GetHead();//temp는 head부터 시작
		if (temp == nullptr) {
			cout << "Stack is empty\n";
			return;
		}
		while (temp != nullptr) {//temp가 비어있지 않을때 까지 반복
			cout << temp->Getdata() << endl;
			temp = temp->Getnext();//다음 노드로 temp를 옮김
		}
	}
};
int main() {
	string menu;
	Stack<double> stk;//int형으로 클래스 생성
	while (1) {
		cin >> menu;
		if (menu == "push") {//push command
			double ele;
			cin >> ele;//push할 값 입력
			stk.push(ele);//값 push
		}
		else if (menu == "pop") {//pop command
			if (stk.isEmpty()) {//스택이 비어있지 않다면
				double value_pop = stk.pop();//pop, 가장 위 값 반환, 삭제
				cout << "removed value is " << value_pop << endl;
			}
			else//스택이 비어있다면
				cout << "Stack is empty\n";
		}
		else if (menu == "top") {//top command
			if (stk.isEmpty()) {//스택이 비어있지 않다면
				double value_top = stk.top();//top, 가장 위 값 반환
				cout << "Value of top is " << value_top << endl;
			}
			else//스택이 비어있다면
				cout << "Stack is empty\n";
		}
		else if (menu == "isEmpty") {//isEmpty command
			if (!stk.isEmpty())//스택이 비어있다면
				cout << "Stack is empty\n";
			else//스택이 비어있지않다면
				cout << "Stack is not empty\n";
		}
		else if (menu == "print") {//print command
			if (stk.isEmpty())//스택이 비어있지 않다면
				stk.print();//스택의 값 출력
			else
				cout << "Stack is empty\n";
		}
		else if (menu == "exit") {//exit command
			cout << "Exit the program\n";
			return 0;
		}
		else
			cout << "Invalid input\n";
	}
}