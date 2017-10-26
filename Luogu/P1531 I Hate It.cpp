#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

int MAX[222222 << 2];

void PushUP(int rt) {
	MAX[rt] = max(MAX[rt << 1], MAX[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &MAX[rt]);
		return;
	}

	int m = (l + r) >> 1;

	build(lson);
	build(rson);

	PushUP(rt);
}

void update(int p, int sc, int l, int r, int rt) {
	if (l == r) {
		MAX[rt] = max(sc, MAX[rt]);
		return;
	}

	int m = (l + r) >> 1;

	if (p <= m)
		update(p, sc, lson);
	else
		update(p, sc, rson);

	PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return MAX[rt];

	int m = (l + r) >> 1;
	int ret = 0;

	if (L <= m)
		ret = max(ret, query(L, R, lson));
	if (R > m)
		ret = max(ret, query(L, R, rson));

	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);

	int n, m;

	scanf("%d%d", &n, &m);
	build(1, n, 1);

	while (m--) {
		char op[2];
		int a, b;
		
		scanf("%s%d%d", op, &a, &b);

		if (op[0] == 'Q')
			printf("%d\n", query(a, b, 1, n, 1));
		else
			update(a, b, 1, n, 1);
	}

	return 0;
}
