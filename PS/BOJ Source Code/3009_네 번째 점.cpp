#include <iostream>

using namespace std;

int main() {
	int x[3];
	int y[3];
	int px, py;
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", x + i, y + i);
	}
	if (x[0] == x[1])
		px = x[2];

	else if (x[1] == x[2])
		px = x[0];

	else
		px = x[1];

	if (y[0] == y[1])
		py = y[2];

	else if (y[1] == y[2])
		py = y[0];

	else
		py = y[1];

	cout << px << ' ' << py;
}