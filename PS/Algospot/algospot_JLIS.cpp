#include <iostream>
#include <cmath>
#include <memory.h>
#include <limits.h>
using namespace std;

int a[100], b[100];
int dp[101][101];
long long mini = LLONG_MIN;
int na, nb;


int jlis(int ai,int bi) {
	int& ret = dp[ai + 1][bi + 1];
	if (ret !=-1) return ret;

	long long ea = ai == -1 ? mini : a[ai];
	long long eb = bi == -1 ? mini : b[bi];
	long long nextele = max(ea, eb);
	ret = 0;

	for (int nexta = ai + 1; nexta < na; nexta++)
		if(nextele < a[nexta])
			ret = max(ret, jlis(nexta, bi)+1);
	for (int nextb = bi + 1; nextb < nb; nextb++)
		if(nextele < b[nextb])
			ret = max(ret, jlis(ai, nextb)+1);

	return ret;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cin >> na >> nb;
		for (int i = 0; i < 101; i++) memset(dp[i], -1, sizeof(dp[i]));
		for (int i = 0; i < na; i++) scanf(" %d", a + i);
		for (int i = 0; i < nb; i++) scanf(" %d", b + i); 
		cout << jlis(-1, -1) << "\n";
	}
}