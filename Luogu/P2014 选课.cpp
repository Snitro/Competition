#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;

int score[305], fa[305];

bool vis[305];

int f[305][305];

int head[305], edge_len;

struct Edge {
	int to;
	int next;
} edges[605];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x) {
	f[x][1] = score[x];
	int to;
	
	for (int i = head[x]; ~i; i = edges[i].next) {
		to = edges[i].to;
		
		dfs(to);
		
		for (int j = m; j >= 1; j--)
			for (int i = j - 1; i >= 1; i--)
				f[x][j] = max(f[x][j], f[x][j - i] + f[to][i]);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	memset(head, -1, sizeof(head));
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &fa[i], &score[i]);
		add(fa[i], i);
	}
	
	m++;
	
	dfs(0);
	
	cout << f[0][m];
	
	return 0;
}
