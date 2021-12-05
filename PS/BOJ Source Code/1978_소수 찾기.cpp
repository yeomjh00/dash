#include <iostream>

using namespace std;

int main() {
	int n, ans = 0;
	int num[1001];
	fill_n(num, 1001, 1);
	num[0] = num[1] = 0;
	for (int i = 2; i < 1001; i++) {
		if (num[i] == 1) {
			int j = 2 * i;
			while (j <= 1000) {
				num[j] = 0;
				j += i;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int j = 0;
		cin >> j;
		if (num[j] == 1)
			ans++;
	}
	cout << ans;

}