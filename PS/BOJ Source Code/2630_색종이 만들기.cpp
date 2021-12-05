#include <iostream>

using namespace std;

int pa[128][128];

int blue = 0, white = 0;

bool check(int y, int x, int e) {
	if (e == 1)
		return true;

	int color = pa[y][x];
	for (int i = y; i < y + e; i++) {
		for (int j = x; j < x + e; j++) {
			if (color != pa[i][j])
				return false;
		}
	}
	return true;
}

void div(int y, int x, int e) {
	if (check(y, x, e)) {
		if (pa[y][x] == 1)
			blue++;
		else
			white++;
		return;
	}
	else {
		div(y, x, e / 2);
		div(y+e/2, x, e / 2);
		div(y, x+e/2, e / 2);
		div(y+e/2, x+e/2, e / 2);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", pa[i] + j);
	div(0, 0, n);
	cout << white << "\n" << blue;

}