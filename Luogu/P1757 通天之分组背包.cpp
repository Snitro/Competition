#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, T;

int f[105][1005];

struct Node {
	int a;
	int b;
	int c;
} nodes[1005];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &nodes[i].a, &nodes[i].b, &nodes[i].c);
		T = max(T, nodes[i].c);
	}
	
	for (int t = 1; t <= T; t++) {
		memcpy(f[t], f[t - 1], sizeof(f[t]));
		for (int i = 1; i <= m; i++)
			if (nodes[i].c == t)
				for (int j = nodes[i].a; j <= n; j++)
					f[t][j] = max(f[t][j], f[t - 1][j - nodes[i].a] + nodes[i].b);
	}
	
	printf("%d", f[T][n]);
	
	return 0;
}
