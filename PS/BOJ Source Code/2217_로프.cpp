#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int rope[100000];

int main() {
	int n;
	int ans = -1e9;
	cin >> n;
	for (int i = 0; i < n; i++) scanf(" %d", rope + i);

	sort(rope, rope + n);

	for (int i = 0, j=n; i < n; i++, j--) {
		ans = max(ans, rope[i] * j);
	}
	cout << ans;
}