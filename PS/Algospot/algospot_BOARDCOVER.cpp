#include <iostream>
#include <iostream>
using namespace std;

int board[20][20];
int h, w;
int covertype[4][3][2] = {
	{{0,0},{0,1},{1,1}},
	{{1,0},{0,0},{0,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{1,0},{1,1}}
};

bool set(int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int nx = x + covertype[type][i][1];
		const int ny = y + covertype[type][i][0];
		if (nx < 0 || nx >= w || ny >= h ) //check�ϰ� ���� set�ϴ°� �ƴ϶� if-else if ���� �̿��ؼ� �׷��� �� ���� �ִ�.
			ok= false;
		else if ((board[ny][nx] += delta) > 1) // �� check �� ���ϴ°� �ƴ϶�, ���� ���� �� ���� return�ؼ� �Ǵ��� �� �ִ�.
			ok= false;
	}
	return ok;
}

int cover() {
	int ny=-1, nx=-1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			if (board[i][j] == 0) {
				ny = i; nx = j;
				break;
			}
		if (ny != -1)
			break;
	}
	if (ny == -1) return 1;
	int ret = 0;

	for (int i = 0; i < 4; i++) {
		if (set(ny, nx, i, 1))
			ret+=cover();
		set(ny, nx, i, -1);
	}
	return ret;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--)	{
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				char tmp;
				scanf(" %c", &tmp);
				if (tmp == '#')
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		cout << cover() << "\n";
	}
}