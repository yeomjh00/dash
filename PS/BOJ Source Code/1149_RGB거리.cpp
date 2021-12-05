/* ���� ������ ��,
* pt[i][j]���� j��° ���� i��°������ ĥ�ϴµ� ��� ����̴�. �ٵ� �� ���, i�� �޸������� �ʹ� �ָ������� �ִ�.
* ĳ���� ���� �ִ�. ���� pt[1000][3]�� �� ���� ���̴�.
*/
#include <iostream>
#include <cmath>

using namespace std;

int pt[3][1000] = { 0, };

int cost[3][1000];

int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; j++)
		for (int i = 0; i < 3; i++)
			scanf("%d", pt[i] + j);
	cost[0][0] = pt[0][0];
	cost[1][0] = pt[1][0];
	cost[2][0] = pt[2][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp = 1e9;
			for (int k = 0; k < 3; k++) {
				if (j == k)continue;
				else if (tmp > cost[k][i-1])
					tmp = cost[k][i-1];
			}
			cost[j][i] = pt[j][i] + tmp;
		}
	}


	int ans = 1e9;
	for (int i = 0; i < 3; i++)
		ans = min(ans, cost[i][n - 1]);
	cout << ans;
}