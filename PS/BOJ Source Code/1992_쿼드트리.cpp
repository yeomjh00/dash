#include <iostream>
#include <string>

using namespace std;

char t[64][64];
string ans;

bool check(int y, int x, int e) {
	char a = t[y][x];
	for (int i = y; i < y + e; i++)
		for (int j = x; j < x + e; j++)
			if (a != t[i][j])
				return false;
	return true;
}

void quad(int y, int x, int e) {
	if (check(y, x, e)) {
		ans += t[y][x];
		return;
	}
	ans += '(';
	quad(y, x, e / 2);
	quad(y, x + e / 2, e / 2);
	quad(y + e / 2, x, e / 2);
	quad(y + e / 2, x + e / 2, e / 2);
	ans += ')';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", t[i] + j);

	quad(0, 0, n);

	cout << ans;
}