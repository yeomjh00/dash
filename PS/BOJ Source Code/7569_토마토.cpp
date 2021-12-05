#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <memory.h>

using namespace std;

int r, c, h;
int to[100][100][100];
const int xm[6] = { 1,0,-1,0,0,0 };
const int ym[6] = { 0,1,0,-1,0,0 };
const int zm[6] = { 0,0,0,0,1,-1};

bool check() {
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				if (to[i][j][k] == 0)
					return false;
	return true;
}
// array에는 z y x 순으로
// tuple은 x y z 순으로 넣는다.
int main() {
	cin >> c >> r >> h;
	queue<vector<tuple<int,int, int>>> pos;
	vector<tuple<int,int,int>> day;
	int ans = 0;
	memset(to, -1, sizeof(to));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++) {
				scanf(" %d", to[i][j] + k);
				if (to[i][j][k] == 1)
					day.push_back({ k,j,i });
			}
	pos.push(day);

	while (!pos.empty()) {
		vector<tuple<int,int,int>>now = pos.front(), next;
		pos.pop();
		for (int e = 0; e < now.size(); e++) {
			int x = get<0>(now[e]), y = get<1>(now[e]), z = get<2>(now[e]);
			for (int i = 0; i < 6; i++) {
				int ny = y + ym[i], nx = x + xm[i], nz=z+zm[i];
				if (nx < 0 || nx >= c || ny < 0 || ny >= r || nz<0 || nz>=h) continue;
				else if (to[nz][ny][nx] == 0) {
					to[nz][ny][nx] = 1;
					next.push_back({ nx,ny,nz });
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