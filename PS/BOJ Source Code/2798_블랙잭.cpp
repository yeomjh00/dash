#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int my = 0;
	int ab = 100000;
	int n, ans;
	int val[101] = { 0 };
	cin >> n >> ans;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				int tmp = val[i] + val[j] + val[k];
				int dif = ans - tmp;
				if (dif >= 0 && dif <= ab) {
					ab = dif;
					my = tmp;	
				}
			}
		}
	}
	cout << my;
}