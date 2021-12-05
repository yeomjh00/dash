#include <iostream>

using namespace std;

int main() {
	int i, tmp, n, up, down;
	cin >> n;
	i = 1;
	tmp = n;
	while (tmp > i) {
		tmp -= i;
		i++;
	}
	if(i%2==1)
		cout << i + 1 - tmp << '/' << tmp;
	else
		cout << tmp << '/' << i + 1 - tmp;
}