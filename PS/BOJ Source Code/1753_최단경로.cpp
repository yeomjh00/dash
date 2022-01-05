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
//int adl[20001][20001]; 메모리 초과 발생 ->인접행렬이 아니라 인접리스트로 가보자
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
	//path 배열 초기화
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
* 틀린 포인트
* 1. 메모리 제한 : 첫 시도 때 20000 * 20000 배열을 때려버렸더니 메모리 초과가 나왔다.
* 2. 시간 제한 : 우선순위 큐가 아닌 O(N^2) index selecting algorithm을 사용했더니 시간 초과가 나왔다.
* 3. 큐에 updated data를 넣는 걸 깜빡했다.
*/