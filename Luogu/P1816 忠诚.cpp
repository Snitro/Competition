#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define PushUP(x) MAX[x] = min(MAX[x << 1], MAX[x << 1 | 1])

using namespace std;

int MAX[222222 << 2];

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

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return MAX[rt];

	int m = (l + r) >> 1;
	int ret = 999999999;

	if (L <= m)
		ret = min(ret, query(L, R, lson));
	if (R > m)
		ret = min(ret, query(L, R, rson));

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

		scanf("%d%d", &a, &b);

		printf("%d ", query(a, b, 1, n, 1));
	}

	return 0;
}
