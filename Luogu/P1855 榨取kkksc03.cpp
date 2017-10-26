#include <iostream>
#include <cstdio>

using namespace std;

int f[105][205][205];

int n, m, T;

struct Thing {
	int t;
	int v;
} things[105];

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d%d%d", &n, &m, &T);

	for (int i = 1; i <= n; i++)
		scanf("%d%d", &things[i].t, &things[i].v);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int t = 1; t <= T; t++) {
				f[i][j][t] = f[i - 1][j][t];
				
				if (j - things[i].v >= 0 && t - things[i].t >= 0)
					f[i][j][t] = max(f[i][j][t], f[i - 1][j - things[i].v][t - things[i].t] + 1);
			}

	cout << f[n][m][T];

	return 0;
}
