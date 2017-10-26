#include <iostream> 
#include <cstdio>

using namespace std;

int map[100][100], n, x, y;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	map[1][(n + 1) / 2] = 1;
	
	x = (n + 1) / 2;
	y = 1;
	
	for (int i = 2; i <= n * n; i++) {
		if (y == 1 && x < n) {
			map[n][x + 1] = i;
			y = n;
			x++;
		} else if (x == n && y > 1) {
			map[y - 1][1] = i;
			y--;
			x = 1;
		} else if (x == n && y == 1) {
			map[y + 1][x] = i;
			y++;
		} else {
			if (map[y - 1][x + 1] == 0) {
				map[y - 1][x + 1] = i;
				y--;
				x++;
			} else {
				map[y + 1][x] = i;
				y++;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	
	return 0;
}
