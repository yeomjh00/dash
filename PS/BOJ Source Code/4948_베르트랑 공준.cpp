#include <iostream>
#include <cmath>
using namespace std;

int eratos(int n); //1~n������ �Ҽ��� ã�´�. �׸��� ������ ��ȯ���ش�.

int num[246913]; // num size�� �׶��׶� �ٲ���.


int main() {
	int n=1;
	eratos(246912);
	while (n) {
		int ans = 0;
		scanf("%d", &n);
		if (!n)
			break;
		for (int i = n+1; i <= 2 * n; i++)
			if (num[i] == 1)
				ans++;
		printf("%d\n", ans);

	}

}

int eratos(int n) {
	int ans = 0;
	fill_n(num, n + 1, 1);
	num[0] = num[1] = 0;

	for (int i = 2; i < sqrt(n) + 1; i++) {
		if (num[i] == 1) {
			for (int j = i * i; j <= n; j += i)
				num[j] = 0;
		}
	}
	return 0;
}