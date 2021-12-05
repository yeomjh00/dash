#include <iostream>
#include <memory.h>
#include <cmath>
// cost�� 0�� �� �� �ְ�, memory�� �׻� 1 �̻��̴�.
using namespace std;

int memory[101], cost[101];
int dp[101][10001]; //dp i j �� i��° ���α׷����� �������� ��, j��ŭ cost�� �� ��, value�� �ִ� memory���̴�.

int dfs(int tot, int step, int tot_cost) {
	if (step == tot) return 0;
	int& ret = dp[step][tot_cost];
	if (ret) return ret;
	ret = dfs(tot, step + 1, tot_cost);
	if (cost[step] <= tot_cost) ret = max(ret, dfs(tot, step + 1, tot_cost - cost[step]) + memory[step]);
	return ret;
}

int main() {
	int mem, n, sum = 0;
	cin >> n >> mem;
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
	for (int i = 0; i <= sum; i++) {
		if (dfs(n, 0, i) >= mem) {
			cout << i;
			break;
		}
	}
}
