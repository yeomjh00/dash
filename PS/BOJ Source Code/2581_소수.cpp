#include <iostream>
#include <cmath>
using namespace std;

int eratos(int n); //1~n������ �Ҽ��� ã�´�. �׸��� ������ ��ȯ���ش�.

int num[10001]; // num size�� �׶��׶� �ٲ���.


int main() {
	int m, n;
	int min, sum = 0, tmp = 1;
	cin >> m >> n;
	eratos(n);
	for (int i = m; i <= n; i++) {
		if (num[i] == 1) {
			sum += i;
			if (tmp) {
				min = i;
				tmp = 0;
			}
		}
	}
	if (sum == 0)
		cout << "-1";
	else
		cout << sum << endl << min;

}

int eratos(int n) {
	int ans = 0;
	fill_n(num, n + 1, 1);
	num[0] = num[1] = 0;

	for (int i = 2; i < sqrt(n) + 1; i++) {
		if (num[i] == 1) {
			for (int j = 2 * i; j <= n; j += i)
				num[j] = 0;
		}
	}
	return ans;
}