#include <iostream>
#include <cmath>
using namespace std;

int a[7] = { 0, };

int sum() {
	int s = 0;
	for (int i =0; i < 7; i++) {
		s += (pow(10, i) * a[i] + a[i]);
	}
	return s;
}

void dec(int n) {
	int i = 0;
	while (n) {
		a[i]= n % 10;
		n /= 10;
		i++;
	}
	return ;
}

int main() {
	int n;
	bool ind = true;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dec(i);
		if (sum() == n) {
			cout << i;
			ind = false;
			break;
		}
	}
	if (ind)
		cout << "0";
}