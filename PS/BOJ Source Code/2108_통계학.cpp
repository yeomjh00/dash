#include <iostream>
#include <cmath>
#define ze 4000
// counting sort을 사용할 것이다. 범위가 -4000~4000이므로 i는 arr[4000+i]에 저장할 것이다.
// remember that float cannot convert to int perfectly.
using namespace std;

int arr[8001] = { 0, };

int main() {
	double sum = 0;
	int cen, fre = 0;
	int n;
	int up=-5000, dwn=5000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
		arr[ze + tmp]++;
		if (up < tmp)
			up = tmp;
		if (dwn > tmp)
			dwn = tmp;
	}
	int mid = n / 2 + 1, fir=0, sec=0;
	for (int i = up+4000; i >= dwn+4000; i--) {
		mid -= arr[i];
		if (mid <= 0) {
			cen = i-4000;
			mid = n;
		}
		if (fre <= arr[i]) {
			fre = arr[i];
			sec = fir;
			fir = i;
		}
	}
	if (arr[fir] == arr[sec])
		fre = sec-4000;
	else
		fre = fir-4000;

	printf("%d\n", int(round(sum/n)));
	printf("%d\n", cen);
	printf("%d\n", fre);
	printf("%d", up - dwn);
}