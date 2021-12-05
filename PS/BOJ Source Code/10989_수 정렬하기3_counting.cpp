#include <iostream>

using namespace std;

int arr[10001] = { 0, };

int main() {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		while (arr[i]--) {
			printf("%d\n", i);
		}
	}
}