#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int stair[301] = { 0 };
	int best[301] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];
	best[1] = stair[1];
	best[2] = stair[1] + stair[2];
	for (int i = 3; i <= 300; i++) {
		best[i] = max(best[i - 3] + stair[i - 1], best[i - 2]) + stair[i];
	}
	cout << best[n];
	return 0;
}