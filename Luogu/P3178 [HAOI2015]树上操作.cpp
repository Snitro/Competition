#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m;

int value[1000005];

int size[1000005], deep[1000005], son[1000005], id_map[1000005];

int top[1000005], fa[1000005], id[1000005], id_num;

long long sum[1000005 << 2], col[1000005 << 2];

int head[1000005], edge_len;

struct Edge {
	int to;
	int next;
} edges[2000005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs1(int x) {
	size[x] = 1;
	son[x] = 0;
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x]) {
			fa[to] = x;
			deep[to] = deep[x] + 1;
			dfs1(to);
			size[x] += size[to];
			
			if (son[x] == 0 || size[son[x]] < size[to])
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

void PushUP(int x) {
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}

void PushDown(int x, int l) {
	if (col[x]) {
		col[x << 1] += col[x];
		col[x << 1 | 1] += col[x];
		
		sum[x << 1] += (l - (l >> 1)) * col[x];
		sum[x << 1 | 1] += (l >> 1) * col[x];
		
		col[x] = 0;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = value[id_map[l]];
		return;
	}
	
	int m = (r + l) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int L, int R, long long num, int l, int r, int rt) {
	if (L <= l && r <= R) {
		sum[rt] += (r - l + 1) * num;
		col[rt] += num;
		return;
	}
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, num, lson);
	
	if (m < R)
		update(L, R, num, rson);
		
	PushUP(rt);
}

long long query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return sum[rt];
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	long long ret = 0;
	
	if (L <= m)
		ret = query(L, R, lson);
	if (m < R)
		ret += query(L, R, rson);
	
	return ret;
}

long long tree_query(int a, int b) {
	long long sum = 0;
	
	while (top[a] != top[b]) {
		if (deep[top[a]] > deep[top[b]])
			swap(a, b);
			
		sum += query(id[top[b]], id[b], root);
		
		b = fa[top[b]];
	}
	
	if (id[a] > id[b])
		swap(a, b);
		
	sum += query(id[a], id[b], root);
	
	return sum;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &value[i]);
		
	int from, to;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &from, &to);
		add(from, to);
		add(to, from);
	}
	
	deep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
	build(root);
	
	int k, a, b;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);
		
		if (k == 1) {
			scanf("%d%d", &a, &b);
			update(id[a], id[a], b, root);
		} else if (k == 2) {
			scanf("%d%d", &a, &b);
			update(id[a], id[a] + size[a] - 1, b, root);
		} else {
			scanf("%d", &a);
			printf("%lld\n", tree_query(1, a));
		}
	}
	
	return 0;
}
