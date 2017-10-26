#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

int n, m;

long long sum[100000 << 2];
long long col[100000 << 2];

void PushUP(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
	if (l ==  r) {
		scanf("%lld", &sum[rt]);
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void PushDown(int rt, int m) {
	if (col[rt]) {
		sum[rt << 1] += col[rt] * (m - (m >> 1));
		sum[rt << 1 | 1] += col[rt] * (m >> 1);
		
		col[rt << 1] += col[rt];
		col[rt << 1 | 1] += col[rt];
		
		col[rt] = 0;
	}
}

long long query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return sum[rt];
		
	PushDown(rt, r - l + 1);
		
	int m = (l + r) >> 1;
	
	long long ans = 0;
	
	if (L <= m)
		ans += query(L, R, lson);
	
	if (m < R)
		ans += query(L, R, rson);
		
	return ans;	
}

void update(int L, int R, int c, int l, int r, int rt) {
	if (L <= l && r <= R) {
		sum[rt] += (r - l + 1) * c;
		col[rt] += c;
		
		return;
	}
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, c, lson);
	
	if (m < R)
		update(L, R, c, rson);
		
	PushUP(rt);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int a, b, c, d;
	
	build(1, n, 1);
	
	while (m--) {
		scanf("%d", &a);
		
		if (a == 1) {
			scanf("%d%d%d", &b, &c, &d);
			update(b, c, d, 1, n, 1);
		} else {
			scanf("%d%d", &b, &c);
			printf("%lld\n", query(b, c, 1, n, 1));
		}
	}
	
	return 0;
}
