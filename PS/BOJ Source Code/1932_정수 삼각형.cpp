#include <iostream>
#include <cmath>
using namespace std;

int tri[500][500];
int sum[500][500];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", tri[i] + j);

	sum[0][0] = tri[0][0];
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				sum[i][j] = sum[i - 1][j] + tri[i][j];
			else if (j == i)
				sum[i][j] = sum[i - 1][j - 1] + tri[i][j];
			else
				sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + tri[i][j];
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, sum[n - 1][i]);
	cout << ans;
}