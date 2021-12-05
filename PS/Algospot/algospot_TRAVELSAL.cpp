#include <iostream>
#include <vector>

using namespace std;
double dis[8][8];
int n;

double sail(vector<int> rest, double distance) {
	if (rest.size() == n) return distance;
	double ret = 1e9;
	for (int i = 0; i < n; i++) {
		int next = i;
		for (int j = 0; j < rest.size(); j++)
			if (rest[j] == next)
				next = -1;
		if (next == -1) continue;
		int now = rest.back();
		rest.push_back(next);
		ret =min(ret, sail(rest, distance+dis[now][next]));
		rest.pop_back();
	}
	return ret;
}


int main() {
	int tc;
	cin >> tc;
	cout << fixed;
	cout.precision(8);
	while (tc--) {
		cin >> n;
		double ans = 1e9;
		vector<int> path;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf(" %lf", dis[i] + j);
		for (int i = 0; i < n; i++) {
			path.push_back(i);
			ans = min(ans, sail(path, 0));
			path.pop_back();
		}

		cout << ans << "\n";
	}
}