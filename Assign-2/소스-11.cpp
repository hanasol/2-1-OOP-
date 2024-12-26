#include <iostream>
using namespace std;
int strcmp_(const char* str1, const char* str2);
struct node { //��� Ŭ����
	int data;//����� ������
	node* next;//���� ��带 ����Ű�� ������
};
class list {//����Ʈ Ŭ����
private:
	node* head;//�� �� ���
	node* tail;//�� �� ���
public:
	list() {
		head = nullptr;
		tail = nullptr;
	}//��ü ���� �� haed�� tail�� NULL�� �ʱ�ȭ
	void add(int n) {//��带 ���������� �°� �߰��ϴ� �Լ�
		node* temp = new node;//�ӽ� ��� ����
		node* cur = new node;//�߰��� ���
		if (head == nullptr) {//����Ʈ�� ����ִٸ�
			temp->data = n;//temp�� �����͸� n���� �ʱ�ȭ
			head = temp;//head�� temp�� ��
			tail = temp;//head�� tail�� ���� ���(temp)�� ��
			tail->next = nullptr;//tail�� ���� ���� NULL�� ����
		}
		else {//��尡 �Ѱ� �̻� ����
			cur->data = n;//�߰��� ����� ���� n���� �ʱ�ȭ
			temp = head;//�ӽ� ��带 head�� ����(head���� �����Ͽ� �߰�)
			if (temp->data < n) {//���� ���ڰ� head�� �����ͺ��� Ŭ ��
				cur->next = head;//�߰��� ����� ���� ��带 head�� ����
				head = cur;//���� ��带 head�� ����
			}
			else {//���� ���ڰ� head�� �����ͺ��� ���� ��
				while (temp->next != nullptr && temp->next->data >= n) {//���� ��尡 nullptr�� �ƴϰ� ���� ����� ���� ���� ���� ������ ũ�ٸ�
					//temp�� �������� �ű�
					temp = temp->next;
				}//temp�� ���� ������ ��ġ �ٷ� ���� ��尡 ��
				cur->next = temp->next;//���� ����� ���� ��带 temp�� ���� ���� ����(�߰��� �����Ͽ� ���� ���� ����Ʈ�� ����)
				temp->next = cur;//temp�� ���� ��带 �߰��� ���� ����(�߰��� �����Ͽ� ���� ���� ����Ʈ�� ����)
			}
		}
	}
	void deleteNode(int n) {//�Է¹��� ���� ��带 �����ϴ� �Լ�
		node* flag = new node;//������ ����� ���� ��带 ����
		flag = head;//head�� �����Ͽ� �� �պ��� �ݺ�
		while (flag != nullptr) {
			if (flag->next != nullptr && flag->data == n) {//2�� �̻� and �� ���� ���� ��
				head = head->next;//head�� ���� ���� �̵��Ͽ� ����
				delete flag;//�޸�����
				return;
			}
			else if (flag->next != nullptr && flag->next->data == n) {//���Ұ� 2�� �̻��� ��
				node* temp = flag->next;//flag�� ������ ����� ���� ����̹Ƿ� flag->next�� ���� ������ ���, ������ ��带 temp�� ����
				flag->next = temp->next;//���� ����� ���� ��忡 ������ ����� ���� ���� ����
				delete temp;//������ ����� �޸𸮸� ����
				return;
			}
			else if (flag->next == nullptr && flag->data == n) {//���Ұ� 1���� �� 
				head = nullptr;
				tail = nullptr;//���Ұ� 1���� �� �����ϸ� �� ����Ʈ�� �ǹǷ� head�� tail�� ��� NULL�� �ʱ�ȭ
				return;
			}
			flag = flag->next;//flag�� ���� ���� �ű�
		}
	}
	void ShowList(node* head) {//����Ʈ ���
		node* temp = new node;//�ӽ� ��� ����
		if (head == nullptr)//head�� NULL�̶�� �� ����Ʈ
			cout << "����Ʈ�� ����ֽ��ϴ�.";
		else {
			cout << "Linked list : ";
			temp = head;//temp�� head�� ����
			while (temp != nullptr) {//tail���� �ݺ�
				cout << temp->data;//temp�� ������ ���
				if (temp->next != nullptr)//temp�� ������尡 NULL�̶�� temp�� tail�� �ٷ� ���� �����
					cout << "->";//tail �ٷ� �������� ȭ��ǥ ���
				temp = temp->next;//temp�� ���� ���� �̵�
			}
		}
		cout << endl;
	}
	node* GetHead() {
		return head;//����Ʈ�� �� �� ��带 ��ȯ
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
			a.add(n);//n���� ���Ḯ��Ʈ�� �߰�
			a.ShowList(a.GetHead());//head�� ��ȯ�Ͽ� head���� �� ���
		}
		else if (0 == strcmp_(menu, "delete")) {
			cin >> n;
			a.deleteNode(n);//n���� ã�Ƽ� ����
			a.ShowList(a.GetHead());//head���� �� ���
		}
		else if (0 == strcmp_(menu, "exit")) {//���α׷� ����
			cout << "Exit the program";
			delete menu;
			return 0;
		}
		else
			cout << "Invalid input\n";
	}
}
int strcmp_(const char* str1, const char* str2) {//���ڿ��� ������ �����ִ� �Լ�
	int i = 0;
	while (str1[i] != NULL && (str1[i] == str2[i])) {//�� ���ڿ��� ���ڰ� ���� str1�� NULL�� �ƴ϶�� �ݺ�
		i++;
	}
	if (str1[i] - str2[i] == 0)//�� �ƽ�Ű ���� ���̰� 0�̶�� �� ���ڿ��� ����
		return 0;
	else if (str1[i] > str2[i])
		return 1;//str1�� str2���� ���������� �ڸ� 1��ȯ
	else
		return -1;//str1�� str2���� ���������� ���̸� -1��ȯ
}