#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<unsigned int, unsigned int> t[100000];

bool cmp(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int ans = 0;
	int end = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &t[i].first, &t[i].second);
	sort(t, t + n, cmp);
	end = t[0].second;
	ans = 1;
	for (int i = 1; i < n; i++) {
		if (end > t[i].first)continue;
		end = t[i].second;
		ans++;
	}
	cout << ans;
}