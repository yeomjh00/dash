#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;

	while (cin >> n) {
		string reverse, tmp;
		tmp = n;
		int len = n.length();
		for (int i = 0; i < len; i++) {
			reverse.push_back(tmp.back());
			tmp.pop_back();
		}
		if (n == "0")
			;
		else if (n == reverse)
			cout << "yes\n";
		else
			cout << "no\n";
	}


	return 0;
}
