#include <iostream>

using namespace std;

int arr[1000000];
int temp[1000000];

void merge(int l, int r) {
	int mid = (l + r) / 2;
	int k=l, i  = l, j = mid+1;
	if (l >= r)
		return;
	merge(l, mid);
	merge(mid + 1, r);
	while (i <= mid && j <= r) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= r) temp[k++] = arr[j++];
	for (int i = l; i <= r; i++)
		arr[i] = temp[i];
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	merge(0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}