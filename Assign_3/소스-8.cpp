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
	void Setdata(T data) {//data�� private ��� �����̹Ƿ� Node Ŭ���������� �����Ͽ� data�� ������ �Լ��� �ʿ���
		m_Data = data;
	}
	void Setnext(Node* next) {//m_next���� private ��� �����̹Ƿ� Node Ŭ���������� �����Ͽ� next ��带 ������ �Լ��� �ʿ�
		m_next = next;
	}
	T Getdata() {//�ش� ����� data�� ��ȯ�ϴ� �Լ�
		return m_Data;
	}
	Node* Getnext() {//���� ��带 ��ȯ�ϴ� �Լ�
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
	void enqueue(T data) {//ť�� �� ����
		Node<T>* temp = new Node<T>;//���� ������ ���
		temp->Setdata(data);
		if (m_Front == nullptr) {//ť�� ����ִٸ�
			m_Front = temp;
			m_Back = temp;//front, back ��� temp�� �ʱ�ȭ
			m_Back->Setnext(nullptr);//back�� ���� ���� nullptr
		}
		else {//ť�� ������� �ʴٸ�
			m_Back->Setnext(temp);//back����� ���� ���� temp�� ����
			m_Back = temp;//back��带 temp�� �ű�
			m_Back->Setnext(nullptr);//back�� ���� ���� nullptr
		}
	}
	T dequeue() {//ť�� ���� �� �� ��ȯ, ����
		Node<T>* temp = new Node<T>;
		T data = m_Front->Getdata();//���� �� ���� data�� ����
		temp = m_Front;//temp�� m_front�� ����
		m_Front = m_Front->Getnext();//m_front�� ���� ���� �ű�
		delete temp;//temp �޸� ����
		return data;//���� �� �� ��ȯ
	}
	bool isEmpty() {//ť�� ����ִ��� �Ǵ��ϴ� �Լ�
		if (m_Front == nullptr)
			return false;//��������� false
		return true;//�ƴ϶�� true
	}
	T Front() {//���� �� �� ��ȯ
		return m_Front->Getdata();
	}
	void print() {
		Node<T>* temp = m_Front;//m_Front������ ����
		if (m_Front == nullptr)//m_Front��尡 nullptr�̶�� ť�� �������
			cout << "Queue is empty\n";
		else {//�ƴ϶��
			while (temp != nullptr) {//nullptr�� �ƴ� ������ �ݺ�
				cout << temp->Getdata() << endl;//temp�� ������ ���
				temp = temp->Getnext();//temp�� ���� ���� �ű�
			}
		}
	}
};

int main() {
	Queue<int> que;//int������ ť ��ü ����
	string menu;
	while (1) {
		cin >> menu;
		if (menu == "enqueue") {//enqueue command
			int data;
			cin >> data;//�����͸� �Է¹���
			que.enqueue(data);//ť�� enqueue
		}
		else if (menu == "dequeue") {//dequeue command
			if (que.isEmpty()) {//ť�� ������� �ʴٸ� ����
				int data = que.dequeue();//���� �� ������ ��ȯ, ����
				cout << "Value of front is " << data << endl;
			}
			else
				cout << "Queue is empty\n";
		}
		else if (menu == "front") {//front command
			if (que.isEmpty()) {//ť�� ������� �ʴٸ� ����
				int data = que.Front();//���� �� ������ ��ȯ
				cout << "Value of front is " << data << endl;
			}
			else
				cout << "Queue is empty\n";
		}
		else if (menu == "isEmpty") {//isEmpty command
			if (!que.isEmpty())//ť�� ����ִٸ�
				cout << "Queue is empty\n";
			else//ť�� ������� �ʴٸ�
				cout << "Queue is not empty\n";
		}
		else if (menu == "print") {//print command
			que.print();
		}
		else if (menu == "exit") {//exit command
			cout << "Exit the program";
			return 0;
		}
		else {//��ȿ���� ���� command
			cout << "Invalid input\n";
		}
	}
}