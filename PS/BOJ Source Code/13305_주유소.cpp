#include <iostream>
#include <cmath>
using namespace std;

int oilval[100000];
int d[100000];

int main() {
	int n, val;
	unsigned long long int tot_val = 0;
	unsigned long long int dist = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) scanf("%d", d + i);
	for (int i = 0; i < n; i++) scanf("%d", oilval + i);

	val = oilval[0];
	for (int i = 1; i < n; i++) {
		dist = d[i - 1];
		if (val < oilval[i]) {
			tot_val += (val * dist);
		}
		else {
			tot_val += (val * dist);
			val = oilval[i];
		}
	}
	cout << tot_val;

}