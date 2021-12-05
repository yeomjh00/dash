#include <iostream>

using namespace std;

int brd[502][502];
int dp[502][502];

const int y_move[4] = { 1, 0, -1, 0 };
const int x_move[4] = { 0, 1, 0, -1 };

int r, c;

// we should check whether we already visited or not. Otherwise, time will not wait for us.
int lab(int y, int x) {
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + y_move[i], nx = x + x_move[i];
		if(brd[ny][nx])
			if (brd[y][x] < brd[ny][nx])
				ret += lab(ny, nx);
	}
	return ret;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r + 2; i++)
		for (int j = 0; j < c + 2; j++)
			brd[i][j] = -1e9;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf(" %d", brd[i] + j);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			dp[i][j] = -1;
			
	dp[1][1] = 1;
	cout << lab(r, c);
}