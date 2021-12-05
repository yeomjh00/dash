#include <iostream>

using namespace std;

int arr[1000];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void insertion(int n) {
	for (int i = 1; i < n; i++) {
		int tmp = arr[i];
		for (int j = i ; j >0; j--) {
			if (arr[j - 1] > tmp)
				swap(arr + j, arr + j - 1);
			else {
				arr[j] = tmp;
				break;
			}
		}
	}
	return;
}

void bubble(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr + j, arr + j + 1);
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	bubble(n);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}