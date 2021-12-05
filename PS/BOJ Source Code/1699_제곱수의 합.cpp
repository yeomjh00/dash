#include <iostream>
#include <cmath>

using namespace std;

int dp[100000];

int main() {
	int n, ans=0;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++)
		dp[i * i]=1;
	for (int i = 1; i <= n; i++) {
		if (dp[i]) continue;
		dp[i] = 1e9;
		for (int j = 1; j <= sqrt(i); j++) {
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}
	cout << dp[n];
}