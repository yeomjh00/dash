#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<pair<int, int>> data;
	vector<int> ans(1000001);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		data.push_back({ tmp, i });
	}
	sort(data.begin(), data.end());
	int tmp = data[0].first;
	int rank = 0;
	for (int i = 0; i < n; i++) {
		if (data[i].first == tmp) {
			ans[data[i].second] = rank;
		}
		else {
			rank++;
			tmp = data[i].first;
			ans[data[i].second] = rank;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
}