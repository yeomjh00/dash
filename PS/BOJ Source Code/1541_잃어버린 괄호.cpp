#include <iostream>
#include <string>
using namespace std;

int main() {
	string st;
	cin >> st;
	int i=0, len=st.length();
	int tmp = 0, ans=0;
	int mc = 1;
	
	for (int i = 0; i < len; i++) {
		if (st[i] == '+') {
			ans += tmp;
			tmp = 0;
		}
		else if (st[i] == '-') {
			ans += tmp;
			mc = -1;
			tmp = 0;
		}
		else {
			tmp *= 10;
			tmp += (st[i] - '0')*mc;
		}
	}
	ans += tmp;
	cout << ans;
}
