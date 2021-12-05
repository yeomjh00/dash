#include <iostream>

using namespace std;

int f[10][10];
int v[10];

int partner(int n_tot, int n_now) {
	int ans = 0, first;
	if (n_tot == n_now) return 1;
	for(int i=0;i<n_tot;i++)
		if (v[i] == 0) {
			first = i;
			break;
		}

	for (int j = 0; j < n_tot; j++) {
		if (f[first][j] == 1 && v[j]==0) {
			v[first] = v[j] = 1;
			ans+=partner(n_tot, n_now + 2);
			v[first] = v[j] = 0;
		}
	}

	return ans;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, nrel, a,b;
		cin >> n >> nrel;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				f[i][j] = 0;
		for (int i = 0; i < 10; i++)
			v[i] = 0;
		for (int i = 0; i < nrel; i++) {
			scanf(" %d %d", &a, &b);
			f[a][b] = f[b][a] = 1;
		}
		cout << partner(n, 0) << "\n";

	}
}