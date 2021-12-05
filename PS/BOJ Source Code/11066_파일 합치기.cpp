#include <iostream>
#include <algorithm>
#include <cmath>
#define inf 1e9
using namespace std;

int dat[500];
int psum[500];
int dp[500][500];

int merge(int a, int b) {
	int& ret = dp[a][b];
	if (a == b) return ret = 0;
	else if (ret !=1e9) return ret;
	
	int tmp = psum[b]-psum[a]+dat[a];
	for (int i = a; i < b; i++)
		ret = min(ret, merge(a,i)+merge(i+1,b)+tmp);
	return ret;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		int n;
		for (int i = 0; i < 500; i++)
			for (int j = 0; j < 500; j++)
				dp[i][j] = 1e9;
		for (int i = 0; i < 500; i++)
			psum[i] = 0;
		cin >> n;

		for (int i = 0; i < n; i++)
			scanf(" %d", dat + i);
		psum[0] = dat[0];
		for (int i = 1; i < n; i++)
			psum[i] = psum[i - 1] + dat[i];

		cout << merge(0,n-1) << "\n";
	

	}
}