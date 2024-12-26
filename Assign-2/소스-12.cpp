#include <iostream>
#include <fstream>
using namespace std;
void strcpy_(char* str1, const char* str2);
int strcmp_(const char* str1, const char* str2);
struct node { //노드 구조체
	char data[16];//노드의 문자열, 최대 15자리
	node* next;//다음 노드를 가리키는 포인터
	node* under;//아래 노드를 가리키는 포인터
};
class list {//2차원 리스트 클래스
private:
	node* head[26];//해당 알파벳의 단어들을 저장할 head배열
public:
	list() {
		for (int i = 0; i < 26; i++)
			head[i] = nullptr;
	}//생성자에서 각 행을 초기화
	~list(){ }
	void add(const char* str) {
		int idx = str[0] - 'A';//A=0, B=1...의 배열로 저장
		node* temp = new node;//임시 노드 생성
		strcpy_(temp->data, str);//임시 노드에 문자열 복사
		temp->next = nullptr;//다음 열을 NULL로 초기화
		temp->under = nullptr;//다음 행을 NULL로 초기화
		if (!head[idx]) {//idx행의 배열이 비어있으면
			head[idx] = temp;//임시 노드를 헤드로 설정
		}
		else {
			temp->next = head[idx];
			head[idx] = temp;
		}
	}
	void ShowList() {//2차원 리스트 출력
		int i = 0;
		while (i < 26) {
			if (head[i] != nullptr) {//행이 비어있지 않을 때
				cout << head[i]->data[0] << " : ";//i행의 첫번 째 data의 첫번 째 글자는 대문자 알파벳임
				node* column = head[i];//i행의 head를 column에 저장
				while (column != nullptr) {//열이 비어있지 않을 때까지
					cout << column->data;//해당 열의 데이터 출력
					if (column->next != nullptr)//다음 노드가 비어있지 않다면
						cout << " -> ";//중간에 화살표 출력
					column = column->next;//다음 노드로 이동
				}
				cout << "\n";
			}
			i++;//i증가
		}
	}
	void sort() {//사전순으로 정렬하는 함수
		for (int i = 0; i < 26; i++) {//행 순환
			if (head[i] != nullptr) {//비어있지 않은 행만 수행
				for (int j = 0; j < 26 - i; j++) {
					node* column = head[i];//열을 탐색할 column변수에 i행의 head저장
					while (column->next != nullptr) {//다음 노드가 비어있지 않을 떄까지 반복
						if (strcmp_(column->data, column->next->data) > 0) {//strcmp_의 값이 양수라면 앞의 노드의 데이터가 
							//뒤의 노드의 데이터보다 사전순으로 뒤에있음
							char temp[16];
							strcpy_(temp, column->data);
							strcpy_(column->data, column->next->data);
							strcpy_(column->next->data, temp);//값을 교체하여 사전배열순으로 정렬
						}
						column = column->next;//다음 열의 노드로 이동
					}
				}
			}
		}
	}
};
int main() {
	list Matrix;//list 객체
	ifstream fin;//ifstream 객체
	char temp[16];
	fin.open("Input.dat");//파일 오픈
	while (fin.getline(temp, 16)) {//temp에 한 문장씩 문자열을 저장
		Matrix.add(temp);//받아온 문자열을 매트릭스에 추가
	}
	Matrix.sort();//사전순으로 정렬
	Matrix.ShowList();//리스트 출력
	fin.close();//파일 닫기
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
void strcpy_(char* str1, const char* str2) {//str2의 문자열을 str1에 복사하는 함수
	int i = 0;
	while (str2[i] != NULL) {//str2가 NULL이 아니라면 반복
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0'; // 문자열의 끝에 널 문자를 추가
}
