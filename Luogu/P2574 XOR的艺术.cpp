#include <iostream>
#include <cstdio>
#include <cstring>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

string data;

int sum[200000 << 2];
bool col[200000 << 2];

int n, m;

int read;

void PushDown(int rt, int m) {
	if (col[rt]) {
		col[rt << 1] = !col[rt << 1];
		col[rt << 1 | 1] = !col[rt << 1 | 1];
		
		sum[rt << 1] = (m - (m >> 1)) - sum[rt << 1];
		sum[rt << 1 | 1] = (m >> 1) - sum[rt << 1 | 1];
		
		col[rt] = false;
	}
}

void PushUP(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = data[read++] == '1';
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		sum[rt] = (r - l + 1) - sum[rt];
		col[rt] = !col[rt];
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

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return sum[rt];
	
	PushDown(rt, r - l + 1);
	
	int m = (r + l) >> 1;
	int ans = 0;

	if (L <= m)
		ans = query(L, R, lson);
		
	if (m < R)
		ans += query(L, R, rson);
		
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	cin >> data;
	
	build(1, n, 1);
	
	int a, b, c;
	
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		
		if (a)
			printf("%d\n", query(b, c, 1, n, 1));
		else
			update(b, c, 1, n, 1);
	}
	
	return 0;
}
