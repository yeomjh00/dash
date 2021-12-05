#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int dp[1001][1001] = { 0, };

int main() {
	string a, b;
	cin >> a >> b;
	if (a.length() < b.length()) {
		string tmp = a;
		a = b;
		b = tmp;
	}
	int sa = a.length(), sb = b.length();
	a = ' ' + a;
	b = ' ' + b;
	for (int i = 1; i <= sa; i++) {
		for (int j = 1; j <= sb; j++) {
			if (a[i] == b[j]) {
				if (i == 1 || j == 1)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i-1][j-1] + 1;
				}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= sa; i++)
		for (int j = 0; j <= sb; j++)
			ans = max(ans, dp[i][j]);
	cout << ans;
}