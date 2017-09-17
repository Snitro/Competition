#include <iostream>
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

int n, q;

int init[20005];

int fa[20005], p[20005][25], deep[20005], sum[20005];

long long tree[20005];

int head[20005], edge_len;

struct Edge {
	int to;
	int next;
} edges[40005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void tree_add(int x, long long num) {
	while (x <= n) {
		tree[x] += num;
		x += lowbit(x);
	}
}

long long query(int x) {
	long long ans = 0;
	
	while (x) {
		ans += tree[x];
		x -= lowbit(x);
	}
	
	return ans;
}

void dfs(int x) {
	if (!(deep[x] % 2))
		sum[x] = sum[fa[x]] + init[x];
	else
		sum[x] = sum[fa[x]] - init[x];
	p[x][0] = fa[x];
	
	for (int i = 1; p[x][i - 1]; i++)
		p[x][i] = p[p[x][i - 1]][i - 1];
	
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x]) {
			deep[to] = deep[x] + 1;
			fa[to] = x;
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
		for (int i = 24; i >= 0; i--)
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
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &init[i]);
		
	int from, root;
		
	for (int i = 1; i <= n; i++) {
		scanf("%d", &from);
		
		if (from == -1)
			root = i;
		else {
			add(i, from);
			add(from, i);
		}
	}
	
	dfs(root);
	deep[0] = -1;
	
	char Q[10];
	int x, y;
	
	for (int i = 1; i <= q; i++) {
		scanf("%s%d%d", Q, &x, &y);
		
		if (Q[0] == 'M') {
			if (!(x % 2))
				y = -y;
			tree_add(x, y);
		} else {
			int rt = lca(x, y);
			long long ans = sum[x] + sum[y] - sum[rt] - sum[fa[rt]] + query(deep[x] + 1) + query(deep[y] + 1) - query(deep[rt] + 1) - query(deep[fa[rt]] + 1);
			printf("%lld\n", (ans < 0) ? -ans : ans);
		}
	}
	
	return 0;
}
