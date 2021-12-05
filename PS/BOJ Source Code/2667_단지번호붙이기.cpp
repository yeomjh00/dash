#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int town[25][25];
bool visit[25][25];
const int xm[4] = { 1,0,-1,0 };
const int ym[4] = { 0,1,0,-1 };

int dfs(int n, int y, int x) {
	int ans = 1;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + ym[i], nx = x + xm[i]; //next position

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //out of range
		else if (visit[ny][nx]) continue; //already visited
		else if ((!town[ny][nx])) { //not a town
			visit[ny][nx] = true;
			continue;
		}
		visit[ny][nx] = true;
		ans+= dfs(n, ny, nx);
	}

	return ans;
}

int main() {
	int n;
	vector<int>homes;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %1d", town[i] + j);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (town[i][j] && (!visit[i][j])) {
				visit[i][j] = true;
				int v = dfs(n, i, j);
				homes.push_back(v);
			}
		}
	sort(homes.begin(), homes.end());
	cout << homes.size() << "\n";
	for (int i = 0; i < homes.size(); i++)
		cout << homes[i] << "\n";
}