#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

//dp(i,j) = dp(wi, si)
/* dp table 정의 :
* dp(wi,si)는 각 w[wi], s[si]까지 match되었을 때를 나타내며
* 1은 matched, 0은 unmatched -1는 uncalculated 이다.
*/
int dp[101][101];
int n;
string s, w;
int wildcard(int si, int wi) {
	int& ret = dp[wi][si];
	if (ret != -1)
		return ret;
	if (si < s.size() && wi < w.size() && (w[wi] == '?' || s[si] == w[wi])) {
		return ret = wildcard(si + 1, wi + 1);
	}
	if (wi == w.size()) return ret = (si == s.size());
	else if (w[wi] == '*')
		if ((si<s.size() && wildcard(si+1, wi)) || wildcard(si, wi+1)) return ret = 1;
	return ret = 0;
}


int main() {
	int tc; cin >> tc;
	while (tc--) {

		cin >> w;
		cin >> n;
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < 101; j++) memset(dp[j], -1, sizeof(dp[j]));
			if (wildcard(0, 0))
				ans.push_back(s);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

	}
}