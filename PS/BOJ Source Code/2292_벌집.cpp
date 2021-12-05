#include <iostream>

using namespace std;

int main() {
	int n,i=1, tmp=1;
	cin >> n;
	while (n > tmp) {
		i++;
		tmp += 6 * i - 6;
	}
	cout << i;
}
//육각형을 6개의 삼각형으로 나누면 i번째 층에 i개의 육각형이 모여서 삼각형을 이룬다.
//i번째 층의 특정 삼각형으로 가기 위해서는 i개의 방을 거쳐서 가면 된다.
// 6x-6은 각 i번째 육각형 껍질을 생성하는데 필요한 육각형의 갯수이다.