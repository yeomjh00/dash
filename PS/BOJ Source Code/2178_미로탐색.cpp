/* �� ������ DFS�� �ƴ� BFS �����̴�.
*  DFS�� Ǯ�� �� ���, �ð��ʰ��� ���� �Ǵµ�, �� ������
* 1. bool table�� ���� ���, �翬�� �ð� �ʰ��� ����.
* 2. bool table�� ���� ���, �ѹ� ������ ���� �ٽô� �� �������� ������ ������ Ǯ �� ����.
*	�ڼ��� �̾߱⸦ �غ��ڸ�, dfs�� �湮 ������ ���� ���� ����� ���� �������� �ѷ��Ѵٸ�, �� ���� Ž��������
*	�������� �� �� ����. ��, �ð� �ʰ��� �ƴ�����, ���� ���� �� ����.
* �׷��� ������ dfs�� �ƴ� bfs�� ������ Ǯ��� �Ѵ�.
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