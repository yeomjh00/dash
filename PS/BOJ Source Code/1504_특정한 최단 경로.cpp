#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int v, e, p1, p2;
int adm[801][801];
int path[801];

int shortdis(int st, int dest) {
	vector<int>temppath(v + 1, 1e9);
	priority_queue<pair<int, int>> q;
	q.push({ 0, st });
	temppath[st] = 0;
	while (!q.empty()) {
		int now = q.top().second, val = q.top().first;
		q.pop();
		for (int i = 1; i <= v; i++) {
			if (adm[now][i] == 1e9) continue;
			int nextval = adm[now][i] + val;
			if (nextval < temppath[i]) {
				temppath[i] = nextval;
				q.push({ nextval, i });
			}
		}
	}
	if (temppath[dest] == 1e9)
		return 0;
	else
		return temppath[dest];
}

// problem is 1 -> p1 -> p2 -> v로 가는 최단거리를 searching
// idea : 1-> p1 최단거리 찾고, 거기서 다시 p2까지 가는 최단거리 찾기
int main() {
	scanf(" %d %d", &v, &e);
	int tmp1, tmp2, tmp3;
	//adjacency matrix initialize
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			adm[i][j] = 1e9;

	// indirected adjacency graph input
	for (int i = 0; i < e; i++) {
			scanf(" %d %d %d", &tmp1, &tmp2, &tmp3);
			adm[tmp1][tmp2] = adm[tmp2][tmp1] = min(tmp3, adm[tmp2][tmp1]);
		}
	cin >> p1 >> p2;

	int to_p1 = shortdis(1, p1);
	int to_p2 = shortdis(1, p2);
	int p1_p2 = shortdis(p1, p2);
	int p1_dest = shortdis(p1, v);
	int p2_dest = shortdis(p2, v);
	int ans1 = -1, ans2 = -1;

	if (to_p1 && p1_p2 && p2_dest)
		ans1 = to_p1 + p1_p2 + p2_dest;
	if (to_p2 && p1_p2 && p1_dest)
		ans2 = to_p2 + p1_p2 + p1_dest;
	if (ans1 != -1 && ans2 != -1)
		cout << min(ans1, ans2);
	else
		cout << (ans1 == -1) ? ans2 : ans1;
}