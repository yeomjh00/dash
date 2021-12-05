#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int a[50], b[50];

int main() {
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf(" %d", a + i);
	for (int i = 0; i < n; i++)
		scanf(" %d", b + i);
	sort(a, a + n);
	sort(b, b + n,
		[](int x, int y) {
			return x > y;
		}
	);
	for (int i = 0; i < n; i++)
		ans += (a[i] * b[i]);
	cout << ans;
}