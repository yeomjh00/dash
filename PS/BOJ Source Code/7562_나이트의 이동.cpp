#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>

using namespace std;

int board[300][300];
int visit[300][300];
const int xm[8] = { 2,1,-1,-2,-2,-1,1,2 };
const int ym[8] = { 1,2,2,1,-1,-2,-2,-1 };

int main() {
	int tc; cin >> tc;
	while (tc--) {
		memset(board, 0, sizeof(board));
		memset(visit, 0, sizeof(visit));
		int n;
		cin >> n;
		queue<pair<int, int>> q;
		int orix, oriy, gy, gx;
		cin >> oriy >> orix;
		cin >> gy >> gx;
		q.push({ oriy, orix });
		visit[oriy][orix] = 1;
		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			if (y == gy && x == gx) break;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + xm[i], ny = y + ym[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (visit[ny][nx]) continue;
				visit[ny][nx] = visit[y][x] + 1;
				q.push({ ny,nx });
			}
		}
		cout << visit[gy][gx]-1 << "\n";
	}
}