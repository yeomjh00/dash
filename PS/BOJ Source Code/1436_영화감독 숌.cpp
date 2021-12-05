#include <iostream>

using namespace std;

int name(int n) {
	int cnt = 0;
	int tmp = n;
	while (n) {
		int num = n % 10;
		if (num == 6) {
			cnt++;
			if (cnt == 3)
				return tmp;
		}
		else
			cnt = 0;
		n /= 10;
	}
	return -1;
}

int main() {
	int n, ans=0,i=666;
	cin >> n;
	while (true) {
		int cnt = name(i);
		if (cnt != -1) {
			ans++;
			if (ans == n) {
				cout << cnt;
				break;
			}
		}
		i++;
	}
}