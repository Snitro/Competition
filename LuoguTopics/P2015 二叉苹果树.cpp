#include <iostream>
#include <cstdio>

using namespace std;

int n, q;

bool vis[105];

int value[105];

int head[100], edge_len;

struct Node {
	int left;
	int right;
	int f[105];
} nodes[105];

struct Edge {
	int to;
	int value;
	int next;
} edges[205];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void value_dfs(int x) {
	int to;
	bool flg = false;

	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;

		if (!vis[to]) {
			vis[to] = true;
			value[to] = edges[i].value;
			value_dfs(to);

			if (flg)
				nodes[x].right = to;

			if (!flg) {
				flg = true;
				nodes[x].left = to;
			}
		}
	}
}

void dfs(int x) {
	Node & left = nodes[nodes[x].left];
	Node & right = nodes[nodes[x].right];

	if (nodes[x].left) {
		dfs(nodes[x].left);
		dfs(nodes[x].right);
	}

	for (int i = 1; i <= q; i++) {
		nodes[x].f[i] = max(left.f[i - 1] + value[nodes[x].left],
		                    right.f[i - 1] + value[nodes[x].right]);

		if (i > 1)
			for (int j = 0; j <= i - 2; j++)
				nodes[x].f[i] = max(nodes[x].f[i],
				                    left.f[j] + right.f[i - 2 - j] + value[nodes[x].left] +
				                    value[nodes[x].right]);
	}
}

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d%d", &n, &q);

	int a, b, c;

	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);

		add(a, b, c);
		add(b, a, c);
	}

	vis[1] = true;
	value_dfs(1);

	dfs(1);

	cout << nodes[1].f[q];

	return 0;
}
