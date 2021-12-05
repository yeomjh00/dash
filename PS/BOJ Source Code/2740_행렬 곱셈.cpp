#include <iostream>

using namespace std;

int a[100][100];
int b[100][100];
int c[100][100] = { 0, };

int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %d", a[i] + j);
	cin >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			scanf(" %d", b[i] + j);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int l = 0; l < m; l++)
				c[i][j] += (a[i][l] * b[l][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}

}