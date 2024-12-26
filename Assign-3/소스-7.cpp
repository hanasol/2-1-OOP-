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
	void Setnext(Node<T>* nextValue) {//��� ������ next�� private���� ����Ǿ������Ƿ� NodeŬ���� ������ �����ؾ���
		m_next = nextValue;//���ڷ� ���� ��带 next���� ����
	}
	void Setdata(T data) {//data���� private���� ����Ǿ� �����Ƿ� Node Ŭ���� ������ �����ؾ���
		m_Data = data;
	}
	Node* Getnext() {//���� ��带 ��ȯ�ϴ� �Լ�
		return m_next;
	}
	T Getdata() {//�ش� ����� data�� ��ȯ�ϴ� �Լ�
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
	void push(T data){//���ÿ� ���� push
		Node<T>* temp = new Node<T>;//�߰��� ���
		temp->Setnext(nullptr);
		temp->Setdata(data);
		if (m_Top == nullptr) {//������ ���������
			m_Top = temp;
		}
		else {//�ϳ� �̻� ���Ұ� �ִٸ�
			temp->Setnext(m_Top);//temp�� ���� ���� Top
			m_Top = temp;//Top��带 temp�� �ű�
		}
	}
	T pop() {//���ÿ��� ���� pop
		Node<T>* temp = new Node<T>;//������ ���
		T data_top = m_Top->Getdata();//Top����� data�� ����
		temp = m_Top;//temp�� Top��� ����
		m_Top = m_Top->Getnext();//Top��带 �������� �ű�
		delete temp;//temp �޸� ����
		return data_top;//���� Top����� data��ȯ
	}
	bool isEmpty() {
		if (m_Top == nullptr)//Top��尡 nullptr�̶�� ������ �������
			return false;//��������� flase
		return true;//�ƴϸ� true
	}
	T top() {//���� �� �� ��ȯ
		return m_Top->Getdata();
	}
	Node<T>* GetHead() {//Head ��ȯ
		return m_Top;
	}
	void print() {
		Node<T>* temp = GetHead();//temp�� head���� ����
		if (temp == nullptr) {
			cout << "Stack is empty\n";
			return;
		}
		while (temp != nullptr) {//temp�� ������� ������ ���� �ݺ�
			cout << temp->Getdata() << endl;
			temp = temp->Getnext();//���� ���� temp�� �ű�
		}
	}
};
int main() {
	string menu;
	Stack<double> stk;//int������ Ŭ���� ����
	while (1) {
		cin >> menu;
		if (menu == "push") {//push command
			double ele;
			cin >> ele;//push�� �� �Է�
			stk.push(ele);//�� push
		}
		else if (menu == "pop") {//pop command
			if (stk.isEmpty()) {//������ ������� �ʴٸ�
				double value_pop = stk.pop();//pop, ���� �� �� ��ȯ, ����
				cout << "removed value is " << value_pop << endl;
			}
			else//������ ����ִٸ�
				cout << "Stack is empty\n";
		}
		else if (menu == "top") {//top command
			if (stk.isEmpty()) {//������ ������� �ʴٸ�
				double value_top = stk.top();//top, ���� �� �� ��ȯ
				cout << "Value of top is " << value_top << endl;
			}
			else//������ ����ִٸ�
				cout << "Stack is empty\n";
		}
		else if (menu == "isEmpty") {//isEmpty command
			if (!stk.isEmpty())//������ ����ִٸ�
				cout << "Stack is empty\n";
			else//������ ��������ʴٸ�
				cout << "Stack is not empty\n";
		}
		else if (menu == "print") {//print command
			if (stk.isEmpty())//������ ������� �ʴٸ�
				stk.print();//������ �� ���
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