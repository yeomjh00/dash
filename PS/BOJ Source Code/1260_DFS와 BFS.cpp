#include <iostream>
#include <queue>

using namespace std;


bool ad[1001][1001];
bool dchk[1001];
bool bchk[1001];
int v, e, start;

void dfs(int start) {
	dchk[start] = true;
	printf("%d ", start);
	for (int i = 1; i <= v; i++) {
		if (ad[start][i] && (!dchk[i])) {
			dfs(i);
		}
	}
	return;
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	bchk[start] = true;
	while (!q.empty()) {
		int here = q.front();
		printf("%d ", here);
		q.pop();
		for (int i = 1; i <= v; i++) {
			if (ad[i][here] && (!bchk[i])) {
				bchk[i] = true;
				q.push(i);
			}
		}
	}
	return;
}

int main() {

	int t1, t2;
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++) {
		scanf(" %d %d", &t1, &t2);
		ad[t1][t2] = ad[t2][t1] = true;
	}
	dfs(start);
	cout << "\n";
	bfs(start);
}