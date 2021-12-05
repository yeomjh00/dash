#include <iostream>
#include <algorithm>

using namespace std;

int tree[1000000];
int n, m;

long long get_tree(int h) {
	long long ans = 0;
	for (int i = 0; i < n; i++)
		if (tree[i] > h)
			ans += (tree[i] - h);
	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		scanf(" %d", tree + i);

	sort(tree, tree + n);

	long long l = 0, r = tree[n - 1];
	long long mid = (l + r) / 2;
	long long ans = 0, num = 0;

	while (true) {
		num = get_tree(mid);
		if (num < m)
			r = mid - 1;
		else if (num >= m) {
			l = mid + 1;
			ans = mid;
		}
		mid = (l + r) / 2;
		if (l > r)
			break;
	}
	cout << ans;
}