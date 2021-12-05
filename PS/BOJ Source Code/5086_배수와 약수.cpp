#include <iostream>

using namespace std;

int main() {
	int n=1, m=1;
	cin >> n >> m;
	while (n && m) {
		if (m % n == 0)
			cout << "factor" << "\n";
		else if (n % m == 0)
			cout << "multiple" << "\n";
		else
			cout << "neither" << "\n";
		cin >> n >> m;
	}
}