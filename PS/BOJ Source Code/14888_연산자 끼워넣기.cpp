#include<iostream>
#include <vector>
#include <cmath>
using namespace std;


int s;
int up=-1e9, down=1e9;
vector<int> n;

int cal(int tot, int n, int i) {
	switch (i) {
	case 0:
		return tot + n;
	case 1:
		return tot - n;
	case 2:
		return tot * n;
	case 3:
		return tot / n;
	}
}

void sol(int step, int ans, int opr[4]) {
	if (step == s) {
		up = max(up, ans);
		down = min(down, ans);
		return;
	}
	for (int j = 0; j < 4; j++) {
		if (!opr[j]) continue;
		opr[j]--;
		sol(step + 1, cal(ans, n[step], j),opr);
		opr[j]++;
	}
	return ;
}



int main() {
	int opr[4];
	cin >> s;
	for (int i = 0; i < s; i++) {
		int tmp;
		cin >> tmp;
		n.push_back(tmp);
	}
	for (int i = 0; i < 4; i++)
		cin >> opr[i];
	s = n.size();
	sol(1, n[0], opr);
	cout << up << "\n" << down;

}