#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

int fence[20000];

int max_fence(int l, int r) {
	if (l == r) return fence[l];
	int mid = (l + r) / 2;
	int ans = 0;
	ans = max(max_fence(l, mid), max_fence(mid + 1, r));
	int left = mid, right = mid+1;
	int minh = min(fence[left], fence[right]);
	int area = 2 * minh;
	while (left > l || right < r) {
		if (right < r && ((fence[left - 1]) < fence[right + 1]) || l == left) {
			right++;
			minh = min(minh, fence[right]);
		}
		else {
			left--;
			minh = min(minh, fence[left]);
		}
		area = max(area, minh * (right - left + 1));
	}
	ans = max(ans, area);
	return ans;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		memset(fence, 0, sizeof(fence));
		for (int i = 0; i < n; i++)
			scanf(" %d", fence + i);
		cout << max_fence(0, n - 1) << "\n";
			
	}
}