#include <iostream>

using namespace std;

int a[10];

int main() {
	int n, tmp;
	cin >> n;
	tmp = n;
	while (tmp) {
		int t = tmp % 10;
		a[t]++;
		tmp /= 10;
	}
	for (int i = 9; i >= 0; i--) {
		while (a[i]) {
			printf("%d", i);
			a[i]--;
		}
	}

}