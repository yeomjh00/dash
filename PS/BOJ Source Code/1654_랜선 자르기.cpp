#include <iostream>
#include <algorithm>

using namespace std;

int lan[1000000];
long long n, k;

int divide(int len) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (lan[i] / len);
	}
	return ans;
}

int main() {
	cin >> n >> k;
	int num, ans;
	for (int i = 0; i < n; i++)
		scanf(" %d", lan + i);

	sort(lan, lan + n);

	long long l = 1, r = lan[n - 1];
	long long mid = (l + r) / 2;

	while (true) {
		num = divide(mid);

		if (k > num)
			r = mid - 1;

		else if (k <= num) {
			l = mid + 1;
			ans = mid;
		}

		mid = (l + r) / 2;

		if (l > r)
			break;
	}
	cout << ans;
}