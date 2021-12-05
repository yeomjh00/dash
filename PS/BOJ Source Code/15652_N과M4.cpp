#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> path;

void ans(int step) {
	if (step == m) {
		for (int i = 0; i < path.size(); i++) printf("%d ", path[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(!path.empty())
			if (path.back() > i) continue;
		path.push_back(i);
		ans(step + 1);
		path.pop_back();
	}

}

int main() {
	cin >> n >> m;
	ans(0);
}