#include <iostream>
#include <algorithm>

using namespace std;

int uclid(int a, int b) {
	if (a < b)
		swap(a, b);
	while (a % b != 0) {
		while (a > b) {
			a -= b;
		}
		swap(a, b);
	}
	return b;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		cout << n * m / uclid(n, m) << "\n";
	}
}