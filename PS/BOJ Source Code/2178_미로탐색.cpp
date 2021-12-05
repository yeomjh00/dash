/* 이 문제는 DFS가 아닌 BFS 문제이다.
*  DFS로 풀게 될 경우, 시간초과가 나게 되는데, 그 이유는
* 1. bool table이 없을 경우, 당연히 시간 초과가 난다.
* 2. bool table이 있을 경우, 한번 지나간 곳을 다시는 못 지나가기 때문에 문제를 풀 수 없다.
*	자세히 이야기를 해보자면, dfs의 방문 순서에 따라서 먼저 출발한 길이 목적지를 둘러싼다면, 그 다음 탐색에서는
*	목적지로 갈 수 없다. 즉, 시간 초과는 아니지만, 답은 구할 수 없다.
* 그렇기 때문에 dfs가 아닌 bfs로 문제를 풀어야 한다.
*/
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int r, c;
const int xm[4] = { 1,0,-1,0 };
const int ym[4] = { 0,1,0,-1 };
int lab[101][101];
int visit[101][101];

int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			scanf(" %1d", lab[i] + j);
			if (lab[i][j])
				visit[i][j] = 10001;
		}


	queue<pair<int, int>> q;
	visit[1][1] = 1;
	q.push({ 1,1 });
	while (!q.empty()) {
		pair<int, int>here = q.front();
		int y = here.first, x = here.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + ym[i], nx = x + xm[i];
			if (ny<1 || ny>r || nx<1 || nx>c) continue;
			else if (visit[ny][nx]!=10001) continue;
			else if (!lab[ny][nx])continue;
			visit[ny][nx] = min(visit[ny][nx], visit[y][x] + 1);
			q.push({ ny, nx });
		}
	}
	cout << visit[r][c];
}