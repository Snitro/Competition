#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

struct position{
	double x;
	double y;
}data[60005];

int n;


int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &data[i].x, &data[i].y);
	double length = 999999999999999;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			double a = data[i].x - data[j].x;
			double b = data[i].y - data[j].y;
			double s = abs(a * a + b * b);
			if (s == 0) {
				cout << 0.0000;
				return 0;
			}
			if (s < length)
				length = s;
		}
	}
	printf("%.4lf", sqrt(length));
	return 0;
}
