#include <iostream>
#include <cstdio>

using namespace std;

int dfs_num, dfn[100005], low[100005], fa[100005], head[100005], edge_len;

int n, m, size;

bool flag[100005];

struct Edge {
	int to;
	int next;
} edges[200005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void tarjan(int x) {
	int children = 0;
	dfn[x] = low[x] = ++dfs_num;
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!dfn[to]) {
			fa[to] = x;
			tarjan(to);
			
			low[x] = min(low[x], low[to]);
				
			if (low[to] >= dfn[x] && fa[x] != x)
				flag[x] = true;
			
			if (fa[x] == x)
				children++;
		}
		low[x] = min(low[x], dfn[to]);
	}
	
	if (fa[x] == x && children >= 2)
		flag[x] = true;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int v, u;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		
		add(u, v);
		add(v, u);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) {
			fa[i] = i;
			tarjan(i);
		}
			
	for (int i = 1; i <= n; i++)
		if (flag[i])
			size++;
	
	printf("%d\n", size);
	
	for (int i = 1; i <= n; i++)
		if (flag[i])
			printf("%d ", i);
	
	return 0;
}
