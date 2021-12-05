#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int farm[50][50];
bool visit[50][50];
const int xm[4] = { 1,0,-1,0 };
const int ym[4] = { 0,1,0,-1 };

void dfs(int r, int c, int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + ym[i], nx = x + xm[i];
		if (ny >= r || ny < 0 || nx >= c || nx < 0) continue;
		else if (visit[ny][nx]) continue;
		else if (!farm[ny][nx]) {
			visit[ny][nx] = true;
			continue;
		}
		visit[ny][nx] = true;
		dfs(r,c,ny, nx);
	}
	return;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int ans = 0;
		int r, c, n;
		cin >> c >> r >> n;
		int t1, t2;
		memset(farm, 0, sizeof(farm));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			scanf(" %d %d", &t1, &t2);
			farm[t2][t1]= 1;
		}

		for(int i=0;i<r;i++)
			for (int j = 0; j < c; j++) {
				if (farm[i][j] && (!visit[i][j])) {
					visit[i][j] = true;
					dfs(r,c,i, j);
					ans++;
				}
			}
		cout << ans << "\n";
	}
}