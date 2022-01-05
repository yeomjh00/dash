#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int v, e, p1, p2;
int adm[801][801];
int path[801];

// problem is 1 -> p1 -> p2 -> v로 가는 최단거리를 searching
// idea : 1-> p1 최단거리 찾고, 거기서 다시 p2까지 가는 최단거리 찾기
int main() {
	cin >> v >> e;
	int tmp1, tmp2, tmp3;
	//adjacency matrix initialize
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			adm[i][j] = 1e9;

	// indirected adjacency graph input
	for (int i = 0; i < e; i++) {
			scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
			adm[tmp1][tmp2] = adm[tmp2][tmp1] = min(tmp3, adm[tmp2][tmp1]);
		}
	cin >> p1 >> p2;

	// go 1 to p1
	for (int i = 1; i <= v; i++)
		path[i] = 1e9;
	path[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>> q;
	q.push({ 0, 1 });
	while (!q.empty()) {
		int now = q.top().second, val = q.top().first;
		q.pop();
		for (int i = 1; i <= v; i++) {
			if (adm[now][i] == 1e9) continue;
			int nextval = adm[now][i] + val;
			if (nextval < path[i]) {
				path[i] = nextval;
				q.push({ nextval, i });
			}
		}
	}

	// go p1 to p2
	priority_queue<pair<int, int>, vector<pair<int, int>>> q1;
	if(path[p1]!=1e9)
		q1.push({path[p1], p1});
	for (int i = 1; i <= v; i++)
		path[i] = 1e9;
	path[p1] = 0;
	while (!q1.empty()) {
		int now = q1.top().second, val = q1.top().first;
		q1.pop();
		for (int i = 1; i <= v; i++) {
			if (adm[now][i] == 1e9) continue;
			int nextval = adm[now][i] + val;
			if (nextval < path[i]) {
				path[i] = nextval;
				q1.push({ nextval, i });
			}
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>> q2;
	if (path[p2] != 1e9)
		q2.push({ path[p2], p2 });
	for (int i = 1; i <= v; i++)
		path[i] = 1e9;
	path[p2] = 0;
	while (!q2.empty()) {
		int now = q2.top().second, val = q2.top().first;
		q2.pop();
		for (int i = 1; i <= v; i++) {
			if (adm[now][i] == 1e9) continue;
			int nextval = adm[now][i] + val;
			if (nextval < path[i]) {
				path[i] = nextval;
				q2.push({ nextval, i });
			}
		}
	}
	if (path[p1] == 1e9 || path[p2] == 1e9 || path[v] == 1e9)
		cout << "-1";
	else
		cout <<path[v];
}