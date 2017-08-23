#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

int tree[400010 << 2];

int h, w, n; // h个广告牌, 每个广告牌 w 个空间, n条广告 

void PushUP(int rt) {
	tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
	tree[rt] = w;
	if (l == r)
		return;
	
	int m = (l + r) >> 1;
	
	build(lson);
	build(rson);
}

int query(int x, int l, int r, int rt) {
	if (l == r) {
		tree[rt] -= x;
		return l;
	}
	
	int m = (l + r) >> 1;
	
	int ret = (tree[rt << 1] >= x) ? query(x, lson) : query(x, rson);
	PushUP(rt);
	
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	while(~scanf("%d%d%d", &h, &w, &n)) { 
		if (h > n)
			h = n;
		
		build(1, h, 1);
		
		int data;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &data);
			
			if (tree[1] < data)
				printf("-1\n");
			else
				printf("%d\n", query(data, 1, h, 1));
		}
	} 
	return 0;
}
