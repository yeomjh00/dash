#include <iostream>
#include <cmath>
using namespace std;

int one[1000001] = { 0, };


int main(){
	int n;
	cin >> n;
	one[2] = one[3] = 1;
	for (int i = 4; i <= n; i++) {
		one[i] = 1e9;
		if (i % 2 == 0) one[i] = min(one[i], 1 + one[i / 2]);
		if (i % 3 == 0) one[i] = min(one[i], 1 + one[i / 3]);
		one[i] = min(one[i], 1 + one[i-1]);
	}

	cout << one[n];
}