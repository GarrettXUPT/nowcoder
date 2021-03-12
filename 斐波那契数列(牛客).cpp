#include<iostream>
#include<algorithm>

using namespace std;

int Fibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main() {
	cout << Fibonacci(4) << endl;
	return 0;
}