#include <iostream>
#define ll long long
using namespace std;

ll psum[92683];

int main() {
	ll n;
	int ans;
	cin >> n;
	psum[0] = 0;
	for (int i = 1; i <= 92682; i++)
		psum[i] = psum[i - 1] + i;
	for(int i=0;i<=92682;i++)
		if (n < psum[i]) {
			ans = i - 1;
			break;
		}
	cout << ans;
}