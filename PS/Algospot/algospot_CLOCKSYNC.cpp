#include <iostream>
#include <vector>

using namespace std;

int button[10][5] = {
	{0,1,2, -1, -1},
	{3,7,9,11, -1},
	{4,10,14,15, -1},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15, -1},
	{3, 14, 15, -1, -1},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

bool check(const vector<int>& clck) {
	for (int i = 0; i < 16; i++)
		if (clck[i])
			return false;
	return true;
}

void push(vector<int>& clck, int type) {
	if (type > -1) {
		for (int i = 0; i < 5; i++)
			if (button[type][i] != -1)
				clck[button[type][i]] = (clck[button[type][i]] + 1) % 4;
	}
	return;
}

int press(vector<int> clck, int type) {
	if (type == 10)return check(clck) ? 0 : 1e9;
	int ans = 1e9;

	for (int i = 0; i < 4; i++) {
		ans = min(ans, i + press(clck, type + 1));
		push(clck, type);
	}
	return ans;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		vector<int>clck(16);
		for (int i = 0; i < 16; i++) {
			int tmp;
			scanf(" %d", &tmp);
			clck[i] = (tmp / 3) % 4;
		}
		int ans = press(clck, 0);
		if (ans == 1e9)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
}