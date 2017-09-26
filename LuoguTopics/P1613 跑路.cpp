#include <iostream> 
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int dist[55][55];

bool map[55][55][100];

int n, m;

int head[100], edge_len;

struct Edge {
	int to;
	int next;
} edges[20005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	memset(dist, 0x7f, sizeof(dist));
	
	int u, v;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		
		map[u][v][0] = true;
		dist[u][v] = 1;
	}
	
	for (int t = 1; t <= 64; t++)
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (map[k][j][t - 1] && map[j][i][t - 1]) {
						map[k][i][t] = true;
						dist[k][i] = 1;
					}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][k] < dist[0][0] && dist[k][j] < dist[0][0])
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
	
	cout << dist[1][n];
	
	return 0;
}
