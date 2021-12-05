// 0~i������ ���������� i~n������ ���Ҽ����� ���� �ִ�!
#include <iostream>
#include <cmath>

using namespace std;

int l[1000];
int du[1000];
int dd[1000];


int main() {
	int ans1 = 0;
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", l + i);
	for (int i = 0; i < n; i++) {
		du[i] = 1;
		for (int j = 0; j < i; j++)
			if (l[i] > l[j])
				du[i] = max(du[j] + 1, du[i]);
	}
	for (int i = n-1; i>=0; i--) {
		dd[i] = 1;
		for (int j = n-1; j > i; j--)
			if (l[i] > l[j])
				dd[i] = max(dd[j] + 1, dd[i]);
	}
	for (int i = 0; i < n; i++) 
		ans = max(ans, dd[i] + du[i]);
	ans -= 1;
	cout << ans;
}