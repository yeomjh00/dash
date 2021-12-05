#include <iostream>
#include <cmath>
using namespace std;

int l[1000];
int dp[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", l + i);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (l[i]> l[j])
				dp[i] = max(dp[j]+1, dp[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}