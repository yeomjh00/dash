#include <iostream>
#include <cmath>
using namespace std;

int eratos(int n); //1~n������ �Ҽ��� ã�´�. �׸��� ������ ��ȯ���ش�.

int num[10000001]; // num size�� �׶��׶� �ٲ���.

int eratos(int n) {
	int ans = 0;
	fill_n(num, n+1, 1);
	num[0] = num[1] = 0;

	for (int i = 2; i < sqrt(n)+1; i++) {
		if (num[i] == 1) {
			for (int j = i * i; j <= n; j += i)
				num[j] = 0;
			}
		ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	eratos(n);


}


