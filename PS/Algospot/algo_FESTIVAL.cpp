#include <iostream>
#include <cmath>

using namespace std;

int cost[1001];

int main() {
	int test;
	cin >> test;
	cout << fixed;
	cout.precision(8);
	while (test--) {
		int n, k;
		double ans = 100.5;
		double temp = 0.0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) scanf(" %d", cost + i);

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += cost[j];
				if (j - i + 1 >= k) {
					temp = sum * 1.0;
					temp/= (j - i + 1);
					ans = min(temp, ans);
				}
			}
		}
		cout << ans << "\n";
	}
}