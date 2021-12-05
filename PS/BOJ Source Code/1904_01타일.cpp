#include <iostream>

using namespace std;

int tile[1000001] = { 0, };

int main() {
	int n;
	cin >> n;
	tile[1] = 1;
	tile[2] = 2;
	for (int i = 3; i <= n; i++) {
		tile[i] = tile[i - 1] + tile[i - 2];
		tile[i] %= 15746;
	}
	cout << tile[n];
}