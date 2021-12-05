#include <iostream>

using namespace std;

int main() {
	int n, rem;
	int thr=0, fiv=0;
	cin >> n;
	fiv = n / 5;
	rem = n % 5;
	thr = rem / 3;
	rem %= 3;

	while (rem != 0) {
		if (fiv < 0)
			break;
		fiv -= 1;
		rem += 5;
		while (rem / 3) {
			rem -= 3;
			thr += 1;
		}
	}
	if (fiv < 0)
		cout << "-1";
	else
		cout << fiv + thr;
}