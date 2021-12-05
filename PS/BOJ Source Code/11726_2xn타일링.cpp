#include <iostream>

using namespace std;

int pi[1001];

int main() {
	int n;
	cin >> n;
	pi[1] = 1;
	pi[2] = 2;
	for (int i = 3; i <= n; i++)
		pi[i] = (pi[i - 1] + pi[i - 2])%10007;
	cout << pi[n];
}