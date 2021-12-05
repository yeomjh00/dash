#include <iostream>
#include <string>
#include <stack>

using namespace std;

string bigsum(string a, string b);

int main() {
	string a, b;
	cin >> a >> b;
	if (a.length() < b.length())
		swap(a, b);
	string ans = bigsum(a, b);
	cout << ans;
}

string bigsum(string a, string b) {
	int j = a.length()-1;
	for (int i = b.length() - 1; i >= 0; i--, j--)
		a[j] = a[j] + b[i] - 48;;
	for (int i = a.length()-1; i > 0; i--) {
		if (a[i] > '9') {
			a[i - 1] += 1;
			a[i] -= 10;
		}
	}
	if (a[0] > '9') {
		string k = "1";
		a[0] -= 10;
		k += a;
		a = k;
	}
	return a;
}