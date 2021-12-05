#include <iostream>

using namespace std;

unsigned long long st[101][10];

int main() {
	int n;
	cin >> n;
	for(int i=0;i<10;i++)
		st[1][i] = 1;
	st[1][0] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 10; j++) {
			if(j!=0)
				st[i][j] += st[i - 1][j - 1];
			if(j!=9)
				st[i][j] += st[i - 1][j + 1];
			st[i][j] %= 1000000000;
		}
	unsigned long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += st[n][i];
	ans %= 1000000000;
	cout << ans;
}