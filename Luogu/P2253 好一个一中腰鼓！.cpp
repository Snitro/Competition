#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m;

struct Node {
	int l;
	int r;
	int mid;
	int len;
	bool Left;//是不是红色 
	bool Right;
} nodes[20000 << 2];

void PushUP(int rt) {
	nodes[rt].Left = nodes[rt << 1].Left;
	nodes[rt].Right = nodes[rt << 1 | 1].Right;
	
	nodes[rt].l = nodes[rt << 1].l;
	nodes[rt].r = nodes[rt << 1 | 1].r;
	
	if (nodes[rt << 1].l == nodes[rt << 1].len && nodes[rt << 1].Right != nodes[rt << 1 | 1].Left)
		nodes[rt].l = nodes[rt << 1].len + nodes[rt << 1 | 1].l;
		
	if (nodes[rt << 1 | 1].r == nodes[rt << 1 | 1].len && nodes[rt << 1].Right != nodes[rt << 1 | 1].Left)
		nodes[rt].r = nodes[rt << 1 | 1].len + nodes[rt << 1].r;
	
	nodes[rt].mid = max(nodes[rt << 1].mid, nodes[rt << 1 | 1].mid);
	
	if (nodes[rt << 1].Right != nodes[rt << 1 | 1].Left)
		nodes[rt].mid = max(nodes[rt].mid, nodes[rt << 1].r + nodes[rt << 1 | 1].l);
		
	nodes[rt].len = nodes[rt << 1].len + nodes[rt << 1 | 1].len;
}

void build(int l, int r, int rt) {
	if (l == r) {
		nodes[rt].Left = nodes[rt].Right = nodes[rt].l = nodes[rt].r = nodes[rt].mid = nodes[rt].len = 1;
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int id, int l, int r, int rt) {
	if (l == r) {
		nodes[rt].Left = !nodes[rt].Left;
		nodes[rt].Right = !nodes[rt].Right;
		return;
	}
	
	int m = (l + r) >> 1;
	
	if (id <= m)
		update(id, lson);
	
	if (m < id)
		update(id, rson);
		
	PushUP(rt);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	build(root);
	
	int a;
	
	while (m--) {
		scanf("%d", &a);
		
		update(a, root);
		
		printf("%d\n", max(max(nodes[1].l, nodes[1].r), nodes[1].mid));
	}
}
