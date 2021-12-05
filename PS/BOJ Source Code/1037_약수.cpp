// remind that the product of two integer might exceed the range of int.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	long long int ans;
	cin >> n;
	vector<long long int> a;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	ans = a[0] * a[a.size() - 1];
	cout << ans;

}