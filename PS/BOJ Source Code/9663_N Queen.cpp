// vector[i]==j라고 할 때, ith row에 jth column에 queen이 있다.
//대각선의 queen을 확인하는 방법은 두 queen의 i의 변화량과 j의 변화량이 똑같으면 대각선이다. (절댓값 비교)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> pos;

// suppose that already inserted elements in pos is not collasped each other.
bool chk() {
	if (pos.empty()) return false;
	if (pos.size() == 1) return true;
	int row = pos.size() - 1;
	int col = pos.back();
	for (int i = 0; i < pos.size()-1; i++) {
		int drow = abs(row - i);
		int dcol = abs(col - pos[i]);
		if (drow == dcol) return false;
	}
	return true;
}

int Q(int n, int m) { //n은 놓아야할 퀸의 수, m은 현재 놓은 퀸의 수
	if (n == m)
		return 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int ind = 0;
		for (int j = 0; j < pos.size(); j++)
			if (pos[j] == i) ind = 1;
		if (ind) continue;
		pos.push_back(i);
		if (chk())
			ans+=Q(n, m + 1);
		pos.pop_back();
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int ans = Q(n, 0);
	printf("%d", ans);
}