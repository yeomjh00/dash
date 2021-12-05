#include <iostream>
#include <cstring>
using namespace std;

int w[21][21][21] = { 0, };

int fun(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return fun(20, 20, 20);
	int& tmp = w[a][b][c];
	if (tmp != 0) return tmp;
	else if (a < b && b < c)
		return tmp = fun(a, b, c - 1) + fun(a, b - 1, c - 1) - fun(a, b - 1, c);
	return tmp = fun(a - 1, b, c) + fun(a - 1, b - 1, c) + fun(a-1, b, c - 1) - fun(a - 1, b - 1, c - 1);
}

int main() {
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	while (!(a == -1 && b == -1 && c == -1)) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, fun(a, b, c));
		cin >> a >> b >> c;
	}
}