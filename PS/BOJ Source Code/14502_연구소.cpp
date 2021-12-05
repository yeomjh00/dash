#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int r, c;
int area[8][8];
//check 도 dfs로 해야할 수 밖에 없다.
int check() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (area[i][j] == 0)
				;
}

int dfs(vector<pair<int, int>>& walls, int step) {
	if (step == 4) return 1;
}

int main() {
	cin >> r >> c;
	vector<pair<int, int>> walls;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			scanf(" %d", area[i] + j);
			if (area[i][j] == 1)
				walls.push_back({ i,j });
		}

}