#include <iostream>
#include <algorithm>

using namespace std;

int home[200000];

int ok(int dis, int n) {
	int m = 1;
	int bef = home[0]+dis;
	for (int i = 0; i < n; i++) {
		if (bef > home[i])
			continue;
		else {
			bef = home[i]+dis;
			m++;
		}
	}
	return m;
}

int main() {
	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		scanf(" %d", home + i);

	sort(home, home + n);

	int l = 1, r = home[n - 1];
	int mid = (l + r) / 2;
	int ans = 0;
	while (true) {
		int num = ok(mid, n);

		if (num < c)
			r = mid - 1;
		else {
			l = mid + 1;
			ans = mid;
		}

		mid = (l + r) / 2;

		if (l > r)
			break;
	}

	cout << ans;
}