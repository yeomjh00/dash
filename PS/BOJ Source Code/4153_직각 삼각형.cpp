#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int ed[3] = { 1,1,1 };
	while (true) {
		for (int i = 0; i < 3; i++)
			scanf("%d", ed + i);

		if (!(ed[0] && ed[1] && ed[2]))
			break;

		sort(ed, ed + 3);
		if (pow(ed[2], 2) == pow(ed[0], 2) + pow(ed[1], 2))
			printf("right\n");
		else
			printf("wrong\n");
	}

}