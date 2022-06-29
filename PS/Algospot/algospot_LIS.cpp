#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int> seq) {
	vector<int>ans; ans.push_back(-1);
	int s = seq.size();
	for (int i = 0; i < s; i++) {
		if (seq[i] > ans.back()) {
			ans.push_back(seq[i]);
		}
		else{
			vector<int>::iterator idx = lower_bound(ans.begin(), ans.end(), seq[i]);
			ans[idx - ans.begin()] = seq[i];
		}
	}
	return ans.size() - 1;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>seq(n);
		for (int i = 0; i < n; i++) scanf(" %d", &seq[i]);
		cout << lis(seq) << "\n";
	}
}