#include <iostream>
#include <memory.h>

using namespace std;

int board[101][101];
bool dp[101][101];


void dfs(int y, int x, int n) {
	if (y < 1 || x < 1 || y>100 || x>100)  return;
	bool& chk = dp[y][x];
	if (chk) return;
	if (y == n && x == n) {
		chk = true;
		return;
	}
	chk = true;
	dfs(y + board[y][x], x, n);
	dfs(y, x + board[y][x], n);
	return;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		for (int i = 0; i <= 100; i++)
			memset(board[i], 0, sizeof(board[i]));
		for (int i = 0; i <= 100; i++)
			memset(dp[i], 0, sizeof(dp[i]));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf(" %d", board[i]+j);	
		dfs(1, 1, n);
		if (dp[n][n]) cout << "YES\n";
		else cout << "NO\n";
	}
}