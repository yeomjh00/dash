#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

bool visit[100000];

int main() {
	int n, k,ans=0;
	cin >> n >> k;
	if (n >= k)
		cout << abs(n - k);
	else {
		queue<vector<int>> q;
		q.push({ n, });
		visit[n] = true;
		while (!q.empty()) {
			bool bre = false;
			vector<int>now = q.front(), next;
			q.pop();
			ans++;
			for (int i = 0; i < now.size(); i++) {
				int minus = now[i] - 1, plus = now[i] + 1, doub = 2 * now[i];
				if (minus == k || plus == k || doub == k) { bre = true; break; }
				if (minus >=0 && !visit[minus]) {
					next.push_back(minus);
					visit[minus] = true;
				}
				if (plus<100001&&!visit[plus]) {
					next.push_back(plus);
					visit[plus] = true;
				}
				if (doub<100001&&!visit[doub]) {
					next.push_back(doub);
					visit[doub] = true;
				}

			}
			if (bre) break;
			q.push(next);
		}
		cout << ans;
	}
}

//�׳� ������ ���������� O(3^x)�� �ð� ���⵵�̴�.
// �����̳� �ٸ� �Ǵ� ������ �ʿ��ϴٰ� �����ȴ�.