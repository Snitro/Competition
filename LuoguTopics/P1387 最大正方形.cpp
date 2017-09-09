#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int map[105][105];

int ans;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[j][i]);
	
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
			if (map[x][y]) {
				map[x][y] = min(map[x - 1][y], map[x][y - 1]) + 1;
				
				if (map[x][y] >= 2 && !map[x - map[x][y] + 1][y - map[x][y] + 1])
					map[x][y]--;
				
				if (map[x][y] > ans)
					ans = map[x][y];
			}
	
	cout << ans;
	
	return 0;
}
