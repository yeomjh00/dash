#include <iostream>
#define ull unsigned long long int

using namespace std;

unsigned long long int dp[31][31];

unsigned long long int comb(unsigned long long int n, unsigned long long int k) {
	ull& ret = dp[n][k];
	if (ret) return ret;
	if (n == k) return ret = 1;
	else if (k == 1) return ret = n;
	else
		return ret = comb(n - 1, k) + comb(n - 1, k - 1);
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		unsigned long long int n, k, ans;
		cin >> k >> n;
		ans = comb(n, k);
		cout << ans << "\n";
	}
}