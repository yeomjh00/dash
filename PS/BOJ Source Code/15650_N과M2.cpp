//parameter에 가장 큰 수가 들어있다고 가정하고 그 수를 통해서 비교.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
bool v[9];
vector<int>path;

void ans(int step, int mx) {
	if (step == m) {
		for (int i = 0; i < path.size(); i++) printf("%d ", path[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] || mx>i) continue;
		path.push_back(i);
		v[i] = 1;
		ans(step + 1, i);
		v[i] = 0;
		path.pop_back();
	}
}

int main() {
	cin >> n >> m;
	ans(0, 0);
}