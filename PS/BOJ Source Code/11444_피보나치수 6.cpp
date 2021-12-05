#include <iostream>
#include <vector>
#define ull unsigned long long

using namespace std;

typedef vector<vector<ull>> matrix;

int mod = 1000000007;

matrix base = { {1,1},{1,0} };

matrix matmul(matrix a, matrix b) {
	matrix temp(2, vector<ull>(2));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				temp[i][j] += (a[i][k] * b[k][j])%mod;
	return temp;
}

int main() {
	ull n, ans=0;
	cin >> n;
	matrix sq = { {1,0},{0,1} };
	n -= 1;
	while (n) {
		if (n & 1) {
			sq = matmul(sq, base);
		}
		base = matmul(base, base);
		n >>= 1;
	}
	cout << sq[0][0]%mod;
}