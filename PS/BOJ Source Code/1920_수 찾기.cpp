#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int goal[100000];

int main() {
	int n,m,mid;
	int l, r;
	cin >> n;
	mid = 0;
	for (int i = 0; i < n; i++)
		scanf(" %d", arr + i);
	sort(arr, arr + n);
	cin >> m;

	for (int i = 0; i < m; i++)
		scanf(" %d", goal + i);

	for (int i = 0; i < m; i++) {
		int tmp = goal[i];
		l = 0;
		r = n - 1;

		while (1) {
			mid = (l + r) / 2;

			if (arr[mid] > tmp) {
				r = mid - 1;
			}
			else if(arr[mid]<tmp) {
				l = mid + 1;
			}
			else if(arr[mid]==tmp){
				printf("1\n");
				break;
			}

			if (l > r) {
				printf("0\n");
				break;
			}
		}
	}

}