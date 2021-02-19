#include <iostream>
using namespace std;
int g = 20;//전역변수

int add(int x, int y) { //전역함수
	return x + y;

}

int main() {
	int a, b, sum;
	cin >> a >> b;
	sum = a + b;
	cout << sum;
	return 0;
}