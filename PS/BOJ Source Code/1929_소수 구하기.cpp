//1929�������� ���� �߿��� ���� �����佺�׳׽� ü�� ���� �Ͱ� cout, endl ��� printf�� ����ϴ� ���̴�.
// ���ʿ� cin, cout�� scanf, printf���� �� ���� �ð��� ��ƸԴµ�, endl�� �� ������ ��´�.
#include <iostream>
#include <cmath>

using namespace std;

bool num[1000001]; // num size�� �׶��׶� �ٲ���.


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