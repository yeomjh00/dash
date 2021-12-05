#include <iostream>
#include <cmath>
#include <utility>
#define ull long long int

using namespace std;

// for�� �ȿ� �ִ� i�� ull a �� ���Ե� �� ������, ull�� �����ϵ��� ����.
pair<ull, ull> count25(ull a) {
	ull two = 0, five = 0;
	for (ull i = 2; i <= a; i *= 2)
		two += (a / i);

	for (ull i = 5 ; i <= a; i *= 5)
		five += (a / i);
	return make_pair( two, five );
}

int main() {
	ull n, k, two, five;
	pair<ull, ull> cn, ck, cnk;
	cin >> n >> k;

	cn = count25(n);
	ck = count25(k);
	cnk = count25(n - k);
	two = cn.first - ck.first - cnk.first;
	five = cn.second - ck.second - cnk.second;
	ull ans = two < five ? two : five;
	cout << ans;
}