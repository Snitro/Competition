#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, t, m;

int nodes[100000 << 2];

int col[100000 << 2];

void PushUP(int rt) {
	nodes[rt] = nodes[rt << 1] | nodes[rt << 1 | 1];
}

void PushDown(int rt) {
	if (col[rt]) {
		col[rt << 1] = col[rt << 1 | 1] = col[rt];
		
		nodes[rt << 1] = nodes[rt << 1 | 1] = col[rt];
		
		col[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		nodes[rt] = 1;
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int L, int R, int t, int l, int r, int rt) {
	if (L <= l && r <= R) {
		nodes[rt] = t;
		col[rt] = t;
		return;
	}
	
	PushDown(rt);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, t, lson);
		
	if (m < R)
		update(L, R, t, rson);
		
	PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return nodes[rt];
		
	PushDown(rt);
	
	int m = (l + r) >> 1;
	int ret = 0;
	
	if (L <= m)
		ret = query(L, R, lson);
		
	if (m < R)
		ret |= query(L, R, rson);
		
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &t, &m);
	
	char f;
	int a, b, c;
	
	build(root);
	
	while (m--) {
		cin >> f;
		scanf("%d%d", &a, &b);
		
		if (a > b)
		    swap(a, b);
		
		if (f == 'C') {
			scanf("%d", &c) ;
			update(a, b, 1 << (c - 1), root);
		}
		else {
			int ret = query(a, b, root);
			int count = 0;
			
			for (int i = 0; i < t; i++)
				if (ret & (1 << i))
					count++;
			
			printf("%d\n", count);
		}
	}
	
	return 0;
}
