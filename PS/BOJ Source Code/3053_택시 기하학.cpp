#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

//math.h를 include 하기 전에 _USE_MATH_DEFINES 를 정의해야한다!

using namespace std;

int main() {
	int r;
	double tarea, area;
	double pi = M_PI;
	scanf("%d", &r);
	area = r * r * pi;
	tarea = r * r * 2;
	printf("%.6lf\n%.6lf", area, tarea);
}