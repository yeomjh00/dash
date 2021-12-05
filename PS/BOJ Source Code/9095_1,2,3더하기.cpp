#include <iostream>

using namespace std;

int num[10];

int main() {
	int test;
	cin >> test;
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;
	for (int i = 4; i < 11; i++)
		num[i] = num[i - 1] + num[i - 2] + num[i - 3];
	while (test--) {
		int n;
		cin >> n;
		cout << num[n] << "\n";
	}

}