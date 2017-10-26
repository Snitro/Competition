#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m, r, p;

long long value[100005];

int size[100005], son[100005], fa[100005], deep[100005];

int top[100005], id[100005], id_map[100005], id_num;

long long sum[100005 << 2], col[100005 << 2];

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

void PushDown(int rt, int l) {
	if (col[rt]) {
		col[rt << 1] += col[rt];
		col[rt << 1 | 1] += col[rt];

		sum[rt << 1] += (l - (l >> 1)) * col[rt];
		sum[rt << 1 | 1] += (l >> 1) * col[rt];

		sum[rt << 1] %= p;
        sum[rt << 1 | 1] %= p;
        col[rt << 1] %= p;
        col[rt << 1 | 1] %= p;

		col[rt] = 0;
	}
}

void PushUP(int rt) {
	sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % p;
}

void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = value[id_map[l]];
		return;
	}

	int m = (l + r) >> 1;

	build(lson);
	build(rson);

	PushUP(rt);
}

long long query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return sum[rt] % p;

	PushDown(rt, r - l + 1);

	int m = (l + r) >> 1;
	long long ret = 0;

	if (L <= m)
		ret = query(L, R, lson);
	if (m < R)
		ret += query(L, R, rson);

	return ret % p;

}

void update(int L, int R, int num, int l, int r, int rt) {
	if (L <= l && r <= R) {
		sum[rt] += (r - l + 1) * num;
		col[rt] += num;
		
		sum[rt] %= p;
		col[rt] %= p;
		
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

void dfs1(int x) {
	size[x] = 1;
	int to;

	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;

		if (to != fa[x]) {
			deep[to] = deep[x] + 1;
			fa[to] = x;
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

void tree_add(int a, int b, int c) {
	while (top[a] != top[b]) {
		if (deep[top[a]] > deep[top[b]])
			swap(a, b);

		update(id[top[b]], id[b], c, root);

		b = fa[top[b]];
	}

	if (id[a] > id[b])
		swap(a, b);

	update(id[a], id[b], c, root);
}

long long tree_query(int a, int b) {
	long long ret = 0;

	while (top[a] != top[b]) {
		if (deep[top[a]] > deep[top[b]])
			swap(a, b);

		ret += query(id[top[b]], id[b], root);

		b = fa[top[b]];
		ret %= p;
	}

	if (id[a] > id[b])
		swap(a, b);

	ret += query(id[a], id[b], root) % p;

	return ret % p;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &r, &p);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &value[i]);
		value[i] %= p;
	}

	int a, b, c, k;

	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}

	dfs1(r);
	dfs2(r, r);
	build(root);

	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);

		if (k == 1) {
			scanf("%d%d%d", &a, &b, &c);
			tree_add(a, b, c % p);
		} else if (k == 2) {
			scanf("%d%d", &a, &b);
			printf("%lld\n", tree_query(a, b) % p);
		} else if (k == 3) {
			scanf("%d%d", &a, &b);
			update(id[a], id[a] + size[a] - 1, b % p, root);
		} else {
			scanf("%d", &a);
			printf("%lld\n", query(id[a], id[a] + size[a] - 1, root) % p);
		}
	}

	return 0;
}
