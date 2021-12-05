#include <iostream>

using namespace std;

int co[10];

int main() {
	int ans = 0;
	int n,val;
	cin >> n >> val;
	for (int i = 0; i < n; i++)
		scanf("%d", co + i);
	int i = n - 1;
	while (val) {
		while (val >= co[i]) {
			val -= co[i];
			ans++;
		}
		i--;
	}
	cout << ans;
}