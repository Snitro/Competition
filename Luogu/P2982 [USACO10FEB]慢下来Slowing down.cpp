#include <iostream>
#include <cstdio>

#define lowbit(x) ((x) & (-(x)))

using namespace std;

bool vis[100005];

int n, map[100005], tot[100005], head[100005], edge_len;

long long ans[100005];

struct Edge {
	int to;
	int next;
} edges[200005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void update(int x, int num) {
	while (x <= n) {
		tot[x] += num;
		x += lowbit(x);
	}
}

int query(int x) {
	int ret = 0;
	
	while (x) {
		ret += tot[x];
		x -= lowbit(x);
	}
	
	return ret;
}

void dfs(int x) {
	ans[map[x]] = query(map[x]);
	update(map[x], 1);
	
	vis[x] = true;
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!vis[to])
			dfs(to);
	}
	
	update(map[x], -1);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	int a, b;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		
		add(a, b);
		add(b, a);
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		
		map[a] = i;
	}
	
	dfs(1);
	
	for (int i = 1; i <= n; i++)
		printf("%lld\n", ans[i]);
	
	return 0;
}
