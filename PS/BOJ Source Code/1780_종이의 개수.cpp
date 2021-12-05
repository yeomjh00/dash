#include <iostream>
#include <string>

using namespace std;

int t[2187][2187];
int col[3];

bool check(int y, int x, int e) {
	int a = t[y][x];
	for (int i = y; i < y + e; i++)
		for (int j = x; j < x + e; j++)
			if (a != t[i][j])
				return false;
	return true;
}

void pap(int y, int x, int e) {
	if (check(y, x, e)) {
		col[t[y][x] + 1]++;
		return;
	}
	int k = e / 3;
	for (int i = 0; i < e; i += k)
		for (int j = 0; j < e; j += k)
			pap(y + i, x + j, e / 3);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", t[i] + j);

	pap(0, 0, n);

	cout << col[0] << "\n" << col[1] << "\n" << col[2];
}