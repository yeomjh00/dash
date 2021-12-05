#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int num;
int pwr[21][21];
int tot = 0;
int ans = 1e9;
vector<int> plyr;

int scr(vector<int> v) {
	int tmp = 0;
	int s = v.size();
	for (int i = 0; i < s; i++) {
		for (int j = i; j < s; j++) {
			tmp += pwr[v[i]][v[j]];
		}
	}
	return tmp;
}

void match(int stp) {
	if (stp == num/2) {
		int j = 0;
		vector<int> temp;
		for (int i = 1; i <= num; i++) {
			if (i == plyr[j]) {
				j++;
				if (j == plyr.size()) j--;
				continue;
			}
			temp.push_back(i);
		}
		int tmp = scr(plyr);

		int opp = scr(temp);
		ans = min(abs(opp-tmp),ans);
		return;
	}
	int s = plyr.size();
	for (int i =1; i <= num; i++) {
		if (!plyr.empty() && plyr[stp - 1] >= i) continue;
		plyr.push_back(i);
		match(stp + 1);
		plyr.pop_back();
	}
	return;
}

int main() {
	cin >> num;
	// i와j가 같은 팀에 있을 때 나오는 시너지를 합쳐버렸다.
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++) {
			cin >> pwr[i][j];
			tot += pwr[i][j];
			if (i > j) {
				pwr[j][i] += pwr[i][j];
				pwr[i][j] = 0;
			}
		}
	match(0);
	cout << ans;



}