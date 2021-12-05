#include <iostream>
#include <algorithm>

using namespace std;

int mycard[500000];
int srch[500000];


int main() {
	int ans = 0;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf(" %d", mycard + i);
	sort(mycard, mycard + n);
	cin >> m;
	for (int i = 0; i < m; i++)
		scanf(" %d", srch + i);

	for (int i = 0; i < m; i++)
		printf("%d ", upper_bound(mycard, mycard+n,srch[i])-lower_bound(mycard,mycard+n,srch[i]));
}