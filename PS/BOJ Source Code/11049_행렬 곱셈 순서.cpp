#include <iostream>
#include <cmath>
#define uint unsigned int

using namespace std;

uint dp[500][500];
uint r[500];
uint c[500];

uint matmul(int a, int b) {
	uint& ret = dp[a][b];
	if (a == b) return ret = 0;
	else if (ret != -1) return ret;
	for (int i = a; i < b; i++)
		ret = min(ret, matmul(a, i) + matmul(i + 1, b) + r[a] * c[i] * c[b]);
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf(" %d %d", r + i, c + i);
	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			dp[i][j] = -1;
	cout << matmul(0, n - 1);

}