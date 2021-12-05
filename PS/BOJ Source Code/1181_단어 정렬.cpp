/* 이 문제를 통해 배울 수 있는 점.
*  1. unique 사용법. unique(start_iterator, end_iterator)
*  - 배열된 상태에서 사용해야 하며, 중복된 값들을 그대로 뒤로 밀어버린다.
*  - 리턴 값은 중복된 값이 시작하는 부분의 iterator이다.
*  2. scanf, printf 로 string type을 입출력하는데는 많은 어려움이 따른다. 순순히 cin cout을 사용하자.
*  3. erase 로 단일 값만 지우는게 아니라, iterator로 range를 만들어서 해당 range를 지울 수 있다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	int as = a.length();
	int bs = b.length();
	if (as != bs)
		return as < bs;
	else
		return a < b;
}

int main() {
	vector<string> ans;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ans.push_back(s);
	}
	sort(ans.begin(), ans.end(), cmp);
	vector<string>::iterator last = unique(ans.begin(), ans.end());
	ans.erase(last, ans.end());
	int l = ans.size();
	for (int i = 0; i < l; i++)
		cout << ans[i] << "\n";
}