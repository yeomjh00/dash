// ���� ������ ���ؼ�, �԰ų�, �� �԰ų� ��찡 2���� �����Ƿ� (�� ������ �� + 1)�� �����ְ�, (�� �Դ� ��� ����)
// ��� ��� �� �Դ� ��찡 �߻��ϹǷ� �信�� 1�� �� �� �����Ѵ�.
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