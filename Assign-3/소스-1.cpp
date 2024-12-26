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
	int cnt;//����Ʈ�� ����� ����
public:
	List() : cnt(0) {
		head = nullptr;
		tail = nullptr;
	}
	void addValue(int data) {
		node* temp = new node;//�߰��� ���
		temp->data = data;//�߰��� ����� ������ ����
		temp->next = nullptr;
		if (head == nullptr) {//����Ʈ�� ������� ��
			head = temp;
			tail = temp;//head�� tail�� temp�� ����
			tail->next = nullptr;//tail�� ���� ���� nullptr
			head->idx = tail->idx = 0;//head�� tail�� index�� 0
			cnt++;//����Ʈ�� ��� ���� ����
		}
		else {//����Ʈ�� 1�� �̻��� ��尡 ���� ��
			tail->next = temp;//tail�� ���� ���� temp�� ����
			tail = temp;//tail�� temp�� �ű�
			tail->idx = cnt;//tail�� index�� ���� ����� ����
			cnt++;//����� ���� ����
		}
		if (cnt == 10) {//����Ʈ�� 10���� �� á�ٸ�
			tail->next = head;//tail�� ���� ��带 head�� �̾���
		}
	}
	node* Gethead() {//head�� ��ȯ
		return head;
	}
	void print() {
		node* temp = head;//temp�� head ������ ����
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != nullptr && temp != head);//�ش� ��尡 nullptr�� �ƴϰ� head�� �ƴϸ� �ݺ�
		cout << endl;
	}
	void transfer(int a, int b) {//b �ε����� ���� a �ε����� ������ �����ϴ� �Լ�
		node* temp = head;//head���� ��ȸ
		if (a != b) {
			while (temp->idx != a)
				temp = temp->next;//a �ε������� �̵�
			int data = temp->data;//a �ε����� ���� ����
			while (temp->idx != b) {//b �ε������� �̵��ϴ� ����
				srand(time(NULL));
				int flag = rand() % 10;//0~9�� random number generation
				if (flag == 0) {//0~9 �߿��� 0�� ������ ������ ����: 1/10->10%Ȯ��
					cout << "Detected a disconnection between " << temp->idx << " and " << temp->next->idx << endl;
					temp->next = nullptr;//�ش� ����� ���� ��带 nullptr�� �����Ͽ� ������ ����
					return;//�Լ� ����
				}
				temp = temp->next;//10%�� Ȯ���� ������ ������ ������ ���� ���� �̵�
			}
			temp->data = data;//temp�� b �ε������� �̵������Ƿ� �ش� ����� �����͸� a �ε����� �����ͷ� �ٲ���
		}
		else
			return;
	}
};
int main() {
	int arr[10] = { 0, };//�ʱ�ȭ �� ���� ������ �迭
	char menu[20];
	List list;//���Ḯ��Ʈ ��ü ����
	while (1) {
		cin >> menu;
		if (0== strcmp(menu,"initialize")) {//initialize command
			for (int i = 0; i < 10; i++) {
				cin >> arr[i];//10���� ����Ʈ ���� �Է�
				list.addValue(arr[i]);//����Ʈ�� �߰�
			}
		}
		else if (0 == strcmp(menu, "transfer")) {//transfer command
			int a, b;//�ű� �ε���
			char temp[20];
			cin >> a >> temp >>b;//to�� �Է¹ޱ⸸ �ϰ� ���X
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