#include <iostream>
using namespace std;
class Matrix {
private:
	double data[4][4];
public:
	Matrix() {//4x4 ����� ��� 0���� �ʱ�ȭ
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				data[i][j] = 0;
		}
	}
	~Matrix() { }

	Matrix operator+(Matrix& mtx) {//���+����� �����ϴ� +������ �����ε�
		double temp[4][4] = { 0, };//��ĳ��� ���� ����� �����ϴ� 2���� �迭
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = mtx.data[i][j];//mtx�� i�� j���� �����͸� ����
				temp[i][j] += data[i][j];//���� ��ü�� i�� j���� �����͸� ����
			}
		}
		Matrix newMat;
		newMat.setValue(temp);//temp�� ������ mewMat�� �� ����
		return newMat;//��ȯ
	}
	Matrix operator-(Matrix& mtx) {//���-����� �����ϴ� +������ �����ε�
		double temp[4][4] = { 0, };//��Ŀ��� ����� �� ����� �����ϴ� 2���� �迭
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = -mtx.data[i][j];//-�� ��ȯ��Ģ ����X, mtx�� �����͸� ������ ����
				temp[i][j] += data[i][j];//���� ��ü�� �����͸� ����
			}
		}
		Matrix newMat;
		newMat.setValue(temp);//temp�� newMat�� �� ����
		return newMat;//��ȯ
	}
	Matrix operator*(Matrix& mtx) {//���*����� �����ϴ� *������ �����ε�
		double temp[4][4] = { 0, };
		for (int i = 0; i < 4; i++) {//��
			for (int j = 0; j < 4; j++) {//��
				for (int k = 0; k < 4; k++) {
					temp[i][j] += data[i][k] * mtx.data[k][j];//���� ��ü�� i��� mtx�� j���� ����
				}
			}
		}
		Matrix newMat;
		newMat.setValue(temp);//nexMat�� temp�� ����
		return newMat;//��ȯ
	}

	Matrix operator+(int Scalar) {
		double temp[4][4] = { 0, };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = data[i][j];//���� �� ����
				temp[i][j] += Scalar;//���ڷ� ���� scalar�� ����
			}
		}
		Matrix newMat;
		newMat.setValue(temp);
		return newMat;
	}
	Matrix operator-(int Scalar) {
		double temp[4][4] = { 0, };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = data[i][j];//���� �� ����
				temp[i][j] -= Scalar;//���ڷ� ���� scalar�� ��
			}
		}
		Matrix newMat;
		newMat.setValue(temp);
		return newMat;
	}
	Matrix operator*(int Scalar) {
		double temp[4][4] = { 0, };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = data[i][j];//���� �� ����
				temp[i][j] *= Scalar;//���ڷ� ���� scalar�� ����
			}
		}
		Matrix newMat;
		newMat.setValue(temp);
		return newMat;
	}
	Matrix operator/(int Scalar) {
		double temp[4][4] = { 0, };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = data[i][j];//���� �� ����
				temp[i][j] /= Scalar;//���ڷ� ���� scalar�� ����
			}
		}
		Matrix newMat;
		newMat.setValue(temp);
		return newMat;
	}

	void setValue(double arr[4][4]) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				data[i][j] = arr[i][j];//���ڷ� ���� 2���� �迭�� ������ ����
		}
	}
	void display() {//��� ���
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cout << data[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
};
int main() {
	Matrix mat1, mat2;

	double arr1[4][4] = {
		{1, 2, 3, 4},
		{5, 7, 8, 4},
		{9, 5, 7, 1},
		{5, 8, 7, 4}
	};
	double arr2[4][4] = {
		{5, 1, 2, 3},
		{4, 1, 2, 3},
		{3, 1, 2, 3},
		{2, 1, 2, 3}
	};
	mat1.setValue(arr1);
	mat2.setValue(arr2);
	Matrix mat3 = mat1 * mat2;
	Matrix mat4 = mat1 + 3;
	cout << "Matrix 1:\n";
	mat1.display();
	cout << "Matrix 2:\n";
	mat2.display();
	cout << "Mat1 * Mat2:\n";
	mat3.display();
	cout << "Mat1 + 3:\n";
	mat4.display();
}