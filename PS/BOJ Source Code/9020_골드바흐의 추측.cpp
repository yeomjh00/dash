#include <iostream>
#include <cmath>
using namespace	std;

int num[20001]; // num size는 그때그때 바꾸자.

int right(int i) {
	i += 1;
	while (num[i] == 0)
		i++;
	return i;
}

int left(int i) {
	i -= 1;
	while (num[i] == 0)
		i--;
	return i;
}

int main() {
	int test;
	scanf("%d", &test);

	fill_n(num, 20001, 1);
	num[0] = num[1] = 0;

	for (int i = 2; i < sqrt(20000) + 1; i++) {
		if (num[i] == 1) {
			for (int j = i * i; j <= 20000; j += i)
				num[j] = 0;
		}
	}

	while (test--) {
		int n, sum, r, l;
		scanf("%d", &n);
		r = l = n / 2;
		if (num[r] == 0) {
			r = right(r);
			l = left(l);
		}
		sum = r + l;
		while (sum != n) {
			sum = r + l;
			if (sum < n) {
				r = right(r);
			}
			else if (sum > n) {
				l = left(l);
			}
		}
		printf("%d %d\n", l, r);

	}
}