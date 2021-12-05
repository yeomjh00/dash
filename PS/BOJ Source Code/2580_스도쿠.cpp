#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int tab[9][9];
bool com = false;
int num;
vector<pair<int, int>> pos;

//결함이 있을 경우 true로 return
bool check(int y, int x, int k) {
	int nx = 3 * (x / 3);
	int ny = 3 * (y / 3);
	for (int i = 0; i < 9; i++)
		if (tab[y][i] == k) return true;
	for (int i = 0; i < 9; i++)
		if (tab[i][x] == k) return true;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tab[ny + i][nx + j] == k) return true;
	return false;
}

void sol(int step) {
	int s = pos.size();
	if (com)return;
	if (step == num) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", tab[i][j]);
			printf("\n");
		}
		com = true;
		return;
	}

	for (int i = step; i < num; i++) {
		int y = pos[i].first;
		int x = pos[i].second;
		for (int j = 1; j <= 9; j++) {
			if (check(y, x, j)) continue;
			tab[y][x] = j;
			sol(step + 1);

		}
		tab[y][x] = 0;
		return;
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int tmp;
			cin >> tmp;
			tab[i][j] = tmp;
			if (!tmp) pos.push_back({ i,j });
		}
	num = pos.size();
	sol(0);
}