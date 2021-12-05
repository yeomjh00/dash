// we have stable_sort, it is different from just sort.
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	vector<pair<int, string>> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int m;
		cin >> m >> s;
		ans.push_back(make_pair(m, s));
	}
	stable_sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}