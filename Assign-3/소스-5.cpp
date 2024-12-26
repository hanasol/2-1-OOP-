#include <iostream>
using namespace std;
int pow_(int num, int exp);
class Term {
private:
	int m_Coefficient;
	int m_Exponent;
	Term* m_pNext;
public:
	Term(){ 
		m_Coefficient = 0;
		m_Exponent = 0;
		m_pNext = nullptr;
	}
	void Setcoe(int coe) {//coe를 저장하는 함수
		m_Coefficient = coe;
	}
	void Setexp(int exp) {//exp를 저장하는 함수
		m_Exponent = exp;
	}
	void Setnext(Term* next) {//next를 저장하는 함수
		m_pNext = next;
	}
	int Getcoe() {//해당 노드의 coe를 반환하는 함수
		return m_Coefficient;
	}
	int Getexp() {//해당 노드의 exp를 반환하는 함수
		return m_Exponent;
	}
	Term* Getnext() {//해당 노드의 다음 노드를 반환하는 함수
		return m_pNext;
	}
	~Term() { }
};
class Polynomial {
private:
	Term* m_pHead;
public:
	Polynomial() {
		m_pHead = nullptr;//객체 생성 시 head를 nullptr로 저장
	}
	~Polynomial(){ }
	void addTerm(int coeff, int exp) {//방정식을 추가하는 함수
		Term* node = new Term;//내가 추가할 노드
		node->Setnext(nullptr);//내가 추가할 노드의 다음 노드는 nullptr
		node->Setcoe(coeff);//입력받은 coe저장
		node->Setexp(exp);//입력받은 exp저장
		if (m_pHead == nullptr) {//리스트가 비어있다면
			m_pHead = node;//head는 temp가 됨
		}
		else {//비어있지 않다면
			Term* ptr = m_pHead;//ptr은 head부터 시작
			while (ptr != nullptr) {//ptr이 nullptr이 아닐 때까지 반복
				if (ptr->Getexp() == exp) {//현재 노드의 차수와 입력받은 차수가 같다면
					int existingcoe = ptr->Getcoe();//현재 노드의 계수를 저장
					ptr->Setcoe(existingcoe + coeff);//현재 노드의 계수+입력받은 계수를 새로운 계수로 저장
					return;//한 노드는 같은 차수이므로 더 추가할 노드가 없음. 따라서 종료
				}
				ptr = ptr->Getnext();
			}
			Term* temp = m_pHead;//temp는 head에서 시작
			while (temp->Getnext() != nullptr) {//다음 노드가 nullptr이 아닐때까지 반복
				temp = temp->Getnext();//다음 노드로 이동
			}//temp가 마지막 노드로 이동됨
			temp->Setnext(node);//temp의 다음 노드로 추가할 노드 저장
		}
	}
	void printPolynomial() {//방정식 출력
		Term* node = m_pHead;//head에서 시작
		while (node != nullptr) {//nullptr이 아닐때까지 반복
			if (node->Getcoe() == 1) {//계수가 1일 때
				if (node->Getexp() == 0)//차수가 0이라면
					cout << "1";//1을 출력
			}//차수가 0이 아니라면 계수는 출력X
			else if (node->Getcoe() == -1) {//계수가 -1일 때
				if (node->Getexp() == 0)//차수가 0이라면
					cout << "-1";//-1 출력
				else
					cout << "-";//차수가 0이 아니라면 -만 출력
			}
			else {//0을 제외한 숫자 출력
				if(node->Getcoe()!=0)//0은 출력X
					cout << node->Getcoe();
			}

			if(node->Getexp()==0){ }//exponent가 0이라면 미지수는 출력X
			else {//차수가 0이 아닐 때
				if (node->Getcoe() != 0)//계수도 0이 아닐 때
					cout << "x^" << node->Getexp();//해당 exponent출력
			}
			if (node->Getnext() != nullptr) {
				if (node->Getcoe() != 0)//계수가 0이 아닐 때
					cout << " + ";//미지수 사이에 +출력
			}
			node = node->Getnext();//다음 노드로 이동
		}
		cout << endl;
	}
	Polynomial operator+(const Polynomial& poly) {//+연산자 오버로딩
		Polynomial newPoly;
		Term* node1 = m_pHead;//1 방정식의 head
		Term* node2 = poly.m_pHead;//2 방정식의 head
		while (node1 != nullptr && node2 != nullptr) {
			if (node1->Getexp() > node2->Getexp()) {//1 방정식의 차수가 2 방정식의 차수보다 크다면
				newPoly.addTerm(node1->Getcoe(), node1->Getexp());//새로운 방정식에 1 방정식의 차수와 계수를 똑같이 저장
				node1 = node1->Getnext();//1 방정식의 노드를 다음으로 옮겨서 차수를 내림
				continue;//다음 반복
			}
			else if (node1->Getexp() < node2->Getexp()) {//1 방정식의 차수가 2 방정식의 차수보다 작다면
				newPoly.addTerm(node2->Getcoe(), node2->Getexp());//새로운 방정식에 2 방정식의 차수와 계수를 똑같이 저장
				node2 = node2->Getnext();//2 방정식의 노드를 다음으로 옮겨서 차수를 내림
				continue;//다음 반복 
			}
			int newCoe = node1->Getcoe() + node2->Getcoe();//차수가 맞춰진 두 방정식의 계수를 더함
			newPoly.addTerm(newCoe, node1->Getexp());//새로운 계수와 차수로 미지수를 만들어 저장
			node1 = node1->Getnext();//1 방정식의 다음 노드로 이동
			node2 = node2->Getnext();//2 방정식의 다음 노드로 이동
		}
		return newPoly;//새로운 방정식 반환
	}
	Polynomial operator-(const Polynomial& poly) {//-연산자 오버로딩
		Polynomial newPoly;
		Term* node1 = m_pHead;//1 방정식의 head
		Term* node2 = poly.m_pHead;//2 방정식의 head
		while (node1 != nullptr && node2 != nullptr) {
			if (node1->Getexp() > node2->Getexp()) {//1 방정식의 차수가 2 방정식의 차수보다 크다면
				newPoly.addTerm(node1->Getcoe(), node1->Getexp());//새로운 방정식에 1 방정식의 차수와 계수를 똑같이 저장
				node1 = node1->Getnext();//1 방정식의 노드를 다음으로 옮겨서 차수를 내림
				continue;//다음 반복
			}
			else if (node1->Getexp() < node2->Getexp()) {//1 방정식의 차수가 2 방정식의 차수보다 작다면
				int neg_coe = -(node2->Getcoe());//1 방정식에서 2 방정식을 빼야하는데, 2 방정식의 차수가 크면 2 방정식의 계수의 부호를 바꾸어서 저장해야함
				newPoly.addTerm(neg_coe, node2->Getexp());//2 방정식의 계수는 부호를 바꾸어서 저장, 차수는 똑같이 저장
				node2 = node2->Getnext();//2 방정식의 노드를 다음으로 옮겨서 차수를 내림
				continue;//다음 반복 
			}
			int newCoe = node1->Getcoe() - node2->Getcoe();//차수가 맞춰진 두 방정식의 계수를 뺌
			newPoly.addTerm(newCoe, node1->Getexp());//새로운 계수와 차수 저장
			node1 = node1->Getnext();//1 방정식의 다음 노드로 이동
			node2 = node2->Getnext();//2 방정식의 다음 노드로 이동
		}
		return newPoly;
	}
	Polynomial differentiation() {//미분
		Polynomial newPoly;
		Term* node = m_pHead;
		while (node != nullptr) {
			if (node->Getexp() == 0) {//해당 노드가 상수라면
				
			}
			else if (node->Getexp() == 1) {//해당 노드의 차수가 1이라면
				newPoly.addTerm(node->Getcoe(), node->Getexp() - 1);//계수는 그대로, 차수만 하나 줄어듦
			}
			else {//해당 노드의 차수가 2 이상이라면
				int newcoe = node->Getcoe() * node->Getexp();//차수와 계수를 곱해서 새로운 계수를 만듦
				newPoly.addTerm(newcoe, node->Getexp() - 1);
			}
			node = node->Getnext();
		}
		return newPoly;
	}
	int calculate(int x) {//x에 대한 계산 값 반환
		int result = 0;
		Term* node = m_pHead;//head부터 반복
		while (node != nullptr) {
			int temp = node->Getcoe();//temp에 node의 계수를 저장
			temp*= pow_(x, node->Getexp());//x^node의 차수를 계산하여 temp에 저장
			result += temp;//result에 temp를 더함
			node = node->Getnext();//다음 노드로 이동
		}
		return result;//각 미지수의 결과값이 합산되어 저장됨
	}
};
int main() {
	Polynomial poly1, poly2, result1, result2;
	poly1.addTerm(-3, 3);
	poly1.addTerm(1, 3);
	poly1.addTerm(2, 1);
	cout << "Polynomial 1: ";
	poly1.printPolynomial();

	poly2.addTerm(-1, 3);
	poly2.addTerm(1, 2);
	poly2.addTerm(-4, 1);
	poly2.addTerm(4, 0);
	cout << "Polynomial 2: ";
	poly2.printPolynomial();

	result1 = poly1 + poly2;//두 객체가 더해지고 소멸자가 호출, 동적 할당을 진행하지 않았으므로 소멸자에서는 아무기능 X. 따라서 대입연산자 오버로딩은 필요 X
	//두 객체가 이미 생성&초기화 된 상태에서 대입하려면 대입 연산자 호출,
	//객체가 새로 생성되는 시점에서 대입하려면 복사 생성자 호출
	result2 = poly1.differentiation();
	cout << "poly1 + poly2: ";
	result1.printPolynomial();
	cout << "differentiation of poly1: ";
	result2.printPolynomial();
}
int pow_(int num, int exp) {//num의 exp제곱 값을 반환하는 함수
	if (exp == 0)//exp가 0이라면
		return 1;//1 반환
	else
		return num * pow_(num, exp - 1);//num^exp=num*num^(exp-1)이므로 pow함수 다시 호출
}