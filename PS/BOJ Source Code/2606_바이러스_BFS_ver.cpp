#include <iostream>
#include <queue>

using namespace std;

int n;
bool ad[101][101];
bool visit[101];

int virus(int st) {
	int ans = 0, here;
	queue<int> net;
	net.push(st);
	visit[st] = true;
	while (!net.empty()) {
		here = net.front();
		net.pop();
		for (int i = 1; i <= n; i++) {
			if (ad[i][here] && (!visit[i])) {
				net.push(i);	
				ans++;
				visit[i] = true;
			}
		}
	}
	return ans;
}

int main() {
	cin >> n;
	int p, t1, t2;
	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> t1 >> t2;
		ad[t1][t2] = ad[t2][t1] = true;
	}
	cout << virus(1);
}