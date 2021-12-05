#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int fix, var, price;
	int point = 0;
	cin >> fix >> var >> price;
	if (var >= price)
		point = -1;
	else {
		point = ceil(fix / (price - var));
		if (point == fix / (price - var))
			point += 1;
	}
	cout << point;
}