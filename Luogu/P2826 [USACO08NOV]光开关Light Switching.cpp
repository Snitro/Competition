#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

bool color[100000 << 2];

int n, m, nodes[100000 << 2];

void PushUP(int rt) {
	nodes[rt] = nodes[rt << 1] + nodes[rt << 1 | 1];
}

void PushDown(int rt, int m) {
	if (color[rt]) {
		color[rt << 1] = !color[rt << 1];
		color[rt << 1 | 1] = !color[rt << 1 | 1];
		
		nodes[rt << 1] = (m - (m >> 1)) - nodes[rt << 1];
		nodes[rt << 1 | 1] = (m >> 1) - nodes[rt << 1 | 1];
		
		color[rt] = false;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		nodes[rt] = 0;
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return nodes[rt];
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	int ret = 0;
	
	if (L <= m)
		ret += query(L, R, lson);
	if (m < R)
		ret += query(L, R, rson);
	
	return ret;
}

void update(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		color[rt] = !color[rt];
		nodes[rt] = (r - l + 1) - nodes[rt];
		return;
	}
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, lson);
	if (m < R)
		update(L, R, rson);
		
	PushUP(rt);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	build(root) ;
	
	int c, a, b;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &c, &a, &b);
		
		if (c == 0)
			update(a, b, root);
		else
			printf("%d\n", query(a, b, root));
	}
	
	return 0;
}
