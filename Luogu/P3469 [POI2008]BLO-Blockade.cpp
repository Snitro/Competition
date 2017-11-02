#include <iostream>
#include <cstdio>

using namespace std;

bool flag[100005];

long long ans[100005];

int dfn[100005], low[100005], size[100005], dfs_num;

int head[100005], edge_len, n, m, deep[100005];

struct Edge {
	int to;
	int next;
} edges[1000005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void tarjan(int x, int fa) {
	int children = 0, to, temp = 0;
	dfn[x] = low[x] = ++dfs_num;
	ans[x] += n - 1;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!dfn[to]) {
			deep[to] = deep[x] + 1;
			tarjan(to, x);
			
			low[x] = min(low[x], low[to]);
			size[x] += size[to];
			
			if (low[to] >= dfn[x] && fa != 0) {
				flag[x] = true;
				temp += size[to];
				ans[x] += (long long)(size[to]) * (n - temp - 1);
			}
				
			if (fa == 0)
				children++;
		}
		
		low[x] = min(low[x], dfn[to]);
	}
	
	size[x]++;
	
	if (fa == 0 && children >= 2) {
		flag[x] = true;
		temp = 0;
		ans[x] = (long long)(size[x] - 1);
		
		for (int i = head[x]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (deep[to] == deep[x] + 1) {
				ans[x] += (long long)size[to] * temp;
				temp += size[to];
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int u, v;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		
		add(u, v);
		add(v, u);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) {
			deep[i] = 1;
			tarjan(i, 0);
		}
	
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i] * 2);
	}
	
	return 0;
}
