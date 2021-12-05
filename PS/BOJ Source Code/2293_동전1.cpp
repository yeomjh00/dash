#include <iostream>
#include <algorithm>

using namespace std;

int coin[100];
int dp[10001];

int main() {
	int n, val, tmp, rn=0;
	cin >> n >> val;
	for (int i = 0; i < n; i++) {
		scanf(" %d", &tmp);
		if (tmp <= 10000) {
			coin[rn] = tmp;
			rn++;
		}
	}
	n = rn;
	sort(coin, coin + n);
	
	for (int i = coin[0]; i <= val; i += coin[0])
		dp[i] = 1;

	for (int i = 1; i < n; i++) {
		dp[coin[i]]++;
		if (coin[i] > 9999) continue;
		for (int j = coin[i]+1; j <= val; j ++)
			dp[j] = dp[j] + dp[j - coin[i]];
	}
	cout << dp[val];
}