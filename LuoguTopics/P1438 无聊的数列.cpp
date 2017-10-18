#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m;

int datas[100005];

int sum[100000 << 2], color[100000 << 2];

void PushDown(int rt, int m) {
	if (color[rt]) {
		sum[rt << 1] += (m - (m >> 1)) * color[rt];
		sum[rt << 1 | 1] += (m >> 1) * color[rt];
		
		color[rt << 1] += color[rt];
		color[rt << 1 | 1] += color[rt];
		
		color[rt] = 0;
	}
}

void PushUP(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = datas[l];
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int L, int R, int num, int l, int r, int rt) {
	if (L <= l && r <= R) {
		color[rt] += num;
		sum[rt] += (r - l + 1) * num;
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

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return sum[rt];
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	int ret = 0;
	
	if (L <= m)
		ret += query(L, R, lson);
	if (m < R)
		ret += query(L, R, rson);
		
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &datas[i]);
	
	for (int i = n; i >= 2; i--)
		datas[i] -= datas[i - 1];
	
	int a, l, r, k, d;
	
	build(root);
	
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a);
		
		if (a == 1) {
			scanf("%d%d%d%d", &l, &r, &k, &d);
			
			update(l, l, k, root);
			
			if (l + 1 <= r)
				update(l + 1, r, d, root);
			if (r < n)
				update(r + 1, r + 1, -k - d * (r - l), root);
		} else {
			scanf("%d", &l);
			
			printf("%d\n", query(1, l, root));
		}
	}
	
	return 0;
}
