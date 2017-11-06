#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n, m, value[205], map[205][205], k = 1, size, add = 1;

struct Que {
	int u;
	int v;
	int t;
} q[50005];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &value[i]);
	
	memset(map, 0x7f, sizeof(map));
	
	int u, v;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d", &map[u + 1][v + 1]);
		map[v + 1][u + 1] = map[u + 1][v + 1];
	}
	
	scanf("%d", &size);
	
	for (int i = 1; i <= size; i++) {
		scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].t);
		q[i].u++;
		q[i].v++;
	}
	
	for (int i = 1; i <= size; i++) {
		for (; k <= n && value[k] <= q[i].t; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (map[i][k] != map[0][0] && map[k][j] != map[0][0])
						map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		
		if (value[q[i].u] <= q[i].t && value[q[i].v] <= q[i].t)
			printf("%d\n", map[q[i].u][q[i].v] == map[0][0] ? -1 : map[q[i].u][q[i].v]);
		else
			puts("-1");
	}
	
	return 0;
}
