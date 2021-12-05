#include <iostream>
#define ull unsigned long long

using namespace std;

ull mod = 1000000007;

ull hyper_pow(ull a, ull pow) {
	ull ans = 1;
	while (pow) {
		if (pow & 1)
			ans = (ans*a)%mod;
		a = (a * a) % mod;
		pow >>= 1;
	}
	return ans;
}

int main() {
	ull n, k;
	ull ans = 1, nk=1;
	cin >> n >> k;

	for (ull i = 2; i <= n; i++)
		ans = (ans * i) % mod;
	for (ull i = 2; i <= k; i++)
		nk = (nk * i) % mod;
	for (ull i = 2; i <= n-k; i++)
		nk = (nk * i) % mod;
	nk = hyper_pow(nk, mod - 2);
	cout << (ans * nk) % mod;
}