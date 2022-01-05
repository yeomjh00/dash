#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};
int v, e, s ;
int path[20001];
int visit[20001];
//int adl[20001][20001]; �޸� �ʰ� �߻� ->��������� �ƴ϶� ��������Ʈ�� ������
vector<vector<pair<int,int>>> adl(20001);
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;



int main() {
	cin >> v >> e;
	cin >> s;
	int start = s;
	int t1, t2, t3;
	// adl[departure]={destination, value}
	for (int i = 0; i < e; i++) {
		scanf(" %d %d %d", &t1, &t2, &t3);
		adl[t1].push_back({ t2, t3 });
	}
	//path �迭 �ʱ�ȭ
	for (int i = 1; i <= v; i++) path[i] = 1e9;

	path[start] = 0;
	q.push({ start, 0 });

	while (!q.empty()) {
		int starting = q.top().first, val = q.top().second;
		q.pop();
		if (visit[starting] == 1) continue;
		visit[starting] == 1;
		for (int i = 0; i < adl[starting].size(); i++) {
			int next = adl[starting][i].first, nextval = adl[starting][i].second + val;
			if (nextval < path[next]) {
				path[next] = nextval;
				q.push({ next, nextval });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (path[i] == 1e9)
			cout << "INF\n";
		else
			cout << path[i] << "\n";
	}
}
/*
* Ʋ�� ����Ʈ
* 1. �޸� ���� : ù �õ� �� 20000 * 20000 �迭�� �������ȴ��� �޸� �ʰ��� ���Դ�.
* 2. �ð� ���� : �켱���� ť�� �ƴ� O(N^2) index selecting algorithm�� ����ߴ��� �ð� �ʰ��� ���Դ�.
* 3. ť�� updated data�� �ִ� �� �����ߴ�.
*/