#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#include <iomanip> 

using namespace std;

int s, t, A, B, pay[405];
double map[405][405];

struct Node {
	int x;
	int y;
} nodes[160005];

double calc(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
	scanf("%d%d%d%d", &s, &t, &A, &B);

	memset(map, 0x7f, sizeof(map));
	int x1, x2, x3, y1, y2, y3;
	double x4, y4, cx, cy, a, b, c;
	
	for (int i = 1; i <= s; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> pay[i];
		a = calc(x1, y1, x2, y2);
		b = calc(x1, y1, x3, y3);
		c = calc(x2, y2, x3, y3);
		
		if (a > b && a > c) {
			cx = (x1 + x2) / 2.0;
			cy = (y1 + y2) / 2.0;
			x4 = x3;
			y4 = y3;
		} else if (b > a && b > c) {
			cx = (x1 + x3) / 2.0;
			cy = (y1 + y3) / 2.0;
			x4 = x2;
			y4 = y2;
		} else {
			cx = (x2 + x3) / 2.0;
			cy = (y2 + y3) / 2.0;
			x4 = x1;
			y4 = y1;
		}
		
		nodes[(i - 1) * 4 + 1].x = x1;
		nodes[(i - 1) * 4 + 1].y = y1;
		nodes[(i - 1) * 4 + 2].x = x2;
		nodes[(i - 1) * 4 + 2].y = y2;
		nodes[(i - 1) * 4 + 3].x = x3;
		nodes[(i - 1) * 4 + 3].y = y3;
		nodes[(i - 1) * 4 + 4].x = cx + (cx - x4);
		nodes[(i - 1) * 4 + 4].y = cy + (cy - y4);
	}
	
	for (int i = 1; i <= s * 4; i++)
		for (int j = 1; j <= s * 4; j++)
			if ((i - 1) / 4 == (j - 1) / 4)
				map[j][i] = map[i][j] = calc(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y) * pay[(i - 1) / 4 + 1];
			else
				map[j][i] = map[i][j] = calc(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y) * t;
	
	for (int k = 1; k <= s * 4; k++)
		for (int i = 1; i <= s * 4; i++)
			for (int j = 1; j <= s * 4; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				
	double ans = 10e20;
	
	for (int i = (A - 1) * 4 + 1; i <= (A - 1) * 4 + 4; i++)
		for (int j = (B - 1) * 4 + 1; j <= (B - 1) * 4 + 4; j++)
			ans = min(ans, map[i][j]);
	
	printf("%.1f\n", ans);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	int t;
	scanf("%d", &t);
	
	while (t--)
		solve();
	
	return 0;
}
