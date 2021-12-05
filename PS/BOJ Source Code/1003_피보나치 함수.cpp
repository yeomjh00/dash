#include <iostream>

using namespace std;

int main() {
	int test;
	cin >> test;
	int fib1[41] = { 0, };
	int fib0[41] = { 0, };
	fib0[0] = 1;
	fib0[2] = 1;
	fib1[1] = 1;
	fib1[2] = 1;
	for (int i = 3; i < 41; i++) {
		fib0[i] = fib0[i - 1] + fib0[i - 2];
		fib1[i] = fib1[i - 1] + fib1[i - 2];
	}
	while (test--) {
		int n;
		cin >> n;
		cout << fib0[n] << ' ' << fib1[n] << "\n";
	}
}