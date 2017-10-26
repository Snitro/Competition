#include <iostream>
#include <cstdio>
#include <cstring>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

int sum[100000 << 2];

int n, w;

void PushUP(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
	if (l == r)
		return;

	int m = (l + r) >> 1;

	build(lson);
	build(rson);
}

void update(int W, int c, int l, int r, int rt) {
	if (l == r) {
		sum[rt] += c;
		return;
	}

	int m = (l + r) >> 1;

	if (W <= m)
		update(W, c, lson);
	else
		update(W, c, rson);

	PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return sum[rt];

	int m = (r + l) >> 1;

	int re = 0;

	if (L <= m)
		re += query(L, R, lson);

	if (m < R)
		re += query(L, R, rson);

	return re;
}

int main() {
	freopen("in.txt", "r", stdin);

	cin >> n >> w;

	build(1, n, 1);

	string data;
	int a, b;

	for (int i = 1; i <= w; i++) {
		cin >> data >> a >> b;

		if (data[0] == 'x')
			update(a, b, 1, n, 1);
		else
			cout << query(a, b, 1, n, 1) << endl;
	}

	return 0;
}
