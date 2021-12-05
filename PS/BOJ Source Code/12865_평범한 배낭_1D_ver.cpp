#include <iostream>
#include <cmath>

using namespace std;

int w[501];
int v[501];
int dp[100001];

int main() {
	int n, wm;
	cin >> n >> wm;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", w + i, v + i);
	for (int i = 1; i <= n; i++) {
		for (int j = wm; j > 0; j--) {
			if (j >= w[i])
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[wm];
}

/*
* 2D ver에서는 ith 물건을 idx i에 저장했기 때문에 increasing order로 j를 탐색해도 됐었지만,
* 1D ver에서는 ith 물건을 고른다는 정보를 우리가 dp table의 가정으로 때웠기 때문에 j는 decreasing order를 사용해야한다.
*/