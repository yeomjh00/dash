#include <iostream>
#include <cstring>

using namespace std;

string subquad(string ori, int off) {
	int i = 0, end = 1;
	while (i < end) {
		if (ori[off + i] == 'x')
			end += 4;
		i++;
	}
	return ori.substr(off, i);
}

string quadtree(string ori) {
	if (ori.length() == 1)
		return ori;
	int off = 1;
	string subs[4];
	for (int i = 0; i < 4; i++) {
		subs[i] = subquad(ori, off);
		off += subs[i].length();
	}
	string tmp = subs[0];
	subs[0] = subs[2]; subs[2] = tmp;
	tmp = subs[1];
	subs[1] = subs[3]; subs[3] = tmp;
	tmp = "x";
	for (int i = 0; i < 4; i++)
		tmp += quadtree(subs[i]);
	return tmp;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string t;
		cin >> t;
		cout << quadtree(t) << "\n";
	}

}