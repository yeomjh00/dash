/* �� ������ ���� ��� �� �ִ� ��.
*  1. unique ����. unique(start_iterator, end_iterator)
*  - �迭�� ���¿��� ����ؾ� �ϸ�, �ߺ��� ������ �״�� �ڷ� �о������.
*  - ���� ���� �ߺ��� ���� �����ϴ� �κ��� iterator�̴�.
*  2. scanf, printf �� string type�� ������ϴµ��� ���� ������� ������. ������ cin cout�� �������.
*  3. erase �� ���� ���� ����°� �ƴ϶�, iterator�� range�� ���� �ش� range�� ���� �� �ִ�.
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