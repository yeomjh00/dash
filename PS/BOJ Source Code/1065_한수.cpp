#include <iostream>

using namespace std;

int isarith(int n);

int main() {
	int n;
	int ans = 99;
	cin >> n;
	if (n < 100)
		cout << n;
	else {
		if (n == 1000)
			n = 999;
		for (int i = 100; i <= n; i++) {
			ans += isarith(i);
		}
		cout << ans;
	}
	return 0;
}

int isarith(int n) {
	int i = 0;
	int t[3] = { 0 };
	int ind = n;
	while (ind) {
		t[i++] = ind % 10;
		ind /= 10;
	}
	if (t[0] + t[2] == 2 * t[1])
		return 1;
	else
		return 0;
}