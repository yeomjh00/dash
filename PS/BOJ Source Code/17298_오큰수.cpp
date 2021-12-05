#include <iostream>
#include <utility>
#include <stack>

using namespace std;

int rnk[1000000];

int main() {
	int n;
	cin >> n;
	stack<pair<int,int>> st;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (st.empty()) st.push({ tmp, i });

		else {
			while (st.top().first < tmp) {
				rnk[st.top().second] = tmp;
				st.pop();
				if (st.empty())
					break;
			}
			st.push({ tmp, i });
		}

	}
	while (!st.empty()) {
		rnk[st.top().second] = -1;
		st.pop();
	}
	for (int i = 0; i < n; i++)
		printf("%d ", rnk[i]);
}