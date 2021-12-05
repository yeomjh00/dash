#include<iostream>

using namespace std;

unsigned long long tri[101] = { 0, };

int main() {
	int test;
	cin >> test;
	tri[1] = 1;
	tri[2] = 1;
	tri[3] = 1;
	tri[4] = 2;
	tri[5] = 2;
	for (int i = 6; i < 101; i++)
		tri[i] = tri[i - 1] + tri[i - 5];
	while (test--) {
		int n;
		cin >> n;
		cout << tri[n] << "\n";
	}
}