#include <iostream>
#include <vector>

using namespace std;
int n, arr[8];

int dfs(vector<bool>& visit, vector<int>& seq, int step) {
	if (step == n) return 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int here = seq.back();
		if (visit[i]) continue;
		visit[i] = true;
		seq.push_back(arr[i]);
		ans = max(ans, dfs(visit, seq, step + 1) + abs(here-seq.back()));
		seq.pop_back();
		visit[i] = false;
	}
	return ans;
}

int main() {
	cin >> n;
	int ans = 0;
	vector<int> seq(n);
	vector<bool> visit(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		tmp.push_back(arr[i]);
		visit[i] = true;
		ans = max(ans, dfs(visit, tmp, 0));
		visit[i] = false;
	}
	cout << ans;
}