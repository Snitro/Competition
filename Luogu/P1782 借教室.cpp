#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m;

int MIN[1000000 << 2];
int col[1000000 << 2];

void PushUP(int rt) {
	MIN[rt] = min(MIN[rt << 1], MIN[rt << 1 | 1]);
}

void PushDown(int rt) {
	if (col[rt]) {
		col[rt << 1] += col[rt];
		col[rt << 1 | 1] += col[rt];
		
		MIN[rt << 1] += col[rt];
		MIN[rt << 1 | 1] += col[rt];
		
		col[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &MIN[rt]);
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int L, int R, int add, int l, int r, int rt) {
	if (L <= l && r <= R) {
		MIN[rt] += add;
		col[rt] += add;
		
		return;
	}
	
	PushDown(rt);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, add, lson);
		
	if (m < R)
		update(L, R, add, rson);
		
	PushUP(rt);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	build(root);
	
	int d, s, t;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &d, &s, &t);
		
		update(s, t, -d, root);
		
		if (MIN[1] < 0) {
			printf("-1\n%d", i);
			return 0;
		}
	}
	
	cout << 0 << endl;
	
	return 0;
}
