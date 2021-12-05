#include <iostream>
#include <cmath>

using namespace std;

int m[1000000];
int dp[1000000];

int main() {
	int n;
	int ans = -1e9;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", m + i);
	dp[0] = m[0];
	for (int i = 1; i < n; i++)
		dp[i] = max(dp[i - 1]+m[i], m[i]);
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}