#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	int ans = 0;
	stack<int> st;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (!tmp)
			st.pop();
		else
			st.push(tmp);
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans;
}
