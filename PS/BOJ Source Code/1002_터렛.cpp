#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int x1, y1, r1, x2, y2, r2, r, rm;
		double d;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		r = r1 + r2;
		rm = abs(r1 - r2);
		// 만나지 않을 때
		if (d > r)
			cout << "0";
		else if (d == 0 && r1 != r2)
			cout << "0";
		else if (d < rm)
			cout << "0";
		//무수히 많은 점에서 만날 때
		else if (d == 0 && r1 == r2)
			cout << "-1";
		// 한 점에서 만날 때
		else if (d == r || d == rm)
			cout << "1";
		else
			cout << "2";
		
		

		if (test > 0)
			cout << endl;
	}
}