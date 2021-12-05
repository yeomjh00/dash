//sort하면 편하다. 하지만 merge sort 복습차, merge sort로 풀어보자.
#include <iostream>

using namespace std;

int t[1000];
int st[1000];

void merge(int l, int r) {
	int m = (l + r) / 2;
	if (l >= r) return;
	merge(l, m);
	merge(m + 1, r);
	int i = l, j = m + 1;
	int idx = l;
	while (i <= m && j <= r) {
		if (t[i] <= t[j])
			st[idx++] = t[i++];
		
		else 
			st[idx++] = t[j++];
		
	}
	while (i <= m) st[idx++] = t[i++];
	while (j <= r) st[idx++] = t[j++];
	for (int k = l; k <= r; k++)
		t[k] = st[k];
	return;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", t + i);
	merge(0, n-1);
	int ans = 0, tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += t[i];
		ans += tmp;
	}
	cout << ans;
}