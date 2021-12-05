#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, k;
	int ans = 0, num = 0;
	cin >> n >> k;
	int l = 0, r = 1e9;
	int mid;
	while (l <= r) {
		ans = 0;
		mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			ans += min(mid / i, n);
		}
		if (ans < k)
			l = mid + 1;
		
		else if (ans >= k) {
			num = mid;
			r = mid - 1;
		}
	}
	cout << num;
}