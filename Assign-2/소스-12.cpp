#include <iostream>
#include <fstream>
using namespace std;
void strcpy_(char* str1, const char* str2);
int strcmp_(const char* str1, const char* str2);
struct node { //��� ����ü
	char data[16];//����� ���ڿ�, �ִ� 15�ڸ�
	node* next;//���� ��带 ����Ű�� ������
	node* under;//�Ʒ� ��带 ����Ű�� ������
};
class list {//2���� ����Ʈ Ŭ����
private:
	node* head[26];//�ش� ���ĺ��� �ܾ���� ������ head�迭
public:
	list() {
		for (int i = 0; i < 26; i++)
			head[i] = nullptr;
	}//�����ڿ��� �� ���� �ʱ�ȭ
	~list(){ }
	void add(const char* str) {
		int idx = str[0] - 'A';//A=0, B=1...�� �迭�� ����
		node* temp = new node;//�ӽ� ��� ����
		strcpy_(temp->data, str);//�ӽ� ��忡 ���ڿ� ����
		temp->next = nullptr;//���� ���� NULL�� �ʱ�ȭ
		temp->under = nullptr;//���� ���� NULL�� �ʱ�ȭ
		if (!head[idx]) {//idx���� �迭�� ���������
			head[idx] = temp;//�ӽ� ��带 ���� ����
		}
		else {
			temp->next = head[idx];
			head[idx] = temp;
		}
	}
	void ShowList() {//2���� ����Ʈ ���
		int i = 0;
		while (i < 26) {
			if (head[i] != nullptr) {//���� ������� ���� ��
				cout << head[i]->data[0] << " : ";//i���� ù�� ° data�� ù�� ° ���ڴ� �빮�� ���ĺ���
				node* column = head[i];//i���� head�� column�� ����
				while (column != nullptr) {//���� ������� ���� ������
					cout << column->data;//�ش� ���� ������ ���
					if (column->next != nullptr)//���� ��尡 ������� �ʴٸ�
						cout << " -> ";//�߰��� ȭ��ǥ ���
					column = column->next;//���� ���� �̵�
				}
				cout << "\n";
			}
			i++;//i����
		}
	}
	void sort() {//���������� �����ϴ� �Լ�
		for (int i = 0; i < 26; i++) {//�� ��ȯ
			if (head[i] != nullptr) {//������� ���� �ุ ����
				for (int j = 0; j < 26 - i; j++) {
					node* column = head[i];//���� Ž���� column������ i���� head����
					while (column->next != nullptr) {//���� ��尡 ������� ���� ������ �ݺ�
						if (strcmp_(column->data, column->next->data) > 0) {//strcmp_�� ���� ������ ���� ����� �����Ͱ� 
							//���� ����� �����ͺ��� ���������� �ڿ�����
							char temp[16];
							strcpy_(temp, column->data);
							strcpy_(column->data, column->next->data);
							strcpy_(column->next->data, temp);//���� ��ü�Ͽ� �����迭������ ����
						}
						column = column->next;//���� ���� ���� �̵�
					}
				}
			}
		}
	}
};
int main() {
	list Matrix;//list ��ü
	ifstream fin;//ifstream ��ü
	char temp[16];
	fin.open("Input.dat");//���� ����
	while (fin.getline(temp, 16)) {//temp�� �� ���徿 ���ڿ��� ����
		Matrix.add(temp);//�޾ƿ� ���ڿ��� ��Ʈ������ �߰�
	}
	Matrix.sort();//���������� ����
	Matrix.ShowList();//����Ʈ ���
	fin.close();//���� �ݱ�
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
void strcpy_(char* str1, const char* str2) {//str2�� ���ڿ��� str1�� �����ϴ� �Լ�
	int i = 0;
	while (str2[i] != NULL) {//str2�� NULL�� �ƴ϶�� �ݺ�
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0'; // ���ڿ��� ���� �� ���ڸ� �߰�
}
