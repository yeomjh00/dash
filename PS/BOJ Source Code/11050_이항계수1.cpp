#include <iostream>

using namespace std;

int main() {
	int n, k;
	int ans=1;
	cin >> n >> k;
	int j = k;
	for (int i = n; j > 0; i--, j--)
		ans *= i;
	for (int i = k; i > 1; i--)
		ans /= i;

	cout << ans;
}