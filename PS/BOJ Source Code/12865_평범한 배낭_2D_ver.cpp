#include <iostream>
#include <cmath>
using namespace std;

int v[501];
int w[501];
int dp[501][100001] = { 0, };

int main() {
	int n, wm;
	cin >> n >> wm;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", w + i, v + i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= wm; j++) {
			dp[i][j] = dp[i - 1][j];
			if(j>=w[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	cout << dp[n][wm];
}