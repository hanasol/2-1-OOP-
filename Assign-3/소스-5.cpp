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
	void Setcoe(int coe) {//coe�� �����ϴ� �Լ�
		m_Coefficient = coe;
	}
	void Setexp(int exp) {//exp�� �����ϴ� �Լ�
		m_Exponent = exp;
	}
	void Setnext(Term* next) {//next�� �����ϴ� �Լ�
		m_pNext = next;
	}
	int Getcoe() {//�ش� ����� coe�� ��ȯ�ϴ� �Լ�
		return m_Coefficient;
	}
	int Getexp() {//�ش� ����� exp�� ��ȯ�ϴ� �Լ�
		return m_Exponent;
	}
	Term* Getnext() {//�ش� ����� ���� ��带 ��ȯ�ϴ� �Լ�
		return m_pNext;
	}
	~Term() { }
};
class Polynomial {
private:
	Term* m_pHead;
public:
	Polynomial() {
		m_pHead = nullptr;//��ü ���� �� head�� nullptr�� ����
	}
	~Polynomial(){ }
	void addTerm(int coeff, int exp) {//�������� �߰��ϴ� �Լ�
		Term* node = new Term;//���� �߰��� ���
		node->Setnext(nullptr);//���� �߰��� ����� ���� ���� nullptr
		node->Setcoe(coeff);//�Է¹��� coe����
		node->Setexp(exp);//�Է¹��� exp����
		if (m_pHead == nullptr) {//����Ʈ�� ����ִٸ�
			m_pHead = node;//head�� temp�� ��
		}
		else {//������� �ʴٸ�
			Term* ptr = m_pHead;//ptr�� head���� ����
			while (ptr != nullptr) {//ptr�� nullptr�� �ƴ� ������ �ݺ�
				if (ptr->Getexp() == exp) {//���� ����� ������ �Է¹��� ������ ���ٸ�
					int existingcoe = ptr->Getcoe();//���� ����� ����� ����
					ptr->Setcoe(existingcoe + coeff);//���� ����� ���+�Է¹��� ����� ���ο� ����� ����
					return;//�� ���� ���� �����̹Ƿ� �� �߰��� ��尡 ����. ���� ����
				}
				ptr = ptr->Getnext();
			}
			Term* temp = m_pHead;//temp�� head���� ����
			while (temp->Getnext() != nullptr) {//���� ��尡 nullptr�� �ƴҶ����� �ݺ�
				temp = temp->Getnext();//���� ���� �̵�
			}//temp�� ������ ���� �̵���
			temp->Setnext(node);//temp�� ���� ���� �߰��� ��� ����
		}
	}
	void printPolynomial() {//������ ���
		Term* node = m_pHead;//head���� ����
		while (node != nullptr) {//nullptr�� �ƴҶ����� �ݺ�
			if (node->Getcoe() == 1) {//����� 1�� ��
				if (node->Getexp() == 0)//������ 0�̶��
					cout << "1";//1�� ���
			}//������ 0�� �ƴ϶�� ����� ���X
			else if (node->Getcoe() == -1) {//����� -1�� ��
				if (node->Getexp() == 0)//������ 0�̶��
					cout << "-1";//-1 ���
				else
					cout << "-";//������ 0�� �ƴ϶�� -�� ���
			}
			else {//0�� ������ ���� ���
				if(node->Getcoe()!=0)//0�� ���X
					cout << node->Getcoe();
			}

			if(node->Getexp()==0){ }//exponent�� 0�̶�� �������� ���X
			else {//������ 0�� �ƴ� ��
				if (node->Getcoe() != 0)//����� 0�� �ƴ� ��
					cout << "x^" << node->Getexp();//�ش� exponent���
			}
			if (node->Getnext() != nullptr) {
				if (node->Getcoe() != 0)//����� 0�� �ƴ� ��
					cout << " + ";//������ ���̿� +���
			}
			node = node->Getnext();//���� ���� �̵�
		}
		cout << endl;
	}
	Polynomial operator+(const Polynomial& poly) {//+������ �����ε�
		Polynomial newPoly;
		Term* node1 = m_pHead;//1 �������� head
		Term* node2 = poly.m_pHead;//2 �������� head
		while (node1 != nullptr && node2 != nullptr) {
			if (node1->Getexp() > node2->Getexp()) {//1 �������� ������ 2 �������� �������� ũ�ٸ�
				newPoly.addTerm(node1->Getcoe(), node1->Getexp());//���ο� �����Ŀ� 1 �������� ������ ����� �Ȱ��� ����
				node1 = node1->Getnext();//1 �������� ��带 �������� �Űܼ� ������ ����
				continue;//���� �ݺ�
			}
			else if (node1->Getexp() < node2->Getexp()) {//1 �������� ������ 2 �������� �������� �۴ٸ�
				newPoly.addTerm(node2->Getcoe(), node2->Getexp());//���ο� �����Ŀ� 2 �������� ������ ����� �Ȱ��� ����
				node2 = node2->Getnext();//2 �������� ��带 �������� �Űܼ� ������ ����
				continue;//���� �ݺ� 
			}
			int newCoe = node1->Getcoe() + node2->Getcoe();//������ ������ �� �������� ����� ����
			newPoly.addTerm(newCoe, node1->Getexp());//���ο� ����� ������ �������� ����� ����
			node1 = node1->Getnext();//1 �������� ���� ���� �̵�
			node2 = node2->Getnext();//2 �������� ���� ���� �̵�
		}
		return newPoly;//���ο� ������ ��ȯ
	}
	Polynomial operator-(const Polynomial& poly) {//-������ �����ε�
		Polynomial newPoly;
		Term* node1 = m_pHead;//1 �������� head
		Term* node2 = poly.m_pHead;//2 �������� head
		while (node1 != nullptr && node2 != nullptr) {
			if (node1->Getexp() > node2->Getexp()) {//1 �������� ������ 2 �������� �������� ũ�ٸ�
				newPoly.addTerm(node1->Getcoe(), node1->Getexp());//���ο� �����Ŀ� 1 �������� ������ ����� �Ȱ��� ����
				node1 = node1->Getnext();//1 �������� ��带 �������� �Űܼ� ������ ����
				continue;//���� �ݺ�
			}
			else if (node1->Getexp() < node2->Getexp()) {//1 �������� ������ 2 �������� �������� �۴ٸ�
				int neg_coe = -(node2->Getcoe());//1 �����Ŀ��� 2 �������� �����ϴµ�, 2 �������� ������ ũ�� 2 �������� ����� ��ȣ�� �ٲپ �����ؾ���
				newPoly.addTerm(neg_coe, node2->Getexp());//2 �������� ����� ��ȣ�� �ٲپ ����, ������ �Ȱ��� ����
				node2 = node2->Getnext();//2 �������� ��带 �������� �Űܼ� ������ ����
				continue;//���� �ݺ� 
			}
			int newCoe = node1->Getcoe() - node2->Getcoe();//������ ������ �� �������� ����� ��
			newPoly.addTerm(newCoe, node1->Getexp());//���ο� ����� ���� ����
			node1 = node1->Getnext();//1 �������� ���� ���� �̵�
			node2 = node2->Getnext();//2 �������� ���� ���� �̵�
		}
		return newPoly;
	}
	Polynomial differentiation() {//�̺�
		Polynomial newPoly;
		Term* node = m_pHead;
		while (node != nullptr) {
			if (node->Getexp() == 0) {//�ش� ��尡 ������
				
			}
			else if (node->Getexp() == 1) {//�ش� ����� ������ 1�̶��
				newPoly.addTerm(node->Getcoe(), node->Getexp() - 1);//����� �״��, ������ �ϳ� �پ��
			}
			else {//�ش� ����� ������ 2 �̻��̶��
				int newcoe = node->Getcoe() * node->Getexp();//������ ����� ���ؼ� ���ο� ����� ����
				newPoly.addTerm(newcoe, node->Getexp() - 1);
			}
			node = node->Getnext();
		}
		return newPoly;
	}
	int calculate(int x) {//x�� ���� ��� �� ��ȯ
		int result = 0;
		Term* node = m_pHead;//head���� �ݺ�
		while (node != nullptr) {
			int temp = node->Getcoe();//temp�� node�� ����� ����
			temp*= pow_(x, node->Getexp());//x^node�� ������ ����Ͽ� temp�� ����
			result += temp;//result�� temp�� ����
			node = node->Getnext();//���� ���� �̵�
		}
		return result;//�� �������� ������� �ջ�Ǿ� �����
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

	result1 = poly1 + poly2;//�� ��ü�� �������� �Ҹ��ڰ� ȣ��, ���� �Ҵ��� �������� �ʾ����Ƿ� �Ҹ��ڿ����� �ƹ���� X. ���� ���Կ����� �����ε��� �ʿ� X
	//�� ��ü�� �̹� ����&�ʱ�ȭ �� ���¿��� �����Ϸ��� ���� ������ ȣ��,
	//��ü�� ���� �����Ǵ� �������� �����Ϸ��� ���� ������ ȣ��
	result2 = poly1.differentiation();
	cout << "poly1 + poly2: ";
	result1.printPolynomial();
	cout << "differentiation of poly1: ";
	result2.printPolynomial();
}
int pow_(int num, int exp) {//num�� exp���� ���� ��ȯ�ϴ� �Լ�
	if (exp == 0)//exp�� 0�̶��
		return 1;//1 ��ȯ
	else
		return num * pow_(num, exp - 1);//num^exp=num*num^(exp-1)�̹Ƿ� pow�Լ� �ٽ� ȣ��
}