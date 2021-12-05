#include <iostream>

using namespace std;

int main() {
	int test, h, w, n;
	cin >> test;
	while (test--) {
		cin >> h >> w >> n;
		int num, stry;
		num = n / h;
		if (n % h)
			num++;
		if (!(n % h))
			stry = h;
		else
			stry = n % h;
		cout << stry;
		cout.width(2);
		cout.fill('0');
		cout << num << endl;
	}
}