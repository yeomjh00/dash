#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool v[9];
vector<int> path;

void ans(int step){
	if (step == m) {
		int s = path.size();
		for (int i = 0; i < s; i++)
			printf("%d ", path[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		path.push_back(i);
		v[i] = 1;
		ans(step + 1);
		v[i] = 0;
		path.pop_back();
	}
}

int main() {
	cin >> n >> m;
	ans(0);
}