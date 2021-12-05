#include <iostream>
// 1 3 2 3

using namespace std;

int arr[1000000];
int srt[1000000];

int k=0;

void insert_binary(int e) {
	if (!k) {
		srt[0] = e;
		k++;
		return;
	}
	int l = 0, r = k - 1;
	int mid,ans=0;
	if (e > srt[r]) {
		srt[k] = e;
		k++;
		return;
	}
	while (l <= r) {
		mid = (l + r) / 2;
		if (e > srt[mid])
			l = mid + 1;
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	srt[ans] = e;
	return;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf(" %d", arr + i);
	for (int i = 0; i < n; i++)
		insert_binary(arr[i]);
	cout << k;
}