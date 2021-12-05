#include <iostream>

using namespace std;

int dp[1001][1001];

int comb(int n, int k) {
	int& ret = dp[n][k];
	if (ret) return ret;
	if (k == 0|| n==k)
		return ret = 1;
	else if (k == 1)
		return ret = n;
	return ret = (comb(n - 1, k - 1) + comb(n - 1, k)) % 10007;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << comb(n, k);
}