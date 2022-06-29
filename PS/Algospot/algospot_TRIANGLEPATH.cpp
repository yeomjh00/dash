#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

int tri[100][100];
int dp[100][100];

int tripath(int y, int x, int n) {
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	if (y == n - 1) return ret = tri[y][x];
	return ret = max(tripath(y + 1, x, n), tripath(y + 1, x + 1, n)) + tri[y][x];
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i < 100; i++) memset(dp[i], -1, sizeof(dp[i]));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++)
				scanf(" %d", tri[i] + j);
		}
		cout << tripath(0, 0, n) << "\n";
	}
}