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
* 2D ver������ ith ������ idx i�� �����߱� ������ increasing order�� j�� Ž���ص� �ƾ�����,
* 1D ver������ ith ������ ���ٴ� ������ �츮�� dp table�� �������� ������ ������ j�� decreasing order�� ����ؾ��Ѵ�.
*/