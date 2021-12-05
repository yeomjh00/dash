#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

ll func(ll a, ll b, ll c) {
	if (b > 1) {
		ll result = func(a, b / 2, c);
		if (b % 2 == 0)
			return (result * result) % c;
		else
			return ((result * result) % c) * a % c;
	}
	return a;
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << func(a%c, b, c);
}