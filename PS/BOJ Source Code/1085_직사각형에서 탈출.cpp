// 거리가 0부터 시작한다는 것을 주의해서 풀도록 하자!
#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	int dis = 1001;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (x < (w+1) / 2) {
		dis = x;
		if (y < (h+1) / 2)
			dis = min(dis, y);
		else
			dis = min(dis, h - y);
	}

	else {
		dis = w - x;
		if (y < (h + 1) / 2)
			dis = min(dis, y);
		else
			dis = min(dis, h - y);
	}
	printf("%d", dis);
}