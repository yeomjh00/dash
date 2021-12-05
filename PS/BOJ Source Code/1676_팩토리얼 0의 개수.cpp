#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int two = 0, five = 0;
	for (int i = 1; i <= n;i++) {
		int j = i;
		while (j % 2 == 0) {
			j /= 2;
			two++;
		}
		while (j % 5 == 0) {
			j /= 5;
			five++;
		}
	}
	cout << min(two, five);
}