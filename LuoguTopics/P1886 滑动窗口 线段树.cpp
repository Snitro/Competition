#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

int n, w;

struct Node {
	int MAX;
	int MIN;
} nodes[1000000 << 2];

int Max[1000000];

void PushUP(int rt) {
	nodes[rt].MAX = max(nodes[rt << 1].MAX, nodes[rt << 1 | 1].MAX);
	nodes[rt].MIN = min(nodes[rt << 1].MIN, nodes[rt << 1 | 1].MIN);
}

void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &nodes[rt].MAX);
		nodes[rt].MIN = nodes[rt].MAX;
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

Node query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return nodes[rt];
	
	int m = (l + r) >> 1;
	
	Node node;
	bool flg = false;
	
	if (L <= m) {
		node = query(L, R, lson);
		flg = true;
	}
		
	if (m < R) {
		if (flg) {
			Node tn = query(L, R, rson);
			node.MAX = max(node.MAX, tn.MAX);
			node.MIN = min(node.MIN, tn.MIN);
		} else
			return query(L, R, rson);
	}
	
	return node;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &w);
	
	if (w == 1) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &Max[i]);
		
		for (int i = 1; i <= n; i++)
			printf("%d ", Max[i]);
		
		printf("\n");
		
		for (int i = 1; i <= n; i++)
			printf("%d ", Max[i]);
		
		return 0;
	}
	
	build(1, n, 1);
	
	for (int i = 1; i <= n - w + 1; i++) {
		Node node = query(i, i + w - 1, 1, n, 1);
		
		printf("%d ", node.MIN);
		
		Max[i] = node.MAX;
	}
	
	printf("\n");
	
	for (int i = 1; i <= n - w + 1; i++)
		printf("%d ", Max[i]);
		
	return 0;
}
