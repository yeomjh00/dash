#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <memory.h>

using namespace std;

int r, c;
int to[1000][1000];
const int xm[4] = { 1,0,-1,0 };
const int ym[4] = { 0,1,0,-1 };

bool check() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (to[i][j] == 0)
				return false;
	return true;
}

int main() {
	cin >> c >> r;
	queue<vector<pair<int, int>>> pos;
	vector<pair<int, int>> day;
	int ans = 0;
	memset(to, -1, sizeof(to));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			scanf(" %d", to[i] + j);
			if (to[i][j] == 1)
				day.push_back({ i,j });
		}
	pos.push(day);

	while (!pos.empty()) {
		vector<pair<int,int>>now = pos.front(), next;
		pos.pop();
		for (int e = 0; e < now.size(); e++) {
			int y = now[e].first, x = now[e].second;
			for (int i = 0; i < 4; i++) {
				int ny = y + ym[i], nx = x + xm[i];
				if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
				else if (to[ny][nx] == 0) {
					to[ny][nx] = 1;
					next.push_back({ ny,nx });
				}
			}
		}
		if (!next.empty())
			pos.push(next);
		else
			break;
		ans++;
	}
	if (!check())
		cout << "-1";
	else
		cout << ans;

}