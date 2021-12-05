#include <iostream>
#include <cmath>

using namespace std;

int n_ball, n_w;

int w[31];
bool w_seq[31][15001];
bool w_able[15001];

void measure(int step, int w_now) {
	if (step > n_w) return;
	if (w_seq[step][w_now]) return;
	w_seq[step][w_now] = true;
	w_able[w_now] = true;
	measure(step+1, w_now);
	measure(step+1, w_now+w[step]);
	measure(step+1, abs(w_now - w[step]));
	return;
}

int main() {
	cin >> n_w;
	for (int i = 0; i < n_w; i++)
		cin >> w[i];

	measure(0,0);

	cin >> n_ball;
	int ball;
	for (int i = 0; i < n_ball; i++) {
		cin >> ball;
		if (ball <= 15000 && w_able[ball])
			cout << "Y ";
		else
			cout << "N ";
	}


}