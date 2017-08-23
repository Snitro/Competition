#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

int sum[100000 << 2];

int col[100000 << 2];

void PushUP(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1] ;
}

void PushDown(int rt, int m) {
	if (col[rt]) {
		col[rt << 1] = col[rt << 1 | 1] = col[rt];
		sum[rt << 1] = (m - (m >> 1)) * col[rt];
		sum[rt << 1 | 1] = (m >> 1) * col[rt];
		col[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	col[rt] = 0;
	sum[rt] = 1;
	
	if (l == r)
		return;
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
	
}

void update(int L, int R, int c, int l, int r, int rt) {
	if (L <= l && r <= R) {
		sum[rt] = c * (r - l + 1);
		col[rt] = c;
		return;
	}
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, c, lson);
	
	if (R > m)
		update(L, R, c, rson);
		
	PushUP(rt);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	int T, n, m;
	int a, b, c;
	
	scanf("%d", &T);
	
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &n, &m);
		
		build(1, n, 1);
		
		while (m--) {
			scanf("%d%d%d", &a, &b, &c);
			
			update(a, b, c, 1, n, 1);
		}
		
		printf("Case %d: The total value of the hook is %d.\n", i, sum[1]);
	}
	
	return 0;
}
