#include <iostream>
#include <cmath>
using namespace std;

int al[10001];
int dp[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", al + i);
	dp[1] = al[1];
	dp[2] = al[1] + al[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + al[i - 1] + al[i], dp[i-2]+al[i]);
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[n];
}