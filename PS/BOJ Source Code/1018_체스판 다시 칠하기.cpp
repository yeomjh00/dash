#include <iostream>
#include <cmath>
using namespace std;

char tab[50][50];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> tab[i][j];
	}
	int col = 10000000;

	int sb = 0;// start with black
	int sw = 0; // start with white
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			sb = sw = 0;
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if ((x + y) % 2 == 0)
					{
						if (tab[i + x][j + y] == 'B')
							sw++;
						else
							sb++;
					}
					else
					{
						if (tab[i + x][j + y] == 'B')
							sb++;
						else
							sw++;
					}
				}
			}
			col = min(col, sb);
			col = min(col, sw);
		}
	}
	cout << col;

}