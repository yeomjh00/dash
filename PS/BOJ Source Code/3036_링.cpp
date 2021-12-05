#include <iostream>
#include <iostream>

using namespace std;

int ring[100];

int uclid(int n, int m) {
	if (m > n)
		swap(n, m);
	while (n % m != 0) {
		while (n > m) {
			n -= m;
		}
		swap(n, m);
	}
	return m;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", ring + i);
	int std = ring[0];
	for (int i = 1; i < n; i++) {
	int tmp = uclid(std, ring[i]);
	printf("%d/%d\n", std / tmp, ring[i] / tmp);
	}

}