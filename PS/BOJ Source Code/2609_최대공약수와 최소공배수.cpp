#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int n1, m1;
	if (n > m) {
		n1 = n;
		m1 = m;
	}
	else {
		n1 = m;
		m1 = n;
	}

	while (n1 % m1 != 0) {
		while (n1 > m1) {
			n1 -= m1;
		}
		swap(n1, m1);
	}
	cout << m1 << "\n";
	cout << n * m / m1;
}