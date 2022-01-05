#include <iostream>
#include <string>
#include <vector>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;
// normalize를 optimization하면 풀 수 있다.
// 다만, 모든 함수에 normalize과정을 넣으면 불가능하다.
/*
* Due to timeout, normalize become built-in func in addto, subfrom
vector<int> normalize(vector<int> a) {
	int sa = a.size();
	a.push_back(0);
	for (int i = 0; i < sa; i++) {
		if (a[i] < 0) {
			int borrow = (abs(a[i]) + 9) / 10;
			a[i + 1] -= borrow;
			a[i] += borrow * 10;
		}
		else if(a[i]>10){
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	return a;
}
*/


//substract a from b
void subfrom(vector<int>& a, vector<int>& b) {
	int sa = a.size(), sb = b. size();
	for (int i = 0; i < sa; i++) b[i] -= a[i];

	for (int i = 0; i < sb-1; i++) {
		if (b[i] < 0) {
			int borrow = (abs(b[i]) + 9) / 10;
			b[i + 1] -= borrow;
			b[i] += borrow * 10;
		}
	}
	return;
}

// a+= b * (10^k)
void addto(vector<int>& a, vector<int>& b, int k) {
	int sa = a.size(), sb = b.size();
	a.resize(max(sa, sb + k));
	for (int i = 0; i < sb; i++) a[i+k] += b[i];
	sa = a.size();
	a.push_back(0);
	for (int i = 0; i < sa; i++) {
		if (a[i] > 10) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	return;
}

vector<int> multiply(vector<int> a, vector<int> b) {
	int sa = a.size(), sb = b.size();
	vector<int> c(sa + sb + 1, 0);
	for (int i = 0; i < sa; i++) {
		for (int j = 0; j < sb; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	int sc = c.size();
	c.push_back(0);
	for (int i = 0; i < sc; i++) {
		if (c[i] > 10) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	return c;
}

// suppose a > b
vector<int> karatsuba(vector<int> a, vector<int> b) {
	int an = a.size(), bn = b.size();
	if (an == 0 || bn == 0) return vector<int>();
	if (an < bn) return karatsuba(b, a);
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	
	//fraction of a, b 
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addto(a1, a0, 0); addto(b1, b0, 0);
	vector<int> z1 = karatsuba(a1, b1);
	subfrom(z0, z1);
	subfrom(z2, z1);
	vector<int> ret;
	addto(ret, z0, 0);
	addto(ret, z1, half);
	addto(ret, z2, half + half);
	return ret;
}

int hug(string star, string fan) {
	int m = star.size(), n = fan.size();
	vector<int> st(m), f(n);
	for (int i = 0; i < m; i++) st[i] = (star[i] == 'M');
	for (int i = 0; i < n; i++) f[n-i-1] = (fan[i] == 'M');
	vector<int> ans = karatsuba(f, st);
	int hugs = 0;
	for (int i = m - 1; i<n; i++)
		if (ans[i] ==0) hugs++;

	return hugs;
} 

int main() {
	fastio;
	int tc;
	cin >> tc;
	while (tc--) {
		string star, fan;
		cin >> star >> fan;
		cout << hug(star, fan) << "\n";

	}
}