#include <iostream> 
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

int n, m;

int nodes[100005];

int size[100005], son[100005], deep[100005], fa[100005], top[100005];

int id[100005], id_map[100005], id_num, to_father[100005];

int head[100005], edge_len;

struct Edge {
	int to;
	int next;
	int value;
} edges[200005];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	edges[edge_len].value = value;
	head[from] = edge_len;
}

void add(int x, int num) {
	while (x <= n) {
		nodes[x] += num;
		x += lowbit(x);
	}
}

int query(int x) {
	int ans = 0;
	
	while (x) {
		ans += nodes[x];
		x -= lowbit(x);
	}
	
	return ans;
}

void dfs1(int x) {
	size[x] = 1;
	son[x] = 0;
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x]) {
			deep[to] = deep[x] + 1;
			fa[to] = x;
			to_father[to] = edges[i].value;
			dfs1(to);
			
			size[x] += size[to];
			if (!son[x] || size[son[x]] < size[to])
				son[x] = to;
		}
	}
}

void dfs2(int x, int tp) {
	top[x] = tp;
	id[x] = ++id_num;
	id_map[id_num] = x;
	int to;
	
	if (son[x])
		dfs2(son[x], tp);
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x] && to != son[x])
			dfs2(to, to);
	}
}

void update(int a, int b) {
	while (top[a] != top[b]) {
		if (deep[top[a]] > deep[top[b]])
			swap(a, b);
		
		add(id[top[b]], 1);
		add(id[b] + 1, -1);
		
		b = fa[top[b]];
	}
	
	if (id[a] > id[b])
		swap(a, b);
	
	add(id[a] + 1, 1);
	add(id[b] + 1, -1);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	char k[3];
	int a, b;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		add(a, b, 0);
		add(b, a, 0);
	}
	
	dfs1(1);
	dfs2(1, 1);
	
	for (int i = 1; i <= m; i++) {
		scanf("%s%d%d", k, &a, &b);
		
		if (k[0] == 'P')
			update(a, b);
		else {
			int rel = deep[a] > deep[b] ? a : b;
			printf("%d\n", query(id[rel]));
		}
	}
	
	return 0;
}
