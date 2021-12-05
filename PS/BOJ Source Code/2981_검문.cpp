#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num[100];

int uclid(int n, int m) {
	int tmp;
	if (m > n)
		swap(n, m);
	while (m) {
		tmp = m;
		m = n % m;
		n = tmp;
	}
	return n;
}

int main() {
	int n, tmp=0, ans=0;
	vector<int> narr;
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", num + i);
	sort(num, num + n);
	ans = num[1] - num[0];
	for (int i = 2; i < n; i++) {
		ans = uclid(ans, num[i]-num[i-1]);
	}
	for (int i = 2; i*i <= ans; i++) {
		if (!(ans % i)) {
			narr.push_back(i);
			if (i != ans / i)
				narr.push_back(ans / i);
		}
	}
	narr.push_back(ans);
	sort(narr.begin(), narr.end());
	for (int i = 0; i < narr.size(); i++)
		printf("%d ", narr[i]);
}