#include <iostream>

using namespace std;

int main() {
	int test;
	cin >> test;
	int apart[15][15] = { 0 };
	for (int i = 1; i < 15; i++) {
		apart[0][i] = i;
		apart[i][1] = 1;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 2; j < 15; j++) {
			apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
		}
	}
	while (test--) {
		int st, n;
		cin >> st >> n;
		cout << apart[st][n] << endl;
	}
}