#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int n, m;

struct Node {
	int left;
	int right;
	int middle;
	
	int sum;
	
	Node() {
		left = right = middle = sum = 0;
	}
} nodes[500000 << 2];

void PushUP(int rt) {
	nodes[rt].sum = nodes[rt << 1].sum + nodes[rt << 1 | 1].sum;
	
	nodes[rt].left = max(nodes[rt << 1].left, nodes[rt << 1].sum + nodes[rt << 1 | 1].left);
	nodes[rt].right = max(nodes[rt << 1 | 1].right, nodes[rt << 1].right + nodes[rt << 1 | 1].sum);
	nodes[rt].middle = max(max(nodes[rt << 1].middle, nodes[rt << 1 | 1].middle), nodes[rt << 1].right + nodes[rt << 1 | 1].left);
}

void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &nodes[rt].left);
		nodes[rt].right = nodes[rt].middle = nodes[rt].sum = nodes[rt].left;
		
		return;
	}
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	PushUP(rt);
}

void update(int id, int v, int l, int r, int rt) {
	if (l == r) {
		nodes[rt].right = nodes[rt].middle = nodes[rt].sum = nodes[rt].left = v;
		
		return;
	}
	
	int m = (l + r) >> 1;
	
	if (id <= m)
		update(id, v, lson);
	
	if (m < id)
		update(id, v, rson);
		
	PushUP(rt);
}

Node query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return nodes[rt];
		
	int m = (r + l) >> 1;
	bool flg = false;
	Node left, right, MAX;
	
	if (L <= m) {
		left = query(L, R, lson);
		flg = true;
	}
	
	if (m < R) {
		if (flg) {
			right = query(L, R, rson);
			
			MAX.left = max(left.left, left.sum + right.left);
			MAX.right = max(right.right, right.sum + left.right);
			MAX.middle = max(max(left.middle, right.middle), left.right + right.left);
			MAX.sum = left.sum + right.sum;
			
			return MAX;
		} else
			return query(L, R, rson);
	}
	
	return left;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	build(root);
	
	int a, b, c;
	
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		
		if (a == 1) {
			Node ans = query(min(b, c), max(b, c), root);
			printf("%d\n", max(max(ans.left, ans.right), ans.middle));
		} else
			update(b, c, root);
	}
	
	return 0;
}
