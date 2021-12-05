#include <iostream>

using namespace std;

int main() {
	int h, u, d;
	int day, cliday;
	int tmp=1;
	cin >> u >> d >> h;
	cliday = u - d;
	if (h <= u)
		cout << '1';
	else {
		day = (h - u) / (cliday);
		if ((h - u) % cliday)
			tmp++;
		cout << day+tmp;
	}
}