#include <iostream>

using namespace std;

int memory[100], cost[100];
int n, dp[10001];
//dp[i]�� i��ŭ cost�� �� ��, ���� �� �ִ� �ִ��� memory���� ���Ѵ�.

int main(){
	int mem;
	cin >> n >> mem;
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	for (int i = 0; i < n; i++) {
		for (int j = 10000; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= mem) {
			cout << i;
			break;
		}
	}
}