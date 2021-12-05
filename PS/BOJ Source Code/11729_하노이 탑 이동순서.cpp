#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int mid, int end) {
	if (n == 1) {
		printf("%d %d\n", start, end);
		return;
	}
	hanoi(n - 1, start, end, mid);
	printf("%d %d\n", start, end);
	hanoi(n - 1, mid, start, end);
}

int main() {
	int n;
	cin >> n;
	int ans = pow(2, n) - 1;
	printf("%d\n", ans);
	hanoi(n, 1, 2, 3);

}