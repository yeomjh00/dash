//1929문제에서 가장 중요한 점은 에라토스테네스 체를 쓰는 것과 cout, endl 대신 printf를 사용하는 것이다.
// 애초에 cin, cout이 scanf, printf보다 더 많은 시간을 잡아먹는데, endl은 그 정점을 찍는다.
#include <iostream>
#include <cmath>

using namespace std;

bool num[1000001]; // num size는 그때그때 바꾸자.


int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int sqrtn = sqrt(n);
	fill_n(num, n + 1, 1);
	num[0] = num[1] = 0;

	for (int i = 2; i < sqrtn + 1; i++) {
		if (num[i] == 1) {
			for (int j = i * i; j <= n; j += i)
				num[j] = 0;
		}
	}
	for (int i = m; i <= n; i++)
		if (num[i] == 1)
			printf("%d\n", i);

}