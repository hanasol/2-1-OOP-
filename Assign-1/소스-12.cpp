#include <iostream>
using namespace std;
int fibo_rec(int num);//재귀함수로 구현한 피보나치 수열 선언
int fibo_iter(int num);//재귀함수를 사용하지 않은 피보나치 수열 선언
int main() {
	int a;
	cout << "Enter the number:";
	cin >> a;//숫자 입력
	cout << "Fibonacci_iter(" << a << "): " << fibo_rec(a) << endl;//입력받은 숫자의 피보나치 수열 값 출력
	cout << "Fibonacci_iter(" << a << "): " << fibo_iter(a);//입력받은 숫자의 피보나치 수열 값 출력
}
int fibo_rec(int num) {//재귀함수로 구현한 피보나치 수열 정의
	if (num == 1)//피보나치 수열의 첫번째 값은 0
		return 0;
	else if (num == 2)//피보나치 수열의 두번째 값은 1
		return 1;
	else
		return fibo_rec(num - 1) + fibo_rec(num - 2);//3번째 이상의 수열은 앞선 두 값의 합이므로 
	//num-1, num-2를 파라미터로 전달하여 둘을 더한 값 반환하고 이 과정에서 자기 자신과
	//같은 함수를 호출하므로 재귀함수임
}
int fibo_iter(int num) {//재귀함수를 사용하지 않은 피보나치 수열 정의
	int* arr = new int[num];//arr에 int의 사이즈를 num만큼 동적으로 크기 할당
	arr[1] = 0;//피보나치 수열의 첫번째 값은 0
	arr[2] = 1;//피보나치 수열의 두번째 값은 1
	for (int i = 3; i <= num; i++)
		arr[i] = arr[i - 1] + arr[i - 2];//3부터 num까지 앞선 두 배열의 값을 더하여 저장
	return arr[num];//입력받은 수의 피보나치 수열 값을 반환
	delete arr;//메모리 해제
}