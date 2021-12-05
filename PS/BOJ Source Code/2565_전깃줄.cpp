#include <iostream>
#include <cmath>

using namespace std;

int l[501];
int la[501];
int dp[501];
int dpa[501];

int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m, v;
		scanf("%d %d", &m, &v);
		l[m] = v;
		la[v] = m;
	}
	for (int i = 1; i <= 500; i++) {
		if (!l[i]) continue;
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (!l[j]) continue;
			if (l[i] > l[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = 1; i <= 500; i++) {
		if (!la[i]) continue;
		dpa[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (!la[j]) continue;
			if (la[i] > la[j]) dpa[i] = max(dpa[i], dpa[j] + 1);
		}
	}
	for (int i = 1; i <=500; i++) 
		ans = max(ans, dp[i]);
	cout << n - ans;
}