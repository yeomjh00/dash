#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

//math.h�� include �ϱ� ���� _USE_MATH_DEFINES �� �����ؾ��Ѵ�!

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