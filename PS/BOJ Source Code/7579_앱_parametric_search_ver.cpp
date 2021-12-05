#include <iostream>
#include <cmath>

using namespace std;

int dp[100][10001], cost[100], memory[100];
int n, mem;

int dfs(int step,int tot_cost) {
	if (step == n) return 0;
	int& ret = dp[step][tot_cost];
	if (ret) return ret;
	ret = dfs(step + 1, tot_cost);
	if (tot_cost >= cost[step]) ret = max(ret, dfs(step + 1, tot_cost - cost[step])+memory[step]);
	return ret;
}

int main() {
	cin >> n >> mem;
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	int l = 0, r = 10000, ans=0;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (dfs(0, mid) >= mem) {
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	cout << ans;
}