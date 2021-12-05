// 같은 종류에 대해서, 입거나, 안 입거나 경우가 2가지 있으므로 (각 종류의 수 + 1)을 곱해주고, (안 입는 경우 포함)
// 대신 모두 안 입는 경우가 발생하므로 답에서 1을 뺀 후 제출한다.
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int isin(vector<pair<string, int>> a, string str) {
	for (int i = 0; i < a.size(); i++)
		if (a[i].first == str)
			return i+1;
	return 0;
}


int main() {
	int test;
	cin >> test;
	while (test--) {
		int n, ind;
		cin >> n;
		vector<pair<string, int>> clth;
		for (int i = 0; i < n; i++) {
			string clo, typ;
			cin >> clo >> typ;
			if (ind = isin(clth, typ))
				clth[ind - 1].second++;
			else
				clth.push_back({ typ, 1 });
		}
		int ans = 1;
		for (int i = 0; i < clth.size(); i++)
			ans *= (clth[i].second+1);
		ans -= 1;
		cout << ans << "\n";

	}
}