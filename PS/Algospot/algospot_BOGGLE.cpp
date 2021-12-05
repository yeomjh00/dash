#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool find[10];
const int x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
char board[5][5];

bool check_in(int y, int x) {
	if (y < 0 || x < 0 || x>4 || y>4) return false;
	return true;
}


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				scanf(" %c", board[i] + j);
		int n;
		vector<string> target;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			target.push_back(tmp);
		}


	}
}