#include <iostream>

using namespace std;

int main() {
	int n;
	int h[50];
	int w[50];
	int r[50] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", w + i, h + i);

	for (int i = 0; i < n; i++) {
		int k = 1;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (w[i] < w[j] && h[i] < h[j])
					k++;
			}
		}
		r[i] = k;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", r[i]);
}