#include <iostream>
#include <cstdio>

using namespace std;

int n, q;

int p[100005][25], fa[100005], deep[100005];

int head[100005], edge_len;

struct Edge {
	int to;
	int next;
} edges[200005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x) {
	p[x][0] = fa[x];
	
	for (int i = 1; p[x][i - 1]; i++)
		p[x][i] = p[p[x][i - 1]][i - 1];
		
	int to;
		
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x]) {
			fa[to] = x;
			deep[to] = deep[x] + 1;
			dfs(to);
		}
	}
}

int lca(int a, int b) {
	if (deep[a] > deep[b])
		swap(a, b);
	
	int f = deep[b] - deep[a];
	for (int i = 0; (1 << i) <= f; i++)
		if ((1 << i) & f)
			b = p[b][i];
	
	if (a != b) {
		for (int i = 20; i >= 0; i--)
			if (p[a][i] != p[b][i]) {
				a = p[a][i];
				b = p[b][i];
			}
			
		a = p[a][0];
	}
	
	return a;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &q);
	
	int from, to, a, b, c, d;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &from, &to);
		
		add(from, to);
		add(to, from);
	}
	
	dfs(1);
	
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		
		from = lca(a, b);
		to = lca(c, d);
		
		if (deep[from] > deep[to]) {
			swap(from, to);
			swap(a, c);
			swap(b, d);
		}
		
		if (lca(to, a) == to || lca(to, b) == to)
			printf("Y\n");
		else
			printf("N\n");
	}
	
	return 0;
}
