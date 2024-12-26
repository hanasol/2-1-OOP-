#include <iostream>
using namespace std;
class Matrix {
private:
	double data[4][4];
public:
	Matrix() {//4x4 행렬을 모두 0으로 초기화
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				data[i][j] = 0;
		}
	}
	~Matrix() { }

	Matrix operator+(Matrix& mtx) {//행렬+행렬을 수행하는 +연산자 오버로딩
		double temp[4][4] = { 0, };//행렬끼리 더한 행렬을 저장하는 2차원 배열
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = mtx.data[i][j];//mtx의 i행 j열의 데이터를 저장
				temp[i][j] += data[i][j];//현재 객체의 i행 j열의 데이터를 더함
			}
		}
		Matrix newMat;
		newMat.setValue(temp);//temp의 값으로 mewMat의 값 저장
		return newMat;//반환
	}
	Matrix operator-(Matrix& mtx) {//행렬-행렬을 수행하는 +연산자 오버로딩
		double temp[4][4] = { 0, };//행렬에서 행렬을 뺀 행렬을 저장하는 2차원 배열
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = -mtx.data[i][j];//-는 교환법칙 성립X, mtx의 데이터를 음수로 저장
				temp[i][j] += data[i][j];//현재 객체의 데이터를 더함
			}
		}
		Matrix newMat;
		newMat.setValue(temp);//temp로 newMat의 값 저장
		return newMat;//반환
	}
	Matrix operator*(Matrix& mtx) {//행렬*행렬을 수행하는 *연산자 오버로딩
		double temp[4][4] = { 0, };
		for (int i = 0; i < 4; i++) {//행
			for (int j = 0; j < 4; j++) {//열
				for (int k = 0; k < 4; k++) {
					temp[i][j] += data[i][k] * mtx.data[k][j];//현재 객체의 i행과 mtx의 j열의 내적
				}
			}
		}
		Matrix newMat;
		newMat.setValue(temp);//nexMat를 temp로 세팅
		return newMat;//반환
	}

	Matrix operator+(int Scalar) {
		double temp[4][4] = { 0, };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = data[i][j];//현재 값 저장
				temp[i][j] += Scalar;//인자로 받은 scalar를 더함
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
				temp[i][j] = data[i][j];//현재 값 저장
				temp[i][j] -= Scalar;//인자로 받은 scalar를 뺌
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
				temp[i][j] = data[i][j];//현재 값 저장
				temp[i][j] *= Scalar;//인자로 받은 scalar를 곱함
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
				temp[i][j] = data[i][j];//현재 값 저장
				temp[i][j] /= Scalar;//인자로 받은 scalar로 나눔
			}
		}
		Matrix newMat;
		newMat.setValue(temp);
		return newMat;
	}

	void setValue(double arr[4][4]) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				data[i][j] = arr[i][j];//인자로 들어온 2차원 배열의 값으로 저장
		}
	}
	void display() {//행렬 출력
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