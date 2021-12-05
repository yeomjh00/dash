#include <iostream>

using namespace std;

int main() {
	int test;
	cin >> test;
	while (test--) {
		int x, y, n;
		unsigned int i = 1, ans=0;
		cin >> x >> y;
		n = y - x;
		for (i = 1; ; i++) {
			if (i * i >= n) {
				ans = 2 * i - 1;
				break;
			}
			else if (i * i + i >= n) {
				ans = 2 * i;
				break;
			}
		}
		cout << ans << endl;
	}
}