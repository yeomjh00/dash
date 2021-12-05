#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
int n, edge;
int visit[20001];

bool dfs(vector<vector<int>>& v,int idx, int color) {
	bool ret = true;
	vector<int>& now = v[idx];
	for (int i = 0; i < now.size(); i++) {
		if (visit[now[i]] == color) continue;
		else if (visit[now[i]] == 0) {
			visit[now[i]] = color;
			ret = dfs(v, now[i], color * -1) && ret; 
		}
		else return false;
	}
	return ret;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int t1, t2;
		bool ans = true;
		memset(visit, 0, sizeof(visit));
		cin >> n >> edge;
		vector<vector<int>> adl(n+1);
		for (int i = 0; i < edge; i++) {
			scanf(" %d %d", &t1, &t2);
			adl[t1].push_back(t2);
			adl[t2].push_back(t1);
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i]) continue;
			visit[i] = 1;
			ans = (ans && dfs(adl, i, -1));
		}
		if (ans)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}