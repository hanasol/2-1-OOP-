#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
private:
	Node<T>* m_left;//왼쪽 자식 노드
	Node<T>* m_right;//오른쪽 자식 노드
	T m_Data;//데이터
	int depth;//깊이, 가장 위 노드부터 0
public:
	Node() {
		m_left = nullptr;
		m_right = nullptr;
		m_Data = 0;
		depth = 0;
	}
	~Node() { }
	void Setleft(Node<T>* temp) {//m_left가 private 멤버변수이므로 Node클래스 내에서 접근하여 저장할 함수 필요
		m_left = temp;
	}
	void Setright(Node<T>* temp) {//m_right가 private 멤버변수이므로 Node클래스 내에서 접근하여 저장할 함수 필요
		m_right = temp;
	}
	void Setdata(T data) {//m_Data가 private 멤버변수이므로 Node클래스 내에서 접근하여 저장할 함수 필요
		m_Data = data;
	}
	void Setdepth(int dep) {//depth가 private 멤버변수이므로 Node클래스 내에서 접근하여 저장할 함수 필요
		depth = dep;
	}
	Node<T>* Getleft() {//해당 노드의 왼쪽 자식 노드를 반환
		return m_left;
	}
	Node<T>* Getright() {//해당 노드의 오른쪽 자식 노드를 반환
		return m_right;
	}
	T Getdata() {//해당 노드의 데이터 반환
		return m_Data;
	}
	int Getdepth() {//해당 노드의 깊이 반환
		return depth;
	}
};
template <typename T>
class BST {
private:
	Node<T>* m_root;//가장 위, root노드
public:
	BST() {
		m_root = nullptr;
	}
	~BST() { }
	void build(T arr[], int start, int end) {
		if (start > end)
			return;
		Node<T>* node = new Node<T>;//내가 저장할 노드
		Node<T>* temp = nullptr;//내가 저장할 노드의 부모 노드
		int dep = 0;//해당 노드의 깊이
		int mid = (start + end) / 2;//인자로 전달되는 start와 end의 중간 값을 mid로 저장
		node->Setdata(arr[mid]);//mid인덱스 배열의 값을 node의 데이터로 저장
		if (m_root == nullptr) {//루트 노드가 비어있다면
			m_root = node;//루트노드는 node
			insert(arr[mid], 0);//mid인덱스 배열의 값과 깊이 저장
			m_root->Setleft(nullptr);//왼쪽 자식노드는 nullptr
			m_root->Setright(nullptr);//오른쪽 자식노드도 nullptr
		}
		else {//아니라면
			Node<T>* ptr = m_root;//root부터 노드를 순회할 ptr노드 선언
			while (ptr != nullptr) {//ptr이 nullptr이 아닐때까지 반복
				temp = ptr;//temp를 ptr로 초기화
				if (node->Getdata() < ptr->Getdata())//내가 저장할 노드의 값이 ptr 노드의 값보다 작으면
					ptr = ptr->Getleft();//왼쪽 노드로 이동
				else//내가 저장할 노드의 값이 ptr 노드의 값보다 크면
					ptr = ptr->Getright();//오른쪽 노드로 이동
				dep++;//깊이 증가
			}
			node->Setdepth(dep);//깊이 저장
			if (node->Getdata() < temp->Getdata()) {//현재 노드의 값이 temp(현재 노드의 부모) 노드의 값보다 작으면
				temp->Setleft(node);//temp의 왼쪽 노드에 node 저장
			}
			else {//현재 노드의 값이 temp 노드의 값보다 크다면
				temp->Setright(node);//temp의 오른쪽 노드에 node 저장
			}
		}
		build(arr, start, mid - 1);//왼쪽 서브트리 구성
		build(arr, mid + 1, end);//오른쪽 서브트리 구성
	}
	void insert(T n, int depth) {
		m_root->Setdata(n);//인자로 전달받은 데이터를 루트 노드의 데이터로 저장
		m_root->Setdepth(depth);//인자로 전달받은 깊이를 루트 노드의 깊이로 저장
	}
	void printTree(Node<T>* node) {
		if (node == nullptr)//해당 노드가 nullptr이라면 함수 종료
			return;
		printTree(node->Getright());//오른쪽부터 출력
		for (int i = 0; i < node->Getdepth(); i++)
			cout << "	";//깊이*3만큼 공백 출력
		cout << node->Getdata() << endl;//노드의 데이터 출력
		if (node->Getleft() == nullptr && node->Getright() != nullptr) {//왼쪽 자식 노드만 없을 때
			for (int i = 0; i < node->Getdepth() + 1; i++)
				cout << "	";//(부모 노드의 깊이+1)*3 만큼 공백 출력
			cout << "  " << endl;//비어있는 노드를 공백 2칸으로 대체하여 출력
		}
		else if (node->Getleft() != nullptr && node->Getright() == nullptr) {//오른쪽 자식 노드만 없을 때
			for (int i = 0; i < node->Getdepth() + 1; i++)
				cout << "	";//(부모 노드의 깊이+1)*3 만큼 빈칸 출력
			cout << "  " << endl;//비어있는 노드를 공백 2칸으로 대체하여 출력
		}
		printTree(node->Getleft());//왼쪽 출력
	}
	Node<T>* Gethead() {//root노드를 반환하는 함수
		return m_root;
	}
};
int main() {
	char* temp=new char[300];//정수를 입력받을 문자열 메모리 할당
	int arr[100];//10~99 사이의 정수가 들어올 수 있음
	int i = 0;//트리의 원소 개수
	cout << "input array = ";
	cin.getline(temp, 300);//getline을 통해서 공백까지 입력받음
	char* data = strtok(temp, " ");//첫 정수를 빈칸으로 구분하여 data에 저장
	while (data != nullptr) {//data가 nullptr이 아닐 때까지 반복
		arr[i] = stoi(data);//정수로 변환후 배열에 저장
		data = strtok(NULL, " ");//다음 정수를 빈칸으로 구분하여 data에 저장
		i++;//원소 개수 증가
	}
	BST<int> bst;//int형 트리 객체 생성
	bst.build(arr, 0, i-1);//트리 세팅
	bst.printTree(bst.Gethead());//트리 출력
	delete[] temp;//메모리 해제
}