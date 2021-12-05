#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

int n;
unsigned long long re;

matrix matmul(matrix a, matrix b) {
	matrix result(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				result[i][j] += (a[i][k] * b[k][j]) % 1000;
		}
	return result;
}

int main() {

	cin >> n >> re;
	matrix base(n, vector<int>(n));
	matrix ans(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j) ans[i][j] = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> base[i][j];



	while (re) {
		if (re & 1) {
			ans = matmul(ans, base);
		}


		base = matmul(base, base);
		re >>= 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", ans[i][j] % 1000);
		printf("\n");
	}


}