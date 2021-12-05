#include <iostream>
#include <memory.h>

using namespace std;

char tab[2187][2187] = {' '};

void star(int x, int y, int size) {
	if (size == 3) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if(i!=1 || j!=1)
					tab[x + i][y + j] = '*';
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			star(x+size / 3 * i, y+size / 3 * j, size / 3);
		}
	}
}

int main() {
	int n;
	cin >> n;
	memset(tab, ' ', sizeof(tab));
	star(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", tab[i][j]);
		printf("\n");
	}
}