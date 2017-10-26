#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m;

struct Node {
	int size;
	int left;
	int right;
	int mid;
} nodes[50000 << 2];

int color[50000 << 2];//1×¡ËÞ 2²»×¡ËÞ 

void PushUP(int rt) {
	nodes[rt].left = nodes[rt << 1].left + (nodes[rt << 1].size == nodes[rt << 1].left ? nodes[rt << 1 | 1].left : 0);
	nodes[rt].right = nodes[rt << 1 | 1].right + (nodes[rt << 1 | 1].right == nodes[rt << 1 | 1].size ? nodes[rt << 1].right : 0);
	nodes[rt].mid = max(nodes[rt << 1].mid, nodes[rt << 1 | 1].mid);
	nodes[rt].mid = max(nodes[rt].mid, nodes[rt << 1].right + nodes[rt << 1 | 1].left);
	nodes[rt].size = nodes[rt << 1].size + nodes[rt << 1 | 1].size;
}

void PushDown(int rt) {
	if (color[rt]) {
		if (color[rt] == 1) {
			nodes[rt << 1].left = nodes[rt << 1].right = nodes[rt << 1].mid = 0;
			nodes[rt << 1 | 1].left = nodes[rt << 1 | 1].right = nodes[rt << 1 | 1].mid = 0;
		} else if (color[rt] == 2) {
			nodes[rt << 1].left = nodes[rt << 1].right = nodes[rt << 1].mid = nodes[rt << 1].size;
			nodes[rt << 1 | 1].left = nodes[rt << 1 | 1].right = nodes[rt << 1 | 1].mid = nodes[rt << 1 | 1].size;
		}
		color[rt << 1] = color[rt << 1 | 1] = color[rt];
		color[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		nodes[rt].size = nodes[rt].left = nodes[rt].right = nodes[rt].mid = 1;
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int L, int R, int num, int l, int r, int rt) {
	if (L <= l && r <= R) {
		nodes[rt].left = nodes[rt].right = nodes[rt].mid = num == 1 ? 0 : nodes[rt].size;
		color[rt] = num;
		return;
	}

	PushDown(rt);

	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, num, lson);
	if (m < R)
		update(L, R, num, rson);
		
	PushUP(rt);
}

int query(int num, int l, int r, int rt) {
	if (l == r)
		return l;
		
	PushDown(rt);
		
	int m = (l + r) >> 1;
	
	if (nodes[rt << 1].mid >= num)
		return query(num, lson);
	if (nodes[rt << 1].right + nodes[rt << 1 | 1].left >= num)
		return m - nodes[rt << 1].right + 1;
	else
		return query(num, rson);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	build(root);
	
	while (m--) {
		int a, b, c;
		
		scanf("%d", &a);
		
		if (a == 1) {
			scanf("%d", &b);
			
			if (nodes[1].mid < b) {
				printf("0\n");
				continue;
			}
			
			c = query(b, root);
			printf("%d\n", c);
			update(c, c + b - 1, 1, root);
		} else {
			scanf("%d%d", &b, &c);
			update(b, b + c - 1, 2, root);
		}
	}
	
	return 0;
}
