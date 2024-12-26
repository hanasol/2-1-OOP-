#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
private:
	Node<T>* m_left;//���� �ڽ� ���
	Node<T>* m_right;//������ �ڽ� ���
	T m_Data;//������
	int depth;//����, ���� �� ������ 0
public:
	Node() {
		m_left = nullptr;
		m_right = nullptr;
		m_Data = 0;
		depth = 0;
	}
	~Node() { }
	void Setleft(Node<T>* temp) {//m_left�� private ��������̹Ƿ� NodeŬ���� ������ �����Ͽ� ������ �Լ� �ʿ�
		m_left = temp;
	}
	void Setright(Node<T>* temp) {//m_right�� private ��������̹Ƿ� NodeŬ���� ������ �����Ͽ� ������ �Լ� �ʿ�
		m_right = temp;
	}
	void Setdata(T data) {//m_Data�� private ��������̹Ƿ� NodeŬ���� ������ �����Ͽ� ������ �Լ� �ʿ�
		m_Data = data;
	}
	void Setdepth(int dep) {//depth�� private ��������̹Ƿ� NodeŬ���� ������ �����Ͽ� ������ �Լ� �ʿ�
		depth = dep;
	}
	Node<T>* Getleft() {//�ش� ����� ���� �ڽ� ��带 ��ȯ
		return m_left;
	}
	Node<T>* Getright() {//�ش� ����� ������ �ڽ� ��带 ��ȯ
		return m_right;
	}
	T Getdata() {//�ش� ����� ������ ��ȯ
		return m_Data;
	}
	int Getdepth() {//�ش� ����� ���� ��ȯ
		return depth;
	}
};
template <typename T>
class BST {
private:
	Node<T>* m_root;//���� ��, root���
public:
	BST() {
		m_root = nullptr;
	}
	~BST() { }
	void build(T arr[], int start, int end) {
		if (start > end)
			return;
		Node<T>* node = new Node<T>;//���� ������ ���
		Node<T>* temp = nullptr;//���� ������ ����� �θ� ���
		int dep = 0;//�ش� ����� ����
		int mid = (start + end) / 2;//���ڷ� ���޵Ǵ� start�� end�� �߰� ���� mid�� ����
		node->Setdata(arr[mid]);//mid�ε��� �迭�� ���� node�� �����ͷ� ����
		if (m_root == nullptr) {//��Ʈ ��尡 ����ִٸ�
			m_root = node;//��Ʈ���� node
			insert(arr[mid], 0);//mid�ε��� �迭�� ���� ���� ����
			m_root->Setleft(nullptr);//���� �ڽĳ��� nullptr
			m_root->Setright(nullptr);//������ �ڽĳ�嵵 nullptr
		}
		else {//�ƴ϶��
			Node<T>* ptr = m_root;//root���� ��带 ��ȸ�� ptr��� ����
			while (ptr != nullptr) {//ptr�� nullptr�� �ƴҶ����� �ݺ�
				temp = ptr;//temp�� ptr�� �ʱ�ȭ
				if (node->Getdata() < ptr->Getdata())//���� ������ ����� ���� ptr ����� ������ ������
					ptr = ptr->Getleft();//���� ���� �̵�
				else//���� ������ ����� ���� ptr ����� ������ ũ��
					ptr = ptr->Getright();//������ ���� �̵�
				dep++;//���� ����
			}
			node->Setdepth(dep);//���� ����
			if (node->Getdata() < temp->Getdata()) {//���� ����� ���� temp(���� ����� �θ�) ����� ������ ������
				temp->Setleft(node);//temp�� ���� ��忡 node ����
			}
			else {//���� ����� ���� temp ����� ������ ũ�ٸ�
				temp->Setright(node);//temp�� ������ ��忡 node ����
			}
		}
		build(arr, start, mid - 1);//���� ����Ʈ�� ����
		build(arr, mid + 1, end);//������ ����Ʈ�� ����
	}
	void insert(T n, int depth) {
		m_root->Setdata(n);//���ڷ� ���޹��� �����͸� ��Ʈ ����� �����ͷ� ����
		m_root->Setdepth(depth);//���ڷ� ���޹��� ���̸� ��Ʈ ����� ���̷� ����
	}
	void printTree(Node<T>* node) {
		if (node == nullptr)//�ش� ��尡 nullptr�̶�� �Լ� ����
			return;
		printTree(node->Getright());//�����ʺ��� ���
		for (int i = 0; i < node->Getdepth(); i++)
			cout << "	";//����*3��ŭ ���� ���
		cout << node->Getdata() << endl;//����� ������ ���
		if (node->Getleft() == nullptr && node->Getright() != nullptr) {//���� �ڽ� ��常 ���� ��
			for (int i = 0; i < node->Getdepth() + 1; i++)
				cout << "	";//(�θ� ����� ����+1)*3 ��ŭ ���� ���
			cout << "  " << endl;//����ִ� ��带 ���� 2ĭ���� ��ü�Ͽ� ���
		}
		else if (node->Getleft() != nullptr && node->Getright() == nullptr) {//������ �ڽ� ��常 ���� ��
			for (int i = 0; i < node->Getdepth() + 1; i++)
				cout << "	";//(�θ� ����� ����+1)*3 ��ŭ ��ĭ ���
			cout << "  " << endl;//����ִ� ��带 ���� 2ĭ���� ��ü�Ͽ� ���
		}
		printTree(node->Getleft());//���� ���
	}
	Node<T>* Gethead() {//root��带 ��ȯ�ϴ� �Լ�
		return m_root;
	}
};
int main() {
	char* temp=new char[300];//������ �Է¹��� ���ڿ� �޸� �Ҵ�
	int arr[100];//10~99 ������ ������ ���� �� ����
	int i = 0;//Ʈ���� ���� ����
	cout << "input array = ";
	cin.getline(temp, 300);//getline�� ���ؼ� ������� �Է¹���
	char* data = strtok(temp, " ");//ù ������ ��ĭ���� �����Ͽ� data�� ����
	while (data != nullptr) {//data�� nullptr�� �ƴ� ������ �ݺ�
		arr[i] = stoi(data);//������ ��ȯ�� �迭�� ����
		data = strtok(NULL, " ");//���� ������ ��ĭ���� �����Ͽ� data�� ����
		i++;//���� ���� ����
	}
	BST<int> bst;//int�� Ʈ�� ��ü ����
	bst.build(arr, 0, i-1);//Ʈ�� ����
	bst.printTree(bst.Gethead());//Ʈ�� ���
	delete[] temp;//�޸� ����
}