#include <iostream>
#include <memory.h>

using namespace std;

bool visit[100][100];
int area[100][100];
int n;
const int x[4] = { 1,0,-1,0 };
const int y[4] = { 0,-1,0,1 };

void dfs(int h, int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) return;
	if (visit[r][c]) return ;
	visit[r][c] = true;
	if (area[r][c] > h) {
		for (int i = 0; i < 4; i++) {
			int ny = r + y[i];
			int nx = c + x[i];
			dfs(h, ny, nx);
		}
	}
	return;
}

int main() {
	int ans = 1, tmp = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", area[i] + j);

	for (int h = 1; h <= 100; h++) {
		memset(visit, 0, sizeof(visit));
		tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][j] > h && (!visit[i][j])) {
					tmp++;
					dfs(h, i,j);
				}
			}
		}
		ans = max(ans, tmp);
	}
	cout << ans;
}