#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int r, c;
int lab[1001][1001];
int visit[1001][1001][2];
const int ym[4] = { 0,1,-1,0 };
const int xm[4] = { 1,0,0,-1 };

int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf(" %1d", lab[i] + j);

	queue<tuple<int,int,int>> q;
	q.push({ 1,1,0 });
	visit[1][1][0] =1;

	while (!q.empty()) {
		int y = get<0>(q.front()), x = get<1>(q.front()), wall = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + ym[i], nx = x + xm[i];

			if (nx<1 || ny<1 || nx>c || ny>r) continue;

			if (visit[ny][nx][1] == 0 && lab[ny][nx]&&(!wall)) {
				visit[ny][nx][1] = visit[y][x][0] + 1;
				q.push({ ny,nx,1 });
			}

			else if (visit[ny][nx][wall] == 0 && (!lab[ny][nx])) {
				visit[ny][nx][wall] = visit[y][x][wall] + 1;
				q.push({ ny,nx,wall });
			}
		}
	}
	int ans = min(visit[r][c][0], visit[r][c][1]);
	if (ans)
		cout << ans;
	else if (visit[r][c][0] || visit[r][c][1])
		visit[r][c][0] == 0 ? cout << visit[r][c][1] : cout << visit[r][c][0];
	else
		cout << "-1";
}