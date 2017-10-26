#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m;

double col[100000 << 2];

struct Node {
	double square;
	double sum;
} nodes[100000 << 2];

void PushUP(int rt) {
	nodes[rt].square = nodes[rt << 1].square + nodes[rt << 1 | 1].square;
	nodes[rt].sum = nodes[rt << 1].sum + nodes[rt << 1 | 1].sum;
}

void PushDown(int rt, int m) {
	if (col[rt]) {
		col[rt << 1] += col[rt];
		col[rt << 1 | 1] += col[rt];
		
		nodes[rt << 1].square += (m - (m >> 1)) * col[rt] * col[rt] + 2 * nodes[rt << 1].sum * col[rt];
		nodes[rt << 1].sum += (m - (m >> 1)) * col[rt];
		
		nodes[rt << 1 | 1].square += (m >> 1) * col[rt] * col[rt] + 2 * nodes[rt << 1 | 1].sum * col[rt];
		nodes[rt << 1 | 1].sum += (m >> 1) * col[rt];
		
		col[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%lf", &nodes[rt].sum);
		nodes[rt].square = nodes[rt].sum * nodes[rt].sum;
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int L, int R, double add, int l, int r, int rt) {
	if (L <= l && r <= R) {
		col[rt] += add;
		
		nodes[rt].square += (r - l + 1) * add * add + 2 * nodes[rt].sum * add;
		nodes[rt].sum += (r - l + 1) * add;
		
		return;
	}
	
	PushDown(rt, r - l + 1);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, add, lson);
	
	if (m < R)
		update(L, R, add, rson);
		
	PushUP(rt);
}

double sum_query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return nodes[rt].sum;
	
	PushDown(rt, r - l + 1);
	
	double sum = 0;
	int m = (l + r) >> 1;
	
	if (L <= m)
		sum = sum_query(L, R, lson);
		
	if (m < R)
		sum += sum_query(L, R, rson);
		
	return sum;
}

double square_query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return nodes[rt].square;
		
	PushDown(rt, r - l + 1);
	
	double sum = 0;
	int m = (r + l) >> 1;
	
	if (L <= m)
		sum = square_query(L, R, lson);
		
	if (m < R)
		sum += square_query(L, R, rson);
		
	return sum;
}

double count_average(int l, int r) {
	return sum_query(l, r, root) / (r - l + 1);
}

double count_variance(int l, int r) {
	return (square_query(l, r, root) / (r - l + 1) - count_average(l, r) * count_average(l, r));
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	build(root);
	
	int a, b, c;
	double d;
	
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		
		if (a == 1) {
			scanf("%lf", &d);
			
			update(b, c, d, root);
		} else if (a == 2)
			printf("%.4f\n", count_average(b, c));
		else
			printf("%.4f\n", count_variance(b, c));
	}
	
	return 0;
}
