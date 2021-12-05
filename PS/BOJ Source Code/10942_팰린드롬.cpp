#include <iostream>

using namespace std;

int seq[2001];
int dp[2001][2001];

int main() {
	int n, k,ans;
	scanf(" %d", &n);
	for (int i = 1; i <= n; i++)
		scanf(" %d", seq + i);
	scanf(" %d", &k);

	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;

	for (int i = 1; i < n; i++)
		dp[i][i + 1] = (seq[i] == seq[i + 1]);
	
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= n - i +1 ; j++) {
			dp[j][j + i - 1] = (seq[j] == seq[j + i - 1] && dp[j + 1][j + i - 2]);
		}
	}

	int tmp1, tmp2;
	while(k--){
		scanf(" %d %d", &tmp1, &tmp2);
		printf("%d\n", dp[tmp1][tmp2]);
	}
}